# Open Distro for Elasticsearch ODBC Driver

ElasticsearchODBC is a read-only ODBC driver for Windows and Mac for connecting to Open Distro for Elasticsearch SQL support.

## Specifications

The driver is compatible with ODBC 3.51.

## Supported Versions


  | Operating System  | Version | Supported Bitness |
  | ------------- |-------------| ----------------- |
  |  Windows    |  Windows 10   | 32-bit, 64-bit |
  |  MacOS    |  Catalina 10.15.4, Mojave 10.14.6 | 64-bit |

## Installing the Driver

You can use the installers generated as part of the most recent release.

### Windows

1. Run the `.msi` installer to install the ODFE SQL ODBC Driver.

To use the driver with Tableau:
1. Copy the `.tdc` file from `<driver-install-dir>/resources` to `<windows-user-dir>/Documents/My Tableau Repository/Datasources`.

This will customize the connection from Tableau to ODFE, ensuring that the correct forms of queries are used. 

### Mac

iODBC Driver Manager should be installed before installing the ODFE SQL ODBC Driver on Mac.

1. Run the `.pkg` installer to install the ODFE SQL ODBC Driver.
2. Open **iODBC Administrator** using the following command (this gives the application permissions to save the Driver & DSN configurations):
	1. `sudo /Applications/iODBC/iODBC\ Administrator64.app/Contents/MacOS/iODBC\ Administrator64`
    * **iODBC Administrator** is installed with **iODBC Driver Manager**.
3. Go to the **ODBC Drivers** tab.
3. Click **Add a Driver**
	* **Description of the Driver**: The driver name used for ODBC connections (ex. `ODFE SQL ODBC Driver`)
	* **Driver File Name**: The path to the driver file (default: `<driver-install-dir>/bin/libodfesqlodbc.dylib`)
	* **Setup File Name**: The path to the driver file (default: `<driver-install-dir>/bin/libodfesqlodbc.dylib`)
	* Set as a **User** driver
	* Click **OK** to save the options.
4. Go to the **User DSN** tab
5. Select **Add**.
	* Choose the Driver that was added above.
	* **Data Source Name (DSN)**: The name of the DSN used to store connection options (ex. `ODFE SQL ODBC DSN`)
	* **Comment**: Not required
	* Add key-value pairs by using the **'+'** button. The following is the recommended set of options for a default local ODFE installation:
		* **Host** | **localhost** //  ODFE server endpoint
		* **Port** | **9200** // ODFE server port
		* **Auth** | **NONE** // Authentication mode
		* **Username** | **(blank)** //  username used for BASIC auth
		* **Password** | **(blank)** //   password used for BASIC auth
		* **ResponseTimeout** | **10** // number of seconds to wait for a response from the server
		* **UseSSL** | **0** // do not use SSL for connections
    * Click **OK** to save the DSN configuration.
6. Click **OK** to exit the iODBC Administrator.

To use the driver with Tableau:
1. Copy the `.tdc` file from `<driver-install-dir>/resources` to `<mac-user-dir>/Documents/My Tableau Repository/Datasources`.

This will customize the connection from Tableau to ODFE, ensuring that the correct forms of queries are used.

## Using the Driver

The driver comes in the form of a library file:
    odfesqlodbc.dll for Window
    libodfesqlodbc.dylib for Mac

If using with ODBC compatible BI tools,refer to the tool documentation on configuring a new ODBC driver. Typically, all that's required is to make the tool aware of the location of the driver library file and then use it to setup database (i.e Elasticsearch) connections.

### Connection Strings and Other Settings

To setup a connection, the driver uses an ODBC connection string. Connection strings are semicolon-delimited strings specifying the set of options to use for a connection. Typically, a connection string will either:

1. specify a Data Source Name containing a pre-configured set of options (`DSN=xxx;User=xxx;Password=xxx;`)
2. or configure options explicitly using the string (`Host=xxx;Port=xxx;LogLevel=ES_DEBUG;...`)

The following are the driver options that can be configured using a DSN or connection string:

(**NOTE:** All option names are *case-insensitive*.) 

#### Basic Options

| Option | Description | Type | Default |
|--------|-------------|------|---------------|
| `DSN` | **D**ata **S**ource **N**ame used for configuring the connection. | string | |
| `Host` / `Server` | Hostname or IP address for the target cluster. | string | |
| `Port` | Port number on which the cluster's REST interface is listening. | string | |

#### Authentication Options

| Option | Description | Type | Default |
|--------|-------------|------|---------------|
| `Auth` | Authentication mechanism to use. | one of `BASIC` (basic HTTP), `AWS_SIGV4` (AWS auth), `NONE` | `NONE`
| `User` / `UID` | [`Auth=BASIC`] Username for the connection. | string | |
| `Password` / `PWD` | [`Auth=BASIC`] Password for the connection. | string | |
| `Region` | [`Auth=AWS_SIGV4`] Region used for signing requests | AWS region (eg. `us-west-1`) | |

#### Advanced Options

| Option | Description | Type | Default |
|--------|-------------|------|---------------|
| `UseSSL` | Whether to establish the connection over SSL/TLS | boolean (`0` or `1`) | false (`0`) |
| `HostnameVerification` | Indicate whether certificate hostname verification should be performed for an SSL/TLS connection. | boolean (`0` or `1`) | true (`1`) |
| `ResponseTimeout` | The maximum time to wait for responses from the `Host`, in seconds. | integer | `10` |

#### Logging Options

| Option | Description | Type | Default |
|--------|-------------|------|---------------|
| `LogLevel` | Severity level for driver logs. | one of `ES_OFF`, `ES_FATAL`, `ES_ERROR`, `ES_INFO`, `ES_DEBUG`, `ES_TRACE`, `ES_ALL` | `ES_WARNING` |
| `LogOutput` | Location for storing driver logs. | string | WIN: `C:\`, MAC: `/tmp` |

**NOTE:** Administrative privileges are required to change the value of logging options.

## Building from source

### Building

Please refer to the [build instructions](./BUILD_INSTRUCTIONS.md) for detailed build instructions on your platform.
If your PC is already setup to build the library, you can simply invoke cmake using

> cmake ./src

From the projects root directory, then build the project using Visual Studio (Windows) or make (Mac). To build in Visual Studio, open ./global_make_list.sln. To build for Mac, simply enter

> make

### Testing

**NOTE**: Some tests in ITODBCConnection will fail if a test DSN (Data Source Name) is not configured on your system. Refer to "Running Tests" in the [build instructions](./BUILD_INSTRUCTIONS.md) for more information on configuring this.

## Documentation

Please refer to the [documentation](https://opendistro.github.io/for-elasticsearch-docs/) for detailed information on installing and configuring Open Distro for Elasticsearch.

## Code of Conduct

This project has adopted an [Open Source Code of Conduct](https://opendistro.github.io/for-elasticsearch/codeofconduct.html).

## Security issue notifications

If you discover a potential security issue in this project we ask that you notify AWS/Amazon Security via our [vulnerability reporting page](http://aws.amazon.com/security/vulnerability-reporting/). Please do **not** create a public GitHub issue.

## Licensing

See the [LICENSE](./LICENSE) file for our project's licensing. We will ask you to confirm the licensing of your contribution.

## Copyright

Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
