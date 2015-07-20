//  Copyright (c) 2015 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPX_PARALLEL_TRAITS_IS_RANGE_JUL_18_2015_1017AM)
#define HPX_PARALLEL_TRAITS_IS_RANGE_JUL_18_2015_1017AM

#include <hpx/config.hpp>
#include <hpx/util/decay.hpp>

#include <boost/range/iterator_range_core.hpp>

#include <type_traits>

namespace hpx { namespace parallel { namespace traits
{
    namespace detail
    {
        template <typename Rng, typename Enable = void>
        struct is_range
          : std::false_type
        {};

        template <typename Iterator>
        struct is_range<boost::iterator_range<Iterator> >
          : std::true_type
        {};
    }

    template <typename Rng, typename Enable = void>
    struct is_range
      : detail::is_range<typename hpx::util::decay<Rng>::type>
    {};
}}}

#endif
