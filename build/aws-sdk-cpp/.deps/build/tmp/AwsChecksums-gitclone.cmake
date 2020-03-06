
if(NOT "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsChecksums-stamp/AwsChecksums-gitinfo.txt" IS_NEWER_THAN "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsChecksums-stamp/AwsChecksums-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsChecksums-stamp/AwsChecksums-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsChecksums"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsChecksums'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/local/bin/git"  clone --no-checkout "https://github.com/awslabs/aws-checksums.git" "AwsChecksums"
    WORKING_DIRECTORY "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/awslabs/aws-checksums.git'")
endif()

execute_process(
  COMMAND "/usr/local/bin/git"  checkout v0.1.5 --
  WORKING_DIRECTORY "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsChecksums"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'v0.1.5'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/local/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsChecksums"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsChecksums'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsChecksums-stamp/AwsChecksums-gitinfo.txt"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsChecksums-stamp/AwsChecksums-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/.deps/build/src/AwsChecksums-stamp/AwsChecksums-gitclone-lastrun.txt'")
endif()

