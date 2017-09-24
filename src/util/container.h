//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

 #pragma once

#include <algorithm>

// UTILITY
// -------

std::ptrdiff_t normalize_index(size_t length, std::ptrdiff_t index)
{
    if (index < 0) {
        return length + index;
    } else {
        return index;
    }
}

// ARRAY
// -----

template <typename T, typename V>
bool array_contains(const T& t, const V& v)
{
    return std::find(std::begin(t), std::end(t), v) != std::end(t);
}


template <typename T, typename V, typename Pred>
bool array_contains_pred(const T& t, const V& v, Pred pred)
{
    auto p = [&v, &pred](const V& r) -> bool
    {
        return pred(v, r);
    };
    return std::find_if(std::begin(t), std::end(t), p) != std::end(t);
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


template <typename T>
void array_erase(T& t, size_t index)
{
    t.erase(std::begin(t) + index);
}


template <typename T, typename V>
void array_remove(T& t, const V& v)
{
    auto first = std::begin(t);
    auto last = std::end(t);
    auto it = std::find(first, last, v);
    if (it == last) {
        throw std::out_of_range("Value not found in container.");
    }
    t.erase(it);
}


template <typename T, typename V>
size_t array_index(const T& t, const V& v)
{
    auto first = std::begin(t);
    auto last = std::end(t);
    auto it = std::find(first, last, v);
    if (it == last) {
        throw std::out_of_range("Value not found in container.");
    }
    return std::distance(first, it);
}


template <typename T, typename V>
size_t array_count(const T& t, const V& v)
{
    return std::count(std::begin(t), std::end(t), v);
}


// MAP
// ---


template <typename T, typename V>
bool map_contains(const T& t, const V& v)
{
    return t.find(v) != std::end(t);
}

// TODO:
// map insert
