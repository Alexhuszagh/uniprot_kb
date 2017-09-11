# distutils: language = c++
#   :copyright: (c) 2017 Alex Huszagh.
#   :license: MIT, see licenses/mit.md for more details.
'''
    operator
    --------
    Cython wrappers for the C++/Python operator interface.
'''

# DECLARATIONS
# ------------

cdef extern from "util/operator.h" nogil:
    bint symmetry_cmp[T](const T& l, const T& r, int op) except +
    bint total_cmp[T](const T& l, const T& r, int op) except +