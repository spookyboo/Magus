/****************************************************************************
**
** Copyright (C) 2014
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

#ifndef MAGUS_CONSTANTS_H
#define MAGUS_CONSTANTS_H

#include <QString>

//****************************************************************************/
// Builder types
static const QString BUILDER_TYPE_QT = QString("qt");
static const QString BUILDER_TYPE_WXWIDGETS = QString("wxwidgets");

//****************************************************************************/
// Screen constants
static const int MAIN_WINDOW_WIDTH = 1024;
static const int MAIN_WINDOW_HEIGHT = 768;
static const int TEMPLATE_DIALOG_WIDTH = 800;
static const int TEMPLATE_DIALOG_HEIGHT = 600;
static const int TEMPLATE_DIALOG_NAME_WIDTH = 200;
static const int TEMPLATE_DIALOG_ICON_WIDTH = 300;
static const int TEMPLATE_DIALOG_ICON_HEIGHT = 170;
static const int TEMPLATE_DIALOG_PADDING_WIDTH = 16;
static const int ICON_DIALOG_SELECTION_WIDTH = 400;
static const int ICON_DIALOG_SELECTION_HEIGHT = 160;
static const int ICON_SIZE = 56;
static const int BIN_SIZE = 72;
static const int FIXED_LABEL_SIZE = 120;
static const int FIXED_SMALL_EDIT_SIZE = 64;
static const int FIXED_MEDIUM_EDIT_SIZE = 120;
static const int FIXED_LARGE_EDIT_SIZE = 240;
static const QString GLOBAL_CONFIG_FILE = QString("global.cfg");
static const QString ICONS_CONFIG_FILE = QString("icons.cfg");
static const QString GLOBAL_TEMPLATES_FILE = QString("templates.cfg");
static const QString TEMPLATES_GROUP = QString("TEMPLATES");
static const QString WINDOWS_GROUP = QString("WINDOWS");
static const QString MENU_GROUP = QString("MENU");
static const QString CATEGORIES_GROUP = QString("CATEGORIES");

//****************************************************************************/
// Keywords in template and configuration files
static const QString CONFIG_KEY_TEMPLATE_DIR = QString("template_dir");
static const QString CONFIG_KEY_ICON_DIR = QString("icon_dir");
static const QString CONFIG_KEY_LAYOUT_DIR = QString("layout_dir");
static const QString CONFIG_KEY_QT_DIR = QString("qt_dir");
static const QString CONFIG_KEY_OUTPUT_DIR = QString("output_dir");
static const QString CONFIG_KEY_OUTPUT_BIN_DIR = QString("output_bin_dir");
static const QString CONFIG_KEY_OUTPUT_ICON_DIR = QString("output_icon_dir");
static const QString CONFIG_KEY_OUTPUT_HEADER_DIR = QString("output_header_dir");
static const QString CONFIG_KEY_OUTPUT_SRC_DIR = QString("output_src_dir");
static const QString CONFIG_KEY_OUTPUT_OGRE_DIR = QString("output_ogre_dir");
static const QString CONFIG_KEY_OGRE_ROOT = QString("ogre_root");
static const QString CONFIG_KEY_OGRE_ROOT_ENV = QString("ogre_root_env");
static const QString CONFIG_KEY_OGRE_DIR = QString("ogre_dir");
static const QString TEMPLATE_KEY_PROJECT = QString("project");
static const QString TEMPLATE_KEY_DESCRIPTION = QString("description");
static const QString TEMPLATE_KEY_ICON = QString("icon");
static const QString TEMPLATE_KEY_NAME = QString("name");
static const QString TEMPLATE_KEY_TAB = QString("tab");
static const QString TEMPLATE_KEY_TYPE = QString("type");
static const QString TEMPLATE_KEY_STYLE = QString("style");
static const QString TEMPLATE_KEY_USE_ASSET_WIDGET = QString("use_asset_widget");
static const QString TEMPLATE_KEY_USE_NODE_EDITOR = QString("use_node_editor");
static const QString TEMPLATE_KEY_USE_TOOLS = QString("use_tools");
static const QString TEMPLATE_KEY_TEMPLATE = QString("template");
static const QString TEMPLATE_KEY_WINDOW = QString("window");
static const QString TEMPLATE_KEY_WINDOW_TITLE = QString("title");
static const QString TEMPLATE_KEY_DISPLAY_TITLE = QString("display_title");
static const QString TEMPLATE_KEY_WINDOW_ORDER = QString("order");
static const QString TEMPLATE_KEY_WINDOW_AREA = QString("area");
static const QString TEMPLATE_KEY_WINDOW_MENU_GROUP = QString("menu_group");
static const QString TEMPLATE_KEY_WINDOW_HTOOLBAR_GROUP = QString("htoolbar_group");
static const QString TEMPLATE_KEY_WINDOW_VTOOLBAR_GROUP = QString("vtoolbar_group");
static const QString TEMPLATE_KEY_WINDOW_TAB_GROUP = QString("tab_group");
static const QString TEMPLATE_KEY_CATEGORY = QString("category");
static const QString TEMPLATE_KEY_MENU = QString("menu");
static const QString TEMPLATE_KEY_MENU_ITEM = QString("item");
static const QString TEMPLATE_KEY_MENU_SUBITEM = QString("subitem");
static const QString TEMPLATE_KEY_WINDOW_USE_TRANS_WIDGET = QString("transformation_widget");
static const QString TEMPLATE_KEY_USE_OGRE_CONTROL = QString("ogre_control");
static const QString TEMPLATE_KEY_USE_OGRE_ASSET = QString("ogre_asset");
static const QString TEMPLATE_KEY_OGRE_TARGET = QString("ogre_target");
static const QString TEMPLATE_KEY_USE_OGRE_CONTROL_VISUALS = QString("ogre_control_visuals");
static const QString TEMPLATE_KEY_USE_DEFAULT_ACTION_EXIT = QString("use_action_exit");
static const QString TEMPLATE_KEY_USE_DEFAULT_ACTION_QUIT = QString("use_action_quit");
static const QString TEMPLATE_KEY_USE_DEFAULT_ACTION_ABOUT = QString("use_action_about");
static const QString TEMPLATE_KEY_USE_DEFAULT_ACTION_RESET_WINDOWS = QString("use_action_reset_windows");

