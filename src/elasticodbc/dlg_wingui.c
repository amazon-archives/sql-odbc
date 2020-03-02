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
    int show_basic = (strcmp(am->authtype_str, AUTHTYPE_BASIC) == 0);
    ShowWindow(GetDlgItem(hdlg, IDC_USER), show_basic);
    ShowWindow(GetDlgItem(hdlg, IDC_PASSWORD), show_basic);
    ShowWindow(GetDlgItem(hdlg, IDC_PASSWORD_STATIC), show_basic);
    ShowWindow(GetDlgItem(hdlg, IDC_USERNAME_STATIC), show_basic);
    int show_iam = (strcmp(am->authtype_str, AUTHTYPE_IAM) == 0);
    ShowWindow(GetDlgItem(hdlg, IDC_REGION), show_iam);
    ShowWindow(GetDlgItem(hdlg, IDC_REGION_STATIC), show_iam);
}

void SetDlgStuff(HWND hdlg, const ConnInfo *ci) {
    // Connection
    SetDlgItemText(hdlg, IDC_DATABASE, ci->database);
    SetDlgItemText(hdlg, IDC_SERVER, ci->server);
    SetDlgItemText(hdlg, IDC_PORT, ci->port);
    SetDlgItemText(hdlg, IDC_CONNTIMEOUT, ci->response_timeout);

    // Authentication
    SetDlgItemText(hdlg, IDC_USER, ci->username);
    SetDlgItemText(hdlg, IDC_PASSWORD, SAFE_NAME(ci->password));
    SetDlgItemText(hdlg, IDC_REGION, ci->region);

    // Encryption
    int use_ssl = (IsDlgButtonChecked(hdlg, IDC_USESSL) ? 1 : 0);
    ShowWindow(GetDlgItem(hdlg, IDC_ALLOWSELFSIGNED), use_ssl);
    ShowWindow(GetDlgItem(hdlg, IDC_CERTIFICATE), use_ssl);
    ShowWindow(GetDlgItem(hdlg, IDC_CERTIFICATE_STATIC), use_ssl);
    ShowWindow(GetDlgItem(hdlg, IDC_KEY), use_ssl);
    ShowWindow(GetDlgItem(hdlg, IDC_KEY_STATIC), use_ssl);
    SetDlgItemText(hdlg, IDC_CERTIFICATE, ci->certificate);
    SetDlgItemText(hdlg, IDC_KEY, ci->key);

    // Misc
    UINT log_button_checked = ci->drivers.commlog && ci->drivers.debug;
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
    GetDlgItemText(hdlg, IDC_DATABASE, ci->database, sizeof(ci->database));
    GetDlgItemText(hdlg, IDC_SERVER, ci->server, sizeof(ci->server));
    GetDlgItemText(hdlg, IDC_CONNTIMEOUT, ci->response_timeout,
                   sizeof(ci->response_timeout));
    GetDlgItemText(hdlg, IDC_PORT, ci->port, sizeof(ci->port));

    // Authentication
    GetDlgItemText(hdlg, IDC_USER, ci->username, sizeof(ci->username));
    GetNameField(hdlg, IDC_PASSWORD, &ci->password);
    GetDlgItemText(hdlg, IDC_REGION, ci->region, sizeof(ci->region));
    const struct authmode *am = GetCurrentAuthMode(hdlg);
    SetAuthenticationVisibility(hdlg, am);
    STRCPY_FIXED(ci->authtype, am->authtype_str);

    // Encryption
    ci->use_ssl = (IsDlgButtonChecked(hdlg, IDC_USESSL) ? 1 : 0);
    ShowWindow(GetDlgItem(hdlg, IDC_ALLOWSELFSIGNED), ci->use_ssl);
    ShowWindow(GetDlgItem(hdlg, IDC_CERTIFICATE), ci->use_ssl);
    ShowWindow(GetDlgItem(hdlg, IDC_CERTIFICATE_STATIC), ci->use_ssl);
    ShowWindow(GetDlgItem(hdlg, IDC_CERTIFICATENOTE_STATIC), ci->use_ssl);
    GetDlgItemText(hdlg, IDC_CERTIFICATE, ci->certificate,
                   sizeof(ci->certificate));
    GetDlgItemText(hdlg, IDC_KEY, ci->key, sizeof(ci->key));

    // Misc
    ci->drivers.commlog = ci->drivers.debug =
        (IsDlgButtonChecked(hdlg, IDC_CHECK1) ? 1 : 0);
    setGlobalCommlog(ci->drivers.commlog);
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

#endif /* WIN32 */
