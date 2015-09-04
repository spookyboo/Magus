QT += widgets

OGREHOME = "C:/Users/Henry/Documents/Visual Studio 2010/Projects/ogre1.9"


HEADERS       = \
    source/header/constants.h \
    source/header/mainwindow.h \
    source/header/renderer_dockwidget.h \ 
    source/header/editor_dockwidget.h \ 
    source/header/asset_dockwidget.h \ 
    source/header/ogre_renderman.h \ 
    source/header/ogre_prereqs.h \ 
    source/header/ogre_widget.h \ 
    source/header/ogre_cameraman.h \ 
    source/header/ogre_colouredrectangle.h \ 
    source/header/asset_assetwidget.h \ 
    source/header/asset_assetconstants.h \ 
    source/header/asset_clickableframe.h \ 
    source/header/asset_clickablelabel.h \ 
    source/header/asset_containerwidget.h \ 
    source/header/asset_propertywidget.h \ 
    source/header/asset_propertywidget_checkbox.h \ 
    source/header/asset_propertywidget_string.h \ 
    source/header/asset_propertywidget_xyz.h \ 
    source/header/asset_propertywidget_xy.h \ 
    source/header/asset_propertywidget_select.h \ 
    source/header/asset_propertywidget_slider.h \ 
    source/header/asset_propertywidget_decimal.h \ 
    source/header/asset_propertywidget_color.h \ 
    source/header/asset_propertywidget_texture.h \ 
    source/header/asset_propertywidget_curve.h \ 
    source/header/asset_curve_grid.h \ 
    source/header/asset_curve_dialog.h \ 
    source/header/asset_propertywidget_quaternion.h \ 
    source/header/node_connection.h \ 
    source/header/node_constants.h \ 
    source/header/node_editorwidget.h \ 
    source/header/node_node.h \ 
    source/header/node_porttype.h \ 
    source/header/node_port.h \ 
    source/header/sme_node_material.h \
    source/header/sme_node_pass.h \
    source/header/sme_node_technique.h \
    source/header/sme_node_texture_unit.h \
    source/header/sme_node_porttype.h \
    source/header/sme_asset_material.h \
    source/header/sme_asset_technique.h \
    source/header/sme_asset_pass.h \
    source/header/sme_asset_texture_unit.h \
    source/header/node_compound.h \
    source/header/node_scene.h \
    source/header/magus_core.h


SOURCES       = \
    source/src/main.cpp \
    source/src/mainwindow.cpp \
    source/src/renderer_dockwidget.cpp \ 
    source/src/editor_dockwidget.cpp \ 
    source/src/asset_dockwidget.cpp \ 
    source/src/ogre_renderman.cpp \ 
    source/src/ogre_widget.cpp \ 
    source/src/asset_assetwidget.cpp \ 
    source/src/asset_containerwidget.cpp \ 
    source/src/asset_propertywidget_checkbox.cpp \ 
    source/src/asset_propertywidget_string.cpp \ 
    source/src/asset_propertywidget_xyz.cpp \ 
    source/src/asset_propertywidget_xy.cpp \ 
    source/src/asset_propertywidget_select.cpp \ 
    source/src/asset_propertywidget_slider.cpp \ 
    source/src/asset_propertywidget_decimal.cpp \ 
    source/src/asset_propertywidget_color.cpp \ 
    source/src/asset_propertywidget_texture.cpp \ 
    source/src/asset_propertywidget_curve.cpp \ 
    source/src/asset_curve_grid.cpp \ 
    source/src/asset_curve_dialog.cpp \ 
    source/src/asset_propertywidget_quaternion.cpp \ 
    source/src/node_connection.cpp \ 
    source/src/node_node.cpp \ 
    source/src/node_editorwidget.cpp \ 
    source/src/node_porttype.cpp \ 
    source/src/node_port.cpp \ 
    source/src/sme_node_material.cpp \
    source/src/sme_node_pass.cpp \
    source/src/sme_node_technique.cpp \
    source/src/sme_node_texture_unit.cpp \
    source/src/sme_node_porttype.cpp \
    source/src/sme_asset_material.cpp \
    source/src/sme_asset_technique.cpp \
    source/src/sme_asset_pass.cpp \
    source/src/sme_asset_texture_unit.cpp \
    source/src/node_compound.cpp


INCLUDEPATH += "../SimpleMaterialEditor/source/header/"
INCLUDEPATH += "$$OGREHOME/OgreMain/include"
INCLUDEPATH += "$$OGREHOME/VCBuild/include"
INCLUDEPATH += .


Debug:LIBS += -L"$$OGREHOME/VCBuild/lib/Debug"
Release:LIBS += -L"$$OGREHOME/VCBuild/lib/Release"
CONFIG(debug, debug|release):LIBS *= -lOgreMain_d
CONFIG(release, debug|release):LIBS *= -lOgreMain


Release:DESTDIR = ../SimpleMaterialEditor/bin
Debug:DESTDIR = ../SimpleMaterialEditor/bin
target.path = $$[QTDIR]/
INSTALLS += target

