__all__ = []

from .tools import *
from . import tools
__all__ += tools.__all__

from . import linpred
from .linpred import *
__all__ += linpred.__all__

from . import version

from numpy.testing import Tester

test = Tester().test
bench = Tester().bench
