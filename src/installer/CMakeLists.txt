#
#   Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
#
#   Licensed under the Apache License, Version 2.0 (the "License").
#   You may not use this file except in compliance with the License.
#   A copy of the License is located at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#   or in the "license" file accompanying this file. This file is distributed
#   on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
#   express or implied. See the License for the specific language governing
#   permissions and limitations under the License.
#

if(WIN32)
    # Set generator to WIX
    set(CPACK_GENERATOR "WIX")

    # This is a unique id for the installer - required for Windows
    # Generated at https://www.guidgen.com/
    set(CPACK_WIX_UPGRADE_GUID "2D325BD7-1176-40E8-8AB8-C52DD2F7B792")
	
	# The Icon shown next to the program name in Add/Remove programs
	set(CPACK_WIX_PRODUCT_ICON "${CMAKE_CURRENT_SOURCE_DIR}/icon.ico")
	
	# The bitmap will appear at the top of all installer pages other than the welcome and completion dialogs
	set(CPACK_WIX_UI_BANNER "${CMAKE_CURRENT_SOURCE_DIR}/banner.bmp")
	
	# Background bitmap used on the welcome and completion dialogs
	set(CPACK_WIX_UI_DIALOG "${CMAKE_CURRENT_SOURCE_DIR}/dialog.bmp")

	# This XML file is used for registry setup
	set(CPACK_WIX_PATCH_FILE "${CMAKE_CURRENT_SOURCE_DIR}/patch.xml")
	
else()
    # See https://gitlab.kitware.com/cmake/community/-/wikis/doc/cpack/PackageGenerators for more details on package generators
endif()

# Include system libraries in installer
include(InstallRequiredSystemLibraries)

# Add elasticodbc project to installer
install(TARGETS elasticodbc DESTINATION bin)

# General package info - to be updated later
set(CPACK_PACKAGE_NAME "Opendistro SQL ODBC Driver")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Opendistro SQL ODBC Driver")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${PROJECT_ROOT}/README.md")
set(CPACK_PACKAGE_VENDOR "Amazon.com")
set(CPACK_PACKAGE_CONTACT "someemail@foo.blah")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "${CPACK_PACKAGE_NAME}")
set(CPACK_SYSTEM_NAME "${CMAKE_SYSTEM_NAME}")
set(CPACK_PACKAGE_VERSION "${PACKAGE_VERSION}")

# Wix doesn't allow extensionless licenses, need to make a copy with an extension, .txt is appropriate
if(WIN32)
    configure_file("${PROJECT_ROOT}/LICENSE" "${PROJECT_ROOT}/LICENSE.txt" COPYONLY)
    set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_ROOT}/LICENSE.txt")
else()
    # Add license for mac - may be able to use LICENSE directly
endif()

include(CPack)