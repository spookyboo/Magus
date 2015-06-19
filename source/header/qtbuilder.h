/****************************************************************************
**
** Copyright (C) 2015
**
** This file is part of the Magus toolkit
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
****************************************************************************/

#ifndef MAGUS_QTBUILDER_H
#define MAGUS_QTBUILDER_H

#include "builder.h"

//****************************************************************************/
// Keywords in configuration file
static const QString CONFIG_KEY_QTH_DIR = QString("qt_header_dir");
static const QString CONFIG_KEY_QTSRC_DIR = QString("qt_src_dir");

//****************************************************************************/
// Filenames - DLLs
static const QString FILE_QT_DLL_CORE = QString("Qt5Core.dll");
static const QString FILE_QT_DLL_WIDGETS = QString("Qt5Widgets.dll");
static const QString FILE_QT_DLL_GUI = QString("Qt5Gui.dll");
static const QString FILE_QT_DLL_ICUDT = QString("icudt52.dll");
static const QString FILE_QT_DLL_ICUIN = QString("icuin52.dll");
static const QString FILE_QT_DLL_ICUUC = QString("icuuc52.dll");
static const QString FILE_QT_DLL_WINDOWS = QString("qwindows.dll");
static const QString PATH_QT_DLL_WINDOWS = QString("platforms/");

// Core source files
static const QString FILE_MAIN_CTP = QString("main.ctp");
static const QString FILE_MAIN_CPP = QString("main.cpp");
static const QString FILE_CONSTANTS_HTP = QString("constants.htp");
static const QString FILE_CONSTANTS_H = QString("constants.h");
static const QString FILE_MAINWINDOW_CTP = QString("mainwindow.ctp");
static const QString FILE_MAINWINDOW_CPP = QString("mainwindow.cpp");
static const QString FILE_MAINWINDOW_HTP = QString("mainwindow.htp");
static const QString FILE_MAINWINDOW_H = QString("mainwindow.h");
static const QString FILE_PROJECT_PTP = QString("project.ptp");
static const QString FILE_DOCKWIDGET_HTP = QString("dockwidget.htp");
static const QString FILE_DOCKWIDGET_CTP = QString("dockwidget.ctp");
static const QString FILE_GENERIC_FUNCTIONS_H = QString("generic_funtions.h");
static const QString FILE_TRANSFORMATION_WIDGET_H = QString("tb_transformationwidget.h");
static const QString FILE_TRANSFORMATION_WIDGET_CPP = QString("tb_transformationwidget.cpp");

// Asset filenames
static const QString FILE_ASSET_CONSTANTS_H = QString("asset_assetconstants.h");
static const QString FILE_ASSET_H = QString("asset_assetwidget.h");
static const QString FILE_ASSET_CLICKABLE_FRAME_H = QString("asset_clickableframe.h");
static const QString FILE_ASSET_CLICKABLE_LABEL_H = QString("asset_clickablelabel.h");
static const QString FILE_ASSET_CONTAINER_H = QString("asset_containerwidget.h");
static const QString FILE_ASSET_PROPERTY_H = QString("asset_propertywidget.h");
static const QString FILE_ASSET_PROPERTY_CHECKBOX_H = QString("asset_propertywidget_checkbox.h");
static const QString FILE_ASSET_PROPERTY_STRING_H = QString("asset_propertywidget_string.h");
static const QString FILE_ASSET_PROPERTY_XYZ_H = QString("asset_propertywidget_xyz.h");
static const QString FILE_ASSET_PROPERTY_XY_H = QString("asset_propertywidget_xy.h");
static const QString FILE_ASSET_PROPERTY_SELECT_H = QString("asset_propertywidget_select.h");
static const QString FILE_ASSET_PROPERTY_SLIDER_H = QString("asset_propertywidget_slider.h");
static const QString FILE_ASSET_PROPERTY_DECIMAL_H = QString("asset_propertywidget_decimal.h");
static const QString FILE_ASSET_PROPERTY_COLOR_H = QString("asset_propertywidget_color.h");
static const QString FILE_ASSET_PROPERTY_TEXTURE_H = QString("asset_propertywidget_texture.h");
static const QString FILE_ASSET_PROPERTY_CURVE_H = QString("asset_propertywidget_curve.h");
static const QString FILE_ASSET_PROPERTY_QUATERNION_H = QString("asset_propertywidget_quaternion.h");
static const QString FILE_ASSET_CURVE_GRID_H = QString("asset_curve_grid.h");
static const QString FILE_ASSET_CURVE_DIALOG_H = QString("asset_curve_dialog.h");

