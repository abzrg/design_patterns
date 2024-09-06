cmake_minimum_required(VERSION 3.30)

project(design_patterns
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
# set(CMAKE_CXX_CLANG_TIDY clang-tidy)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING
        "Default build type: RelWithDebInfo" FORCE)
endif()

add_subdirectory(src)
