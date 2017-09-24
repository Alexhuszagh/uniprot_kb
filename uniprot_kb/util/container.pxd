# distutils: language = c++
#   :copyright: (c) 2017 Alex Huszagh.
#   :license: MIT, see licenses/mit.md for more details.
'''
    container
    ---------
    Cython wrappers for the C++/Python container interface.
'''

# DECLARATIONS
# ------------
# TODO: Finish unimplemented methods

cdef extern from "util/container.h" nogil:
    # UTILITY
    # -------
    int normalize_index(int length, int index)

    # ARRAY
    # -----
    bint array_contains[T, V](const T& t, const V& v) except +
    bint array_contains_pred[T, V, P](const T& t, const V& v, P p) except +
    void array_reverse[T](T& t) except +
    void array_insert[T, V](T& t, int index, const V& v) except +
    void array_erase[T](T& t, size_t index) except +
    void array_remove[T, V](T& t, const V& v) except +
    int array_index[T, V](const T& t, const V& v) except +
    int array_count[T, V](const T& t, const V& v) except +

    # MAP
    # ---
    bint map_contains[T, V](const T& t, const V& v) except +
#    void map_insert[T, K, V](T& t, const K& k, const V& v) except +
#    int map_count[T, V](const T& t, const V& v) except +
