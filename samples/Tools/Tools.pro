QT += widgets



HEADERS       = \
    source/header/constants.h \
    source/header/mainwindow.h \
    source/header/tool_gradientwidget.h \
    source/header/tool_texturewidget.h \
    source/header/tool_texturemodel.h \
    source/header/generic_funtions.h \
    source/header/tool_gradientmarker.h \
    source/header/tool_gradient.h \
    source/header/tool_layerwidget.h \
    source/header/tool_sceneviewwidget.h \
    source/header/tool_layered_sceneviewwidget.h


SOURCES       = \
    source/src/main.cpp \
    source/src/mainwindow.cpp \
    source/src/tool_gradientwidget.cpp \
    source/src/tool_texturewidget.cpp \
    source/src/tool_texturemodel.cpp \
    source/src/tool_gradientmarker.cpp \
    source/src/tool_gradient.cpp \
    source/src/tool_layerwidget.cpp \
    source/src/tool_sceneviewwidget.cpp \
    source/src/tool_layered_sceneviewwidget.cpp


INCLUDEPATH += "../Tools/source/header/"




Release:DESTDIR = ../Tools/bin
Debug:DESTDIR = ../Tools/bin
target.path = $$[QTDIR]/
INSTALLS += target
