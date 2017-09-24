#  :copyright: (c) 2017 Alex Huszagh.
#  :license: MIT, see LICENSE.md for more details.

from libc.stdint cimport *
from libcpp.memory cimport shared_ptr
from libcpp.string cimport string
from libcpp.vector cimport vector

# DECLARATIONS
# ------------


cdef extern from "record.h" nogil:
    cdef cppclass _record "uniprot::record":
        uint8_t sequence_version
        uint8_t protein_evidence;
        double mass;
        size_t length;
        string gene;
        string id;
        string mnemonic;
        string name;
        string organism;
        string proteome;
        string sequence;
        string taxonomy;

        _record()
        _record(const _record&);

    cdef cppclass _record_list "uniprot::record_list"(vector[shared_ptr[_record]]):
        pass
