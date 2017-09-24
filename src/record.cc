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


bool record::operator==(const record& rhs) const
{
    return tie(*this) == tie(rhs);
}


bool record::operator<(const record& rhs) const
{
    return std::tie(length, mass) < std::tie(rhs.length, rhs.mass);
}


bool record_list::operator==(const record_list& rhs) const
{
    auto pred = [](const value_type& l, const value_type& r) -> bool
    {
        if (l && r) {
            return *l == *r;
        } else {
            return l == r;
        }
    };

    return size() == rhs.size() && std::equal(begin(), end(), rhs.begin(), pred);
}


bool record_list::operator<(const record_list& rhs) const
{
    auto pred = [](const value_type& l, const value_type& r) -> bool
    {
        if (l && r) {
            return *l < *r;
        } else {
            return l < r;
        }
    };

    return std::lexicographical_compare(begin(), end(), rhs.begin(), rhs.end(), pred);
}

}   /* uniprot */
