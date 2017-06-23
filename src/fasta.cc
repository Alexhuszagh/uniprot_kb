//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

#include "fasta.h"
#include <getline.h>

#include <sstream>

// CONSTANTS
// ---------

#define LENGTH 60
#if _WIN32
#define NEWLINE "\r\n"
#else
#define NEWLINE "\n"
#endif

// FUNCTIONS
// ---------


static size_t ceildiv(size_t numerator, size_t denominator)
{
    return numerator / denominator + bool(numerator % denominator);
}


std::string& to_fasta(std::string& str, const UniProtRecord& record)
{
    std::ostringstream stream;
    to_fasta(stream, record);
    str = stream.str();

    return str;
}


std::string& to_fasta(std::string& str, const UniProtRecordList& list)
{
    std::ostringstream stream;
    to_fasta(stream, list);
    str = stream.str();

    return str;
}


std::ostream& to_fasta(std::ostream& stream, const UniProtRecord& record)
{
    stream << ">sp|" << record.id << "|" << record.mnemonic
           << " " << record.name << " OS=" << record.organism
           << " GN=" << record.gene << " PE="
           << (int) record.protein_evidence << " SV="
           << (int) record.sequence_version << NEWLINE;

    for (size_t i = 0; i < ceildiv(record.sequence.length(), LENGTH); ++i) {
        size_t start = i * LENGTH;
        stream << record.sequence.substr(start, LENGTH) << NEWLINE;
    }

    return stream;
}


std::ostream& to_fasta(std::ostream& stream, const UniProtRecordList& list)
{
    for (const auto &record: list) {
        to_fasta(stream, record);
        stream << "\n";
    }

    return stream;
}


UniProtRecord& load_fasta(UniProtRecord& record, const std::string& str)
{
    std::istringstream stream(str);
    return load_fasta(record, stream);
}


UniProtRecordList& load_fasta(UniProtRecordList& list, const std::string& str)
{
    std::istringstream stream(str);
    return load_fasta(list, stream);
}


UniProtRecord& load_fasta(UniProtRecord& record, std::istream& stream)
{
    std::string line;
    while (getline(stream, line)) {
    }
    // TODO: here...

    return record;
}


UniProtRecordList& load_fasta(UniProtRecordList& list, std::istream& stream)
{
    std::stringstream buffer;
    std::string line;
    bool have_line = false;
    while (getline(stream, line)) {
        if (line.empty()) {
            if (have_line) {

// TODO: need to implement...
//                // load element
//                list.emplace_back(UniProtRecord());
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
