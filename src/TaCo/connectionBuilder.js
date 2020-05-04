(function dsbuilder(attr)
{
    var params = {};

    params["SERVER"] = attr[connectionHelper.attributeServer];
    params["PORT"] = attr[connectionHelper.attributePort];
    params["UID"] = attr[connectionHelper.attributeUsername];
    params["PWD"] = attr[connectionHelper.attributePassword];

    var authAttrValue = attr[connectionHelper.attributeAuthentication];
    if (authAttrValue == "auth-none"){
        // no-op
    } else if (authAttrValue == "basic")
    {
        params["UID"] = attr[connectionHelper.attributeUsername];
        params["PWD"] = attr[connectionHelper.attributePassword];
    }

    if (attr[connectionHelper.attributeSSLMode] == "require")
    {
        params["sslmode"] = "require";
    }

    var odbcConnectStringExtrasMap = {};
    const attributeODBCConnectStringExtras = "odbc-connect-string-extras";
    if (attributeODBCConnectStringExtras in attr)
    {
        odbcConnectStringExtrasMap = connectionHelper.ParseODBCConnectString(attr[attributeODBCConnectStringExtras]);
    }
    for (var key in odbcConnectStringExtrasMap)
    {
        params[key] = odbcConnectStringExtrasMap[key];
    }

    var formattedParams = [];

    formattedParams.push(connectionHelper.formatKeyValuePair(driverLocator.keywordDriver, driverLocator.locateDriver(attr)));

    for (var key in params)
    {
        formattedParams.push(connectionHelper.formatKeyValuePair(key, params[key]));
    }

    return formattedParams;
})
