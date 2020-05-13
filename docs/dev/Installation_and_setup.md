## Overview

The Open Database Connectivity (ODBC) driver lets you integrate Open Distro for Elasticsearch with your favorite Business Intelligence (BI) applications.

The driver is currently supported for MacOS and Windows platform. The latest version of driver is compatible with ODBC **3.51** specification.

### Supported Versions

  | Operating System  | Version |
  | ------------- |-------------|
  |  Windows    |  Windows 10 |
  |  MacOS    |  Catalina 10.15.4, Mojave 10.14.6 |

## Concepts

 |      |   |
 | ------------- |-------------|
 |  **DSN**    | A Data Source Name is used to store driver information in the system. By storing the information in the system, the information does not need to be specified each time the driver connects. |
 |  **.tdc** file    | The TDC file contains configuration information that Tableau applies to any connection matching the database vendor name and driver name defined in the file. This configuration allows customers to fine-tune parts of their ODBC data connection, turn on/off certain features not supported by data source|

  
## Driver Installation

The driver can be obtained by downloading the bundled distribution installer from [here](https://opendistro.github.io/for-elasticsearch/downloads.html) or by building from source.

###  Via Installer

#### Windows

1. Double click the downloaded `ODFE SQL ODBC Driver-<version>-Windows.msi` installer. In the case installer is unsigned it will show the following pop up. Click on **More info** and click on **Run anyway**. 
Then click **Next** to proceed installation.

<p align="center">
  <img src="img/windows_signing_error_1.png" width="400" height="400">
  <img src="img/windows_singing_error_2.png" width="400" height="400">
</p>

<p align="center">
  <img src="img/windows_installer_home.png" width="506" height="397">
</p>


2. Accept the agreement and click **Next**.

3. The installer comes bundled with documentation and useful resources files to connect with various BI tools, for example `.tdc` file for Tableau. You can choose to keep the documentation and resources, or remove it. You can also choose the download location. Click **Next**.

<p align="center">
  <img src="img/windows_installer_select_and_browse.png" width="506" height="397">
</p>


4. Click **Install** and then **Finish**.

<p align="center">
  <img src="img/windows_installer_install.png" width="506" height="397">
</p>


5. The **DSN** come already setup with the installation. The following connection information is setup as part of default DSN

//TODO; add config

----
#### MacOS

1. Double click the downloaded `ODFE SQL ODBC Driver-<version>-Darwin.pkg` installer. In the case installer is unsigned it will show the following pop up. Right click on installer and select **Open**. 
Click **Continue** to proceed installation.

<p align="center">
  <img src="img/mac_signing_error_1.png" width="417" height="211">
  <img src="img/mac_signing_error_2.png" width="417" height="211">
</p>


<p align="center">
  <img src="img/mac_installer_home.png" width="506" height="397">
</p>

2. Click **Continue** to move past the **Introduction** and **Readme** .

3. Accept the agreement and click **Continue**.

<p align="center">
  <img src="img/mac_installer_license.png" width="506" height="397">
</p>


4. Choose **Destination** to install driver files.

5. The installer comes bundled with documentation and useful resources files to connect with various BI tools, for example `.tdc` file for Tableau. You can choose to keep the documentation and resources, or remove it. Click **Customize** to choose needed files. Click **Continue**.

<p align="center">
  <img src="img/mac_installer_select_and_browse.png" width="506" height="397">
</p>

4. Click **Install** and then **Close**.

<p align="center">
  <img src="img/mac_installer_succesful.png" width="506" height="397">
</p>

5. Currently the **DSN** is not setup as part of installation and need to be configured manually.


## Connecting to Tableau

Pre-requisites:

- Make sure DSN is already setup.
- Make sure Elasticsearch is running on _host_ and _port_ as configured in DSN.
- Make sure the `.tdc` is copied to `<user_home_directory>/Documents/My Tableau Repository/Datasources` in both MacOS and Windows.

1. Start Tableau. Under **Connect** section , go to **To a Server** and choose **Other Databases (ODBC)**.

<p align="center">
  <img src="img/tableau_connection.png" width="733" height="516">
</p>

2. In the **DSN drop-down**, select the Elasticsearch DSN you set up in the previous set of steps. The options you added will be automatically filled into the **Connection Attributes**
 
<p align="center">
  <img src="img/tableau_dsn.png" width="303" height="470">
</p>
 
3. Select **Sign In**. After a few seconds, Tableau will connect to your Elasticsearch server. Once connected, you will directed to  **Datasource** window. The **Database** will be already populated with name of Elasticsearch cluster.
To list all the indices, click the search icon under **Table**. 

<p align="center">
  <img src="img/tableau_sample_data.png" width="620" height="424">
</p>

4. Start playing with data by dragging table to connection area. Click **Update Now** or **Automatically Update** to populate table data.

<p align="center">
  <img src="img/tableau_sample_viz.png" width="745" height="500">
</p>

### Troubleshooting

#### Unable to connect to server
**Problem:** A error window after signing in as below.

<p align="center">
  <img src="img/tableau_connection_error.png" width="360" height="220">
</p>

**Workaround:**

This is most likely due to Elasticsearch server not running on **host** and **post** configured in DSN.
Confirm **host** and **post** are correct and Elasticsearch server is running with ODFE SQL plugin.
Also make sure `.tdc` that was downloaded with installer is copied correctly to `<user_home_directory>/Documents/My Tableau Repository/Datasources` directory.