static const QString FILE_ASSET_CPP = QString("asset_assetwidget.cpp");
static const QString FILE_ASSET_CONTAINER_CPP = QString("asset_containerwidget.cpp");
static const QString FILE_ASSET_PROPERTY_CHECKBOX_CPP = QString("asset_propertywidget_checkbox.cpp");
static const QString FILE_ASSET_PROPERTY_STRING_CPP = QString("asset_propertywidget_string.cpp");
static const QString FILE_ASSET_PROPERTY_XYZ_CPP = QString("asset_propertywidget_xyz.cpp");
static const QString FILE_ASSET_PROPERTY_XY_CPP = QString("asset_propertywidget_xy.cpp");
static const QString FILE_ASSET_PROPERTY_SELECT_CPP = QString("asset_propertywidget_select.cpp");
static const QString FILE_ASSET_PROPERTY_SLIDER_CPP = QString("asset_propertywidget_slider.cpp");
static const QString FILE_ASSET_PROPERTY_DECIMAL_CPP = QString("asset_propertywidget_decimal.cpp");
static const QString FILE_ASSET_PROPERTY_COLOR_CPP = QString("asset_propertywidget_color.cpp");
static const QString FILE_ASSET_PROPERTY_TEXTURE_CPP = QString("asset_propertywidget_texture.cpp");
static const QString FILE_ASSET_PROPERTY_CURVE_CPP = QString("asset_propertywidget_curve.cpp");
static const QString FILE_ASSET_PROPERTY_QUATERNION_CPP = QString("asset_propertywidget_quaternion.cpp");
static const QString FILE_ASSET_CURVE_GRID_CPP = QString("asset_curve_grid.cpp");
static const QString FILE_ASSET_CURVE_DIALOG_CPP = QString("asset_curve_dialog.cpp");

// Ogre asset filenames
static const QString FILE_OGRE_ASSET_CAMERA_H = QString("ogre_asset_camera.h");
static const QString FILE_OGRE_ASSET_CAMERA_CPP = QString("ogre_asset_camera.cpp");
static const QString FILE_OGRE_ASSET_ENTITY_H = QString("ogre_asset_entity.h");
static const QString FILE_OGRE_ASSET_ENTITY_CPP = QString("ogre_asset_entity.cpp");
static const QString FILE_OGRE_ASSET_MATERIAL_H = QString("ogre_asset_material.h");
static const QString FILE_OGRE_ASSET_MATERIAL_CPP = QString("ogre_asset_material.cpp");
static const QString FILE_OGRE_ASSET_LIGHT_H = QString("ogre_asset_light.h");
static const QString FILE_OGRE_ASSET_LIGHT_CPP = QString("ogre_asset_light.cpp");

// Ogre filenames
static const QString FILE_OGRE_WIDGET_PREREQ_H = QString("ogre_prereqs.h");
static const QString FILE_OGRE_WIDGET_H = QString("ogre_widget.h");
static const QString FILE_OGRE_WIDGET_CAMERAMAN_H = QString("ogre_cameraman.h");
static const QString FILE_OGRE_WIDGET_COLRECT_H = QString("ogre_colouredrectangle.h");
static const QString FILE_OGRE_WIDGET_CPP = QString("ogre_widget.cpp");
static const QString FILE_OGRE_RENDERMAN_H = QString("ogre_renderman.h");
static const QString FILE_OGRE_RENDERMAN_CPP = QString("ogre_renderman.cpp");

// Node filenames
static const QString FILE_NODE_COMPOUND_H = QString("node_compound.h");
static const QString FILE_NODE_CONNECTION_H = QString("node_connection.h");
static const QString FILE_NODE_CONSTANTS_H = QString("node_constants.h");
static const QString FILE_NODE_EDITOR_WIDGET_H = QString("node_editorwidget.h");
static const QString FILE_NODE_H = QString("node_node.h");
static const QString FILE_NODE_PORT_H = QString("node_port.h");
static const QString FILE_NODE_PORTTYPE_H = QString("node_porttype.h");
static const QString FILE_NODE_SCENE_H = QString("node_scene.h");
static const QString FILE_NODE_COMPOUND_CPP = QString("node_compound.cpp");
static const QString FILE_NODE_CONNECTION_CPP = QString("node_connection.cpp");
static const QString FILE_NODE_EDITOR_WIDGET_CPP = QString("node_editorwidget.cpp");
static const QString FILE_NODE_CPP = QString("node_node.cpp");
static const QString FILE_NODE_PORT_CPP = QString("node_port.cpp");
static const QString FILE_NODE_PORTTYPE_CPP = QString("node_porttype.cpp");

