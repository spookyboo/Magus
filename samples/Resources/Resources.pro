QT += widgets
QT += multimedia

HEADERS       = \
    source/header/constants.h \
    source/header/mainwindow.h \
    source/header/dock1_dockwidget.h \ 
    source/header/dock2_dockwidget.h \
    source/header/tool_resourcetree_widget.h \
    source/header/tool_default_texturewidget.h \
    source/header/tool_filereader.h \
    source/header/tool_audiowidget.h \
    source/header/magus_core.h \
    source/header/magus_treewidget.h \
    source/header/tool_resourcewidget.h \
    source/header/tool_resourcewidget_sources.h \
    source/header/tool_resourcewidget_collections.h \
    source/header/tool_resourcewidget_assets.h \
    source/header/tool_resourcewidget_main.h \
    source/header/tool_generic_assetwidget.h \

SOURCES       = \
    source/src/main.cpp \
    source/src/mainwindow.cpp \
    source/src/dock1_dockwidget.cpp \ 
    source/src/dock2_dockwidget.cpp \ 
    source/src/tool_resourcetree_widget.cpp \
    source/src/tool_default_texturewidget.cpp \
    source/src/tool_filereader.cpp \
    source/src/tool_audiowidget.cpp \
    source/src/magus_treewidget.cpp \
    source/src/tool_resourcewidget.cpp \
    source/src/tool_resourcewidget_assets.cpp \
    source/src/tool_resourcewidget_sources.cpp \
    source/src/tool_resourcewidget_collections.cpp \
    source/src/tool_resourcewidget_main.cpp \
    source/src/tool_generic_assetwidget.cpp

INCLUDEPATH += "../Resources/source/header/"

Release:DESTDIR = ../Resources/bin
Debug:DESTDIR = ../Resources/bin
target.path = $$[QTDIR]/
INSTALLS += target

