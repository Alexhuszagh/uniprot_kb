//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/**
 *  \addtogroup uniprot_kb
 *  \brief UniProt KB tab-delimited text parsers and serializers.
 */

#pragma once

#include "record.h"

#include <iostream>


// FUNCTIONS
// ---------


/**
 *  \brief Serialize single UniProt record to tab-delimited text.
 */
std::string& to_text(std::string& str, const UniprotRecord& record);


/**
 *  \brief Serialize UniProt record list to tab-delimited text.
 */
std::string& to_text(std::string& str, const UniprotRecordList& list);


/**
 *  \brief Serialize single UniProt record to tab-delimited text.
 */
std::ostream& to_text(std::ostream& stream, const UniprotRecord& record);


/**
 *  \brief Serialize UniProt record list to tab-delimited text.
 */
std::ostream& to_text(std::ostream& stream, const UniprotRecordList& list);


/**
 *  \brief Load tab-delimited text to UniProt record.
 */
UniprotRecord& load_text(UniprotRecord& record, const std::string& str);


/**
 *  \brief Load tab-delimited text to UniProt record list.
 */
UniprotRecordList& load_text(UniprotRecordList& list, const std::string& str);


/**
 *  \brief Load tab-delimited text to UniProt record.
 */
UniprotRecord& load_text(UniprotRecord& record, std::istream& stream);


/**
 *  \brief Load tab-delimited text to UniProt record list.
 */
UniprotRecordList& load_text(UniprotRecordList& list, std::istream& stream);
