# Open Distro for Elasticsearch ODBC Driver

ElasticsearchODBC is a read-only ODBC driver for Windows and Mac for connecting to Open Distro for Elasticsearch SQL support.

## Specifications

The driver is compatible with ODBC 3.51.

## Using the Driver

The driver comes in the form of a library file:
    elasticsearch.dll for Window
    libelasticsearch.dylib for Mac

If using with ODBC compatible BI tools,refer to the tool documentation on configuring a new ODBC driver. Typically, all that's required is to make the tool aware of the location of the driver library file and then use it to setup database (i.e Elasticsearch) connections.

### Connection Strings and other Settings

To setup a connection, the driver requires a ODBC connection strings. The connection strings are of the form:

>1. DSN=my_dsn;Username=my_username;Password=my_password;
>2. Host=host_name;Port=port_number;Username=my_username;Password=my_password;

* **DSN**: String that has an associated data structure used to describe a connection to a data source.
* **Host**: Hostname or IP address of the target cluster.
* **Port**: Port number on which the cluster's REST interface is listening. Default value depends on the scheme selected. For http, the default is 9200. For https, the default is 443.
* **Username**: Connection username.
* **Password**: Connection password.

TODO AE-45: Update new connection string options

## Download and Installation

The driver will be available through standard open source repositories for installers.

### Building

Please refer to the [build instructions](./BUILD_INSTRUCTIONS) for detailed build instructions on your platform.
If your PC is already setup to build the library, you can simply invoke cmake using

> cmake ./src

From the projects root directory, then build the project using Visual Studio (Windows) or make (Mac). To build in Visual Studio, open ./global_make_list.sln. To build for Mac, simply enter

> make

### Testing

**NOTE**: Some tests in ITODBCConnection will fail if a test DSN (Data Source Name) is not configured on your system. Refer to "Running Tests" in the [build instructions](./BUILD_INSTRUCTIONS) for more information on configuring this.

## Documentation

Please refer to the [documentation](TODO AE-134: <Documentation link>) for detailed information on installing and configuring opendistro-elasticsearch-security plugin.

## Code of Conduct

This project has adopted an [Open Source Code of Conduct](https://opendistro.github.io/for-elasticsearch/codeofconduct.html).

## Security issue notifications

If you discover a potential security issue in this project we ask that you notify AWS/Amazon Security via our [vulnerability reporting page](http://aws.amazon.com/security/vulnerability-reporting/). Please do **not** create a public GitHub issue.License Agreement — so you can focus on writing great code.

## Licensing

See the [LICENSE](./LICENSE) file for our project's licensing. We will ask you to confirm the licensing of your contribution.

## Copyright

Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
