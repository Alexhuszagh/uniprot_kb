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
std::string& to_text(std::string& str, const UniProtRecord& record);


/**
 *  \brief Serialize UniProt record list to tab-delimited text.
 */
std::string& to_text(std::string& str, const UniProtRecordList& list);


/**
 *  \brief Serialize single UniProt record to tab-delimited text.
 */
std::ostream& to_text(std::ostream& stream, const UniProtRecord& record);


/**
 *  \brief Serialize UniProt record list to tab-delimited text.
 */
std::ostream& to_text(std::ostream& stream, const UniProtRecordList& list);


/**
 *  \brief Load tab-delimited text to UniProt record.
 */
UniProtRecord& load_text(UniProtRecord& record, const std::string& str);


/**
 *  \brief Load tab-delimited text to UniProt record list.
 */
UniProtRecordList& load_text(UniProtRecordList& list, const std::string& str);


/**
 *  \brief Load tab-delimited text to UniProt record.
 */
UniProtRecord& load_text(UniProtRecord& record, std::istream& stream);


/**
 *  \brief Load tab-delimited text to UniProt record list.
 */
UniProtRecordList& load_text(UniProtRecordList& list, std::istream& stream);
