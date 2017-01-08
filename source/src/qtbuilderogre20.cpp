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

#include "constants.h"
#include "qtbuilder.h"
#include "applicationtemplate.h"
#include "utils.h"
#include "qtbuilderogre20.h"

//****************************************************************************/
QtOgre20Builder::QtOgre20Builder()
{
}

//****************************************************************************/
QtOgre20Builder::~QtOgre20Builder()
{
}

//****************************************************************************/
QString QtOgre20Builder::createLibForPro(const QString &ogreBuildDir, const QString &s)
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
        QString("\n\n");

    str = str +
        QString("CONFIG(debug, debug|release):LIBS += \\") +
        QString("\n");

    str = str +
        TAB +
        QString("-lopengl32 \\") +
        QString("\n");

    str = str +
        TAB +
        QString("-lOgreMain_d") +
        QString("\n\n");

    str = str +
        QString("CONFIG(release, debug|release):LIBS += \\") +
        QString("\n");

    str = str +
        TAB +
        QString("-lopengl32 \\") +
        QString("\n");

    str = str +
        TAB +
        QString("-lOgreMain") +
        QString("\n\n");

    return str;
}

//****************************************************************************/
QString QtOgre20Builder::createHeaderForPro(const QString &outputHeaderDir, const QString &s)
{
    QString str = s;

    // Headers
    str = str +
        TAB +
        outputHeaderDir +
        FILE_OGRE2_RENDERMAN_H +
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
        FILE_OGRE2_WIDGET_H +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputHeaderDir +
        FILE_OGRE2_WIDGET_CAMERAMAN_H +
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
QString QtOgre20Builder::createSrcForPro(const QString &outputSrcDir, const QString &s)
{
    QString str = s;

    // Src
    str = str +
        TAB +
        outputSrcDir +
        FILE_OGRE2_RENDERMAN_CPP +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputSrcDir +
        FILE_OGRE2_WIDGET_CPP +
        QString(" \\ ") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgre20Builder::createInclude(const QString &s)
{
    QString str = s;

    // Add the #include
    str = str +
        QString("#include \"") +
        FILE_OGRE2_RENDERMAN_H +
        QString("\"") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgre20Builder::createPublicMemberForMainWindow(const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        TAB +
        QString("Magus::OgreManager* getOgreManager(void) const {return mOgreManager;};") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgre20Builder::createPrivateMemberForMainWindow(const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        TAB +
        QString("Magus::OgreManager* mOgreManager;") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgre20Builder::createConstructorEntryForMainWindow(const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        QString("// Create the Ogre Manager") +
        QString("\n");
    str = str +
        TAB +
        QString("mOgreManager = new Magus::OgreManager();");

    return str;
}

//****************************************************************************/
QString QtOgre20Builder::createQtOgreWidgetForMainWindow(WindowProperties* windowProperties, const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        QString("mOgreWidget = new Magus::QOgreWidget();") +
        QString("\n");
    str = str +
        TAB +
        QString("setCentralWidget(mOgreWidget);") +
        QString("\n");
    str = str +
        TAB +
        QString("mOgreManager->registerOgreWidget(") +
        QVariant(windowProperties->mOrder).toString() +
        QString(", mOgreWidget);") +
        QString("\n");
    str = str +
        TAB +
        QString("mOgreWidget->createRenderWindow(mOgreManager); ") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgre20Builder::createInitializeEntryForMainWindow(const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        QString("mOgreManager->initialize();") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgre20Builder::createPrivateMemberQtOgreWidget(const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        TAB +
        QString("Magus::QOgreWidget* mOgreWidget;") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgre20Builder::createQtOgreWidgetForDockWindow(WindowProperties* windowProperties, const QString &s)
{
    QString str = s;
    str = str +
        TAB +
        QString("mOgreWidget = new Magus::QOgreWidget();") +
        QString("\n");
    str = str +
        TAB +
        QString("mInnerMain->setCentralWidget(mOgreWidget);") +
        QString("\n");
    str = str +
        TAB +
        QString("parent->getOgreManager()->registerOgreWidget(") +
        QVariant(windowProperties->mOrder).toString() +
        QString(", mOgreWidget);") +
        QString("\n");
    str = str +
        TAB +
        QString("mOgreWidget->createRenderWindow(parent->getOgreManager()); ") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgre20Builder::createQtOgreWidgetForTab(WindowProperties* windowProperties, int index, const QString &s)
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
        QString("mOgreWidget = new Magus::QOgreWidget(mInnerMain);") +
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
        QString("parent->getOgreManager()->registerOgreWidget(") +
        QVariant(windowProperties->mOrder).toString() +
        QString(", mOgreWidget);") +
        QString("\n");
    str = str +
        TAB +
        QString("mOgreWidget->createRenderWindow(parent->getOgreManager()); ") +
        QString("\n");

    return str;
}

//****************************************************************************/
void QtOgre20Builder::copyOgreFiles(const QString &ogreRoot,
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
    fileUtil.copy(qtHeader + FILE_OGRE2_WIDGET_H, fullOutputHeaderDir + FILE_OGRE2_WIDGET_H); // Differentiates from Ogre 1.9
    fileUtil.copy(qtHeader + FILE_OGRE2_WIDGET_CAMERAMAN_H, fullOutputHeaderDir + FILE_OGRE2_WIDGET_CAMERAMAN_H); // Differentiates from Ogre 1.9
    fileUtil.copy(qtHeader + FILE_OGRE_WIDGET_COLRECT_H, fullOutputHeaderDir + FILE_OGRE_WIDGET_COLRECT_H);
    fileUtil.copy(qtHeader + FILE_OGRE2_RENDERMAN_H, fullOutputHeaderDir + FILE_OGRE2_RENDERMAN_H); // Differentiates from Ogre 1.9
    fileUtil.copy(qtSrc + FILE_OGRE2_WIDGET_CPP, fullOutputSrcDir + FILE_OGRE2_WIDGET_CPP); // Differentiates from Ogre 1.9
    fileUtil.copy(qtSrc + FILE_OGRE2_RENDERMAN_CPP, fullOutputSrcDir + FILE_OGRE2_RENDERMAN_CPP); // Differentiates from Ogre 1.9

    // Copy the Ogre DLL's (MUST be present, otherwise the generated application crashes)
    //fileUtil.copy(ogreRoot + DIR_OGRE_BIN_RELEASE + FILE_OGRE_MAIN_DLL, fullOutputBinDir + FILE_OGRE_MAIN_DLL);
    //fileUtil.copy(ogreRoot + DIR_OGRE_BIN_DEBUG + FILE_OGRE_MAIN_D_DLL, fullOutputBinDir + FILE_OGRE_MAIN_D_DLL);
    //fileUtil.copy(ogreRoot + DIR_OGRE_BIN_RELEASE + FILE_OGRE_GL_DLL, fullOutputBinDir + FILE_OGRE_GL_DLL);
    //fileUtil.copy(ogreRoot + DIR_OGRE_BIN_DEBUG + FILE_OGRE_GL_D_DLL, fullOutputBinDir + FILE_OGRE_GL_D_DLL);
    //fileUtil.copy(ogreRoot + DIR_OGRE_BIN_RELEASE + FILE_OGRE_3D9_DLL, fullOutputBinDir + FILE_OGRE_3D9_DLL);
    //fileUtil.copy(ogreRoot + DIR_OGRE_BIN_DEBUG + FILE_OGRE_3D9_D_DLL, fullOutputBinDir + FILE_OGRE_3D9_D_DLL);
    fileUtil.copy(ogreRoot + "/" + ogreBuildDir + DIR_OGRE_BIN_RELEASE + FILE_OGRE_MAIN_DLL, fullOutputBinDir + FILE_OGRE_MAIN_DLL);
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
