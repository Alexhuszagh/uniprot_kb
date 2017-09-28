//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/**
 *  \addtogroup uniprot_kb
 *  \brief UniProt KB FASTA parsers and serializers.
 */

#pragma once

#include "fwd.h"
#include "fasta.h"
#include "txt.h"
//#include "xml.h"

#include <pycpp/stream/fstream.h>

namespace uniprot
{
// ENUMS
// -----


/** \brief Serialization formats for UniProt records.
 */
enum format
{
    format_txt = 0,
    format_fasta,
    format_xml,
};


/**
 *  \brief Columns for UniProt KB field.
 */
enum column
{
    column_sequence_version = 0,
    column_protein_evidence,
    column_mass,
    column_length,
    column_gene,
    column_id,
    column_mnemonic,
    column_name,
    column_organism,
    column_proteome,
    column_sequence,
    column_taxonomy,
};


// OBJECTS
// -------


/**
 *  \brief Formatter for column names.
 */
struct column_formatter
{
    std::string name(column c);
    std::string txt(column c);
    std::string fasta(column c);
    std::string xml(column c);
};


/**
 *  \brief Formatter for record values.
 */
struct record_formatter
{
    std::string to_txt(const record& r, column c);
    std::string to_fasta(const record& r, column c);
    std::string to_xml(const record& r, column c);
//    record& load_txt(record& r, const std::string& str, column c);
//    record& load_fasta(record& r, const std::string& str, column c);
//    record& load_xml(record& r, const std::string& str, column c);
};


// FUNCTIONS
// ---------


template <typename T>
std::string to_string(const T& t, format fmt)
{
    std::string str;
    switch (fmt) {
        case format_txt:        return to_text(str, t);
        case format_fasta:      return to_fasta(str, t);
//        case format_xml:        return to_xml(str, t);
        default:        throw std::runtime_error("Unrecognized option.");
    }
}


template <typename T>
T from_string(const std::string& str, format fmt)
{
    T t;
    switch (fmt) {
        case format_txt:        return load_text(t, str);
        case format_fasta:      return load_fasta(t, str);
//        case format_xml:        return load_xml(t, str);
        default:        throw std::runtime_error("Unrecognized option.");
    }
}


template <typename T>
void to_file(const T& t, const std::string& path, format fmt)
{
    ofstream stream(path, std::ios_base::binary);
    switch (fmt) {
        case format_txt:        to_text(stream, t);     return;
        case format_fasta:      to_fasta(stream, t);    return;
//        case format_xml:        to_xml(stream, t);      return;
        default:        throw std::runtime_error("Unrecognized option.");
    }
}


template <typename T>
T from_file(const std::string& path, format fmt)
{
    ifstream stream(path, std::ios_base::binary);
    T t;
    switch (fmt) {
        case format_txt:        return load_text(t, stream);
        case format_fasta:      return load_fasta(t, stream);
//        case format_xml:        return load_xml(t, stream);
        default:        throw std::runtime_error("Unrecognized option.");
    }
}

}   /* uniprot */
