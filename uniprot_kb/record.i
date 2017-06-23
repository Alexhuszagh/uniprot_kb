//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

%module record
%{
#include "format.h"
#include "record.h"
#include "fasta.h"
#include "txt.h"
%}

%include "exception.i"
%include "std_string.i"
%include "std_deque.i"
%include "stdint.i"
%include "format.h"
%include "record.h"

// ALIASES
// -------

%template(UniprotRecordList) std::deque<UniprotRecord>;

// EXCEPTIONS
// ----------

%exception {
    try {
        $action
    } catch(std::runtime_error) {
        SWIG_exception(SWIG_RuntimeError, "Unknown enumerated value");
    }
}

// EXTEND
// ------

%extend UniprotRecord
{
    // CONSTRUCTORS

    UniprotRecord(uint8_t sequence_version = 1,
        uint8_t protein_evidence = 1,
        double mass = 0,
        size_t length = 0,
        std::string gene = "",
        std::string id = "",
        std::string mnemonic = "",
        std::string name = "",
        std::string organism = "",
        std::string proteome = "",
        std::string sequence = "",
        std::string taxonomy = "")
    {
        return new UniprotRecord {
            sequence_version,
            protein_evidence,
            mass,
            length,
            std::move(gene),
            std::move(id),
            std::move(mnemonic),
            std::move(name),
            std::move(organism),
            std::move(proteome),
            std::move(sequence),
            std::move(taxonomy),
        };
    }

    ~UniprotRecord()
    {
        free($self);
    }

    // OPERATORS

    bool operator!=(const UniprotRecord &other) const
    {
        return !(*$self == other);
    }

    bool UniprotRecord::operator<=(const UniprotRecord &other) const
    {
        return !(other < *$self);
    }


    bool UniprotRecord::operator>(const UniprotRecord &other) const
    {
        return other < *$self;
    }

    bool UniprotRecord::operator>=(const UniprotRecord &other) const
    {
        return !(*$self < other);
    }

    // MAGIC

    size_t __hash__() const
    {
        return std::hash<const UniprotRecord*>()($self);
    }

    std::string __str__() const
    {
        return "";
    }

    std::string __repr__() const
    {
        return "";
    }

    UniprotRecord __copy__() const
    {
        return *$self;
    }

    // METHODS

    std::string to_string(format fmt = TEXT) const
    {
        return to_string(*$self, fmt);
    }

    UniprotRecord from_string(const std::string& str, format fmt)
    {
        return from_string<UniprotRecord>(str, fmt = TEXT);
    }

    void to_file(const std::string& path, format fmt = TEXT) const
    {
        to_file(*$self, path, fmt);
    }

    UniprotRecord from_file(const std::string& path, format fmt = TEXT)
    {
        return from_file<UniprotRecord>(path, fmt);
    }
};


%extend std::deque<UniprotRecord>
{
    std::string to_string(format fmt = TEXT) const
    {
        return to_string(*$self, fmt);
    }

    UniprotRecordList from_string(const std::string& str, format fmt = TEXT)
    {
        return from_string<UniprotRecordList>(str, fmt);
    }

    void to_file(const std::string& path, format fmt = TEXT) const
    {
        to_file(*$self, path, fmt);
    }

    UniprotRecordList from_file(const std::string& path, format fmt = TEXT)
    {
        return from_file<UniprotRecordList>(path, fmt);
    }
};


// MAGIC
// -----

%feature("python:slot", "tp_hash", functype="hashfunc") UniprotRecord::__hash__;
%feature("python:slot", "tp_str", functype="strfunc") UniprotRecord::__str__;
%feature("python:slot", "tp_repr", functype="reprfunc") UniprotRecord::__repr__;

