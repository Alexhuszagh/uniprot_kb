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

cdef extern from "util/container.h" nogil:
    int normalize_index(int length, int index) except +
    void reverse_container[T](T& t) except +
    void insert_container[T, V](T& t, int index, const V& v) except +
    void remove_container[T, V](T& t, const V& v) except +
    bint container_contains[T, V](const T& t, const V& v) except +
    int index_container[T, V](const T& t, const V& v) except +
    int count_container[T, V](const T& t, const V& v) except +