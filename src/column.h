//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/**
 *  \addtogroup uniprot_kb
 *  \brief UniProt KB column mapping.
 */

#pragma once

#include "fwd.h"
#include <string>


namespace uniprot
{
// ENUMS
// -----

/**
 *  \brief Columns for UniProt KB field.
 */
enum column
{
    column_sequence_version = 0,
    column_protein_evidence,
    column_mass,
    column_length,
    column_gene,
    column_id,
    column_mnemonic,
    column_name,
    column_organism,
    column_proteome,
    column_sequence,
    column_taxonomy,
};

// OBJECTS
// -------


/**
 *  \brief Formatter for column names.
 */
struct column_formatter
{
    std::string name(column c);
    std::string txt(column c);
    std::string fasta(column c);
    std::string xml(column c);
};


/**
 *  \brief Formatter for record values.
 */
struct record_formatter
{
    std::string txt(const record& r, column c);
    std::string fasta(const record& r, column c);
    std::string xml(const record& r, column c);
};

}   /* uniprot */
