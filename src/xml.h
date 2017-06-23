//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/**
 *  \addtogroup uniprot_kb
 *  \brief UniProt KB XML parsers and serializers.
 */

#pragma once

#include "record.h"

#include <iostream>


// FUNCTIONS
// ---------


/**
 *  \brief Serialize single UniProt record to XML.
 */
std::string& to_xml(std::string& str, const UniprotRecord& record);


/**
 *  \brief Serialize UniProt record list to XML.
 */
std::string& to_xml(std::string& str, const UniprotRecordList& list);


/**
 *  \brief Serialize single UniProt record to XML.
 */
std::ostream& to_xml(std::ostream& stream, const UniprotRecord& record);


/**
 *  \brief Serialize UniProt record list to XML.
 */
std::ostream& to_xml(std::ostream& stream, const UniprotRecordList& list);


/**
 *  \brief Load XML to UniProt record.
 */
UniprotRecord& load_xml(UniprotRecord& record, const std::string& str);


/**
 *  \brief Load XML to UniProt record list.
 */
UniprotRecordList& load_xml(UniprotRecordList& list, const std::string& str);


/**
 *  \brief Load XML to UniProt record.
 */
UniprotRecord& load_xml(UniprotRecord& record, std::istream& stream);


/**
 *  \brief Load XML to UniProt record list.
 */
UniprotRecordList& load_xml(UniprotRecordList& list, std::istream& stream);