// Tool filenames
static const QString FILE_TOOL_GRADIENT_H = QString("tool_gradient.h");
static const QString FILE_TOOL_GRADIENT_CPP = QString("tool_gradient.cpp");
static const QString FILE_TOOL_GRADIENT_MARKER_H = QString("tool_gradientmarker.h");
static const QString FILE_TOOL_GRADIENT_MARKER_CPP = QString("tool_gradientmarker.cpp");
static const QString FILE_TOOL_GRADIENT_WIDGET_H = QString("tool_gradientwidget.h");
static const QString FILE_TOOL_GRADIENT_WIDGET_CPP = QString("tool_gradientwidget.cpp");
static const QString FILE_TOOL_TEXTURE_MODEL_H = QString("tool_texturemodel.h");
static const QString FILE_TOOL_TEXTURE_MODEL_CPP = QString("tool_texturemodel.cpp");
static const QString FILE_TOOL_TEXTURE_WIDGET_H = QString("tool_texturewidget.h");
static const QString FILE_TOOL_TEXTURE_WIDGET_CPP = QString("tool_texturewidget.cpp");
static const QString FILE_TOOL_SCENE_WIDGET_H = QString("tool_sceneviewwidget.h");
static const QString FILE_TOOL_SCENE_WIDGET_CPP = QString("tool_sceneviewwidget.cpp");
static const QString FILE_TOOL_LAYERED_SCENE_WIDGET_H = QString("tool_layered_sceneviewwidget.h");
static const QString FILE_TOOL_LAYERED_SCENE_WIDGET_CPP = QString("tool_layered_sceneviewwidget.cpp");
static const QString FILE_TOOL_LAYER_WIDGET_H = QString("tool_layerwidget.h");
static const QString FILE_TOOL_LAYER_WIDGET_CPP = QString("tool_layerwidget.cpp");
static const QString FILE_TOOL_GL_SPHERE_WIDGET_H = QString("tool_glspherewidget.h");
static const QString FILE_TOOL_GL_SPHERE_WIDGET_CPP = QString("tool_glspherewidget.cpp");
static const QString FILE_TOOL_FILEREADER_H = QString("tool_filereader.h");
static const QString FILE_TOOL_FILEREADER_CPP = QString("tool_filereader.cpp");
static const QString FILE_TOOL_TEXTURE_WIDGET_EXT_H = QString("tool_texturewidget_ext.h");
static const QString FILE_TOOL_TEXTURE_WIDGET_EXT_CPP = QString("tool_texturewidget_ext.cpp");

//****************************************************************************/
// References for project.ptp
static const QString PROJECT_MODULES = QString("${modules}");
static const QString PROJECT_OGRE_ROOT = QString("${ogre_root}");
static const QString PROJECT_OGRE_INCLUDE = QString("${include_ogre}");
static const QString PROJECT_OGRE_LIB = QString("${lib_ogre}");
static const QString PROJECT_HEADER = QString("${project.header}");
static const QString PROJECT_SRC = QString("${project.src}");
static const QString PROJECT_PROJECT = QString("${project.project}");
static const QString PROJECT_ADDITIONAL_HEADER = QString("${project.additionalheader}");
static const QString PROJECT_ADDITIONAL_SRC = QString("${project.additionalsrc}");

//****************************************************************************/
// References for mainwindow.ctp
static const QString MAINWINDOW_INCLUDES = QString("${mainwindow.includes}");
static const QString MAINWINDOW_TITLE = QString("${MainWindow::MainWindow.title}");
static const QString MAINWINDOW_STYLE = QString("${MainWindow::MainWindow.style}");
static const QString MAINWINDOW_MAINWINDOW = QString("${MainWindow::MainWindow}");
static const QString MAINWINDOW_CREATEACTIONS = QString("${MainWindow::createActions}");
static const QString MAINWINDOW_CREATEMENUS = QString("${MainWindow::createMenus}");
static const QString MAINWINDOW_CREATETOOLBARS = QString("${MainWindow::createToolBars}");
static const QString MAINWINDOW_CREATETOOLBARS_E = QString("${MainWindow::createToolBars}");
static const QString MAINWINDOW_CREATESTATUSBAR = QString("${MainWindow::createStatusBar}");
static const QString MAINWINDOW_CREATEDOCKWINDOWS = QString("${MainWindow::createDockWindows}");
static const QString MAINWINDOW_DO_ACTIONS = QString("${MainWindow::doActions}");
static const QString MAINWINDOW_QT_NAMESPACE = QString("${MainWindow.qt.namespace}");
static const QString MAINWINDOW_PUBLIC = QString("${MainWindow.public}");
static const QString MAINWINDOW_PRIVATE_SLOTS = QString("${MainWindow.private_slots}");
static const QString MAINWINDOW_PRIVATE = QString("${MainWindow.private}");
static const QString MAINWINDOW_OGRE_CONSTRUCTOR = QString("${MainWindow::ogreConstructor}");
static const QString MAINWINDOW_OGRE_DESTRUCTOR = QString("${MainWindow::ogreDestructor}");
static const QString MAINWINDOW_OGRE_UPDATE = QString("${MainWindow::ogreUpdate}");
static const QString MAINWINDOW_OGRE_CREATE_WIDGET = QString("${MainWindow::createOgreWidget}");

