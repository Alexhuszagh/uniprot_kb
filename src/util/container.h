//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

 #pragma once

#include <algorithm>

// FUNCTIONS
// ---------

//int normalize_index(int length, int index) except +
//void reverse_container[T](T& t) except +
//void insert_container[T, V](T& t, int index, const V& v) except +
//void remove_container[T, V](T& t, const V& v) except +

template <typename T, typename V>
bool array_contains(const T& t, const V& v)
{
    return std::find(std::begin(t), std::end(t), v) != std::end(t);
}


template <typename T, typename V>
bool map_contains(const T& t, const V& v)
{
    return t.find(v) != std::end(t);
}


//int index_container[T, V](const T& t, const V& v) except +
//int count_container[T, V](const T& t, const V& v) except +
