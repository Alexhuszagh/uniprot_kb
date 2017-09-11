#!/usr/bin/env python
#  :copyright: (c) 2017 Alex Huszagh.
#  :license: MIT, see LICENSE.md for more details.

cimport cython
from libc.stdint cimport *
from libcpp.string cimport string
from libcpp.deque cimport deque
from uniprot_kb.util.operator cimport *

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

    cdef cppclass _record_list "uniprot::record_list"(deque[_record]):
        pass


# PYTHON
# ------


cdef class UniProtRecord:
    '''Model for a single record from a UniProt KB query.'''

    cdef _record c

    def __cinit__(UniProtRecord self, 
                  int sequence_version = 0,
                  int protein_evidence = 1,
                  float mass = 0,
                  int length = 0,
                  gene = u"",
                  id = u"",
                  mnemonic = u"",
                  name = u"",
                  organism = u"",
                  proteome = u"",
                  sequence = u"",
                  taxonomy = u""):
        self.c.sequence_version = sequence_version
        self.c.protein_evidence = protein_evidence
        self.c.mass = mass
        self.c.length = length
        self.c.gene = gene.encode('UTF-8') if type(gene) == unicode else gene
        self.c.id = id.encode('UTF-8') if type(id) == unicode else id
        self.c.mnemonic = mnemonic.encode('UTF-8') if type(mnemonic) == unicode else mnemonic
        self.c.name = name.encode('UTF-8') if type(name) == unicode else name
        self.c.organism = organism.encode('UTF-8') if type(organism) == unicode else organism
        self.c.proteome = proteome.encode('UTF-8') if type(proteome) == unicode else proteome
        self.c.sequence = sequence.encode('UTF-8') if type(sequence) == unicode else sequence
        self.c.taxonomy = taxonomy.encode('UTF-8') if type(taxonomy) == unicode else taxonomy

    def __copy__(UniProtRecord self):
        return copy_record(self.c)

    def __deepcopy__(UniProtRecord self, memo):
        return copy_record(self.c)

    def __richcmp__(UniProtRecord self, UniProtRecord other, int op):
        return total_cmp(self.c, other.c, op)

    property sequence_version:
        def __get__(UniProtRecord self):
            return self.c.sequence_version

        def __set__(UniProtRecord self, int value):
            self.c.sequence_version = value

    property protein_evidence:
        def __get__(UniProtRecord self):
            return self.c.protein_evidence

        def __set__(UniProtRecord self, int value):
            self.c.protein_evidence = value

    property mass:
        def __get__(UniProtRecord self):
            return self.c.mass

        def __set__(UniProtRecord self, float value):
            self.c.mass = value

    property length:
        def __get__(UniProtRecord self):
            return self.c.length

        def __set__(UniProtRecord self, int value):
            self.c.length = value

    property gene:
        def __get__(UniProtRecord self):
            return self.c.gene

        def __set__(UniProtRecord self, bytes value):
            self.c.gene = value

    property id:
        def __get__(UniProtRecord self):
            return self.c.id

        def __set__(UniProtRecord self, bytes value):
            self.c.id = value

    property mnemonic:
        def __get__(UniProtRecord self):
            return self.c.mnemonic

        def __set__(UniProtRecord self, bytes value):
            self.c.mnemonic = value

    property name:
        def __get__(UniProtRecord self):
            return self.c.name

        def __set__(UniProtRecord self, bytes value):
            self.c.name = value

    property organism:
        def __get__(UniProtRecord self):
            return self.c.organism

        def __set__(UniProtRecord self, bytes value):
            self.c.organism = value

    property proteome:
        def __get__(UniProtRecord self):
            return self.c.proteome

        def __set__(UniProtRecord self, bytes value):
            self.c.proteome = value

    property sequence:
        def __get__(UniProtRecord self):
            return self.c.sequence

        def __set__(UniProtRecord self, bytes value):
            self.c.sequence = value

    property taxonomy:
        def __get__(UniProtRecord self):
            return self.c.taxonomy

        def __set__(UniProtRecord self, bytes value):
            self.c.taxonomy = value


cdef UniProtRecord copy_record(const _record& r):
    return UniProtRecord(r.sequence_version,
        r.protein_evidence,
        r.mass,
        r.length,
        r.gene,
        r.id,
        r.mnemonic,
        r.name,
        r.organism,
        r.sequence,
        r.taxonomy
    )


cdef class UniProtRecordList:
    '''Model for a collection of UniProt records.'''

    cdef _record_list c
    cdef deque[_record].iterator it

    def __cinit__(UniProtRecordList self, iterable=None):
        self.it = self.c.end()
        if iterable is not None:
            self.extend(iterable)

    def __copy__(UniProtRecordList self):
        return UniProtRecordList(self)

    def __deepcopy__(UniProtRecordList self, memo):
        copy = UniProtRecordList()
#        for item in self:
#            copy.append(copy_record(item.c))
        return copy

    def __richcmp__(UniProtRecordList self, UniProtRecordList other, int op):
        return total_cmp(self.c, other.c, op)

    def __len__(UniProtRecordList self):
        return self.c.size()