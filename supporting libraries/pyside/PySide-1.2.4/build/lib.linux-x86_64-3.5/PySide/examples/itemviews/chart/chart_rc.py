# -*- coding: utf-8 -*-

# Resource object code
#
# Created: Sen Sep 26 20:57:20 2016
#      by: The Resource Compiler for PySide (Qt v4.8.7)
#
# WARNING! All changes made in this file will be lost!

from PySide import QtCore

qt_resource_data = b"\x00\x00\x01\x9eScientific Research,21,#99e600\x0d\x0aEngineering & Design,18,#99cc00\x0d\x0aAutomotive,14,#99b300\x0d\x0aAerospace,13,#9f991a\x0d\x0aAutomation & Machine Tools,13,#a48033\x0d\x0aMedical & Bioinformatics,13,#a9664d\x0d\x0aImaging & Special Effects,12,#ae4d66\x0d\x0aDefense,11,#b33380\x0d\x0aTest & Measurement Systems,9,#a64086\x0d\x0aOil & Gas,9,#994d8d\x0d\x0aEntertainment & Broadcasting,7,#8d5a93\x0d\x0aFinancial,6,#806699\x0d\x0aConsumer Electronics,4,#8073a6\x0d\x0aOther,38,#8080b3\x0d\x0a"
qt_resource_name = b"\x00\x06\x04\x9e\x89\xb3\x00C\x00h\x00a\x00r\x00t\x00s\x00\x0a\x08\xaf\x5c\xb4\x00q\x00t\x00d\x00a\x00t\x00a\x00.\x00c\x00h\x00t"
qt_resource_struct = b"\x00\x00\x00\x00\x00\x02\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x00\x00\x02\x00\x00\x00\x01\x00\x00\x00\x02\x00\x00\x00\x12\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00"
def qInitResources():
    QtCore.qRegisterResourceData(0x01, qt_resource_struct, qt_resource_name, qt_resource_data)

def qCleanupResources():
    QtCore.qUnregisterResourceData(0x01, qt_resource_struct, qt_resource_name, qt_resource_data)

qInitResources()
