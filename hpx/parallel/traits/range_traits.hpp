//  Copyright (c) 2015 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPX_PARALLEL_TRAITS_RANGE_TRAITS_JUL_18_2015_1107AM)
#define HPX_PARALLEL_TRAITS_RANGE_TRAITS_JUL_18_2015_1107AM

#include <hpx/config.hpp>

#include <boost/range/iterator_range_core.hpp>

namespace hpx { namespace parallel { namespace traits
{
    ///////////////////////////////////////////////////////////////////////////
    template <typename Rng, typename Enable = void>
    struct range_traits;

    template <typename Iterator>
    struct range_traits<boost::iterator_range<Iterator> >
    {
        typedef Iterator iterator_type;
        typedef Iterator sentinel_type;
    };

    ///////////////////////////////////////////////////////////////////////////
    template <typename Rng>
    struct range_iterator
    {
        typedef typename range_traits<Rng>::iterator_type type;
    };

    template <typename Rng>
    struct range_sentinel
    {
        typedef typename range_traits<Rng>::sentinel_type type;
    };
}}}

#endif
