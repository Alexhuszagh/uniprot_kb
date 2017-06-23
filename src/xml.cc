//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

#include "xml.h"

#include <sstream>


// FUNCTIONS
// ---------


std::string& to_xml(std::string& str, const UniProtRecord& record)
{
    std::ostringstream stream;
    to_xml(stream, record);
    str = stream.str();

    return str;
}


std::string& to_xml(std::string& str, const UniProtRecordList& list)
{
    std::ostringstream stream;
    to_xml(stream, list);
    str = stream.str();

    return str;
}


std::ostream& to_xml(std::ostream& stream, const UniProtRecord& record)
{
    // TODO: here...
    return stream;
}


std::ostream& to_xml(std::ostream& stream, const UniProtRecordList& list)
{
    // TODO: here...
    return stream;
}


UniProtRecord& load_xml(UniProtRecord& record, const std::string& str)
{
    std::istringstream stream(str);
    return load_xml(record, stream);
}


UniProtRecordList& load_xml(UniProtRecordList& list, const std::string& str)
{
    std::istringstream stream(str);
    return load_xml(list, stream);
}


UniProtRecord& load_xml(UniProtRecord& record, std::istream& stream)
{
    // TODO: here...
    return record;
}


UniProtRecordList& load_xml(UniProtRecordList& list, std::istream& stream)
{
    // TODO: here...
    return list;
}
