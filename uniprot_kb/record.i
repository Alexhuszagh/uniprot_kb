//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

%module(package="uniprot_kb") record
%{
#include "format.h"
#include "record.h"
#include "fasta.h"
#include "txt.h"
#include <ordering.h>
%}

%include "exception.i"
%include "std_string.i"
%include "std_deque.i"
%include "stdint.i"
%include "format.h"
%include "record.h"

// EXCEPTIONS
// ----------

%exception {
    try {
        $action
    } catch(std::runtime_error) {
        SWIG_exception(SWIG_RuntimeError, "Unknown enumerated value");
    }
}

// ALIASES
// -------

%template(UniProtRecordList) std::deque<UniProtRecord>;

// EXTEND
// ------


%extend UniProtRecord
{
    // CONSTRUCTORS

    UniProtRecord(uint8_t sequence_version = 1,
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
        return new UniProtRecord {
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

    ~UniProtRecord()
    {
        free($self);
    }

    // OPERATORS

    bool operator!=(const UniProtRecord &other) const
    {
        return not_equal_to(*$self, other);
    }

    bool UniProtRecord::operator<=(const UniProtRecord &other) const
    {
        return less_equal(*$self, other);
    }

    bool UniProtRecord::operator>(const UniProtRecord &other) const
    {
        return greater(*$self, other);
    }

    bool UniProtRecord::operator>=(const UniProtRecord &other) const
    {
        return greater_equal(*$self, other);
    }

    // MAGIC

    size_t __hash__() const
    {
        return std::hash<const UniProtRecord*>()($self);
    }

    std::string __str__() const
    {
        return "";
    }

    std::string __repr__() const
    {
        return "";
    }

    UniProtRecord __copy__() const
    {
        return *$self;
    }

    // METHODS

    std::string to_string(format fmt = TEXT) const
    {
        return to_string(*$self, fmt);
    }

    UniProtRecord from_string(const std::string& str, format fmt)
    {
        return from_string<UniProtRecord>(str, fmt = TEXT);
    }

    void to_file(const std::string& path, format fmt = TEXT) const
    {
        to_file(*$self, path, fmt);
    }

    UniProtRecord from_file(const std::string& path, format fmt = TEXT)
    {
        return from_file<UniProtRecord>(path, fmt);
    }
};


%extend std::deque<UniProtRecord>
{
    // METHODS

    std::string to_string(format fmt = TEXT) const
    {
        return to_string(*$self, fmt);
    }

    UniProtRecordList from_string(const std::string& str, format fmt = TEXT)
    {
        return from_string<UniProtRecordList>(str, fmt);
    }

    void to_file(const std::string& path, format fmt = TEXT) const
    {
        to_file(*$self, path, fmt);
    }

    UniProtRecordList from_file(const std::string& path, format fmt = TEXT)
    {
        return from_file<UniProtRecordList>(path, fmt);
    }
};


// MAGIC
// -----

%feature("python:slot", "tp_hash", functype="hashfunc") UniProtRecord::__hash__;
%feature("python:slot", "tp_str", functype="strfunc") UniProtRecord::__str__;
%feature("python:slot", "tp_repr", functype="reprfunc") UniProtRecord::__repr__;

