#!/usr/bin/env python
#  :copyright: (c) 2017 Alex Huszagh.
#  :license: MIT, see LICENSE.md for more details.
'''
    record
    ------
'''

import copy
import unittest
import uniprot_kb


# TESTS
# -----


class UniProtRecordTest(unittest.TestCase):
    '''Test record object definition'''

    def setUp(self):
        self.record = uniprot_kb.UniProtRecord(3,
            1,
            35780,
            333,
            "GAPDH",
            "P46406",
            "G3P_RABIT",
            "Glyceraldehyde-3-phosphate dehydrogenase",
            "Oryctolagus cuniculus",
            "UP000001811",
            "MVKVGVNGFGRIGRLVTRAAFNSGKVDVVAINDPFIDLHYMVYMFQYDSTHGKFHGTVKAENGKLVINGKAITIFQERDPANIKWGDAGAEYVVESTGVFTTMEKAGAHLKGGAKRVIISAPSADAPMFVMGVNHEKYDNSLKIVSNASCTTNCLAPLAKVIHDHFGIVEGLMTTVHAITATQKTVDGPSGKLWRDGRGAAQNIIPASTGAAKAVGKVIPELNGKLTGMAFRVPTPNVSVVDLTCRLEKAAKYDDIKKVVKQASEGPLKGILGYTEDQVVSCDFNSATHSSTFDAGAGIALNDHFVKLISWYDNEFGYSNRVVDLMVHMASKE",
            "9986")

    def test_properties(self):
        self.assertEquals(self.record.sequence_version, 3)
        self.assertEquals(self.record.protein_evidence, 1)
        self.assertEquals(self.record.mass, 35780)
        self.assertEquals(self.record.length, 333)
        self.assertEquals(self.record.gene, "GAPDH")
        self.assertEquals(self.record.id, "P46406")
        self.assertEquals(self.record.mnemonic, "G3P_RABIT")
        self.assertEquals(self.record.name, "Glyceraldehyde-3-phosphate dehydrogenase")
        self.assertEquals(self.record.proteome, "UP000001811")
        self.assertEquals(self.record.sequence, "MVKVGVNGFGRIGRLVTRAAFNSGKVDVVAINDPFIDLHYMVYMFQYDSTHGKFHGTVKAENGKLVINGKAITIFQERDPANIKWGDAGAEYVVESTGVFTTMEKAGAHLKGGAKRVIISAPSADAPMFVMGVNHEKYDNSLKIVSNASCTTNCLAPLAKVIHDHFGIVEGLMTTVHAITATQKTVDGPSGKLWRDGRGAAQNIIPASTGAAKAVGKVIPELNGKLTGMAFRVPTPNVSVVDLTCRLEKAAKYDDIKKVVKQASEGPLKGILGYTEDQVVSCDFNSATHSSTFDAGAGIALNDHFVKLISWYDNEFGYSNRVVDLMVHMASKE")
        self.assertEquals(self.record.taxonomy, "9986")

    def test_copy(self):
        # test shallow copy
        cpy = copy.copy(self.record)
        self.assertEquals(self.record, cpy)
        cpy.id = "P04797"
        self.assertNotEquals(self.record, cpy)
        self.assertNotEquals(self.record.id, cpy.id)

        # test deep copy
        cpy = copy.deepcopy(self.record)
        self.assertEquals(self.record, cpy)
        cpy.id = "P04797"
        self.assertNotEquals(self.record, cpy)
        self.assertNotEquals(self.record.id, cpy.id)

    def test_richcmp(self):
        blank = uniprot_kb.UniProtRecord()
        cpy = copy.copy(self.record)

        self.assertNotEquals(self.record, blank)
        self.assertEquals(self.record, cpy)
        self.assertLess(blank, self.record)
        self.assertLessEqual(blank, self.record)
        self.assertLessEqual(cpy, self.record)
        self.assertGreater(self.record, blank)
        self.assertGreaterEqual(self.record, blank)
        self.assertGreaterEqual(cpy, self.record)

