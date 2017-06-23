//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

#include "xml.h"

#include <sstream>


// FUNCTIONS
// ---------


std::string& to_xml(std::string& str, const UniprotRecord& record)
{
    std::ostringstream stream;
    to_xml(stream, record);
    str = stream.str();

    return str;
}


std::string& to_xml(std::string& str, const UniprotRecordList& list)
{
    std::ostringstream stream;
    to_xml(stream, list);
    str = stream.str();

    return str;
}


std::ostream& to_xml(std::ostream& stream, const UniprotRecord& record)
{
    // TODO: here...
    return stream;
}


std::ostream& to_xml(std::ostream& stream, const UniprotRecordList& list)
{
    // TODO: here...
    return stream;
}


UniprotRecord& load_xml(UniprotRecord& record, const std::string& str)
{
    std::istringstream stream(str);
    return load_xml(record, stream);
}


UniprotRecordList& load_xml(UniprotRecordList& list, const std::string& str)
{
    std::istringstream stream(str);
    return load_xml(list, stream);
}


UniprotRecord& load_xml(UniprotRecord& record, std::istream& stream)
{
    // TODO: here...
    return record;
}


UniprotRecordList& load_xml(UniprotRecordList& list, std::istream& stream)
{
    // TODO: here...
    return list;
}
