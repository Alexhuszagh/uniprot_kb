#  :copyright: (c) 2017 Alex Huszagh.
#  :license: MIT, see LICENSE.md for more details.

from libcpp.string cimport string
from uniprot_kb.record cimport *

# DECLARATIONS
# ------------

cdef extern from "format.h" namespace "uniprot" nogil:
    cdef enum format:
        format_txt
        format_fasta
        format_xml

    cdef string to_string[T](const T& t, format fmt)


cdef inline string _record_to_string(_record t, format fmt):
    return to_string(t, fmt)

cdef inline string _list_to_string(_record_list t, format fmt):
    return to_string(t, fmt)
