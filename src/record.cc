//  :copyright: (c) 2017 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.

#include "record.h"

#include <tuple>


// FUNCTIONS
// ---------


decltype(auto) tie(const UniProtRecord &r)
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


bool UniProtRecord::operator==(const UniProtRecord &other) const
{
    return tie(*this) == tie(other);
}


bool UniProtRecord::operator<(const UniProtRecord &other) const
{
    return std::tie(length, mass) < std::tie(other.length, other.mass);
}
