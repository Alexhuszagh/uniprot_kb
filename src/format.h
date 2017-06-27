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
    TEXT = 0,
    FASTA = 1,
    XML = 2,
};


// FUNCTIONS
// ---------


template <typename T>
std::string to_string(const T& t, format fmt)
{
    std::string str;
    switch (fmt) {
        case TEXT:      return to_text(str, t);
        case FASTA:     return to_fasta(str, t);
        case XML:       return to_xml(str, t);
        default:        throw std::runtime_error("Unrecognized option.");
    }
}


template <typename T>
T from_string(const std::string& str, format fmt)
{
    T t;
    switch (fmt) {
        case TEXT:      return load_text(t, str);
        case FASTA:     return load_fasta(t, str);
        case XML:       return load_xml(t, str);
        default:        throw std::runtime_error("Unrecognized option.");
    }
}


template <typename T>
void to_file(const T& t, const std::string& path, format fmt)
{
    ofstream stream(path, std::ios_base::binary);
    switch (fmt) {
        case TEXT:      to_text(stream, t);     return;
        case FASTA:     to_fasta(stream, t);    return;
        case XML:       to_xml(stream, t);      return;
        default:        throw std::runtime_error("Unrecognized option.");
    }
}


template <typename T>
T from_file(const std::string& path, format fmt)
{
    ifstream stream(path, std::ios_base::binary);
    T t;
    switch (fmt) {
        case TEXT:      return load_text(t, stream);
        case FASTA:     return load_fasta(t, stream);
        case XML:       return load_xml(t, stream);
        default:        throw std::runtime_error("Unrecognized option.");
    }
}
