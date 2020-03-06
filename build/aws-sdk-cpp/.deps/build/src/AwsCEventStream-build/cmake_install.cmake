# Install script for directory: /Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCEventStream

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCEventStream-build/lib/libaws-c-event-stream.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libaws-c-event-stream.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libaws-c-event-stream.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libaws-c-event-stream.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/event-stream" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCEventStream/include/aws/event-stream/event_stream.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCEventStream/include/aws/event-stream/event_stream_exports.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/aws-c-event-stream/cmake/static/aws-c-event-stream-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/aws-c-event-stream/cmake/static/aws-c-event-stream-targets.cmake"
         "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCEventStream-build/CMakeFiles/Export/lib/aws-c-event-stream/cmake/static/aws-c-event-stream-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/aws-c-event-stream/cmake/static/aws-c-event-stream-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/aws-c-event-stream/cmake/static/aws-c-event-stream-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/aws-c-event-stream/cmake/static" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCEventStream-build/CMakeFiles/Export/lib/aws-c-event-stream/cmake/static/aws-c-event-stream-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/aws-c-event-stream/cmake/static" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCEventStream-build/CMakeFiles/Export/lib/aws-c-event-stream/cmake/static/aws-c-event-stream-targets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/aws-c-event-stream/cmake" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCEventStream-build/aws-c-event-stream-config.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCEventStream-build/tests/cmake_install.cmake")
  include("/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCEventStream-build/bin/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCEventStream-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
