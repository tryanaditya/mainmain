# -*- coding: utf-8 -*-

# Resource object code
#
# Created: Sen Sep 26 20:57:20 2016
#      by: The Resource Compiler for PySide (Qt v4.8.7)
#
# WARNING! All changes made in this file will be lost!

from PySide import QtCore

qt_resource_data = b"\x00\x00\x06\xc8TEMPLATE = app\x0d\x0aLANGUAGE = C++\x0d\x0aTARGET         = assistant\x0d\x0a\x0d\x0aCONFIG        += qt warn_on\x0d\x0aQT            += xml network\x0d\x0a\x0d\x0aPROJECTNAME        = Assistant\x0d\x0aDESTDIR            = ../../bin\x0d\x0a\x0d\x0aFORMS += finddialog.ui \x5c\x0d\x0a        helpdialog.ui \x5c\x0d\x0a        mainwindow.ui \x5c\x0d\x0a        settingsdialog.ui \x5c\x0d\x0a        tabbedbrowser.ui \x5c\x0d\x0a        topicchooser.ui\x0d\x0a\x0d\x0aSOURCES += main.cpp \x5c\x0d\x0a        helpwindow.cpp \x5c\x0d\x0a        topicchooser.cpp \x5c\x0d\x0a        docuparser.cpp \x5c\x0d\x0a        settingsdialog.cpp \x5c\x0d\x0a        index.cpp \x5c\x0d\x0a        profile.cpp \x5c\x0d\x0a        config.cpp \x5c\x0d\x0a        finddialog.cpp \x5c\x0d\x0a        helpdialog.cpp \x5c\x0d\x0a        mainwindow.cpp \x5c\x0d\x0a        tabbedbrowser.cpp\x0d\x0a\x0d\x0aHEADERS        += helpwindow.h \x5c\x0d\x0a        topicchooser.h \x5c\x0d\x0a        docuparser.h \x5c\x0d\x0a        settingsdialog.h \x5c\x0d\x0a        index.h \x5c\x0d\x0a        profile.h \x5c\x0d\x0a        finddialog.h \x5c\x0d\x0a        helpdialog.h \x5c\x0d\x0a        mainwindow.h \x5c\x0d\x0a        tabbedbrowser.h \x5c\x0d\x0a        config.h\x0d\x0a\x0d\x0aRESOURCES += assistant.qrc\x0d\x0a\x0d\x0aDEFINES += QT_KEYWORDS\x0d\x0a#DEFINES +=  QT_PALMTOPCENTER_DOCS\x0d\x0a!network:DEFINES        += QT_INTERNAL_NETWORK\x0d\x0aelse:QT += network\x0d\x0a!xml: DEFINES                += QT_INTERNAL_XML\x0d\x0aelse:QT += xml\x0d\x0ainclude( ../../src/qt_professional.pri )\x0d\x0a\x0d\x0awin32 {\x0d\x0a    LIBS += -lshell32\x0d\x0a    RC_FILE = assistant.rc\x0d\x0a}\x0d\x0a\x0d\x0amac {\x0d\x0a    ICON = assistant.icns\x0d\x0a    TARGET = assistant\x0d\x0a#    QMAKE_INFO_PLIST = Info_mac.plist\x0d\x0a}\x0d\x0a\x0d\x0a#target.path = $$[QT_INSTALL_BINS]\x0d\x0a#INSTALLS += target\x0d\x0a\x0d\x0a#assistanttranslations.files = *.qm\x0d\x0a#assistanttranslations.path = $$[QT_INSTALL_TRANSLATIONS]\x0d\x0a#INSTALLS += assistanttranslations\x0d\x0a\x0d\x0aTRANSLATIONS        = assistant_de.ts \x5c\x0d\x0a                  assistant_fr.ts\x0d\x0a\x0d\x0a\x0d\x0aunix:!contains(QT_CONFIG, zlib):LIBS += -lz\x0d\x0a\x0d\x0a\x0d\x0atarget.path=$$[QT_INSTALL_BINS]\x0d\x0aINSTALLS += target\x0d\x0a"
qt_resource_name = b"\x00\x08\x0e\x84\x7fC\x00e\x00x\x00a\x00m\x00p\x00l\x00e\x00s\x00\x07\x0c\xe8G\xe5\x00e\x00x\x00a\x00m\x00p\x00l\x00e"
qt_resource_struct = b"\x00\x00\x00\x00\x00\x02\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x00\x00\x02\x00\x00\x00\x01\x00\x00\x00\x02\x00\x00\x00\x16\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00"
def qInitResources():
    QtCore.qRegisterResourceData(0x01, qt_resource_struct, qt_resource_name, qt_resource_data)

def qCleanupResources():
    QtCore.qUnregisterResourceData(0x01, qt_resource_struct, qt_resource_name, qt_resource_data)

qInitResources()
