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
import sysconfig
import unittest

from setuptools import Command, Extension, setup
from setuptools.command.build_ext import build_ext

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
    'third_party/pycpp',
    'third_party/pycpp/third_party/warnings/src'
]

PYCPP_SOURCES = glob.glob('third_party/pycpp/**/*.cc')

# PACKAGING
# ---------

PACKAGE_NAME = "uniprot_kb"
EXTENSIONS = [
    Extension(name=PACKAGE_NAME,
        sources=[
            '{}/uniprot.pyx'.format(PACKAGE_NAME),
            'src/fasta.cc',
            'src/format.cc',
            'src/record.cc',
            'third_party/pycpp/pycpp/stream/fstream.cc',
        ],
        include_dirs=INCLUDE_DIRS,
        language='c++')
]

# COMMANDS
# --------

MSVC_EXTRA_COMPILE_ARGS = ['/EHsc', '/std:c++14', '/bigobj']
MINGW_EXTRA_COMPILE_ARGS = ['-static-libgcc', '-static-libstdc++', '-std=c++14', '-fpermissive']
CXX_EXTRA_COMPILE_ARGS = ['-std=c++14']


def distutils_build_dir(name):
    '''Get the distutils build directory'''

    platform = sysconfig.get_platform()
    version = sys.version_info
    return "{0}.{1}-{2[0]}.{2[1]}".format(name, platform, version)


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
            for file in glob.iglob(os.path.join(home, PACKAGE_NAME, pattern)):
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

        # get directories for test suite
        home = os.path.dirname(os.path.realpath(__file__))
        lib = distutils_build_dir("lib")
        directory = os.path.join(home, "build", lib)
        if not os.path.isdir(directory):
            print("Must build {} prior to testing.".format(PACKAGE_NAME))
            sys.exit(1)

        # run test suite
        sys.path.insert(0, directory)
        suite = unittest.TestLoader().discover(os.path.join(home, "test"))
        unittest.TextTestRunner(verbosity=2).run(suite)


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

setup(name=PACKAGE_NAME,
    version="0.0.1",
    description=SHORT_DESCRIPTION,
    long_description=LONG_DESCRIPTION,
    license="MIT",
    author="Alex Huszagh",
    author_email="ahuszagh@gmail.com",
    url='https://github.com/Alexhuszagh/{}'.format(PACKAGE_NAME),
    ext_modules=EXTENSIONS,
    cmdclass=COMMANDS,
)
