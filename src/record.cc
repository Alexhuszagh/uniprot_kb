//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

#include "record.h"

#include <tuple>


namespace uniprot
{
// FUNCTIONS
// ---------


decltype(auto) tie(const record& r)
{
    return std::tie(
        r.sequence_version,
        r.protein_evidence,
        r.mass,
        r.length,
        r.gene,
        r.id,
        r.mnemonic,
        r.name,
        r.organism,
        r.proteome,
        r.sequence,
        r.taxonomy
    );
}


// OBJECTS
// -------


bool record::operator==(const record& other) const
{
    return tie(*this) == tie(other);
}


bool record::operator<(const record& other) const
{
    return std::tie(length, mass) < std::tie(other.length, other.mass);
}

}   /* uniprot */    