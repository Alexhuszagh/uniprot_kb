# Roadmap

**Commit**
- Push local PyCPP changes
- Add header for record.pxd
- Define header for fasta.pxd
- Move to single source file (.so library), no package
    - Need to add a py_extension? Dunno what it is...

**Short-term**
- Fix CI integrations for TeaCI
    - Need to ensure Cython is properly installed with the CLI utility
- Write serializers for Uniprot Records
    - XML
    - FASTA
    - TBT

**Mid-term**
- Write deserializers for Uniprot records
    - XML
    - FASTA
    - TBT
