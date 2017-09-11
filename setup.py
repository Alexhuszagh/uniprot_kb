#!/usr/bin/env python
#  :copyright: (c) 2017 Alex Huszagh.
#  :license: MIT, see LICENSE.md for more details.
'''
    setup
    -----

    Build script for MS file library.
'''

import glob
import os
import platform
import shutil
import sys

from setuptools import Command, Extension, setup
from setuptools.command.build_ext import build_ext
from setuptools.command.test import test

# SETTINGS
# --------

NAME = "uniprot_kb"
SHORT_DESCRIPTION = 'A Python Interface with UniProt'

LONG_DESCRIPTION = '''UniProt KB, a library providing
models and tools to fetch data from FASTA, UniProt XML files, and
the Uniprot KB server, as well as serialize data to CSV, FASTA,
or Uniprot XML.
'''

CLASSIFIERS = [
    'Development Status :: 3 - Alpha',
    'Environment :: Console',
    'Intended Audience :: Information Technology',
    'Intended Audience :: Science/Research',
    'License :: OSI Approved :: MIT License',
    'Programming Language :: C++',
    'Programming Language :: Swig',
    'Programming Language :: Python',
    'Topic :: Scientific/Engineering',
    'Topic :: Scientific/Engineering :: Chemistry',
    'Topic :: Scientific/Engineering :: Bio-Informatics',
    'Topic :: Software Development :: Libraries :: Python Modules',
    'Operating System :: Unix',
    'Operating System :: POSIX :: Linux',
    'Operating System :: MacOS :: MacOS X',
    'Operating System :: Microsoft :: Windows',
]

# CONFIGURATION
# -------------

IS_64BIT = sys.maxsize > 2**32
IS_WINDOWS = platform.system() == 'Windows'
INCLUDE_DIRS = [
    'src',
    'third_party/pycpp'
]

PYCPP_SOURCES = glob.glob('third_party/pycpp/**/*.cc')

# PACKAGING
# ---------

SRC_DIR = "uniprot_kb"
PACKAGES = {SRC_DIR}
EXTENSION_NAMES = [
    ("record", [])
]

EXTENSIONS = []
for name, extras in EXTENSION_NAMES:
    EXTENSIONS.append(Extension('uniprot_kb.name'.format(name),
        sources=[
            'uniprot_kb/{}.pyx'.format(name),
            'src/{}.cc'.format(name),
        ] + extras,
        include_dirs=INCLUDE_DIRS,
        language='c++'))

# COMMANDS
# --------

MSVC_EXTRA_COMPILE_ARGS = ['/EHsc', '/std:c++14', '/bigobj']
MINGW_EXTRA_COMPILE_ARGS = ['-static-libgcc', '-static-libstdc++', '-std=c++14', '-fpermissive']
CXX_EXTRA_COMPILE_ARGS = ['-std=c++14']


class Clean(Command):
    '''Custom clean command to remove Cython source files'''

    description = "Test mslib"
    user_options = []

    def initialize_options(self):
        '''Initialize and finalize no optional arguments'''

    def finalize_options(self):
        '''Initialize and finalize no optional arguments'''

    def run(self):
        '''Run clean suite'''

        self.clean_build()
        self.clean_dist()
        self.clean_cython()

    def clean_build(self):
        '''Clean the build directory'''

        home = os.path.dirname(os.path.realpath(__file__))
        build = os.path.join(home, 'build')
        if os.path.exists(build):
            shutil.rmtree(build)

    def clean_dist(self):
        '''Clean the dist directory'''

        home = os.path.dirname(os.path.realpath(__file__))
        dist = os.path.join(home, 'dist')
        if os.path.exists(dist):
            shutil.rmtree(dist)

    def clean_cython(self):
        '''Clean intermediate Cython files'''

        home = os.path.dirname(os.path.realpath(__file__))
        for pattern in ['*.h', '*.c', '*.cpp']:
            for file in glob.iglob(os.path.join(home, 'uniprot_kb', '*', pattern)):
                os.remove(file)


class Test(Command):
    '''Test built libraries'''

    description = "Test mslib"
    user_options = []

    def initialize_options(self):
        '''Initialize and finalize no optional arguments'''

    def finalize_options(self):
        '''Initialize and finalize no optional arguments'''

    def run(self):
        '''Run test suite'''

        #home = os.path.dirname(os.path.realpath(__file__))


class BuildExt(build_ext):
    '''Override default build ext to add compiler-specific arguments'''

    def build_extension(self, ext):
        '''Detect compiler type to add extra arguments'''

        if self.compiler.compiler_type == 'msvc':
            ext.extra_compile_args += MSVC_EXTRA_COMPILE_ARGS
        elif self.compiler.compiler_type == 'mingw32':
            ext.extra_compile_args += MINGW_EXTRA_COMPILE_ARGS
        else:
            ext.extra_compile_args += CXX_EXTRA_COMPILE_ARGS

        build_ext.build_extension(self, ext)


COMMANDS = {
    'build_ext': BuildExt,
    'test': Test,
    'clean': Clean,
}


# SETUP
# -----

setup(name="uniprot_kb",
    version="0.0.1",
    packages=sorted(PACKAGES),
    description=SHORT_DESCRIPTION,
    long_description=LONG_DESCRIPTION,
    license="MIT",
    author="Alex Huszagh",
    author_email="ahuszagh@gmail.com",
    url='https://github.com/Alexhuszagh/uniprot_kb',
    ext_modules=EXTENSIONS,
    cmdclass=COMMANDS,
)
