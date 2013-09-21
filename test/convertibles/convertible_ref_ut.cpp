//
// Copyright (c) 2012-2013 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "boost/di/convertibles/convertible_ref.hpp"

#include <boost/test/unit_test.hpp>
#include <memory>
#include <boost/ref.hpp>

namespace boost {
namespace di {
namespace convertibles {

BOOST_AUTO_TEST_CASE(copy_ctor) {
    int i = 42;
    convertible_ref<int> ref_i(ref(i));
    convertible_ref<int> ref(ref_i);

    BOOST_CHECK_EQUAL(ref_i, ref);
}

BOOST_AUTO_TEST_CASE(to_ref) {
    int i = 42;
    int& i_ref = i;
    int& object_ref = convertible_ref<int>(ref(i_ref));
    BOOST_CHECK_EQUAL(i, object_ref);
}

BOOST_AUTO_TEST_CASE(to_named) {
    int i = 42;
    int& i_ref = i;
    named<int> object_ref = convertible_ref<int>(ref(i_ref));
    BOOST_CHECK_EQUAL(i, object_ref);
}

BOOST_AUTO_TEST_CASE(to_const_ref) {
    const int i = 42;
    const int& i_ref = i;
    const int& object_ref = convertible_ref<const int>(cref(i_ref));
    BOOST_CHECK_EQUAL(i, object_ref);
}

BOOST_AUTO_TEST_CASE(to_const_named_ref) {
    const int i = 42;
    const int& i_ref = i;
    named<const int> object_ref = convertible_ref<const int>(cref(i_ref));
    BOOST_CHECK_EQUAL(i, object_ref);
}

} // namespace convertibles
} // namespace di
} // namespace boost

