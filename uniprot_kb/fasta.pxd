#  :copyright: (c) 2017 Alex Huszagh.
#  :license: MIT, see LICENSE.md for more details.

from libcpp.string cimport string

# DECLARATIONS
# ------------


cdef extern from "fasta.h" nogil:
    # cdef cppclass _record "uniprot::record"
    # How do I cdef functions?

    #string& to_fasta(string& str, const record& r)
    #string& to_fasta(string& str, const record_list& l)
    pass
