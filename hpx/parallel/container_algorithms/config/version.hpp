//  Copyright (c) 2015 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPXCA_CONFIG_VERSION)
#define HPXCA_CONFIG_VERSION

///////////////////////////////////////////////////////////////////////////////
//  The version of HPXCA
//
//  HPXCA_VERSION_FULL & 0x0000FF is the sub-minor version
//  HPXCA_VERSION_FULL & 0x00FF00 is the minor version
//  HPXCA_VERSION_FULL & 0xFF0000 is the major version
//
//  HPXCA_VERSION_DATE   YYYYMMDD is the date of the release
//                               (estimated release date for master branch)
//
#define HPXCA_VERSION_FULL         0x000001

#define HPXCA_VERSION_MAJOR        0
#define HPXCA_VERSION_MINOR        0
#define HPXCA_VERSION_SUBMINOR     1

#define HPXCA_VERSION_DATE         20150718

namespace hpx { namespace parallel { namespace container_algorithms
{
    // return version of this library
    HPXCA_EXPORT unsigned int major_version();
    HPXCA_EXPORT unsigned int minor_version();
    HPXCA_EXPORT unsigned int subminor_version();
    HPXCA_EXPORT unsigned long full_version();
}}}

#endif
