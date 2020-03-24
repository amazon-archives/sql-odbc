#!/bin/bash

# --force: force checks all define combinations (default max is 12)
# -iaws-sdk-cpp: avoid checking AWS C++ SDK source files in our repo
# -UWIN32: do not check WIN32-defined codepaths; this would throw errors on Mac
cppcheck --force -iaws-sdk-cpp -UWIN32 ./src 2> cppcheck-results.log