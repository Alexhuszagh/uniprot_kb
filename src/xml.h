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
std::string& to_xml(std::string& str, const UniProtRecord& record);


/**
 *  \brief Serialize UniProt record list to XML.
 */
std::string& to_xml(std::string& str, const UniProtRecordList& list);


/**
 *  \brief Serialize single UniProt record to XML.
 */
std::ostream& to_xml(std::ostream& stream, const UniProtRecord& record);


/**
 *  \brief Serialize UniProt record list to XML.
 */
std::ostream& to_xml(std::ostream& stream, const UniProtRecordList& list);


/**
 *  \brief Load XML to UniProt record.
 */
UniProtRecord& load_xml(UniProtRecord& record, const std::string& str);


/**
 *  \brief Load XML to UniProt record list.
 */
UniProtRecordList& load_xml(UniProtRecordList& list, const std::string& str);


/**
 *  \brief Load XML to UniProt record.
 */
UniProtRecord& load_xml(UniProtRecord& record, std::istream& stream);


/**
 *  \brief Load XML to UniProt record list.
 */
UniProtRecordList& load_xml(UniProtRecordList& list, std::istream& stream);
