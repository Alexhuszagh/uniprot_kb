//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/**
 *  \addtogroup uniprot_kb
 *  \brief Uniprot record definitions.
 */

#pragma once

#include <deque>
#include <string>

namespace uniprot
{
// CONSTANTS
// ---------

static constexpr size_t ACCESSION_NUMBER_LENGTH = 10;
static constexpr size_t MNEMONIC_LENGTH = 11;

// OBJECTS
// -------


/**
 *  \brief Model for a single record from a UniProt KB query.
 *
 *  Record including core query fields for a given UniProt identifier.
 *  The query fields are defined [here](http://www.uniprot.org/help/query-fields).
 *
 *  \param sequence_version Numerical identifier for protein version.
 *  \param protein_evidence Numerical identifier for protein evidence.
 *  \param mass             Mass of the protein.
 *  \param length           Protein sequence length.
 *  \param gene             HGNC Gene name.
 *  \param id               Accession number (randomly assigned identifier).
 *  \param mnemonic         Entry name (readable identifier).
 *  \param organism         Readable organism name.
 *  \param name             Protein name.
 *  \param proteome         Uniprot proteome identifier.
 *  \param sequence         Protein aminoacid sequence.
 *  \param taxonomy         Taxonomic identifier.
 *
 *  The sequence version is a numerical identifier starting from 1 for
 *  the revision of the protein ID.
 *
 *  The protein evidence is a numerical identifier, with 1 meaning
 *  evidence at the protein level, 2 meaning evidence at the
 *  transcript level, and 3 meaning the protein was inferred via
 *  homology.
 */
struct record
{
    uint8_t sequence_version;
    uint8_t protein_evidence;
    double mass;
    size_t length;
    std::string gene;
    std::string id;
    std::string mnemonic;
    std::string name;
    std::string organism;
    std::string proteome;
    std::string sequence;
    std::string taxonomy;

    bool operator==(const record& other) const;
    bool operator<(const record& other) const;
};


/**
 *  \brief Collection of uniprot records.
 */
typedef std::deque<record> record_list;

}   /* uniprot */    