//****************************************************************************/
// Mime types
static const QString MIME_TYPE_HTOOLBAR = QString("icon/toolbar/htoolbar");
static const QString MIME_TYPE_VTOOLBAR = QString("icon/toolbar/vtoolbar");
static const QString MIME_TYPE_SELECTION = QString("icon/toolbar/selection");

//****************************************************************************/
// Icon names
static const QString ICON_ADD = QString("add.png");
static const QString ICON_DELETE = QString("delete.png");
static const QString ICON_BIN = QString("bin.png");
static const QString NO_IMAGE = QString("NoImage.png");
static const QString ICON_COLLAPSE = QString("collapse.png");
static const QString ICON_EXPAND = QString("expand.png");
static const QString ICON_CAMERA = QString("camera.png");
static const QString ICON_COG = QString("cog.png");
static const QString ICON_NPC = QString("npc.png");
static const QString ICON_CUBE_BOLD = QString("cube_bold.png");
static const QString ICON_AXIS_BOLD = QString("axis_bold.png");
static const QString ICON_RENDERING_BOLD = QString("rendering_bold.png");
static const QString ICON_SHADOW_BOLD = QString("shadow_bold.png");
static const QString ICON_ANIMATION_BOLD = QString("animation_bold.png");
static const QString ICON_NPC_BOLD = QString("npc_bold.png");
static const QString ICON_MATERIAL = QString("material.png");
static const QString ICON_TECHNIQUE_BOLD = QString("technique_bold.png");
static const QString ICON_PASS_BOLD = QString("pass_bold.png");
static const QString ICON_TEXTURE_BOLD = QString("texture_bold.png");
static const QString ICON_LIGHT_OFF = QString("light_off.png");
static const QString ICON_COLOR_BOLD = QString("color_bold.png");
static const QString ICON_CURVE_FIT_HOR = QString("curve_fit_hor.png");
static const QString ICON_CURVE_FIT_VERT = QString("curve_fit_vert.png");
static const QString ICON_CURVE_MOVE = QString("curve_move.png");
static const QString ICON_CURVE_MOVE_ON = QString("curve_move_on.png");
static const QString ICON_CURVE_RUBBERBAND = QString("curve_rubberband.png");
static const QString ICON_CURVE_RUBBERBAND_ON = QString("curve_rubberband_on.png");
static const QString ICON_CURVE_EDIT = QString("curve_edit.png");
static const QString ICON_CURVE_EDIT_ON = QString("curve_edit_on.png");
static const QString ICON_CURVE_ZOOM_IN = QString("curve_zoom_in.png");
static const QString ICON_CURVE_ZOOM_OUT = QString("curve_zoom_out.png");
static const QString ICON_CURVE_PIVOT = QString("curve_pivot.png");
static const QString ICON_CURVE = QString("curve.png");
static const QString ICON_CLOSE = QString("close.png");
static const QString ICON_MINMAX = QString("minmax.png");
static const QString ICON_COMPOUND = QString("compound.png");
static const QString ICON_CLOSE_BOLD = QString("close_bold.png");
static const QString ICON_LAYER_BOLD = QString("layer_bold.png");
static const QString ICON_VISIBLE_BOLD = QString("view_visible_bold.png");
static const QString ICON_INVISIBLE_BOLD = QString("view_invisible_bold.png");

