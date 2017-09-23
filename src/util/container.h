//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

 #pragma once

#include <algorithm>

// FUNCTIONS
// ---------

template <typename T, typename V>
bool array_contains(const T& t, const V& v)
{
    return std::find(std::begin(t), std::end(t), v) != std::end(t);
}


template <typename T>
void array_reverse(T& t)
{
    std::reverse(t.begin(), t.end());
}


template <typename T, typename V>
void array_insert(T& t, size_t index, const V& v)
{
    auto it = std::begin(t);
    std::advance(it, index);
    t.insert(it, v);
}


template <typename T, typename V>
void array_remove(T& t, const V& v)
{
    auto it = std::find(std::begin(t), std::end(t), v);
    if (it == std::end(t)) {
        throw std::out_of_range("Value not found in container.");
    }
    t.erase(it);
}


template <typename T, typename V>
bool map_contains(const T& t, const V& v)
{
    return t.find(v) != std::end(t);
}


// map insert


//int index_container[T, V](const T& t, const V& v) except +
//int count_container[T, V](const T& t, const V& v) except +