#    def test_to_string(self):
#        # TEXT
#
#        # FASTA
#        data = self.record.to_string(uniprot_kb.FASTA).splitlines()
#        self.assertEquals(len(data), 7)
#        self.assertEquals(data[0], ">sp|P46406|G3P_RABIT Glyceraldehyde-3-phosphate dehydrogenase OS=Oryctolagus cuniculus GN=GAPDH PE=1 SV=3")
#        self.assertEquals(data[1], "MVKVGVNGFGRIGRLVTRAAFNSGKVDVVAINDPFIDLHYMVYMFQYDSTHGKFHGTVKA")
#        self.assertEquals(data[2], "ENGKLVINGKAITIFQERDPANIKWGDAGAEYVVESTGVFTTMEKAGAHLKGGAKRVIIS")
#        self.assertEquals(data[3], "APSADAPMFVMGVNHEKYDNSLKIVSNASCTTNCLAPLAKVIHDHFGIVEGLMTTVHAIT")
#        self.assertEquals(data[4], "ATQKTVDGPSGKLWRDGRGAAQNIIPASTGAAKAVGKVIPELNGKLTGMAFRVPTPNVSV")
#        self.assertEquals(data[5], "VDLTCRLEKAAKYDDIKKVVKQASEGPLKGILGYTEDQVVSCDFNSATHSSTFDAGAGIA")
#        self.assertEquals(data[6], "LNDHFVKLISWYDNEFGYSNRVVDLMVHMASKE")
#
#        # XML
#
#    def test_to_file(self):
#        # TEXT
#
#        # FASTA
#        pass
#
#        # XML


