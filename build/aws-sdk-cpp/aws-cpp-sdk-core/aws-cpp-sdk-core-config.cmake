include(CMakeFindDependencyMacro)
find_dependency(aws-c-event-stream)
include("${CMAKE_CURRENT_LIST_DIR}/aws-cpp-sdk-core-targets.cmake")
