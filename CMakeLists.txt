# Copyright (c) 2015 Hartmut Kaiser
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

################################################################################
# Top level CMakeList.txt for HPXca (HPX Container Algorithms)
################################################################################

cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

project(hpxca CXX)

# Project version.
set(HPXCA_MAJOR_VERSION 0)
set(HPXCA_MINOR_VERSION 1)
set(HPXCA_PATCH_LEVEL   0)
set(HPXCA_SOVERSION     ${HPXCA_MAJOR_VERSION})
set(HPXCA_VERSION
    "${HPXCA_MAJOR_VERSION}.${HPXCA_MINOR_VERSION}.${HPXCA_PATCH_LEVEL}")

set(CMAKE_MODULE_PATH
    ${HPX_ROOT}/share/cmake-${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}/Modules)

find_package(HPX REQUIRED)

if(MSVC)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  hpx_add_compile_flag(-Ox CONFIGURATIONS Release LANGUAGES CXX C)
  hpx_add_compile_flag(-RTC1 CONFIGURATIONS Debug LANGUAGES CXX C)

  # VS2012 and above has a special flag for improving the debug experience by
  # adding more symbol information to the build (-d2Zi)
  hpx_add_compile_flag(-d2Zi+ CONFIGURATIONS RelWithDebInfo)

  # VS2013 and above know how to do link time constant data segment folding
  # VS2013 update 2 and above know how to remove debug information for
  #        non-referenced functions and data (-Zc:inline)
  if(MSVC12 OR MSVC13)
    hpx_add_compile_flag(-Zc:inline)
    hpx_add_compile_flag(-Gw CONFIGURATIONS Release RelWithDebInfo MinSizeRelease)
    hpx_add_compile_flag(-Zo CONFIGURATIONS RelWithDebInfo)
  endif()

  hpx_add_compile_flag(-EHsc)       # Exceptions
  hpx_add_compile_flag(-GR)         # Runtime type information
  hpx_add_compile_flag(-MP)         # Multiprocessor build
  hpx_add_compile_flag(-bigobj)     # Increase the maximum size of object file sections
else()
  set(HPX_RPATH
      "${HPX_RPATH}:${CMAKE_INSTALL_PREFIX}/lib/hpx:${CMAKE_BINARY_DIR}/lib/hpx")
endif()

include_directories(${HPX_INCLUDE_DIR})
link_directories(${HPX_LIBRARY_DIR})

include_directories(${hpxca_SOURCE_DIR})

add_subdirectory(src/parallel/container_algorithms)

# handle tests
hpx_option(
  HPXCA_WITH_TESTS_UNIT BOOL "Build HPXca unit tests (default: ON)"
  ON ADVANCED CATEGORY "Build Targets")

add_hpx_pseudo_target(tests)
add_subdirectory(tests)

