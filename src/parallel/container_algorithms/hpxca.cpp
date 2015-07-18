//  Copyright (c) 2015 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <hpx/parallel/container_algorithms/config.hpp>

namespace hpx { namespace parallel { namespace container_algorithms
{
    unsigned int major_version()
    {
        return HPXCA_VERSION_MAJOR;
    }

    unsigned int minor_version()
    {
        return HPXCA_VERSION_MINOR;
    }

    unsigned int subminor_version()
    {
        return HPXCA_VERSION_SUBMINOR;
    }

    unsigned long full_version()
    {
        return HPXCA_VERSION_FULL;
    }
}}}

