//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/**
 *  \addtogroup uniprot_kb
 *  \brief UniProt KB FASTA parsers and serializers.
 */

#pragma once

#include "record.h"

#include <iostream>


// FUNCTIONS
// ---------


/**
 *  \brief Serialize UniProt record to FASTA.
 */
std::string& to_fasta(std::string& str, const UniprotRecord& record);


/**
 *  \brief Serialize UniProt record list to FASTA.
 */
std::string& to_fasta(std::string& str, const UniprotRecordList& list);


/**
 *  \brief Serialize UniProt record to FASTA.
 */
std::ostream& to_fasta(std::ostream& stream, const UniprotRecord& record);


/**
 *  \brief Serialize UniProt record list to FASTA.
 */
std::ostream& to_fasta(std::ostream& stream, const UniprotRecordList& list);


/**
 *  \brief Load FASTA to UniProt record.
 */
UniprotRecord& load_fasta(UniprotRecord& record, const std::string& str);


/**
 *  \brief Load FASTA to UniProt record list.
 */
UniprotRecordList& load_fasta(UniprotRecordList& list, const std::string& str);


/**
 *  \brief Load FASTA to UniProt record.
 */
UniprotRecord& load_fasta(UniprotRecord& record, std::istream& stream);


/**
 *  \brief Load FASTA to UniProt record list.
 */
UniprotRecordList& load_fasta(UniprotRecordList& list, std::istream& stream);
