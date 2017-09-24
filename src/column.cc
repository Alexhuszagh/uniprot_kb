//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

#include "column.h"
#include "record.h"
#include <pycpp/string/whitespace.h>
#include <sstream>
#include <stdexcept>


namespace uniprot
{
// CONSTANTS
// ---------

static constexpr size_t SEQUENCE_LINE_LENGTH = 60;

// FUNCTIONS
// ---------

std::string format_sequence_fasta(const std::string& sequence)
{
    std::stringstream stream;
    stream << PYCPP_NAMESPACE::NEWLINE;
    for (size_t i = 0 ; i < sequence.size(); i += SEQUENCE_LINE_LENGTH) {
        stream << sequence.substr(i, SEQUENCE_LINE_LENGTH);
        stream << PYCPP_NAMESPACE::NEWLINE;
    }

    return stream.str();
}

// OBJECTS
// -------


std::string column_formatter::name(column c)
{
    switch (c) {
        case column_sequence_version:
            return "version(sequence)";
        case column_protein_evidence:
            return "existence";
        case column_mass:
            return "mass";
        case column_length:
            return "length";
        case column_gene:
            return "genes(PREFERRED)";
        case column_id:
            return "id";
        case column_mnemonic:
            return "entry name";
        case column_name:
            return "protein names";
        case column_organism:
            return "organism";
        case column_proteome:
            return "proteome";
        case column_sequence:
            return "sequence";
        case column_taxonomy:
            return "organism-id";
        default:
            throw std::invalid_argument("Unknown column");
    }
}


std::string column_formatter::txt(column c)
{
    switch (c) {
        case column_sequence_version:
            return "Version (sequence)";
        case column_protein_evidence:
            return "Protein existence";
        case column_mass:
            return "Mass";
        case column_length:
            return "Length";
        case column_gene:
            return "Gene names  (primary )";
        case column_id:
            return "Entry";
        case column_mnemonic:
            return "Entry Name";
        case column_name:
            return "Protein names";
        case column_organism:
            return "Organism";
        case column_proteome:
            return "Proteomes";
        case column_sequence:
            return "Sequence";
        case column_taxonomy:
            return "Organism ID";
        default:
            throw std::invalid_argument("Unknown column");
    }
}

std::string column_formatter::fasta(column c)
{
    switch (c) {
        // TODO: how does this work?? They're typically empty
//        case column_sequence_version:
//        case column_protein_evidence:
//        case column_mass:
//        case column_length:
//        case column_gene:
//        case column_id:
//        case column_mnemonic:
//        case column_name:
//        case column_organism:
//        case column_proteome:
//        case column_sequence:
//        case column_taxonomy:
        default:
            throw std::invalid_argument("Unknown column");
    }
}


std::string column_formatter::xml(column c)
{
    switch (c) {
        // TODO: need property names
//        case column_sequence_version:
//        case column_protein_evidence:
//        case column_mass:
//        case column_length:
//        case column_gene:
//        case column_id:
//        case column_mnemonic:
//        case column_name:
//            TODO: need to consider multiple names
//        case column_organism:
//        case column_proteome:
//        case column_sequence:
//        case column_taxonomy:
        default:
            throw std::invalid_argument("Unknown column");
    }
}

std::string record_formatter::txt(const record& r, column c)
{
    switch (c) {
        // TODO:
//        case column_sequence_version:
//        case column_protein_evidence:
//        case column_mass:
//        case column_length:
//        case column_gene:
//        case column_id:
        case column_mnemonic:
            return r.mnemonic;
//        case column_name:
//            TODO: need to consider multiple names
//        case column_organism:
//        case column_proteome:
        case column_sequence:
            return r.sequence;
//        case column_taxonomy:
        default:
            throw std::invalid_argument("Unknown column");
    }
}


std::string record_formatter::fasta(const record& r, column c)
{
    switch (c) {
        // TODO:
//        case column_sequence_version:
//        case column_protein_evidence:
//        case column_mass:
//        case column_length:
//        case column_gene:
        case column_id:
            return r.id;
        case column_mnemonic:
            return r.mnemonic;
//        case column_name:
//            TODO: need to consider multiple names
//        case column_organism:
                return r.organism;      // TODO: is this correct?
//        case column_proteome:
        case column_sequence:
            return format_sequence_fasta(r.sequence);
//        case column_taxonomy:
        default:
            throw std::invalid_argument("Unknown column");
    }
}


std::string record_formatter::xml(const record& r, column c)
{
    switch (c) {
        // TODO:
//        case column_sequence_version:
//        case column_protein_evidence:
//        case column_mass:
//        case column_length:
//        case column_gene:
//        case column_id:
        case column_mnemonic:
            return r.mnemonic;
//        case column_name:
//        case column_organism:
//        case column_proteome:
//        case column_sequence:
//        case column_taxonomy:
        default:
            throw std::invalid_argument("Unknown column");
    }
}

}   /* uniprot */
