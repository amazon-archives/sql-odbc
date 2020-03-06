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

#ifdef WIN32

#include "dlg_specific.h"
#include "es_apifunc.h"
#include "loadlib.h"
#include "misc.h"  // strncpy_null
#include "win_setup.h"
#ifdef _HANDLE_ENLIST_IN_DTC_
#include "connexp.h"
#include "xalibname.h"
#endif /* _HANDLE_ENLIST_IN_DTC_ */

#define AUTHMODE_CNT 3
extern HINSTANCE s_hModule;
static const struct authmode authmodes[AUTHMODE_CNT] = {
    {IDS_AUTHTYPE_NONE, AUTHTYPE_IAM},
    {IDS_AUTHTYPE_BASIC, AUTHTYPE_BASIC},
    {IDS_AUTHTYPE_IAM, AUTHTYPE_NONE}};

const struct authmode *GetCurrentAuthMode(HWND hdlg) {
    unsigned int ams_cnt = 0;
    const struct authmode *ams = GetAuthModes(&ams_cnt);
    unsigned int authtype_selection_idx = (unsigned int)(DWORD)SendMessage(
        GetDlgItem(hdlg, IDC_AUTHTYPE), CB_GETCURSEL, 0L, 0L);
    if (authtype_selection_idx >= ams_cnt)
        authtype_selection_idx = 0;
    return &ams[authtype_selection_idx];
}

void SetAuthenticationVisibility(HWND hdlg, const struct authmode *am) {
    if (strcmp(am->authtype_str, AUTHTYPE_BASIC) == 0) {
        EnableWindow(GetDlgItem(hdlg, IDC_USER), TRUE);
        EnableWindow(GetDlgItem(hdlg, IDC_PASSWORD), TRUE);
        EnableWindow(GetDlgItem(hdlg, IDC_REGION), FALSE);
    } else if (strcmp(am->authtype_str, AUTHTYPE_IAM) == 0) {
        EnableWindow(GetDlgItem(hdlg, IDC_USER), FALSE);
        EnableWindow(GetDlgItem(hdlg, IDC_PASSWORD), FALSE);
        EnableWindow(GetDlgItem(hdlg, IDC_REGION), TRUE);
    } else {
        EnableWindow(GetDlgItem(hdlg, IDC_USER), FALSE);
        EnableWindow(GetDlgItem(hdlg, IDC_PASSWORD), FALSE);
        EnableWindow(GetDlgItem(hdlg, IDC_REGION), FALSE);
    } 
}

void SetDlgStuff(HWND hdlg, const ConnInfo *ci) {
    // Connection
    SetDlgItemText(hdlg, IDC_DSNAME, ci->dsn);
    SetDlgItemText(hdlg, IDC_SERVER, ci->server);
    SetDlgItemText(hdlg, IDC_PORT, ci->port);

    // Authentication
    int authtype_selection_idx = 0;
    unsigned int ams_cnt = 0;
    const struct authmode *ams = GetAuthModes(&ams_cnt);
    char buff[MEDIUM_REGISTRY_LEN + 1];
    for (unsigned int i = 0; i < ams_cnt; i++) {
        LoadString(GetWindowInstance(hdlg), ams[i].authtype_id, buff,
                   MEDIUM_REGISTRY_LEN);
        SendDlgItemMessage(hdlg, IDC_AUTHTYPE, CB_ADDSTRING, 0, (WPARAM)buff);
        if (!stricmp(ci->authtype, ams[i].authtype_str)) {
            authtype_selection_idx = i;
        }
    }
    SendDlgItemMessage(hdlg, IDC_AUTHTYPE, CB_SETCURSEL,
                       ams[authtype_selection_idx].authtype_id, (WPARAM)0);
    SetDlgItemText(hdlg, IDC_USER, ci->username);
    SetDlgItemText(hdlg, IDC_PASSWORD, SAFE_NAME(ci->password));
    SetDlgItemText(hdlg, IDC_REGION, ci->region);

    // Misc
    UINT log_button_checked = ci->drivers.loglevel;
    CheckDlgButton(hdlg, IDC_CHECK1, log_button_checked);
}

static void GetNameField(HWND hdlg, int item, esNAME *name) {
    char medium_buf[MEDIUM_REGISTRY_LEN + 1];
    GetDlgItemText(hdlg, item, medium_buf, sizeof(medium_buf));
    STR_TO_NAME((*name), medium_buf);
}

