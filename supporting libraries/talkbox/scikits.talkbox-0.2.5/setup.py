#! /usr/bin/env python
# Last Change: Thu Mar 26 06:00 PM 2009 J

# Copyright (C) 2008 Cournapeau David <cournape@gmail.com>

import os
import sys

import setuptools
from numpy.distutils.core import setup

from common import *

def configuration(parent_package='', top_path=None, package_name=DISTNAME):
    if os.path.exists('MANIFEST'): os.remove('MANIFEST')

    write_info(os.path.join("scikits", "talkbox", "info.py"))
    write_version(os.path.join("scikits", "talkbox", "version.py"))
    # XXX: find a way to include the doc in sdist
    if os.path.exists(os.path.join("docs", "src")):
        write_version(os.path.join("docs", "src", "talkbox_version.py"))
    pkg_prefix_dir = os.path.join('scikits', 'talkbox')

    from numpy.distutils.misc_util import Configuration
    config = Configuration(None, parent_package, top_path,
        namespace_packages = ['scikits'])

    config.set_options(
                ignore_setup_xxx_py=True,
                assume_default_configuration=True,
                delegate_options_to_subpackages=True,
                quiet=True,
    )

    config.add_subpackage('scikits')
    config.add_subpackage(DISTNAME)
    config.add_data_files('scikits/__init__.py')

    return config

if __name__ == "__main__":
    setup(configuration = configuration,
        install_requires = 'numpy',
        packages = setuptools.find_packages(),
        include_package_data = True,
        name = DISTNAME,
        version = VERSION,
        description = DESCRIPTION,
        long_description = LONG_DESCRIPTION,
        license = LICENSE,
        #test_suite="tester", # for python setup.py test
        zip_safe = False, # because of tests
        classifiers = CLASSIFIERS,
    )
