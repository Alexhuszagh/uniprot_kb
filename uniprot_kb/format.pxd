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
    cdef T from_string[T](const string& str, format fmt)
    cdef void to_file[T](const T& t, const string& path, format fmt)
    cdef T from_file[T](const string& path, format fmt)


cdef inline string _record_to_string(const _record& t, format fmt):
    return to_string(t, fmt)

cdef inline string _list_to_string(const _record_list& t, format fmt):
    return to_string(t, fmt)

cdef inline _record _record_from_string(const string& str, format fmt):
    return from_string[_record](str, fmt)

cdef inline _record_list _list_from_string(const string& str, format fmt):
    return from_string[_record_list](str, fmt)

cdef inline void _record_to_file(const _record& t, const string& path, format fmt):
    to_file[_record](t, path, fmt)

cdef inline void _list_to_file(const _record_list& t, const string& path, format fmt):
    to_file[_record_list](t, path, fmt)

cdef inline _record _record_from_file(const string& path, format fmt):
    return from_file[_record](path, fmt)

cdef inline _record_list _list_from_file(const string& path, format fmt):
    return from_file[_record_list](path, fmt)
