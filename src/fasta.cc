//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

#include "fasta.h"
#include "format.h"
#include <pycpp/string/whitespace.h>

#include <sstream>

namespace uniprot
{
// FUNCTIONS
// ---------

std::string& to_fasta(std::string& str, const record& r)
{
    std::ostringstream stream;
    to_fasta(stream, r);
    str = stream.str();

    return str;
}


std::string& to_fasta(std::string& str, const record_list& list)
{
    std::ostringstream stream;
    to_fasta(stream, list);
    str = stream.str();

    return str;
}


std::ostream& to_fasta(std::ostream& stream, const record& r)
{
    record_formatter formatter;
    stream << ">sp|" << formatter.to_fasta(r, column_id)
           << "|"    << formatter.to_fasta(r, column_mnemonic)
           << " "    << formatter.to_fasta(r, column_name)
           << " OS=" << formatter.to_fasta(r, column_organism)
           << " GN=" << formatter.to_fasta(r, column_gene)
           << " PE=" << formatter.to_fasta(r, column_protein_evidence)
           << " SV=" << formatter.to_fasta(r, column_sequence_version)
           << formatter.to_fasta(r, column_sequence);

    return stream;
}


std::ostream& to_fasta(std::ostream& stream, const record_list& list)
{
    for (const auto &r: list) {
        to_fasta(stream, *r);
        stream << PYCPP_NAMESPACE::NEWLINE;
    }

    return stream;
}


record& load_fasta(record& r, const std::string& str)
{
    std::istringstream stream(str);
    return load_fasta(r, stream);
}


record_list& load_fasta(record_list& list, const std::string& str)
{
    std::istringstream stream(str);
    return load_fasta(list, stream);
}


record& load_fasta(record& r, std::istream& stream)
{
    std::string line;
    while (getline(stream, line)) {
    }
    // TODO: here...

    return r;
}


record_list& load_fasta(record_list& list, std::istream& stream)
{
    std::stringstream buffer;
    std::string line;
    bool have_line = false;
    while (getline(stream, line)) {
        if (line.empty()) {
            if (have_line) {

// TODO: need to implement...
//                // load element
//                list.emplace_back(record());
//                buffer.seekg(0);
//                load_fasta(list.back(), buffer);
//
//                // clear buffer and have line
//                buffer.str("");
//                have_line = false;
            }
        } else {
            buffer << line << NEWLINE;
        }

        have_line |= !line.empty();
    }

    return list;
}

}   /* uniprot */
