//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

#include "txt.h"

#include <sstream>

// CONSTANTS
// ---------


// TODO: remove, deprecated
//std::string COLUMN_NAMES[] = {
//    // http://www.uniprot.org/help/uniprotkb_column_names
//    // Example:
//    //      http://www.uniprot.org/uniprot/?query=id:P46406
//    //      &sort=score
//    //      &format=tab
//    //      &columns=version(sequence)
//    "Version (sequence)",       // sequence_version
//    "Protein existence",        // protein_evidence
//    "Entry",                    // id
//    "Entry Name",               // mnemonic
////    "Status",                   // ??
//    "Protein names",            // name
////    "Gene names",               // ??
//    "Organism",                 // organism
//    "Length",                   // length
//
//};

// FORMATTERS
// ----------

// TODO: remove, deprecated, moved to `column.cc`
// TODO: protein_evidence maps numeric codes to string-based
// identifiers, which demonstrate the evidence of the protein
// existence

// FUNCTIONS
// ---------


std::string& to_text(std::string& str, const UniProtRecord& record)
{
    std::ostringstream stream;
    to_text(stream, record);
    str = stream.str();

    return str;
}


std::string& to_text(std::string& str, const UniProtRecordList& list)
{
    std::ostringstream stream;
    to_text(stream, list);
    str = stream.str();

    return str;
}


std::ostream& to_text(std::ostream& stream, const UniProtRecord& record)
{
    // TODO: here...
    // TODO: need to serialize the columns
    // TODO: need to serialize the data
    return stream;
}


std::ostream& to_text(std::ostream& stream, const UniProtRecordList& list)
{
    // TODO: here...
    return stream;
}


UniProtRecord& load_text(UniProtRecord& record, const std::string& str)
{
    std::istringstream stream(str);
    return load_text(record, stream);
}


UniProtRecordList& load_text(UniProtRecordList& list, const std::string& str)
{
    std::istringstream stream(str);
    return load_text(list, stream);
}


UniProtRecord& load_text(UniProtRecord& record, std::istream& stream)
{
    // TODO: here...
    return record;
}


UniProtRecordList& load_text(UniProtRecordList& list, std::istream& stream)
{
    // TODO: here...
    return list;
}
