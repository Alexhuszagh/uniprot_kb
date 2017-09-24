//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

 #pragma once

// FUNCTIONS
// ---------


template <typename T>
bool symmetry_cmp(const T& l, const T& r, int op)
{
    switch (op) {
        case 2:
            return l == r;
        case 3:
            return !(l == r);
        default:
            return false;
    }
}


template <typename T>
bool total_cmp(const T& l, const T& r, int op)
{
    switch (op) {
        case 0:
            return l < r;
        case 1:
            return !(r < l);
        case 2:
            return l == r;
        case 3:
            return !(l == r);
        case 4:
            return r < l;
        case 5:
            return !(l < r);
        default:
            return false;
    }
}


// FUNCTORS
// --------


struct ptr_equal_to
{
    template <typename T>
    bool operator()(const T& l, const T& r)
    {
        if (l && r) {
            return *l == *r;
        } else {
            return l == r;
        }
    }
};


struct ptr_less_than
{
    template <typename T>
    bool operator()(const T& l, const T& r)
    {
        if (l && r) {
            return *l < *r;
        } else {
            return l < r;
        }
    }
};