class UniProtRecordListTest(unittest.TestCase):
    '''Test record object definition'''

    def setUp(self):
        self.list = uniprot_kb.UniProtRecordList()

        # GAPDH
        self.list.append(uniprot_kb.UniProtRecord(3,
            1,
            35780,
            333,
            "GAPDH",
            "P46406",
            "G3P_RABIT",
            "Glyceraldehyde-3-phosphate dehydrogenase",
            "Oryctolagus cuniculus",
            "UP000001811",
            "MVKVGVNGFGRIGRLVTRAAFNSGKVDVVAINDPFIDLHYMVYMFQYDSTHGKFHGTVKAENGKLVINGKAITIFQERDPANIKWGDAGAEYVVESTGVFTTMEKAGAHLKGGAKRVIISAPSADAPMFVMGVNHEKYDNSLKIVSNASCTTNCLAPLAKVIHDHFGIVEGLMTTVHAITATQKTVDGPSGKLWRDGRGAAQNIIPASTGAAKAVGKVIPELNGKLTGMAFRVPTPNVSVVDLTCRLEKAAKYDDIKKVVKQASEGPLKGILGYTEDQVVSCDFNSATHSSTFDAGAGIALNDHFVKLISWYDNEFGYSNRVVDLMVHMASKE",
            "9986"))

        # BSA
        self.list.append(uniprot_kb.UniProtRecord(4,
            1,
            69293,
            607,
            "ALB",
            "P02769",
            "ALBU_BOVIN",
            "Serum albumin",
            "Bos taurus",
            "UP000009136",
            "MKWVTFISLLLLFSSAYSRGVFRRDTHKSEIAHRFKDLGEEHFKGLVLIAFSQYLQQCPFDEHVKLVNELTEFAKTCVADESHAGCEKSLHTLFGDELCKVASLRETYGDMADCCEKQEPERNECFLSHKDDSPDLPKLKPDPNTLCDEFKADEKKFWGKYLYEIARRHPYFYAPELLYYANKYNGVFQECCQAEDKGACLLPKIETMREKVLASSARQRLRCASIQKFGERALKAWSVARLSQKFPKAEFVEVTKLVTDLTKVHKECCHGDLLECADDRADLAKYICDNQDTISSKLKECCDKPLLEKSHCIAEVEKDAIPENLPPLTADFAEDKDVCKNYQEAKDAFLGSFLYEYSRRHPEYAVSVLLRLAKEYEATLEECCAKDDPHACYSTVFDKLKHLVDEPQNLIKQNCDQFEKLGEYGFQNALIVRYTRKVPQVSTPTLVEVSRSLGKVGTRCCTKPESERMPCTEDYLSLILNRLCVLHEKTPVSEKVTKCCTESLVNRRPCFSALTPDETYVPKAFDEKLFTFHADICTLPDTEKQIKKQTALVELLKHKPKATEEQLKTVMENFVAFVDKCCAADDKEACFAVEGPKLVVSTQTALA",
            "9913"))

    def test_copy(self):
        # test shallow copy (actually a deepcopy)
        cpy = copy.copy(self.list)
        self.assertEquals(self.list, cpy)
        cpy[1].id = "P04797"
        self.assertEquals(self.list, cpy)
        cpy.append(uniprot_kb.UniProtRecord())
        self.assertNotEquals(self.list, cpy)

        # test deep copy
        cpy = copy.deepcopy(self.list)
        self.assertEquals(self.list, cpy)
        cpy[1].id = "P02769"
        self.assertNotEquals(self.list, cpy)
        cpy.append(uniprot_kb.UniProtRecord())
        self.assertNotEquals(self.list, cpy)

    def test_richcmp(self):
        blank = uniprot_kb.UniProtRecordList()
        cpy = copy.copy(self.list)

        self.assertNotEquals(self.list, blank)
        self.assertEquals(self.list, cpy)
        self.assertLess(blank, self.list)
        self.assertLessEqual(blank, self.list)
        self.assertLessEqual(cpy, self.list)
        self.assertGreater(self.list, blank)
        self.assertGreaterEqual(self.list, blank)
        self.assertGreaterEqual(cpy, self.list)

    def test_len(self):
        blank = uniprot_kb.UniProtRecordList()
        self.assertEquals(len(blank), 0)

        cpy = copy.copy(self.list)
        self.assertEquals(len(cpy), 2)
        cpy.append(uniprot_kb.UniProtRecord())
        self.assertEquals(len(cpy), 3)

    def test_contains(self):
        # empty list
        blank = uniprot_kb.UniProtRecordList()
        self.assertFalse(uniprot_kb.UniProtRecord() in blank)
        self.assertFalse(self.list[0] in blank)

        # non-empty list
        self.assertFalse(uniprot_kb.UniProtRecord() in self.list)
        self.assertTrue(self.list[0] in self.list)
        self.assertTrue(copy.copy(self.list[0]) in self.list)

    def test_iter(self):
        it = iter(self.list)
        self.assertEquals(next(it), self.list[0])
        self.assertEquals(next(it), self.list[1])
        with self.assertRaises(StopIteration):
            next(it)

    def test_getitem(self):
        cpy = copy.deepcopy(self.list)
        self.assertEquals(self.list[1], cpy[1])

        # positive index
        self.assertEquals(cpy[1].id, "P02769")

        # negative index
        self.assertEquals(cpy[-1].id, "P02769")

    def test_setitem(self):
        cpy = copy.deepcopy(self.list)
        self.assertEquals(self.list[1], cpy[1])
        cpy[0].id = "P04797"
        cpy[1].id = "P04797"
        self.assertNotEquals(self.list[1], cpy[1])

        # positive index
        self.list[1] = cpy[1]
        self.assertEquals(self.list[1], cpy[1])

        # negative index
        self.list[-2] = cpy[-2]
        self.assertEquals(self.list[0], cpy[0])

    def test_delitem(self):
        cpy = copy.deepcopy(self.list)
        self.assertEquals(len(cpy), 2)

        # positive index
        del cpy[0]
        self.assertEquals(len(cpy), 1)
        self.assertEquals(self.list[1], cpy[0])

        # negative index
        del cpy[-1]
        self.assertEquals(len(cpy), 0)

    def test_append(self):
        cpy = copy.deepcopy(self.list)
        self.assertEquals(len(cpy), 2)
        item = uniprot_kb.UniProtRecord()
        cpy.append(item)
        self.assertEquals(len(cpy), 3)
        self.assertEquals(cpy[2], item)

    def test_extend(self):
        cpy = copy.deepcopy(self.list)
        self.assertEquals(len(cpy), 2)
        item = uniprot_kb.UniProtRecord()
        cpy.extend([item])
        self.assertEquals(len(cpy), 3)
        self.assertEquals(cpy[2], item)

    def test_insert(self):
        cpy = copy.deepcopy(self.list)
        cpy.insert(0, uniprot_kb.UniProtRecord())
        self.assertEquals(len(cpy), 3)
        self.assertEquals(cpy[0], uniprot_kb.UniProtRecord())

    def test_clear(self):
        cpy = copy.deepcopy(self.list)
        self.assertEquals(len(cpy), 2)
        cpy.clear()
        self.assertEquals(len(cpy), 0)

    def test_pop(self):
        cpy = copy.deepcopy(self.list)
        self.assertEquals(len(cpy), 2)

        cpy.pop()
        self.assertEquals(len(cpy), 1)
        self.assertEquals(cpy[0], self.list[0])

        cpy.pop()
        self.assertEquals(len(cpy), 0)

        cpy = copy.deepcopy(self.list)
        cpy.pop(0)
        self.assertEquals(len(cpy), 1)
        self.assertEquals(cpy[0], self.list[1])

        # negative index
        cpy.pop(-1)
        self.assertEquals(len(cpy), 0)

    def test_index(self):
        cpy = copy.copy(self.list)
        self.assertEquals(cpy.index(self.list[0]), 0)
        with self.assertRaises(IndexError):
            cpy.index(uniprot_kb.UniProtRecord())

    def test_count(self):
        cpy = copy.copy(self.list)
        self.assertEquals(cpy.count(self.list[0]), 1)
        self.assertEquals(cpy.count(uniprot_kb.UniProtRecord()), 0)

    def test_reverse(self):
        cpy = copy.copy(self.list)
        cpy.reverse()
        self.assertEquals(cpy[0], self.list[1])
        self.assertEquals(cpy[1], self.list[0])

    def test_add(self):
        cpy = copy.copy(self.list)
        item = uniprot_kb.UniProtRecord()

        # __add__
        self.assertEquals(len(cpy + [item]), 3)
        self.assertEquals(len(cpy), 2)

        # __radd__
        self.assertEquals(len([item] + cpy), 3)
        self.assertEquals(len(cpy), 2)

        # __iadd__
        cpy += [item]
        self.assertEquals(len(cpy), 3)

    def test_mul(self):
        cpy = copy.copy(self.list)

        # __mul__
        self.assertEquals(len(cpy * 1), 2)
        self.assertEquals(len(cpy * 2), 4)
        self.assertEquals(len(cpy), 2)

        # __rmul__
        self.assertEquals(len(1 * cpy), 2)
        self.assertEquals(len(2 * cpy), 4)
        self.assertEquals(len(cpy), 2)

        # __imul__
        cpy *= 2
        self.assertEquals(len(cpy), 4)

        # type-error
        with self.assertRaises(TypeError):
            cpy * []

#    def test_to_string(self):
#        # TEXT
#
#        # FASTA
#        data = self.list.to_string(uniprot_kb.FASTA).splitlines()
#        self.assertEquals(len(data), 21)
#        self.assertEquals(data[0], ">sp|P46406|G3P_RABIT Glyceraldehyde-3-phosphate dehydrogenase OS=Oryctolagus cuniculus GN=GAPDH PE=1 SV=3")
#        self.assertEquals(data[8], ">sp|P02769|ALBU_BOVIN Serum albumin OS=Bos taurus GN=ALB PE=1 SV=4")
#
#        # XML
#
#    def test_to_file(self):
#        # TEXT
#
#        # FASTA
#        pass
#
#        # XML
