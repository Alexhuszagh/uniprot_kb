#  :copyright: (c) 2017 Alex Huszagh.
#  :license: MIT, see LICENSE.md for more details.

from libcpp.string cimport string
from uniprot_kb.record cimport *

# DECLARATIONS
# ------------


cdef extern from "fasta.h" nogil:
    # How do I cdef functions?
#    cdef string& _record_to_fasta(string& str, const _record& r) "uniprot::to_fasta"
#    string& _list_to_fasta(string& str, const _record_list& l) "uniprot::to_fasta"
    pass
