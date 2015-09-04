QT += widgets opengl

HEADERS       = \
    source/header/constants.h \
    source/header/mainwindow.h \
    source/header/tool_gradientwidget.h \
    source/header/tool_gradientmarker.h \
    source/header/tool_gradient.h \
    source/header/tool_layerwidget.h \
    source/header/tool_sceneviewwidget.h \
    source/header/tool_layered_sceneviewwidget.h \
    source/header/tool_filereader.h \
    source/header/tool_glspherewidget.h \
    source/header/tool_simple_texturemodel.h \
    source/header/tool_simple_texturewidget.h \
    source/header/tool_extended_texturewidget.h \
    source/header/magus_core.h


SOURCES       = \
    source/src/main.cpp \
    source/src/mainwindow.cpp \
    source/src/tool_gradientwidget.cpp \
    source/src/tool_gradientmarker.cpp \
    source/src/tool_gradient.cpp \
    source/src/tool_layerwidget.cpp \
    source/src/tool_sceneviewwidget.cpp \
    source/src/tool_layered_sceneviewwidget.cpp \
    source/src/tool_filereader.cpp \
    source/src/tool_glspherewidget.cpp \
    source/src/tool_simple_texturemodel.cpp \
    source/src/tool_simple_texturewidget.cpp \
    source/src/tool_extended_texturewidget.cpp


INCLUDEPATH += "../Tools/source/header/"

Release:DESTDIR = ../Tools/bin
Debug:DESTDIR = ../Tools/bin
target.path = $$[QTDIR]/
INSTALLS += target

