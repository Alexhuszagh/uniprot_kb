//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

#include "txt.h"

#include <sstream>


// FUNCTIONS
// ---------


std::string& to_text(std::string& str, const UniprotRecord& record)
{
    std::ostringstream stream;
    to_text(stream, record);
    str = stream.str();

    return str;
}


std::string& to_text(std::string& str, const UniprotRecordList& list)
{
    std::ostringstream stream;
    to_text(stream, list);
    str = stream.str();

    return str;
}


std::ostream& to_text(std::ostream& stream, const UniprotRecord& record)
{
    // TODO: here...
    return stream;
}


std::ostream& to_text(std::ostream& stream, const UniprotRecordList& list)
{
    // TODO: here...
    return stream;
}


UniprotRecord& load_text(UniprotRecord& record, const std::string& str)
{
    std::istringstream stream(str);
    return load_text(record, stream);
}


UniprotRecordList& load_text(UniprotRecordList& list, const std::string& str)
{
    std::istringstream stream(str);
    return load_text(list, stream);
}


UniprotRecord& load_text(UniprotRecord& record, std::istream& stream)
{
    // TODO: here...
    return record;
}


UniprotRecordList& load_text(UniprotRecordList& list, std::istream& stream)
{
    // TODO: here...
    return list;
}
