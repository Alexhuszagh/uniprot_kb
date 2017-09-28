//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

#include "format.h"
#include "txt.h"
#include <pycpp/string/whitespace.h>

#include <sstream>


namespace uniprot
{
// FORMATTERS
// ----------

static std::ostream& write_header(std::ostream& stream)
{
    column_formatter formatter;
    stream << formatter.txt(column_sequence_version) << "\t"
           << formatter.txt(column_protein_evidence) << "\t"
           << formatter.txt(column_mass) << "\t"
           << formatter.txt(column_length) << "\t"
           << formatter.txt(column_gene) << "\t"
           << formatter.txt(column_id) << "\t"
           << formatter.txt(column_mnemonic) << "\t"
           << formatter.txt(column_name) << "\t"
           << formatter.txt(column_organism) << "\t"
           << formatter.txt(column_proteome) << "\t"
           << formatter.txt(column_sequence) << "\t"
           << formatter.txt(column_taxonomy) << "\t";
    return stream;
}


static std::ostream& write_row(std::ostream& stream, const record& r)
{
    record_formatter formatter;
    stream << formatter.to_txt(r, column_sequence_version) << "\t"
           << formatter.to_txt(r, column_protein_evidence) << "\t"
           << formatter.to_txt(r, column_mass) << "\t"
           << formatter.to_txt(r, column_length) << "\t"
           << formatter.to_txt(r, column_gene) << "\t"
           << formatter.to_txt(r, column_id) << "\t"
           << formatter.to_txt(r, column_mnemonic) << "\t"
           << formatter.to_txt(r, column_name) << "\t"
           << formatter.to_txt(r, column_organism) << "\t"
           << formatter.to_txt(r, column_proteome) << "\t"
           << formatter.to_txt(r, column_sequence) << "\t"
           << formatter.to_txt(r, column_taxonomy) << "\t";
    return stream;
}

// FUNCTIONS
// ---------


std::string& to_text(std::string& str, const record& r)
{
    std::ostringstream stream;
    to_text(stream, r);
    str = stream.str();

    return str;
}


std::string& to_text(std::string& str, const record_list& list)
{
    std::ostringstream stream;
    to_text(stream, list);
    str = stream.str();

    return str;
}


std::ostream& to_text(std::ostream& stream, const record& r)
{
    write_header(stream);
    stream << NEWLINE;
    write_row(stream, r);
    return stream;
}


std::ostream& to_text(std::ostream& stream, const record_list& list)
{
    write_header(stream);
    for (const auto& r: list) {
        stream << NEWLINE;
        write_row(stream, *r);
    }
    return stream;
}


record& load_text(record& r, const std::string& str)
{
    std::istringstream stream(str);
    return load_text(r, stream);
}


record_list& load_text(record_list& list, const std::string& str)
{
    std::istringstream stream(str);
    return load_text(list, stream);
}


record& load_text(record& r, std::istream& stream)
{
    // TODO: here...
    return r;
}


record_list& load_text(record_list& list, std::istream& stream)
{
    // TODO: here...
    return list;
}

}   /* uniprot */
