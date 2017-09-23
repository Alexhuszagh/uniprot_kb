#!/usr/bin/env python
#  :copyright: (c) 2017 Alex Huszagh.
#  :license: MIT, see LICENSE.md for more details.

cimport cython
from cython.operator cimport dereference, preincrement
from libc.stdint cimport *
from libcpp.string cimport string
from libcpp.vector cimport vector
from uniprot_kb.util.container cimport *
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

    cdef cppclass _record_list "uniprot::record_list"(vector[_record]):
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
        r.proteome,
        r.sequence,
        r.taxonomy
    )


cdef class UniProtRecordList:
    '''Model for a collection of UniProt records.'''

    cdef _record_list c
    cdef vector[_record].iterator it

    def __cinit__(UniProtRecordList self, iterable=None):
        self.it = self.c.end()
        if iterable is not None:
            self.extend(iterable)

    def __copy__(UniProtRecordList self):
        return UniProtRecordList(self)

    def __deepcopy__(UniProtRecordList self, memo):
        copy = UniProtRecordList()
        for item in self:
            r = <UniProtRecord>(item)
            copy.append(copy_record(r.c))
        return copy

    def __richcmp__(UniProtRecordList self, UniProtRecordList other, int op):
        return total_cmp(self.c, other.c, op)

    def __len__(UniProtRecordList self):
        return self.c.size()

    def __contains__(UniProtRecordList self, UniProtRecord value):
        return array_contains(self.c, value.c)

    def __add__(UniProtRecordList self, iterable):
        l = self.__copy__()
        l += iterable
        return l

    def __iadd__(UniProtRecordList self, iterable):
        self.extend(iterable)
        return self

    def __radd__(UniProtRecordList self, iterable):
        return self.__add__(iterable)

    def __mul__(UniProtRecordList self, int count):
        l = self.__copy__()
        l *= count
        return l

    def __imul__(UniProtRecordList self, int count):
        if count == 0:
            self.clear()
            return self

        length = self.c.size()
        for _ in range(count-1):
            for index in range(length):
                self.c.push_back(self.c[index])
        return self

    def __rmul__(UniProtRecordList self, int count):
        return self.__mul__(count)

    def __iter__(UniProtRecordList self):
        self.it = self.c.begin()
        return self

    def __next__(UniProtRecordList self):
        if self.it == self.c.end():
            raise StopIteration()
        value = copy_record(dereference(self.it))
        preincrement(self.it)
        return value

    @cython.boundscheck(True)
    @cython.wraparound(True)
    def __getitem__(UniProtRecordList self, int index):
        return copy_record(self.c.at(index))

    @cython.boundscheck(True)
    @cython.wraparound(True)
    def __setitem__(UniProtRecordList self, int index, UniProtRecord value):
        self.c[index] = value.c

    @cython.boundscheck(True)
    @cython.wraparound(True)
    def __delitem__(UniProtRecordList self, int index):
        self.c.erase(self.c.begin() + index);

    def append(UniProtRecordList self, UniProtRecord value):
        self.c.push_back(value.c)

    def extend(UniProtRecordList self, iterable):
        for value in iterable:
            self.append(value)

#    @cython.boundscheck(True)
#    @cython.wraparound(True)
#    def insert(UniProtRecordList self, int index, UniProtRecord value):
#        insert_container(self.c, index, value.c)
#
#    def remove(UniProtRecordList self, UniProtRecord value):
#        remove_container(dereference(self.ptr), dereference(value.ptr))
#
    def clear(UniProtRecordList self):
        self.c.clear()

    def pop(UniProtRecordList self):
        if self.c.empty():
            raise IndexError("pop from empty list")
        self.c.pop_back()

    def pop(UniProtRecordList self, int index):
        del self[index]

#    def index(UniProtRecordList self, UniProtRecord value):
#        return index_container(self.c, dereference(value.ptr))
#
#    def count(UniProtRecordList self, UniProtRecord value):
#        return count_container(self.c, dereference(value.ptr))
#
#    def reverse(UniProtRecordList self):
#        reverse_container(self.c)
