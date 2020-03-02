/*
 * Copyright <2019> Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 *
 */

#include "drvconn.h"

#include <stdio.h>
#include <stdlib.h>

#include "es_connection.h"
#include "es_odbc.h"
#include "misc.h"

#ifndef WIN32
#include <sys/socket.h>
#include <sys/types.h>
#else
#include <winsock2.h>
#endif

#include <string.h>

#ifdef WIN32
#include <windowsx.h>

#include "resource.h"
#include "win_setup.h"
#endif
#include "dlg_specific.h"
#include "es_apifunc.h"

#ifdef WIN32
LRESULT CALLBACK dconn_FDriverConnectProc(HWND hdlg, UINT wMsg, WPARAM wParam,
                                          LPARAM lParam);
extern HINSTANCE s_hModule; /* Saved module handle. */
#endif

char *hide_password(const char *str) {
    char *outstr, *pwdp;

    if (!str)
        return NULL;
    outstr = strdup(str);
    if (!outstr)
        return NULL;
    if (pwdp = strstr(outstr, "PWD="), !pwdp)
        pwdp = strstr(outstr, "pwd=");
    if (pwdp) {
        char *p;

        for (p = pwdp + 4; *p && *p != ';'; p++)
            *p = 'x';
    }
    return outstr;
}

int paramRequired(const ConnInfo *ci, int reqs) {
    int required = 0;
    const char *pw = SAFE_NAME(ci->password);

    /* Password is not necessarily a required parameter. */
    if ((reqs & PASSWORD_IS_REQUIRED) != 0)
        if ('\0' == pw[0])
            required |= PASSWORD_IS_REQUIRED;

    return required;
}

#ifdef WIN32
RETCODE
dconn_DoDialog(HWND hwnd, ConnInfo *ci) {
    LRESULT dialog_result;

    MYLOG(0, "entering ci = %p\n", ci);

    if (hwnd) {
        dialog_result =
            DialogBoxParam(s_hModule, MAKEINTRESOURCE(DLG_CONFIG), hwnd,
                           dconn_FDriverConnectProc, (LPARAM)ci);
        if (-1 == dialog_result) {
            int errc = GetLastError();
            MYLOG(0, " LastError=%d\n", errc);
        }
        if (!dialog_result || (dialog_result == -1))
            return SQL_NO_DATA_FOUND;
        else
            return SQL_SUCCESS;
    }

    MYLOG(0, " No window specified\n");
    return SQL_ERROR;
}

