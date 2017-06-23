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
    'third_party/lattice/include',
    'third_party/crosscxx/src',
]
SWIG_OPTS = [
    '-modern',
    '-Isrc',
    '-c++',
# -builtin causes relative import errors, since it
# conflicts with -relativeimport
#    '-builtin',
    '-relativeimport'
]

# PACKAGING
# ---------


def pack_extensions(names):
    '''Pack extension names to Extension objects'''

    extensions = []
    py_modules = []
    for module, sources, extras in names:
        py_modules.append("uniprot_kb.{}".format(module))
        extension = Extension("uniprot_kb._{}".format(module),
            sources=sources,
            swig_opts=SWIG_OPTS,
            include_dirs=INCLUDE_DIRS,
            language='c++')
        extensions.append(extension)

    return extensions, py_modules


EXTENSION_NAMES = [
    ('record',
        ['uniprot_kb/record.i',
         'src/record.cc',
         'src/fasta.cc',
         'src/xml.cc',
         'src/txt.cc',
         'third_party/crosscxx/src/getline.cc'],
        []),
]
EXTENSIONS, PY_MODULES = pack_extensions(EXTENSION_NAMES)

# COMMANDS
# --------

MSVC_EXTRA_COMPILE_ARGS = ['/EHsc', '/std:c++14', '/bigobj']
MINGW_EXTRA_COMPILE_ARGS = ['-static-libgcc', '-static-libstdc++', '-std=c++14', '-fpermissive']
CXX_EXTRA_COMPILE_ARGS = ['-std=c++14']


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


class Test(test):
    '''Override test args to ensure unittests are discovered.'''

    def _test_args(self):
        yield 'discover'
        for arg in test._test_args(self):
            yield arg


class Clean(Command):
    '''Test built libraries'''

    description = "Clean build objects"
    user_options = []

    def initialize_options(self):
        '''Initialize and finalize no optional arguments'''

    def finalize_options(self):
        '''Initialize and finalize no optional arguments'''

    def run(self):
        '''Run test suite'''

        self.clean_build()
        self.clean_dist()
        self.clean_swig()
        self.clean_egg()

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

    def clean_swig(self):
        '''Clean SWIG intermediate files'''

        home = os.path.dirname(os.path.realpath(__file__))
        for pattern in ['*.h', '*.c', '*.cpp', '*.py']:
            for file in glob.iglob(os.path.join(home, 'uniprot_kb', pattern)):
                if not file.endswith('__init__.py'):
                    os.remove(file)

    def clean_egg(self):
        '''Clean egg-info and egg packaging'''

        home = os.path.dirname(os.path.realpath(__file__))
        egg_info = os.path.join(home, '{}.egg-info'.format(NAME))
        if os.path.exists(egg_info):
            shutil.rmtree(egg_info)


COMMANDS = {
    'build_ext': BuildExt,
    'test': Test,
    'clean': Clean,
}


# SETUP
# -----

setup(name="uniprot_kb",
    version="0.0.1",
    packages=[NAME],
    description=SHORT_DESCRIPTION,
    long_description=LONG_DESCRIPTION,
    license="MIT",
    author="Alex Huszagh",
    author_email="ahuszagh@gmail.com",
    url='https://github.com/Alexhuszagh/uniprot_kb',
    ext_modules=EXTENSIONS,
    py_modules=PY_MODULES,
    cmdclass=COMMANDS,
)
