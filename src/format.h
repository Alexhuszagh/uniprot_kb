//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/**
 *  \addtogroup uniprot_kb
 *  \brief UniProt KB FASTA parsers and serializers.
 */

#pragma once

#include "fasta.h"
#include "txt.h"
#include "xml.h"

#include <fstream.h>

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


// FUNCTIONS
// ---------


template <typename T>
std::string to_string(const T& t, format fmt)
{
    std::string str;
    switch (fmt) {
        case format_txt:        return to_text(str, t);
        case format_fasta:      return to_fasta(str, t);
        case format_xml:        return to_xml(str, t);
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
        case format_xml:        return load_xml(t, str);
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
        case format_xml:        to_xml(stream, t);      return;
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
        case format_xml:        return load_xml(t, stream);
        default:        throw std::runtime_error("Unrecognized option.");
    }
}
