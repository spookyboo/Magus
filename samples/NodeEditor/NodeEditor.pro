QT += widgets



HEADERS       = \
    source/header/constants.h \
    source/header/mainwindow.h \
    source/header/node_compound.h \ 
    source/header/node_connection.h \ 
    source/header/node_constants.h \ 
    source/header/node_editorwidget.h \ 
    source/header/node_node.h \ 
    source/header/node_porttype.h \ 
    source/header/node_port.h \ 
    source/header/node_scene.h \ 


SOURCES       = \
    source/src/main.cpp \
    source/src/mainwindow.cpp \
    source/src/node_compound.cpp \ 
    source/src/node_connection.cpp \ 
    source/src/node_node.cpp \ 
    source/src/node_editorwidget.cpp \ 
    source/src/node_porttype.cpp \ 
    source/src/node_port.cpp \ 


INCLUDEPATH += "../NodeEditor/source/header/"




Release:DESTDIR = ../NodeEditor/bin
Debug:DESTDIR = ../NodeEditor/bin
target.path = $$[QTDIR]/
INSTALLS += target

