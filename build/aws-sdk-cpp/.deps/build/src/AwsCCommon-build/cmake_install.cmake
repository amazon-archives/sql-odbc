# Install script for directory: /Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/allocator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/array_list.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/array_list.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/assert.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/atomics.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/atomics.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/atomics_fallback.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/atomics_gnu.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/atomics_gnu_old.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/atomics_msvc.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/byte_buf.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/byte_order.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/byte_order.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/clock.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/clock.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/command_line_parser.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/common.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/condition_variable.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/date_time.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/device_random.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/encoding.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/encoding.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/environment.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/error.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/error.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/exports.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/hash_table.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/linked_list.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/linked_list.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/log_channel.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/log_formatter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/log_writer.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/logging.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/lru_cache.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/macros.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/math.cbmc.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/math.fallback.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/math.gcc_overflow.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/math.gcc_x64_asm.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/math.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/math.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/math.msvc.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/mutex.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/predicates.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/priority_queue.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/ring_buffer.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/ring_buffer.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/rw_lock.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/stdbool.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/stdint.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/string.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/string.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/system_info.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/task_scheduler.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/thread.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/time.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/uuid.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/zero.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/zero.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common/posix" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/common/posix/common.inl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/common" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon-build/generated/include/aws/common/config.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/testing" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/testing/aws_test_allocators.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/testing" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/include/aws/testing/aws_test_harness.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon-build/libaws-c-common.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libaws-c-common.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libaws-c-common.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libaws-c-common.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/aws-c-common/cmake/static/aws-c-common-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/aws-c-common/cmake/static/aws-c-common-targets.cmake"
         "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon-build/CMakeFiles/Export/lib/aws-c-common/cmake/static/aws-c-common-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/aws-c-common/cmake/static/aws-c-common-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/aws-c-common/cmake/static/aws-c-common-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/aws-c-common/cmake/static" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon-build/CMakeFiles/Export/lib/aws-c-common/cmake/static/aws-c-common-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/aws-c-common/cmake/static" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon-build/CMakeFiles/Export/lib/aws-c-common/cmake/static/aws-c-common-targets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/aws-c-common/cmake" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon-build/aws-c-common-config.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/cmake/AwsCFlags.cmake"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/cmake/AwsSharedLibSetup.cmake"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/cmake/AwsTestHarness.cmake"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/cmake/AwsLibFuzzer.cmake"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/cmake/AwsSanitizers.cmake"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon/cmake/AwsSIMD.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon-build/tests/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsCCommon-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