LRESULT CALLBACK dconn_FDriverConnectProc(HWND hdlg, UINT wMsg, WPARAM wParam,
                                          LPARAM lParam) {
    MYLOG(0, "dconn_FDriverConnectProc\n");
    ConnInfo *ci;
    char strbuf[64];

    switch (wMsg) {
        case WM_INITDIALOG:
            ci = (ConnInfo *)lParam;

            /* Change the caption for the setup dialog */
            SetWindowText(hdlg, "Elasticsearch Connection");

            LoadString(s_hModule, IDS_ADVANCE_CONNECTION, strbuf,
                       sizeof(strbuf));
            SetWindowText(GetDlgItem(hdlg, IDC_DATASOURCE), strbuf);
            CheckDlgButton(hdlg, IDC_CHECK1, getGlobalCommlog());

            /* Hide the DSN and description fields */
            ShowWindow(GetDlgItem(hdlg, IDC_DSNAMETEXT), SW_HIDE);
            ShowWindow(GetDlgItem(hdlg, IDC_DSNAME), SW_HIDE);
            ShowWindow(GetDlgItem(hdlg, IDC_DESCTEXT), SW_HIDE);
            ShowWindow(GetDlgItem(hdlg, IDC_DESC), SW_HIDE);
            ShowWindow(GetDlgItem(hdlg, IDC_DRIVER), SW_HIDE);
            ShowWindow(GetDlgItem(hdlg, IDC_TEST), SW_HIDE);
            ShowWindow(GetDlgItem(hdlg, IDC_MANAGEDSN), SW_HIDE);
            ShowWindow(GetDlgItem(hdlg, IDC_DATASOURCE), SW_HIDE);
            if ('\0' != ci->server[0])
                EnableWindow(GetDlgItem(hdlg, IDC_SERVER), FALSE);
            if ('\0' != ci->port[0])
                EnableWindow(GetDlgItem(hdlg, IDC_PORT), FALSE);

            SetWindowLongPtr(hdlg, DWLP_USER,
                             lParam); /* Save the ConnInfo for the "OK" */
            SetDlgStuff(hdlg, ci);

            if (ci->password_required) {
                HWND notu = GetDlgItem(hdlg, IDC_NOTICE_USER);

                SetFocus(GetDlgItem(hdlg, IDC_PASSWORD));
                SetWindowText(notu, "  Supply password       ");
                ShowWindow(notu, SW_SHOW);
                SendMessage(notu, WM_CTLCOLOR, 0, 0);
            } else if (ci->database[0] == '\0')
                ; /* default focus */
            else if (ci->server[0] == '\0')
                SetFocus(GetDlgItem(hdlg, IDC_SERVER));
            else if (ci->port[0] == '\0')
                SetFocus(GetDlgItem(hdlg, IDC_PORT));
            else if (ci->username[0] == '\0')
                SetFocus(GetDlgItem(hdlg, IDC_USER));
            else if (ci->region[0] == '\0')
                SetFocus(GetDlgItem(hdlg, IDC_REGION));

            // Authentication
            int authtype_selection_idx = 0;
            unsigned int ams_cnt = 0;
            const struct authmode *ams = GetAuthModes(&ams_cnt);
            char buff[MEDIUM_REGISTRY_LEN + 1];
            for (unsigned int i = 0; i < ams_cnt; i++) {
                LoadString(GetWindowInstance(hdlg), ams[i].authtype_id, buff,
                           MEDIUM_REGISTRY_LEN);
                SendDlgItemMessage(hdlg, IDC_AUTHTYPE, CB_ADDSTRING, 0,
                                   (WPARAM)buff);
                if (!stricmp(ci->authtype, ams[i].authtype_str)) {
                    authtype_selection_idx = i;
                }
            }
            SendDlgItemMessage(hdlg, IDC_AUTHTYPE, CB_SETCURSEL,
                               ams[authtype_selection_idx].authtype_id,
                               (WPARAM)0);
            SetAuthenticationVisibility(hdlg, &ams[authtype_selection_idx]);

            // Encryption
            ci->use_ssl = (IsDlgButtonChecked(hdlg, IDC_USESSL) ? 1 : 0);
            ShowWindow(GetDlgItem(hdlg, IDC_ALLOWSELFSIGNED), ci->use_ssl);
            ShowWindow(GetDlgItem(hdlg, IDC_CERTIFICATE), ci->use_ssl);
            ShowWindow(GetDlgItem(hdlg, IDC_CERTIFICATE_STATIC), ci->use_ssl);
            ShowWindow(GetDlgItem(hdlg, IDC_KEY), ci->use_ssl);
            ShowWindow(GetDlgItem(hdlg, IDC_KEY_STATIC), ci->use_ssl);
            break;

        case WM_COMMAND:
            switch (GET_WM_COMMAND_ID(wParam, lParam)) {
                case IDOK:
                    ci = (ConnInfo *)GetWindowLongPtr(hdlg, DWLP_USER);
                    GetDlgStuff(hdlg, ci);

                    if (ci->use_ssl) {
                        if ((strcmp(ci->key, "") == 0)
                            && (strcmp(ci->certificate, "") == 0)) {
                            MessageBox(hdlg,
                                       "If SSL is checked, certificate and key "
                                       "must be provided.",
                                       "Configuration is invalid.",
                                       MB_ICONEXCLAMATION | MB_OK);
                            break;
                        }
                    }

                case IDCANCEL:
                    EndDialog(hdlg, GET_WM_COMMAND_ID(wParam, lParam) == IDOK);
                    return TRUE;

                case IDOK2:  // <== TEST button
                {
                    ConnInfo tmp_info;
                    ci = (ConnInfo *)GetWindowLongPtr(hdlg, DWLP_USER);
                    GetDlgStuff(hdlg, ci);

                    if (ci->use_ssl) {
                        if ((strcmp(ci->key, "") == 0)
                            && (strcmp(ci->certificate, "") == 0)) {
                            MessageBox(hdlg,
                                       "If SSL is checked, certificate and key "
                                       "must be provided.",
                                       "Configuration is invalid.",
                                       MB_ICONEXCLAMATION | MB_OK);
                            break;
                        }
                    }

                    CC_copy_conninfo(&tmp_info, ci);
                    test_connection(hdlg, &tmp_info, FALSE);
                    CC_conninfo_release(&tmp_info);
                    break;
                }
                case IDC_AUTHTYPE: {
                    ci = (ConnInfo *)GetWindowLongPtr(hdlg, DWLP_USER);
                    const struct authmode *am = GetCurrentAuthMode(hdlg);
                    SetAuthenticationVisibility(hdlg, am);
                    break;
                }
                case IDC_USESSL: {
                    ci = (ConnInfo *)GetWindowLongPtr(hdlg, DWLP_USER);
                    int use_ssl =
                        (IsDlgButtonChecked(hdlg, IDC_USESSL) ? 1 : 0);
                    ShowWindow(GetDlgItem(hdlg, IDC_ALLOWSELFSIGNED), use_ssl);
                    ShowWindow(GetDlgItem(hdlg, IDC_CERTIFICATE), use_ssl);
                    ShowWindow(GetDlgItem(hdlg, IDC_CERTIFICATE_STATIC),
                               use_ssl);
                    ShowWindow(GetDlgItem(hdlg, IDC_KEY), use_ssl);
                    ShowWindow(GetDlgItem(hdlg, IDC_KEY_STATIC), use_ssl);
                    break;
                }
            }
            break;
        case WM_CTLCOLORSTATIC:
            if (lParam == (LPARAM)GetDlgItem(hdlg, IDC_NOTICE_USER)) {
                HBRUSH hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
                SetTextColor((HDC)wParam, RGB(255, 0, 0));
                return (LRESULT)hBrush;
            }
            break;
    }

    return FALSE;
}
#endif /* WIN32 */