//****************************************************************************/
// References for dockwidget.htp
static const QString DOCKWIDGET_TITLE = QString("${dockwidget.title}");
static const QString DOCKWIDGET_INCLUDES = QString("${dockwidget.include}");
static const QString DOCKWIDGET_PRIVATE = QString("${dockwidget.private}");
static const QString DOCKWIDGET_PRIVATE_SLOTS = QString("${dockwidget.private_slots}");

//****************************************************************************/
// References for dockwidget.ctp
static const QString DOCKWIDGET_CONSTRUCTOR = QString("${dockwidget.constructor}");
static const QString DOCKWIDGET_CREATE_ACTIONS = QString("${dockwidget.createActions}");
static const QString DOCKWIDGET_CREATE_MENUS = QString("${dockwidget.createMenus}");
static const QString DOCKWIDGET_CREATE_TOOLBARS = QString("${dockwidget.createToolBars}");
static const QString DOCKWIDGET_DO_ACTIONS = QString("${dockwidget::doActions}");
static const QString DOCKWIDGET_OGRE_CREATE_WIDGET = QString("${dockwidget::createOgreWidget}");
static const QString DOCKWIDGET_CONSTRUCTOR_END = QString("${dockwidget.constructorend}");

//****************************************************************************/
// Miscellanious
static const QString KEYWORD_ICON_SEPARATOR1 = QString("separator_vertical.png");
static const QString KEYWORD_ICON_SEPARATOR2 = QString("separator_horizontal.png");
static const QString POST_ACTION_HTOOLBAR = QString("HToolbarAction");
static const QString POST_ACTION_VTOOLBAR = QString("VToolbarAction");

/****************************************************************************
 Implementation of a builder class for Qt.
****************************************************************************/
class WindowProperties;
class WindowMenuProperties;
class ToolbarProperties;

class QtBuilder : public Builder
{
    public:
        QtBuilder();
        virtual ~QtBuilder();

        const QString getType(void) const {return BUILDER_TYPE_QT;};
        void setOutputDir (const QString& outputDir);
        void setOgre (const QString& ogreRootEnv, const QString& ogreRoot);
        bool isMenuAvailable(){return true;};
        bool isHorizontalToolbarAvailable(){return true;};
        bool isVerticalToolbarAvailable(){return true;};
        bool isOgre3dControlAvailable(){return true;};
        void build(ApplicationTemplate* applicationTemplate);

    private:
        // Main functions
        QString createGenericPrivateMembers(WindowProperties* windowProperties, QString &s);
        QString createConstructor(QString &s);

        // Helper functions
        QString createTransformationWidgetHeaderForPro(const QString& additionalHeader);
        QString createTransformationWidgetSrcForPro(const QString& additionalSrc);
        QString createAssetHeaderForPro(const QString& additionalHeader);
        QString createAssetSrcForPro(const QString& additionalSrc);
        QString createNodeHeaderForPro(const QString& additionalHeader);
        QString createNodeSrcForPro(const QString& additionalSrc);
        QString createToolHeaderForPro(const QString& additionalHeader);
        QString createToolSrcForPro(const QString& additionalSrc);

        QString mIconDir;
        QString mQtDir;
        QString mQtHeader;
        QString mQtSrc;
        QString mOutputDir;
        QString mOutputBinDir;
        QString mOutputIconDir;
        QString mOutputHeaderDir;
        QString mOutputSrcDir;
        QString mOutputOgreDir;
        QString mOgreDir;
        QString mOgreRoot;
        QString mCurrentProject;
        QString mCurrentProjectSlash;
        QString mFullOutputHeaderDir;
        QString mFullOutputBinDir;
        QString mFullOutputIconDir;
        QString mFullOutputSrcDir;
        QString mFullOutputOgreDir;
};

//****************************************************************************/
#endif
