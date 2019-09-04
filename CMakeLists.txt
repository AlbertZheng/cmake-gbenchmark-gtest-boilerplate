cmake_minimum_required(VERSION 3.8)
project(demo)

set(APP_EXE_NAME ${PROJECT_NAME})
set(APP_LIB_NAME ${PROJECT_NAME}-api)

# Set build type to RELEASE by default:
if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type provided, default to RELEASE.")
  set(CMAKE_BUILD_TYPE "RELEASE")
endif()

# Options can be turned on and off by providing cmake with a -DOPTIONNAME=ON (or OFF) argument.
# For example, to turn off tests and benchmarks, build a shared library, and use sanitize flags in a DEBUG build:
#    cmake .. -DCMAKE_BUILD_TYPE=DEBUG
#             -DBUILD_TESTS=OFF 
#             -DBUILD_BENCHMARKS=OFF 
#             -DBUILD_SHARED_LIBS=ON
#             -ENABLE_SANITIZE=ON
option(BUILD_TESTS       "Build tests" ON)
option(BUILD_BENCHMARKS  "Build benchmarks" ON)
option(ENABLE_SANITIZE   "Add sanitize flags" OFF)
# BUILD_SHARED_LIBS is a standard CMake variable, 
# but we declare it here to make it prominent in the GUI.
option(BUILD_SHARED_LIBS "Build shared libraries (DLLs)." OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(Threads REQUIRED)
find_package(Boost)
find_package(Math)

if(Boost_FOUND)
  include_directories(. include ${Boost_INCLUDE_DIRS})
else()
  include_directories(. include)
endif()

set(CMAKE_CXX_STANDARD 17) # cmake 3.1 supports '98', '11' or '14'. cmake 3.8 or later support '17'.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(ENABLE_SANITIZE)
  set(CMAKE_CXX_FLAGS "-fsanitize=address -fsanitize=undefined ${CMAKE_CXX_FLAGS}")
endif()

add_subdirectory(src)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
  add_subdirectory(third-party/googletest)
endif()

if(BUILD_BENCHMARKS)
  add_subdirectory(benchmark)
  add_subdirectory(third-party/benchmark)
endif()

message(STATUS "")
message(STATUS "BUILD SUMMARY")
message(STATUS "  CMAKE_GENERATOR       : ${CMAKE_GENERATOR}")
message(STATUS "  Compiler ID           : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "  Build type            : ${CMAKE_BUILD_TYPE}")
message(STATUS "  Sanitize flags        : ${ENABLE_SANITIZE}")
message(STATUS "  Module path           : ${CMAKE_MODULE_PATH}")
message(STATUS "  Project name          : ${PROJECT_NAME}")
if(BUILD_SHARED_LIBS)
message(STATUS "  Project library type  : SHARED")
else()
message(STATUS "  Project library type  : STATIC")
endif()
message(STATUS "  Build tests           : ${BUILD_TESTS}")
message(STATUS "  Build benchmarks      : ${BUILD_BENCHMARKS}")
message(STATUS "  Boost FOUND           : ${Boost_FOUND}")
message(STATUS "  Boost include dirs    : ${Boost_INCLUDE_DIRS}")
message(STATUS "  Math FOUND            : ${MATH_FOUND}")
message(STATUS "  Math include dirs     : ${MATH_INCLUDE_DIR}")
message(STATUS "  Math libraries        : ${MATH_LIBRARIES}")
message(STATUS "")
