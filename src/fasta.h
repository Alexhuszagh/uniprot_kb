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
std::string& to_fasta(std::string& str, const UniProtRecord& record);

/**
 *  \brief Serialize UniProt record list to FASTA.
 */
std::string& to_fasta(std::string& str, const UniProtRecordList& list);

/**
 *  \brief Serialize UniProt record to FASTA.
 */
std::ostream& to_fasta(std::ostream& stream, const UniProtRecord& record);

/**
 *  \brief Serialize UniProt record list to FASTA.
 */
std::ostream& to_fasta(std::ostream& stream, const UniProtRecordList& list);

/**
 *  \brief Load FASTA to UniProt record.
 */
UniProtRecord& load_fasta(UniProtRecord& record, const std::string& str);

/**
 *  \brief Load FASTA to UniProt record list.
 */
UniProtRecordList& load_fasta(UniProtRecordList& list, const std::string& str);

/**
 *  \brief Load FASTA to UniProt record.
 */
UniProtRecord& load_fasta(UniProtRecord& record, std::istream& stream);

/**
 *  \brief Load FASTA to UniProt record list.
 */
UniProtRecordList& load_fasta(UniProtRecordList& list, std::istream& stream);

}   /* uniprot */
