//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

#include "format.h"
#include "record.h"
#include <pycpp/string/whitespace.h>
#include <sstream>
#include <stdexcept>


namespace uniprot
{
// CONSTANTS
// ---------

static constexpr size_t SEQUENCE_LINE_LENGTH = 60;

// HELPERS
// -------

struct us_number_formatter: std::numpunct<char>
{
protected:
    virtual char do_thousands_sep() const;
    virtual std::string do_grouping() const;
};

char us_number_formatter::do_thousands_sep() const
{
    return ',';
}


std::string us_number_formatter::do_grouping() const
{
    return "\03";
}


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


std::string format_protein_name_fasta(const std::string& name)
{
    // secondary names are delimited by " (";
    size_t index = name.find(" (");
    return name.substr(0, index);
}


std::string format_protein_evidence_txt(uint8_t e)
{
    // the documentation is specified here: http://www.uniprot.org/docs/pe_criteria
    switch (e) {
        case 1:
            return "Evidence at protein level";
        case 2:
            return "Evidence at transcript level";
        case 3:
            return "Evidence from homology";
        default:
            throw std::invalid_argument("Unknown protein evidence: " + std::to_string(e));
    }
}

// TODO: need the reverse formatters...


std::string format_mass_txt(const double& mass)
{
    std::stringstream stream;
    // UniProt KB uses the US-locale for mass formatting, evidenced
    // by UniProt ID Q8WZ42.
    stream.imbue(std::locale(stream.getloc(), new us_number_formatter));
    stream << mass;
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
            throw std::invalid_argument("Unknown column: " + std::to_string(c));
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
            throw std::invalid_argument("Unknown column: " + std::to_string(c));
    }
}

std::string column_formatter::fasta(column c)
{
    // null-op, for compatibility reasons only
    switch (c) {
        case column_sequence_version:
        case column_protein_evidence:
        case column_mass:
        case column_length:
        case column_gene:
        case column_id:
        case column_mnemonic:
        case column_name:
        case column_organism:
        case column_proteome:
        case column_sequence:
        case column_taxonomy:
        default:
            throw std::invalid_argument("Unknown column: " + std::to_string(c));
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
            throw std::invalid_argument("Unknown column: " + std::to_string(c));
    }
}

std::string record_formatter::to_txt(const record& r, column c)
{
    switch (c) {
        case column_sequence_version:
            return std::to_string(r.sequence_version);
        case column_protein_evidence:
            return format_protein_evidence_txt(r.protein_evidence);
        case column_mass:
            return format_mass_txt(r.mass);
        case column_length:
            return std::to_string(r.length);
        case column_gene:
            return r.gene;
        case column_id:
            return r.id;
        case column_mnemonic:
            return r.mnemonic;
        case column_name:
            return r.name;
        case column_organism:
            return r.organism;
        case column_proteome:
            return r.proteome;
        case column_sequence:
            return r.sequence;
        case column_taxonomy:
            return r.taxonomy;
        default:
            throw std::invalid_argument("Unknown column: " + std::to_string(c));
    }
}


std::string record_formatter::to_fasta(const record& r, column c)
{
    switch (c) {
        case column_sequence_version:
            return std::to_string(r.sequence_version);
        case column_protein_evidence:
            return std::to_string(r.protein_evidence);
        case column_gene:
            return r.gene;
        case column_id:
            return r.id;
        case column_mnemonic:
            return r.mnemonic;
        case column_name:
            return format_protein_name_fasta(r.name);
        case column_organism:
                return r.organism;
        case column_sequence:
            return format_sequence_fasta(r.sequence);
        // UNIMPLEMENTED
        case column_mass:
        case column_length:
        case column_proteome:
        case column_taxonomy:
        default:
            throw std::invalid_argument("Unknown column: " + std::to_string(c));
    }
}


std::string record_formatter::to_xml(const record& r, column c)
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
            throw std::invalid_argument("Unknown column: " + std::to_string(c));
    }
}

}   /* uniprot */
