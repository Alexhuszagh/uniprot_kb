//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/**
 *  \addtogroup uniprot_kb
 *  \brief UniProt KB FASTA parsers and serializers.
 */

#pragma once

#include "record.h"

#include <iostream>

namespace uniprot
{
// FUNCTIONS
// ---------

/**
 *  \brief Serialize UniProt record to FASTA.
 */
std::string& to_fasta(std::string& str, const record& r);

/**
 *  \brief Serialize UniProt record list to FASTA.
 */
std::string& to_fasta(std::string& str, const record_list& list);

/**
 *  \brief Serialize UniProt record to FASTA.
 */
std::ostream& to_fasta(std::ostream& stream, const record& r);

/**
 *  \brief Serialize UniProt record list to FASTA.
 */
std::ostream& to_fasta(std::ostream& stream, const record_list& list);

/**
 *  \brief Load FASTA to UniProt record.
 */
record& load_fasta(record& r, const std::string& str);

/**
 *  \brief Load FASTA to UniProt record list.
 */
record_list& load_fasta(record_list& list, const std::string& str);

/**
 *  \brief Load FASTA to UniProt record.
 */
record& load_fasta(record& r, std::istream& stream);

/**
 *  \brief Load FASTA to UniProt record list.
 */
record_list& load_fasta(record_list& list, std::istream& stream);

}   /* uniprot */
