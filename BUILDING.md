unniprot_kb
===========

Build instructions for uniprot_kb, including the core C++ libraries and the Python wrappers.

**TODO**: Move from Swig to Cython

**Table Of Contents**

- [About](#about)
- [Sources](#sources)
- [Instructions](#instructions)
  - [Windows](#windows)
    + [MSVC](#msvc)
    + [MSYS2](#msys2)
  - [POSIX](#posix)
    + [Ubuntu/Debian](#ubuntu-debian)
    + [Fedora](#fedora)
    + [Other](#other)
  - [Cross-Compiling](#cross-compiling)

## About

uniprot_kb contains a core C++ library, as well as extensions for Python wrappers. It supports modern desktop and server environments, compatible with any C++11-compatible compiler.

**Tested Builds**

- GCC
- Clang
- MXE for Windows (Static, Release-Only)
- MinGW-w64 (Static, Release-Only)
- MSYS2
- Visual C++ 2015 (MSVC 14)

All are compatible with 32-bit or 64-bit builds.

## Dependencies

- [Python](https://www.python.org/)
- [Git](https://git-scm.com/)
- [Swig](http://swig.org/)

## Instructions

### Windows

#### MSVC

#### MSYS2

### POSIX

For POSIX systems, please use the system default Python, Git and Swig, which are the sole dependencies for this package.

#### Ubuntu/Debian

**Warning: Build instructions temporarily fails for the GUI version, since Debian/Ubuntu currently do not have libqt5charts5-dev. This should be fixed in the near [future](https://packages.debian.org/search?keywords=libqt5charts5).**

```bash
sudo apt install python swig git

# configure and build
cd uniprot_kb
python setup.py build
python setup.py install --user
```

#### Fedora


#### Other

Install Python (2 or 3, depending on which wrappers you would like to use)