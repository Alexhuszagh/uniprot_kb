unniprot_kb
===========

Build instructions for uniprot_kb, including the core C++ libraries and the Python wrappers.

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
- [Cython](http://cython.org/)

## Instructions

### Windows

#### MSVC

#### MSYS2

### POSIX

For POSIX systems, please use the system default Python, Git and Cython, which are the sole dependencies for this package.

#### Ubuntu/Debian

```bash
sudo apt install python swig cython g++ git  # cython3 and python3 for Python3.x

# fetch and update repository
git clone https://github.com/Alexhuszagh/uniprot_kb
cd uniprot_kb
git submodule update --init --recursive

# configure and build
python setup.py build
python setup.py install --user
```

#### Fedora

These instructions are tested on Fedora 26, but likely work with recent Fedora OSes.

```bash
sudo dnf install python swig python-Cython gcc-c++ git  # python3-Cython and python3 for Python3.x

# fetch and update repository
git clone https://github.com/Alexhuszagh/uniprot_kb
cd uniprot_kb
git submodule update --init --recursive

# configure and build
python setup.py build
python setup.py install --user
```

#### Other

Install Python (2 or 3, depending on which wrappers you would like to use), install any modern git and C++ compiler, and with a modern Python install type:

```bash
# install Cython
python -m pip install cython
```