void GetDlgStuff(HWND hdlg, ConnInfo *ci) {
    // Connection
    GetDlgItemText(hdlg, IDC_DESC, ci->desc, sizeof(ci->desc));
    GetDlgItemText(hdlg, IDC_SERVER, ci->server, sizeof(ci->server));
    GetDlgItemText(hdlg, IDC_PORT, ci->port, sizeof(ci->port));

    // Authentication
    GetDlgItemText(hdlg, IDC_USER, ci->username, sizeof(ci->username));
    GetNameField(hdlg, IDC_PASSWORD, &ci->password);
    GetDlgItemText(hdlg, IDC_REGION, ci->region, sizeof(ci->region));
    const struct authmode *am = GetCurrentAuthMode(hdlg);
    SetAuthenticationVisibility(hdlg, am);
    STRCPY_FIXED(ci->authtype, am->authtype_str);

    // Misc
    ci->drivers.loglevel = (IsDlgButtonChecked(hdlg, IDC_CHECK1) ? 1 : 0);
    setGlobalCommlog(ci->drivers.loglevel);
}

const struct authmode *GetAuthModes(unsigned int *count) {
    *count = AUTHMODE_CNT;
    return authmodes;
}
static void getDriversDefaultsOfCi(const ConnInfo *ci, GLOBAL_VALUES *glbv) {
    const char *drivername = NULL;

    if (ci->drivername[0])
        drivername = ci->drivername;
    else if (NAME_IS_VALID(ci->drivers.drivername))
        drivername = SAFE_NAME(ci->drivers.drivername);
    if (drivername && drivername[0])
        getDriversDefaults(drivername, glbv);
    else
        getDriversDefaults(INVALID_DRIVER, glbv);
}

LRESULT CALLBACK advancedOptionsProc(HWND hdlg, UINT wMsg, WPARAM wParam,
                                     LPARAM lParam) {
    LPSETUPDLG lpsetupdlg;
    ConnInfo *ci;

    switch (wMsg) {
        case WM_INITDIALOG:
            SetWindowLongPtr(hdlg, DWLP_USER, lParam);
            lpsetupdlg = (LPSETUPDLG)lParam;
            ci = &lpsetupdlg->ci;
            CheckDlgButton(hdlg, IDC_USESSL, ci->use_ssl);
            CheckDlgButton(hdlg, IDC_HOST_VER, ci->verify_server);
            SetDlgItemText(hdlg, IDC_CONNTIMEOUT, ci->response_timeout);
            break;

        case WM_COMMAND:
            lpsetupdlg = (LPSETUPDLG)GetWindowLongPtr(hdlg, DWLP_USER);
            switch (GET_WM_COMMAND_ID(wParam, lParam)) {
                case IDOK:
                    // Retrieve dialog values 
                    if (!lpsetupdlg->fDefault)
                        GetDlgItemText(hdlg, IDC_DSNAME, lpsetupdlg->ci.dsn,
                                       sizeof(lpsetupdlg->ci.dsn));

                    // Get Dialog Values 
                    lpsetupdlg->ci.use_ssl = (IsDlgButtonChecked(hdlg, IDC_USESSL) ? 1 : 0);
                    lpsetupdlg->ci.verify_server = (IsDlgButtonChecked(hdlg, IDC_HOST_VER) ? 1 : 0);
                    GetDlgItemText(hdlg, IDC_CONNTIMEOUT,
                                   lpsetupdlg->ci.response_timeout,
                                   sizeof(lpsetupdlg->ci.response_timeout));
                    EndDialog(hdlg, FALSE);
                    break;

                case IDCANCEL:
                    EndDialog(hdlg, FALSE);
                    return TRUE;
            }
    }
    return FALSE;
}

LRESULT logOptionsProc(HWND hdlg, UINT wMsg, WPARAM wParam, LPARAM lParam) {
    LPSETUPDLG lpsetupdlg;
    ConnInfo *ci;

    switch (wMsg) {
        case WM_INITDIALOG:
            SetWindowLongPtr(hdlg, DWLP_USER, lParam);
            lpsetupdlg = (LPSETUPDLG)lParam;
            ci = &lpsetupdlg->ci;
            break;

        case WM_COMMAND:
            lpsetupdlg = (LPSETUPDLG)GetWindowLongPtr(hdlg, DWLP_USER);
            switch (GET_WM_COMMAND_ID(wParam, lParam)) {
                case IDOK:
                    EndDialog(hdlg, FALSE);
                    break;

                case IDCANCEL:
                    EndDialog(hdlg, GET_WM_COMMAND_ID(wParam, lParam) == IDOK);
                    return TRUE;
            }
    }
    return FALSE;
}


#endif /* WIN32 */
