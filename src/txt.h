//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/**
 *  \addtogroup uniprot_kb
 *  \brief UniProt KB tab-delimited text parsers and serializers.
 */

#pragma once

#include "record.h"

#include <iostream>


namespace uniprot
{
// FUNCTIONS
// ---------


/**
 *  \brief Serialize single UniProt record to tab-delimited text.
 */
std::string& to_text(std::string& str, const record& r);


/**
 *  \brief Serialize UniProt record list to tab-delimited text.
 */
std::string& to_text(std::string& str, const record_list& list);


/**
 *  \brief Serialize single UniProt record to tab-delimited text.
 */
std::ostream& to_text(std::ostream& stream, const record& r);


/**
 *  \brief Serialize UniProt record list to tab-delimited text.
 */
std::ostream& to_text(std::ostream& stream, const record_list& list);


/**
 *  \brief Load tab-delimited text to UniProt record.
 */
record& load_text(record& r, const std::string& str);


/**
 *  \brief Load tab-delimited text to UniProt record list.
 */
record_list& load_text(record_list& list, const std::string& str);


/**
 *  \brief Load tab-delimited text to UniProt record.
 */
record& load_text(record& r, std::istream& stream);


/**
 *  \brief Load tab-delimited text to UniProt record list.
 */
record_list& load_text(record_list& list, std::istream& stream);

}   /* uniprot */
