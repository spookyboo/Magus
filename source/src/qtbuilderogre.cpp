/****************************************************************************
**
** Copyright (C) 2016
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

#include <QFile>
#include "qtbuilderogre.h"
#include "constants.h"
#include "qtbuilder.h"
#include "applicationtemplate.h"
#include "utils.h"

//****************************************************************************/
QtOgreBuilder::QtOgreBuilder()
{
}

//****************************************************************************/
QtOgreBuilder::~QtOgreBuilder()
{
}

//****************************************************************************/
QString QtOgreBuilder::createInclude(const QString &s)
{
    QString str = s;

    // Add the #include
    str = str +
        QString("#include \"") +
        FILE_OGRE_RENDERMAN_H +
        QString("\"") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createPublicMemberForMainWindow(const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        TAB +
        QString("OgreManager* getOgreManager(void) const {return mOgreManager;};") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createPrivateMemberForMainWindow(const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        TAB +
        QString("OgreManager* mOgreManager;") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createPrivateMemberQtOgreWidget(const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        TAB +
        QString("QOgre::Widget* mOgreWidget;") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createConstructorEntryForMainWindow(const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        QString("// Create the Ogre Manager") +
        QString("\n");
    str = str +
        TAB +
        QString("mOgreManager = new OgreManager();");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createQtOgreWidgetForMainWindow(WindowProperties* windowProperties, const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        QString("mOgreWidget = new QOgre::Widget(this);") +
        QString("\n");
    str = str +
        TAB +
        QString("setCentralWidget(mOgreWidget);") +
        QString("\n");
    str = str +
        TAB +
        QString("mOgreManager->registerQtOgreWidget(") +
        QVariant(windowProperties->mOrder).toString() +
        QString(", mOgreWidget);") +
        QString("\n");
    str = str +
        TAB +
        QString("mOgreWidget->go(mOgreManager->getOgreRoot()); ") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createQtOgreWidgetForDockWindow(WindowProperties* windowProperties, const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        QString("mOgreWidget = new QOgre::Widget(mInnerMain);") +
        QString("\n");
    str = str +
        TAB +
        QString("mInnerMain->setCentralWidget(mOgreWidget);") +
        QString("\n");
    str = str +
        TAB +
        QString("parent->getOgreManager()->registerQtOgreWidget(") +
        QVariant(windowProperties->mOrder).toString() +
        QString(", mOgreWidget);") +
        QString("\n");
    str = str +
        TAB +
        QString("mOgreWidget->go(parent->getOgreManager()->getOgreRoot()); ") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createQtOgreWidgetForTab(WindowProperties* windowProperties, int index, const QString &s)
{
    QString str = s;
    QString indexString = QVariant(index).toString();
    str = str +
        TAB +
        QString("QString label = mTabWidget->tabText(") +
        indexString +
        QString(");") +
        QString("\n");
    str = str +
        TAB +
        QString("mTabWidget->removeTab(") +
        indexString +
        QString(");") +
        QString("\n");
    str = str +
        TAB +
        QString("mOgreWidget = new QOgre::Widget(mInnerMain);") +
        QString("\n");
    str = str +
        TAB +
        QString("mTabWidget->insertTab(") +
        indexString +
        QString(", mOgreWidget, label);") +
        QString("\n");
    str = str +
        TAB +
        QString("mTabWidget->setCurrentIndex(") +
        indexString +
        QString(");") +
        QString("\n");
    str = str +
        TAB +
        QString("parent->getOgreManager()->registerQtOgreWidget(") +
        QVariant(windowProperties->mOrder).toString() +
        QString(", mOgreWidget);") +
        QString("\n");
    str = str +
        TAB +
        QString("mOgreWidget->go(parent->getOgreManager()->getOgreRoot()); ") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createDestructorEntryForMainWindow(const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        QString("delete mOgreManager;");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createUpdateEntryForMainWindow(const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        QString("if (mOgreManager)") +
        QString("\n");

    str = str +
        TAB +
        TAB +
        QString("mOgreManager->renderOgreWidgetsOneFrame();");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createInitializeEntryForMainWindow(const QString &s)
{
    QString str = s;
    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createRootForPro(const QString &ogreRoot, const QString &s)
{
    QString str = s;
    str =
        QString("OGREHOME = \"") +
        ogreRoot +
        QString("\"\n");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createIncludeForPro(const QString &ogreBuildDir, const QString &s)
{
    QString str = s;
    str =
        QString("INCLUDEPATH += \"$$OGREHOME/OgreMain/include\"") +
        QString("\n") +
        QString("INCLUDEPATH += \"$$OGREHOME/") +
        ogreBuildDir +
        QString("/include\"") +
        QString("\n") +
        QString("INCLUDEPATH += .") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createLibForPro(const QString &ogreBuildDir, const QString &s)
{
    QString str = s;
    str =
        QString("Debug:LIBS += -L\"$$OGREHOME/") +
        ogreBuildDir +
        QString("/lib/Debug\"") +
        QString("\n") +
        QString("Release:LIBS += -L\"$$OGREHOME/") +
        ogreBuildDir +
        QString("/lib/Release\"") +
        QString("\n");

    str = str +
        QString("CONFIG(debug, debug|release):LIBS *= -lOgreMain_d") +
        QString("\n");

    str = str +
        QString("CONFIG(release, debug|release):LIBS *= -lOgreMain") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createHeaderForPro(const QString &outputHeaderDir, const QString &s)
{
    QString str = s;

    // Headers
    str = str +
        TAB +
        outputHeaderDir +
        FILE_OGRE_RENDERMAN_H +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputHeaderDir +
        FILE_OGRE_WIDGET_PREREQ_H +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputHeaderDir +
        FILE_OGRE_WIDGET_H +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputHeaderDir +
        FILE_OGRE_WIDGET_CAMERAMAN_H +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputHeaderDir +
        FILE_OGRE_WIDGET_COLRECT_H +
        QString(" \\ ") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgreBuilder::createSrcForPro(const QString &outputSrcDir, const QString &s)
{
    QString str = s;

    // Src
    str = str +
        TAB +
        outputSrcDir +
        FILE_OGRE_RENDERMAN_CPP +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputSrcDir +
        FILE_OGRE_WIDGET_CPP +
        QString(" \\ ") +
        QString("\n");

    return str;
}

/****************************************************************************
 Generates code to copy the Ogre Asset widget header files and add
 them to the project (.pro) file.
****************************************************************************/
QString QtOgreBuilder::createOgreAssetHeaderForPro(const QString& outputHeaderDir, const QString& s)
{
    // Add to the project file
    // Headers
    QString str = s;
    str = str +
        TAB +
        outputHeaderDir +
        FILE_OGRE_ASSET_CAMERA_H +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputHeaderDir +
        FILE_OGRE_ASSET_ENTITY_H +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputHeaderDir +
        FILE_OGRE_ASSET_MATERIAL_H +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputHeaderDir +
        FILE_OGRE_ASSET_LIGHT_H +
        QString(" \\ ") +
        QString("\n");

    return str;
}

/****************************************************************************
 Generates code to copy the Ogre Asset widget cpp files and add
 them to the project (.pro) file.
****************************************************************************/
QString QtOgreBuilder::createOgreAssetSrcForPro(const QString& outputSrcDir, const QString& s)
{
    // Add to the project file
    // Src
    QString str = s;
    str = str +
        TAB +
        outputSrcDir +
        FILE_OGRE_ASSET_CAMERA_CPP +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputSrcDir +
        FILE_OGRE_ASSET_ENTITY_CPP +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputSrcDir +
        FILE_OGRE_ASSET_MATERIAL_CPP +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputSrcDir +
        FILE_OGRE_ASSET_LIGHT_CPP +
        QString(" \\ ") +
        QString("\n");

    return str;
}

//****************************************************************************/
void QtOgreBuilder::copyOgreAssetFiles(const QString& qtHeader,
                                       const QString& qtSrc,
                                       const QString& iconDir,
                                       const QString& fullOutputHeaderDir,
                                       const QString& fullOutputSrcDir,
                                       const QString& fullOutputIconDir)
{
    QFile fileUtil;
    fileUtil.copy(qtHeader + FILE_OGRE_ASSET_CAMERA_H, fullOutputHeaderDir + FILE_OGRE_ASSET_CAMERA_H);
    fileUtil.copy(qtSrc + FILE_OGRE_ASSET_CAMERA_CPP, fullOutputSrcDir + FILE_OGRE_ASSET_CAMERA_CPP);
    fileUtil.copy(qtHeader + FILE_OGRE_ASSET_ENTITY_H, fullOutputHeaderDir + FILE_OGRE_ASSET_ENTITY_H);
    fileUtil.copy(qtSrc + FILE_OGRE_ASSET_ENTITY_CPP, fullOutputSrcDir + FILE_OGRE_ASSET_ENTITY_CPP);
    fileUtil.copy(qtHeader + FILE_OGRE_ASSET_MATERIAL_H, fullOutputHeaderDir + FILE_OGRE_ASSET_MATERIAL_H);
    fileUtil.copy(qtSrc + FILE_OGRE_ASSET_MATERIAL_CPP, fullOutputSrcDir + FILE_OGRE_ASSET_MATERIAL_CPP);
    fileUtil.copy(qtHeader + FILE_OGRE_ASSET_LIGHT_H, fullOutputHeaderDir + FILE_OGRE_ASSET_LIGHT_H);
    fileUtil.copy(qtSrc + FILE_OGRE_ASSET_LIGHT_CPP, fullOutputSrcDir + FILE_OGRE_ASSET_LIGHT_CPP);

    // Also copy the icons
    fileUtil.copy(iconDir + ICON_CUBE_BOLD, fullOutputIconDir + ICON_CUBE_BOLD); // For general use
    fileUtil.copy(iconDir + ICON_AXIS_BOLD, fullOutputIconDir + ICON_AXIS_BOLD); // For general use
    fileUtil.copy(iconDir + ICON_COG, fullOutputIconDir + ICON_COG); // For general use
    fileUtil.copy(iconDir + ICON_CAMERA, fullOutputIconDir + ICON_CAMERA); // Used for Camera asset
    fileUtil.copy(iconDir + ICON_NPC, fullOutputIconDir + ICON_NPC); // Used for Entity asset
    fileUtil.copy(iconDir + ICON_RENDERING_BOLD, fullOutputIconDir + ICON_RENDERING_BOLD); // For Entity asset
    fileUtil.copy(iconDir + ICON_SHADOW_BOLD, fullOutputIconDir + ICON_SHADOW_BOLD); // For Entity asset
    fileUtil.copy(iconDir + ICON_ANIMATION_BOLD, fullOutputIconDir + ICON_ANIMATION_BOLD); // For Entity asset
    fileUtil.copy(iconDir + ICON_NPC_BOLD, fullOutputIconDir + ICON_NPC_BOLD); // For Entity asset
    fileUtil.copy(iconDir + ICON_MATERIAL, fullOutputIconDir + ICON_MATERIAL); // For Material asset
    fileUtil.copy(iconDir + ICON_TECHNIQUE_BOLD, fullOutputIconDir + ICON_TECHNIQUE_BOLD); // For Material asset
    fileUtil.copy(iconDir + ICON_PASS_BOLD, fullOutputIconDir + ICON_PASS_BOLD); // For Material asset
    fileUtil.copy(iconDir + ICON_TEXTURE_BOLD, fullOutputIconDir + ICON_TEXTURE_BOLD); // For Material asset
    fileUtil.copy(iconDir + ICON_LIGHT_OFF, fullOutputIconDir + ICON_LIGHT_OFF); // For Light asset
    fileUtil.copy(iconDir + ICON_COLOR_BOLD, fullOutputIconDir + ICON_COLOR_BOLD); // For Light asset
}

//****************************************************************************/
void QtOgreBuilder::copyOgreFiles(const QString &ogreRoot,
                                  const QString &ogreBuildDir,
                                  const QString &ogreDir,
                                  const QString &qtHeader,
                                  const QString &qtSrc,
                                  const QString &fullOutputHeaderDir,
                                  const QString &fullOutputSrcDir,
                                  const QString &fullOutputBinDir,
                                  const QString &fullOutputOgreDir)
{
    QFile fileUtil;

    // Copy the QtWidget .h and .cpp files
    fileUtil.copy(qtHeader + FILE_OGRE_WIDGET_PREREQ_H, fullOutputHeaderDir + FILE_OGRE_WIDGET_PREREQ_H);
    fileUtil.copy(qtHeader + FILE_OGRE_WIDGET_H, fullOutputHeaderDir + FILE_OGRE_WIDGET_H);
    fileUtil.copy(qtHeader + FILE_OGRE_WIDGET_CAMERAMAN_H, fullOutputHeaderDir + FILE_OGRE_WIDGET_CAMERAMAN_H);
    fileUtil.copy(qtHeader + FILE_OGRE_WIDGET_COLRECT_H, fullOutputHeaderDir + FILE_OGRE_WIDGET_COLRECT_H);
    fileUtil.copy(qtHeader + FILE_OGRE_RENDERMAN_H, fullOutputHeaderDir + FILE_OGRE_RENDERMAN_H);
    fileUtil.copy(qtSrc + FILE_OGRE_WIDGET_CPP, fullOutputSrcDir + FILE_OGRE_WIDGET_CPP);
    fileUtil.copy(qtSrc + FILE_OGRE_RENDERMAN_CPP, fullOutputSrcDir + FILE_OGRE_RENDERMAN_CPP);

    // Copy the Ogre DLL's (MUST be present, otherwise the application crashes)
    //fileUtil.copy(ogreRoot + DIR_OGRE_BIN_RELEASE + FILE_OGRE_MAIN_DLL, fullOutputBinDir + FILE_OGRE_MAIN_DLL);
    //fileUtil.copy(ogreRoot + DIR_OGRE_BIN_DEBUG + FILE_OGRE_MAIN_D_DLL, fullOutputBinDir + FILE_OGRE_MAIN_D_DLL);
    //fileUtil.copy(ogreRoot + DIR_OGRE_BIN_RELEASE + FILE_OGRE_GL_DLL, fullOutputBinDir + FILE_OGRE_GL_DLL);
    //fileUtil.copy(ogreRoot + DIR_OGRE_BIN_DEBUG + FILE_OGRE_GL_D_DLL, fullOutputBinDir + FILE_OGRE_GL_D_DLL);
    //fileUtil.copy(ogreRoot + DIR_OGRE_BIN_RELEASE + FILE_OGRE_3D9_DLL, fullOutputBinDir + FILE_OGRE_3D9_DLL);
    //fileUtil.copy(ogreRoot + DIR_OGRE_BIN_DEBUG + FILE_OGRE_3D9_D_DLL, fullOutputBinDir + FILE_OGRE_3D9_D_DLL);
    fileUtil.copy(ogreRoot + "/" + ogreBuildDir + DIR_OGRE_BIN_RELEASE + FILE_OGRE_MAIN_DLL, fullOutputBinDir + FILE_OGRE_MAIN_DLL); // Note, that ogreBuildDir doesn't have leading/trailing (back)slashes
    fileUtil.copy(ogreRoot + "/" + ogreBuildDir + DIR_OGRE_BIN_DEBUG + FILE_OGRE_MAIN_D_DLL, fullOutputBinDir + FILE_OGRE_MAIN_D_DLL);
    fileUtil.copy(ogreRoot + "/" + ogreBuildDir + DIR_OGRE_BIN_RELEASE + FILE_OGRE_GL_DLL, fullOutputBinDir + FILE_OGRE_GL_DLL);
    fileUtil.copy(ogreRoot + "/" + ogreBuildDir + DIR_OGRE_BIN_DEBUG + FILE_OGRE_GL_D_DLL, fullOutputBinDir + FILE_OGRE_GL_D_DLL);
    fileUtil.copy(ogreRoot + "/" + ogreBuildDir + DIR_OGRE_BIN_RELEASE + FILE_OGRE_3D9_DLL, fullOutputBinDir + FILE_OGRE_3D9_DLL);
    fileUtil.copy(ogreRoot + "/" + ogreBuildDir + DIR_OGRE_BIN_DEBUG + FILE_OGRE_3D9_D_DLL, fullOutputBinDir + FILE_OGRE_3D9_D_DLL);

    // Copy the plugin and resourcefiles and the media
    fileUtil.copy(ogreDir + FILE_OGRE_PLUGINS_D, fullOutputBinDir + FILE_OGRE_PLUGINS_D);
    fileUtil.copy(ogreDir + FILE_OGRE_PLUGINS, fullOutputBinDir + FILE_OGRE_PLUGINS);
    fileUtil.copy(ogreDir + FILE_OGRE_RESOURCES_D, fullOutputBinDir + FILE_OGRE_RESOURCES_D);
    fileUtil.copy(ogreDir + FILE_OGRE_RESOURCES, fullOutputBinDir + FILE_OGRE_RESOURCES);
    fileUtil.copy(ogreDir + FILE_RESOURCES_OGRE_GREENSKIN, fullOutputOgreDir + FILE_RESOURCES_OGRE_GREENSKIN);
    fileUtil.copy(ogreDir + FILE_RESOURCES_OGRE_TUSK, fullOutputOgreDir + FILE_RESOURCES_OGRE_TUSK);
    fileUtil.copy(ogreDir + FILE_RESOURCES_OGRE_MATERIAL, fullOutputOgreDir + FILE_RESOURCES_OGRE_MATERIAL);
    fileUtil.copy(ogreDir + FILE_RESOURCES_OGRE_HEAD, fullOutputOgreDir + FILE_RESOURCES_OGRE_HEAD);
    fileUtil.copy(ogreDir + FILE_RESOURCES_OGRE_MAP, fullOutputOgreDir + FILE_RESOURCES_OGRE_MAP);
}
