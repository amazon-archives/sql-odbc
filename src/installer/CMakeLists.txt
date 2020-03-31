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
else()
    # See https://gitlab.kitware.com/cmake/community/-/wikis/doc/cpack/PackageGenerators for more details on package generators
    set(CPACK_GENERATOR "TGZ;productbuild")
endif()

# Include system libraries in installer
include(InstallRequiredSystemLibraries)

# Add elasticodbc project to installer
install(TARGETS elasticodbc DESTINATION bin)

# General package info - to be updated later
set(CPACK_PACKAGE_NAME "Open Distro for Elasticsearch SQL ODBC Driver")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${PROJECT_ROOT}/README.md")
set(CPACK_PACKAGE_VENDOR "Amazon.com")
set(CPACK_PACKAGE_CONTACT "someemail@foo.blah")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "${CPACK_PACKAGE_NAME}")
set(CPACK_SYSTEM_NAME "${CMAKE_SYSTEM_NAME}")
set(CPACK_PACKAGE_VERSION "${PACKAGE_VERSION}")

# Wix doesn't allow extensionless licenses, need to make a copy with an extension, .txt is appropriate
# TODO: Apply branding choices to installers (#54) (using reasonable defaults for now)
if(WIN32)
    configure_file("${PROJECT_ROOT}/LICENSE" "${PROJECT_ROOT}/LICENSE.txt" COPYONLY)
    set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_ROOT}/LICENSE.txt")
else()
    configure_file("${PROJECT_ROOT}/LICENSE" "${PROJECT_ROOT}/LICENSE.txt" COPYONLY)
    set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_ROOT}/LICENSE.txt")
    configure_file("${PROJECT_ROOT}/README.md" "${PROJECT_ROOT}/README.txt" COPYONLY)
    set(CPACK_RESOURCE_FILE_README "${PROJECT_ROOT}/README.txt")
    set(CPACK_RESOURCE_FILE_WELCOME "${PROJECT_ROOT}/Welcome.txt")
endif()

include(CPack)