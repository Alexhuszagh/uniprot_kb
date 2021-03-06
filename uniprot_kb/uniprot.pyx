#  :copyright: (c) 2017 Alex Huszagh.
#  :license: MIT, see LICENSE.md for more details.

cimport cython
from cython.operator cimport dereference, preincrement
from uniprot_kb.format cimport *
from uniprot_kb.record cimport *
from uniprot_kb.util.container cimport *
from uniprot_kb.util.operator cimport *

# PYTHON
# ------

# FORMAT

cpdef enum Format:
    txt = 0
    fasta = 1
    xml = 2

# RECORD

cdef class UniProtRecord:
    '''Model for a single record from a UniProt KB query.'''

    cdef shared_ptr[_record] p

    def __init__(UniProtRecord self,
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
        # allocate/null-initialize
        self.p.reset(new _record())
        cdef _record* c = self.p.get()

        # construct
        c.sequence_version = sequence_version
        c.protein_evidence = protein_evidence
        c.mass = mass
        c.length = length
        c.gene = gene.encode('UTF-8') if type(gene) == unicode else gene
        c.id = id.encode('UTF-8') if type(id) == unicode else id
        c.mnemonic = mnemonic.encode('UTF-8') if type(mnemonic) == unicode else mnemonic
        c.name = name.encode('UTF-8') if type(name) == unicode else name
        c.organism = organism.encode('UTF-8') if type(organism) == unicode else organism
        c.proteome = proteome.encode('UTF-8') if type(proteome) == unicode else proteome
        c.sequence = sequence.encode('UTF-8') if type(sequence) == unicode else sequence
        c.taxonomy = taxonomy.encode('UTF-8') if type(taxonomy) == unicode else taxonomy

    @cython.nonecheck(True)
    def __copy__(UniProtRecord self):
        return copy_record(self.p)

    @cython.nonecheck(True)
    def __deepcopy__(UniProtRecord self, memo):
        return copy_record(self.p)

    @cython.nonecheck(True)
    def __richcmp__(UniProtRecord self, UniProtRecord other, int op):
        return total_cmp(dereference(self.p), dereference(other.p), op)

    # PROPERTIES
    # ----------

    property sequence_version:
        @cython.nonecheck(True)
        def __get__(UniProtRecord self):
            return dereference(self.p).sequence_version

        @cython.nonecheck(True)
        def __set__(UniProtRecord self, int value):
            dereference(self.p).sequence_version = value

    property protein_evidence:
        @cython.nonecheck(True)
        def __get__(UniProtRecord self):
            return dereference(self.p).protein_evidence

        @cython.nonecheck(True)
        def __set__(UniProtRecord self, int value):
            dereference(self.p).protein_evidence = value

    property mass:
        @cython.nonecheck(True)
        def __get__(UniProtRecord self):
            return dereference(self.p).mass

        @cython.nonecheck(True)
        def __set__(UniProtRecord self, float value):
            dereference(self.p).mass = value

    property length:
        @cython.nonecheck(True)
        def __get__(UniProtRecord self):
            return dereference(self.p).length

        @cython.nonecheck(True)
        def __set__(UniProtRecord self, int value):
            dereference(self.p).length = value

    property gene:
        @cython.nonecheck(True)
        def __get__(UniProtRecord self):
            return dereference(self.p).gene

        @cython.nonecheck(True)
        def __set__(UniProtRecord self, bytes value):
            dereference(self.p).gene = value

    property id:
        @cython.nonecheck(True)
        def __get__(UniProtRecord self):
            return dereference(self.p).id

        @cython.nonecheck(True)
        def __set__(UniProtRecord self, bytes value):
            dereference(self.p).id = value

    property mnemonic:
        @cython.nonecheck(True)
        def __get__(UniProtRecord self):
            return dereference(self.p).mnemonic

        @cython.nonecheck(True)
        def __set__(UniProtRecord self, bytes value):
            dereference(self.p).mnemonic = value

    property name:
        @cython.nonecheck(True)
        def __get__(UniProtRecord self):
            return dereference(self.p).name

        @cython.nonecheck(True)
        def __set__(UniProtRecord self, bytes value):
            dereference(self.p).name = value

    property organism:
        @cython.nonecheck(True)
        def __get__(UniProtRecord self):
            return dereference(self.p).organism

        @cython.nonecheck(True)
        def __set__(UniProtRecord self, bytes value):
            dereference(self.p).organism = value

    property proteome:
        @cython.nonecheck(True)
        def __get__(UniProtRecord self):
            return dereference(self.p).proteome

        @cython.nonecheck(True)
        def __set__(UniProtRecord self, bytes value):
            dereference(self.p).proteome = value

    property sequence:
        @cython.nonecheck(True)
        def __get__(UniProtRecord self):
            return dereference(self.p).sequence

        @cython.nonecheck(True)
        def __set__(UniProtRecord self, bytes value):
            dereference(self.p).sequence = value

    property taxonomy:
        @cython.nonecheck(True)
        def __get__(UniProtRecord self):
            return dereference(self.p).taxonomy

        @cython.nonecheck(True)
        def __set__(UniProtRecord self, bytes value):
            dereference(self.p).taxonomy = value

    # SERIALIZATION
    # -------------

    cpdef to_string(UniProtRecord self, Format fmt):
        return _record_to_string(dereference(self.p), int(fmt))

    cpdef to_file(UniProtRecord self, string path, Format fmt):
        _record_to_file(dereference(self.p), path, int(fmt))

    @classmethod
    def from_string(cls, string str, Format fmt):
        cdef UniProtRecord inst = cls.__new__(cls)
        inst.p.reset(new _record(_record_from_string(str, int(fmt))))
        return inst

    @classmethod
    def from_file(cls, string path, Format fmt):
        cdef UniProtRecord inst = cls.__new__(cls)
        inst.p.reset(new _record(_record_from_file(path, int(fmt))))
        return inst


cdef UniProtRecord copy_record(const shared_ptr[_record]& r):
    cdef UniProtRecord cpy = UniProtRecord.__new__(UniProtRecord)
    cpy.p.reset(new _record(dereference(r)))
    return cpy


cdef UniProtRecord use_record(const shared_ptr[_record]& r):
    cdef UniProtRecord cpy = UniProtRecord.__new__(UniProtRecord)
    cpy.p = r
    return cpy


cdef class UniProtRecordList:
    '''Model for a collection of UniProt records.'''

    cdef _record_list c
    cdef vector[shared_ptr[_record]].iterator it

    def __cinit__(UniProtRecordList self):
        self.it = self.c.end()

    def __init__(UniProtRecordList self, iterable=None):
        if iterable is not None:
            self.extend(iterable)

    def __copy__(UniProtRecordList self):
        return UniProtRecordList(self)

    def __deepcopy__(UniProtRecordList self, memo):
        cdef UniProtRecordList cpy = UniProtRecordList()
        cdef UniProtRecord r
        cdef shared_ptr[_record] p
        for r in self:
            cpy.c.push_back(shared_ptr[_record](new _record(dereference(r.p))))
        return cpy

    def __richcmp__(UniProtRecordList self, UniProtRecordList other, int op):
        return total_cmp(self.c, other.c, op)

    def __len__(UniProtRecordList self):
        return self.c.size()

    def __contains__(UniProtRecordList self, UniProtRecord value):
        return array_contains_pred(self.c, value.p, ptr_equal_to())

    def __add__(lhs, rhs):
        if isinstance(lhs, UniProtRecordList):
            lst = lhs.__copy__()
            lst += rhs
        else:
            lst = rhs.__copy__()
            lst += lhs

        return lst

    def __iadd__(UniProtRecordList self, iterable):
        self.extend(iterable)
        return self

    def __mul__(lhs, rhs):
        if isinstance(rhs, int):
            lst = lhs.__copy__()
            lst *= rhs
        elif isinstance(lhs, int):
            lst = rhs.__copy__()
            lst *= lhs
        else:
            raise TypeError("Invalid multiplier: {}".format(type(rhs).__name__))

        return lst

    def __imul__(UniProtRecordList self, int count):
        if count == 0:
            self.clear()
            return self

        length = self.c.size()
        for _ in range(count-1):
            for index in range(length):
                self.c.push_back(self.c[index])
        return self

    def __iter__(UniProtRecordList self):
        self.it = self.c.begin()
        return self

    def __next__(UniProtRecordList self):
        if self.it == self.c.end():
            raise StopIteration()
        value = use_record(dereference(self.it))
        preincrement(self.it)
        return value

    @cython.boundscheck(True)
    def __getitem__(UniProtRecordList self, int index):
        return use_record(self.c.at(self._normalize_index(index)))

    @cython.boundscheck(True)
    def __setitem__(UniProtRecordList self, int index, UniProtRecord value):
        self.c[self._normalize_index(index)] = value.p

    @cython.boundscheck(True)
    def __delitem__(UniProtRecordList self, int index):
        array_erase(self.c, self._normalize_index(index))

    cpdef append(UniProtRecordList self, UniProtRecord value):
        self.c.push_back(value.p)

    cpdef extend(UniProtRecordList self, iterable):
        for value in iterable:
            self.append(value)

    @cython.boundscheck(True)
    cpdef insert(UniProtRecordList self, int index, UniProtRecord value):
        array_insert(self.c, self._normalize_index(index), value.p)

    cpdef remove(UniProtRecordList self, UniProtRecord value):
        array_remove(self.c, value.p)

    cpdef clear(UniProtRecordList self):
        self.c.clear()

    @cython.boundscheck(True)
    cpdef pop(UniProtRecordList self, int index = -1):
        index = self._normalize_index(index)
        if self.c.empty():
            raise IndexError("pop from empty list")

        value = self[index]
        del self[index]
        return value

    cpdef index(UniProtRecordList self, UniProtRecord value):
        return array_index(self.c, value.p)

    cpdef count(UniProtRecordList self, UniProtRecord value):
        return array_count(self.c, value.p)

    cpdef reverse(UniProtRecordList self):
        array_reverse(self.c)

    # SERIALIZATION
    # -------------

    cpdef to_string(UniProtRecordList self, Format fmt):
        return _list_to_string(self.c, int(fmt))

    cpdef to_file(UniProtRecordList self, string path, Format fmt):
        _list_to_file(self.c, path, int(fmt))

    @classmethod
    def from_string(cls, string str, Format fmt):
        cdef UniProtRecordList inst = cls.__new__(cls)
        inst.c = _list_from_string(str, int(fmt))
        return inst

    @classmethod
    def from_file(cls, string path, Format fmt):
        cdef UniProtRecordList inst = cls.__new__(cls)
        inst.c = _list_from_file(path, int(fmt))
        return inst

    # PRIVATE
    # -------

    cdef _normalize_index(UniProtRecordList self, int index):
        return normalize_index(len(self), index)
