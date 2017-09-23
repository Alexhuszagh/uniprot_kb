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

    def test_operators(self):
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
