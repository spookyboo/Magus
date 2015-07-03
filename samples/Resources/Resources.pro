QT += widgets



HEADERS       = \
    source/header/constants.h \
    source/header/mainwindow.h \
    source/header/dock1_dockwidget.h \ 
    source/header/dock2_dockwidget.h \ 
    source/header/dock3_dockwidget.h \  
    source/header/tool_resourcetree_widget.h \
    source/header/tool_default_texturewidget.h \
    source/header/tool_filereader.h \
    source/header/magus_treewidget.h


SOURCES       = \
    source/src/main.cpp \
    source/src/mainwindow.cpp \
    source/src/dock1_dockwidget.cpp \ 
    source/src/dock2_dockwidget.cpp \ 
    source/src/dock3_dockwidget.cpp \  
    source/src/tool_resourcetree_widget.cpp \
    source/src/tool_default_texturewidget.cpp \
    source/src/tool_filereader.cpp \
    source/src/magus_treewidget.cpp


INCLUDEPATH += "../Resources/source/header/"




Release:DESTDIR = ../Resources/bin
Debug:DESTDIR = ../Resources/bin
target.path = $$[QTDIR]/
INSTALLS += target

