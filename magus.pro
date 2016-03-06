QT += widgets

HEADERS       = \
    source/header/builder.h \
    source/header/constants.h \
    source/header/customtreeitem.h \
    source/header/customtreemodel.h \
    source/header/generaltab.h \
    source/header/mainwindow.h \
    source/header/qtbuilder.h \
    source/header/templatedialog.h \
    source/header/templatereader.h \
    source/header/windowtab.h \
    source/header/wxwidgetsbuilder.h \
    source/header/bin.h \
    source/header/templatewriter.h \
    source/header/applicationtemplate.h \
    source/header/utils.h \
    source/header/customtabwidget.h \
    source/header/application.h \
    source/header/iconcombobox.h \
    source/header/iconreader.h \
    source/header/iconmodel.h \
    source/header/icondialog.h \
    source/header/namedicon.h \
    source/header/qtbuildermenu.h \
    source/header/qtbuilderaction.h \
    source/header/qtbuildertoolbar.h \
    source/header/qtbuildertab.h \
    source/header/qtbuilderogre.h \
    source/header/configdialog.h \
    source/header/pages.h \
    source/header/qtbuilderogre19.h \
    source/header/qtbuilderogre20.h \
    source/header/qtbuilderogre21.h

SOURCES       = \
    source/src/customtreeitem.cpp \
    source/src/customtreemodel.cpp \
    source/src/generaltab.cpp \
    source/src/main.cpp \
    source/src/mainwindow.cpp \
    source/src/qtbuilder.cpp \
    source/src/templatedialog.cpp \
    source/src/templatereader.cpp \
    source/src/windowtab.cpp \
    source/src/wxwidgetsbuilder.cpp \
    source/src/bin.cpp \
    source/src/applicationtemplate.cpp \
    source/src/utils.cpp \
    source/src/customtabwidget.cpp \
    source/src/iconcombobox.cpp \
    source/src/iconreader.cpp \
    source/src/iconmodel.cpp \
    source/src/icondialog.cpp \
    source/src/templatewriter.cpp \
    source/src/qtbuildermenu.cpp \
    source/src/qtbuilderaction.cpp \
    source/src/qtbuildertoolbar.cpp \
    source/src/qtbuildertab.cpp \
    source/src/configdialog.cpp \
    source/src/pages.cpp \
    source/src/qtbuilderogre19.cpp \
    source/src/qtbuilderogre20.cpp \
    source/src/qtbuilderogre.cpp \
    source/src/qtbuilderogre21.cpp

Release:DESTDIR = ../Magus/bin
Debug:DESTDIR = ../Magus/bin
target.path = $$[QTDIR]/
INSTALLS += target

INCLUDEPATH += "../magus/source/header/"
