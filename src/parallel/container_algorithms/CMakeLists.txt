# Copyright (c) 2015 Hartmut Kaiser
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

include_directories(${HPX_INCLUDE_DIR})
link_directories(${HPX_LIBRARY_DIR})

add_definitions("-DHPXCA_EXPORTS")

add_hpx_library(
  hpxca SHARED
  SOURCE_ROOT "${hpxca_SOURCE_DIR}/src/parallel/container_algorithms"
  HEADER_ROOT "${hpxca_SOURCE_DIR}/hpx"
  OUTPUT_SUFFIX .
  AUTOGLOB)

set_target_properties(hpxca_lib PROPERTIES
  VERSION ${HPXCA_VERSION}
  SOVERSION ${HPXCA_SOVERSION}
  CLEAN_DIRECT_OUTPUT 1
  OUTPUT_NAME hpxrx${HPX_DEBUG_POSTFIX}
  FOLDER "Core")

