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
    # FUNCTIONS
    # ---------
    bint symmetry_cmp[T](const T& l, const T& r, int op) except +
    bint total_cmp[T](const T& l, const T& r, int op) except +

    # FUNCTORS
    # --------
    cdef cppclass ptr_equal_to:
        ptr_equal_to()

    cdef cppclass ptr_less_than:
        ptr_less_than()
