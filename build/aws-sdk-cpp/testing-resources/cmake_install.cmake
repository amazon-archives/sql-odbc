# Install script for directory: /Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/testing-resources

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/lib64/libtesting-resources.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtesting-resources.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtesting-resources.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtesting-resources.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/testing" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/testing-resources/include/aws/testing/MemoryTesting.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/testing-resources/include/aws/testing/ProxyConfig.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/testing-resources/include/aws/testing/TestingEnvironment.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/testing-resources/include/aws/testing/Testing_EXPORTS.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/external" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/testing-resources/include/aws/external/gtest.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/testing/platform" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/testing-resources/include/aws/testing/platform/PlatformTesting.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/testing/mocks/aws/auth" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/testing-resources/include/aws/testing/mocks/aws/auth/MockAWSHttpResourceClient.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/testing/mocks/aws/client" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/testing-resources/include/aws/testing/mocks/aws/client/MockAWSClient.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/testing/mocks/event" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/testing-resources/include/aws/testing/mocks/event/MockEventStreamDecoder.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/testing-resources/include/aws/testing/mocks/event/MockEventStreamHandler.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/testing/mocks/http" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/testing-resources/include/aws/testing/mocks/http/MockHttpClient.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/testing-resources/testing-resources-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/testing-resources/testing-resources-targets.cmake"
         "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/testing-resources/CMakeFiles/Export/lib/cmake/testing-resources/testing-resources-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/testing-resources/testing-resources-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/testing-resources/testing-resources-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/testing-resources" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/testing-resources/CMakeFiles/Export/lib/cmake/testing-resources/testing-resources-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/testing-resources" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/testing-resources/CMakeFiles/Export/lib/cmake/testing-resources/testing-resources-targets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/testing-resources" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/testing-resources/testing-resources-config.cmake"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/testing-resources/testing-resources-config-version.cmake"
    )
endif()

