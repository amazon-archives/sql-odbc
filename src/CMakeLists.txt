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

# Pre 3.16 versions of Windows set MD/MT incorrectly and cause linker 'warnings' which are actually serious issues
if(WIN32)
cmake_minimum_required(VERSION 3.16) 
else()
cmake_minimum_required(VERSION 3.13) 
endif()
project(global_make_list)

# This wasn't being picked up on mac, causes some symbol errors
if(APPLE)
	set(CMAKE_CXX_STANDARD 14)
	add_definitions(-DHAVE_STRLCAT)
endif()

if(MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib64")
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib64")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin64")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib")
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin")
endif()

if(NOT WIN32)
	# Unix builds require autoconf
	option(AUTOCONF_ENABLE "Enable autoconf" ON)
	configure_file(autoconf.h.in generated/autoconf.h @ONLY)
endif()

# Base directories
set(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/..")
set(ESODBC_SRC "${CMAKE_CURRENT_SOURCE_DIR}/elasticodbc")
set(ESENLIST_SRC "${CMAKE_CURRENT_SOURCE_DIR}/elasticenlist")
set(INTEGRATION_TESTS "${CMAKE_CURRENT_SOURCE_DIR}/IntegrationTests")
set(UNIT_TESTS "${CMAKE_CURRENT_SOURCE_DIR}/UnitTests")
set(LIBRARY_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../libraries)
set(AWS_SDK_CPP "${CMAKE_CURRENT_SOURCE_DIR}/aws-sdk-cpp")
set(AWS_SDK_CPP_CORE "${AWS_SDK_CPP}/aws-cpp-sdk-core/include")
set(INSTALL_SRC "${CMAKE_CURRENT_SOURCE_DIR}/installer")
set(DSN_INSTALLER_SRC "${CMAKE_CURRENT_SOURCE_DIR}/DSNInstaller")

set(PACKAGE_VERSION "0.0.0")

# Extensions of base directories
set(PERFORMANCE_TESTS "${CMAKE_CURRENT_SOURCE_DIR}/PerformanceTests")
set(UT_HELPER "${UNIT_TESTS}/UTHelper")
set(IT_HELPER "${INTEGRATION_TESTS}/ITODBCHelper")
set(RABBIT_SRC ${LIBRARY_DIRECTORY}/rabbit/include)
set(RAPIDJSON_SRC ${LIBRARY_DIRECTORY}/rapidjson/include)
set(VLD_SRC ${LIBRARY_DIRECTORY}/VisualLeakDetector/include)

# Without this symbols will be exporting to Unix but not Windows
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)	

# General compiler definitions
add_compile_definitions		(	_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
								UNICODE_SUPPORT	
								DYNAMIC_LOAD	
								_MBCS
								_CRT_SECURE_NO_DEPRECATE	
								_USRDLL	
								# USE_SSL					
							)

# Platform specific compiler definitions
if (WIN32)
	# Windows specific
	add_compile_definitions	(	_WINDLL						
								_WIN64			
								_WINDOWS
								WIN_EXPORT				
							)
elseif(APPLE)
	# macOS specific
	add_compile_definitions	(	WITH_IODBC	
								SQLCOLATTRIBUTE_SQLLEN
							)
	# iODBC includes
	include_directories(/usr/local/include)
elseif(UNIX)
	# Unix specific
	add_compile_definitions	(	WITH_UNIXODBC	
								SQLCOLATTRIBUTE_SQLLEN
							)
endif()

# GTest import
include(gtest/googletest.cmake)
fetch_googletest(
    ${PROJECT_SOURCE_DIR}/gtest
    ${PROJECT_BINARY_DIR}/googletest
    )
enable_testing()

# If these are not explicitly set to empty, aws-sdk-cpp will take 
# these and package everything in the user's /usr/local/ directories
set(CMAKE_INSTALL_BINDIR "")
set(CMAKE_INSTALL_LIBDIR "")
set(CMAKE_INSTALL_INCLUDEDIR "")

# Projects to build
add_subdirectory(${ESODBC_SRC})
add_subdirectory(${ESENLIST_SRC})
add_subdirectory(${INTEGRATION_TESTS})
add_subdirectory(${UNIT_TESTS})
add_subdirectory(${PERFORMANCE_TESTS})
add_subdirectory(${AWS_SDK_CPP})
add_subdirectory(${INSTALL_SRC})
add_subdirectory(${DSN_INSTALLER_SRC})