#define ATTRIBUTE_DELIMITER ';'
#define OPENING_BRACKET '{'
#define CLOSING_BRACKET '}'

typedef BOOL (*copyfunc)(ConnInfo *, const char *attribute, const char *value);
BOOL dconn_get_attributes(copyfunc func, const char *connect_string,
                          ConnInfo *ci) {
    BOOL ret = TRUE;
    char *our_connect_string;
    const char *pair, *attribute, *value, *termp;
    BOOL eoftok;
    char *equals, *delp;
    char *strtok_arg;
#ifdef HAVE_STRTOK_R
    char *last = NULL;
#endif /* HAVE_STRTOK_R */

    if (our_connect_string = strdup(connect_string), NULL == our_connect_string)
        return FALSE;
    strtok_arg = our_connect_string;

#ifdef FORCE_PASSWORD_DISPLAY
    MYLOG(0, "our_connect_string = '%s'\n", our_connect_string);
#else
    if (get_mylog()) {
        char *hide_str = hide_password(our_connect_string);

        MYLOG(0, "our_connect_string = '%s'\n", hide_str);
        free(hide_str);
    }
#endif /* FORCE_PASSWORD_DISPLAY */

    termp = strchr(our_connect_string, '\0');
    eoftok = FALSE;
    while (!eoftok) {
        if (strtok_arg != NULL && strtok_arg >= termp) /* for safety */
            break;
#ifdef HAVE_STRTOK_R
        pair = strtok_r(strtok_arg, ";", &last);
#else
        pair = strtok(strtok_arg, ";");
#endif /* HAVE_STRTOK_R */
        if (strtok_arg)
            strtok_arg = NULL;
        if (!pair)
            break;

        equals = strchr(pair, '=');
        if (!equals)
            continue;

        *equals = '\0';
        attribute = pair;   /* ex. DSN */
        value = equals + 1; /* ex. 'CEO co1' */
        /*
         * Values enclosed with braces({}) can contain ; etc
         * We don't remove the braces here because
         * decode_or_remove_braces() in dlg_specifi.c
         * would remove them later.
         * Just correct the misdetected delimter(;).
         */
        switch (*value) {
            const char *valuen, *closep;

            case OPENING_BRACKET:
                delp = strchr(value, '\0');
                if (delp >= termp) {
                    eoftok = TRUE;
                    break;
                }
                /* Where's a corresponding closing bracket? */
                closep = strchr(value, CLOSING_BRACKET);
                if (NULL != closep && closep[1] == '\0')
                    break;

                for (valuen = value; valuen < termp;
                     closep = strchr(valuen, CLOSING_BRACKET)) {
                    if (NULL == closep) {
                        if (!delp) /* error */
                        {
                            MYLOG(0, "closing bracket doesn't exist 1\n");
                            ret = FALSE;
                            goto cleanup;
                        }
                        closep = strchr(delp + 1, CLOSING_BRACKET);
                        if (!closep) /* error */
                        {
                            MYLOG(0, "closing bracket doesn't exist 2\n");
                            ret = FALSE;
                            goto cleanup;
                        }
                        *delp = ATTRIBUTE_DELIMITER; /* restore delimiter */
                        delp = NULL;
                    }
                    if (CLOSING_BRACKET == closep[1]) {
                        valuen = closep + 2;
                        if (valuen >= termp)
                            break;
                        else if (valuen == delp) {
                            *delp = ATTRIBUTE_DELIMITER;
                            delp = NULL;
                        }
                        continue;
                    } else if (ATTRIBUTE_DELIMITER == closep[1]
                               || '\0' == closep[1] || delp == closep + 1) {
                        delp = (char *)(closep + 1);
                        *delp = '\0';
                        strtok_arg = delp + 1;
                        if (strtok_arg + 1 >= termp)
                            eoftok = TRUE;
                        break;
                    }
                    MYLOG(0,
                          "subsequent char to the closing bracket is %c "
                          "value=%s\n",
                          closep[1], value);
                    ret = FALSE;
                    goto cleanup;
                }
        }

        /* Copy the appropriate value to the conninfo  */
        (*func)(ci, attribute, value);
    }

cleanup:
    free(our_connect_string);

    return ret;
}

BOOL dconn_get_DSN_or_Driver(const char *connect_string, ConnInfo *ci) {
    CC_conninfo_init(ci, INIT_GLOBALS);
    return dconn_get_attributes(get_DSN_or_Driver, connect_string, ci);
}

BOOL dconn_get_connect_attributes(const char *connect_string, ConnInfo *ci) {
    return dconn_get_attributes(copyConnAttributes, connect_string, ci);
}