// The separator names must match the names in tbicons.cfg to be recognized as a separator
static const QString ICON_HSEPARATOR = QString("separator_horizontal.png");
static const QString ICON_VSEPARATOR = QString("separator_vertical.png");

//****************************************************************************/
// Default settings for windows
static const QString DEFAULT_WINDOW_TITLE = QString("default");
static const QString DEFAULT_DESCRIPTION = QString("Example");
static const QString DEFAULT_ICON_NAME = QString("layout_example.png");
static const QString DEFAULT_TYPE = QString("qt");
static const QString DEFAULT_STYLE = QString("dark");

//****************************************************************************/
// Stylesheets
static const QString STYLE_DEFAULT = QString("defaultstyle.qss");
static const QString STYLE_DARK = QString("dark.qss");

//****************************************************************************/
// Ogre files and dirs
static const QString FILE_OGRE_MAIN_DLL = QString("OgreMain.dll");
static const QString FILE_OGRE_MAIN_D_DLL = QString("OgreMain_d.dll");
static const QString FILE_OGRE_GL_DLL = QString("RenderSystem_GL.dll");
static const QString FILE_OGRE_GL_D_DLL = QString("RenderSystem_GL_d.dll");
static const QString FILE_OGRE_3D9_DLL = QString("RenderSystem_Direct3D9.dll");
static const QString FILE_OGRE_3D9_D_DLL = QString("RenderSystem_Direct3D9_d.dll");
static const QString FILE_OGRE_PLUGINS_D = QString("plugins_d.cfg");
static const QString FILE_OGRE_PLUGINS = QString("plugins.cfg");
static const QString FILE_OGRE_RESOURCES_D = QString("resources_d.cfg");
static const QString FILE_OGRE_RESOURCES = QString("resources.cfg");
static const QString FILE_RESOURCES_OGRE_GREENSKIN = QString("GreenSkin.jpg");
static const QString FILE_RESOURCES_OGRE_TUSK = QString("tusk.jpg");
static const QString FILE_RESOURCES_OGRE_MATERIAL = QString("Ogre.material");
static const QString FILE_RESOURCES_OGRE_HEAD = QString("ogrehead.mesh");
static const QString FILE_RESOURCES_OGRE_MAP = QString("spheremap.png");
static const QString DIR_OGRE_BIN_DEBUG = QString("/VCBuild/bin/debug/");
static const QString DIR_OGRE_BIN_RELEASE = QString("/VCBuild/bin/release/");

//****************************************************************************/
// Miscelanious
static const QString TAB = QString("    ");
static const QString AREA_LEFT = QString("left");
static const QString AREA_RIGHT = QString("right");
static const QString AREA_TOP = QString("top");
static const QString AREA_BOTTOM = QString("bottom");
static const QString AREA_CENTER = QString("center");
static const QString KEYWORD_MENU_EXIT = QString("Exit");
static const QString KEYWORD_MENU_QUIT = QString("Quit");
static const QString KEYWORD_MENU_ABOUT = QString("About");
static const QString KEYWORD_MENU_RESET_WINDOWS = QString("Reset Window Layout");
static const QString TEXT_USE_OGRE_ASSETS = QString("Use Ogre3d asset library");
static const QString TEXT_USE_OGRE_ASSETS_DISABLED = QString("Use Ogre3d asset library (DISABLED! Ogre assets can only be used if Ogre3d itself is used)");

//****************************************************************************/
#endif
