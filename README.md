uniprot_kb
==========

A C++/Python Interface with UniProt KB.

[![Build Status](https://travis-ci.org/Alexhuszagh/uniprot_kb.svg?branch=master)](https://travis-ci.org/Alexhuszagh/uniprot_kb)
[![Build Status](https://tea-ci.org/api/badges/Alexhuszagh/uniprot_kb/status.svg)](https://tea-ci.org/Alexhuszagh/uniprot_kb)
[![Build status](https://ci.appveyor.com/api/projects/status/jx4mmgo25myx9u9i?svg=true)](https://ci.appveyor.com/project/Alexhuszagh/uniprot_kb)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/Alexhuszagh/uniprot_kb/blob/master/LICENSE.md)

**Table of Contents**

- [Features](#features)
- [Getting Started](#getting-started)
- [Documentation](#documentation)
- [Building](#building)
- [Platforms](#platforms)
- [Contributors](#contributors)
- [License](#license)

## Features

- Loading from and saving to...
  - FASTA
  - Tab-delimited text
  - UniProt XML
- Retrieving records from [uniprot.org](uniprot.org)
- Mapping identifiers
- BLAST

## Getting Started

```python
// TODO: here...
```

## Documentation

## Building

uniprot_kb requires Python, Git, Cython, and C++ compiler environment for building.

```bash
git clone https://github.com/Alexhuszagh/uniprot_kb.git
git submodule update --init --recursive
python setup.py build
python setup.py test            # run unittest suite
python setup.py install --user  # install package locally
```

See [building](/BUILDING.md) for more detailed instructions.

## Platforms

uniprot_kb is continually built with the following compiler and compiler versions:

- Clang 3.8+
- GCC 5.3+
- MinGW 5.3.0 (MXE, MinGW, and MSYS2) 
- Visual Studio 14 2015
- Visual Studio 15 2017

## Contributors

- Alex Huszagh

## License

MIT, see [license](LICENSE.md).
