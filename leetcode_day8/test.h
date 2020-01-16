//
// Created by maverick on 2020/1/15.
//

#ifndef ALGORITHMS_TEST_H
#define ALGORITHMS_TEST_H

#include <iterator>

template <typename T>
class iter:
{
    typedef T value_type;
    typedef std::random_access_iterator_tag iterator_category;
    typedef std::ptrdiff_t different_type;
};

#endif //ALGORITHMS_TEST_H
