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

#include <QMessageBox>
#include "constants.h"
#include "qtbuilder.h"
#include "applicationtemplate.h"
#include "utils.h"
#include "qtbuilderogre21.h"

//****************************************************************************/
QtOgre21Builder::QtOgre21Builder()
{
}

//****************************************************************************/
QtOgre21Builder::~QtOgre21Builder()
{
}

//****************************************************************************/
QString QtOgre21Builder::createIncludeForPro(const QString &s)
{
    QString str = s;
    str =
        QString("INCLUDEPATH += \"$$OGREHOME/OgreMain/include\"") +
        QString("\n") +
        QString("INCLUDEPATH += \"$$OGREHOME/Components/Hlms/Common/include\"") +
        QString("\n") +
        QString("INCLUDEPATH += \"$$OGREHOME/Components/Hlms/Pbs/include\"") +
        QString("\n") +
        QString("INCLUDEPATH += \"$$OGREHOME/Components/Hlms/Unlit/include\"") +
        QString("\n") +
        QString("INCLUDEPATH += \"$$OGREHOME/VCBuild/include\"") +
        QString("\n") +
        QString("INCLUDEPATH += .") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgre21Builder::createLibForPro(const QString &s)
{
    QString str = s;
    str =
        QString("Debug:LIBS += -L\"$$OGREHOME/VCBuild/lib/Debug\"") +
        QString("\n") +
        QString("Release:LIBS += -L\"$$OGREHOME/VCBuild/lib/Release\"") +
        QString("\n\n");

    // Debug
    str = str +
        QString("CONFIG(debug, debug|release):LIBS += \\") +
        QString("\n");

    str = str +
        TAB +
        QString("-lopengl32 \\") +
        QString("\n");

    str = str +
        TAB +
        QString("-lOgreMain_d \\") +
        QString("\n");

    str = str +
        TAB +
        QString("-lOgreHlmsPbs_d \\") +
        QString("\n");

    str = str +
        TAB +
        QString("-lOgreHlmsUnlit_d") +
        QString("\n\n");


    // Release
    str = str +
        QString("CONFIG(release, debug|release):LIBS += \\") +
        QString("\n");

    str = str +
        TAB +
        QString("-lopengl32 \\") +
        QString("\n");

    str = str +
        TAB +
        QString("-lOgreMain \\") +
        QString("\n");

    str = str +
        TAB +
        QString("-lOgreHlmsPbs \\") +
        QString("\n");

    str = str +
        TAB +
        QString("-lOgreHlmsUnlit") +
        QString("\n\n");

    return str;
}

//****************************************************************************/
QString QtOgre21Builder::createHeaderForPro(const QString &outputHeaderDir, const QString &s)
{
    QString str = s;

    // Headers
    str = str +
        TAB +
        outputHeaderDir +
        FILE_OGRE3_RENDERMAN_H +
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
        FILE_OGRE3_WIDGET_H +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputHeaderDir +
        FILE_OGRE3_WIDGET_CAMERAMAN_H +
        QString(" \\ ") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgre21Builder::createSrcForPro(const QString &outputSrcDir, const QString &s)
{
    QString str = s;

    // Src
    str = str +
        TAB +
        outputSrcDir +
        FILE_OGRE3_RENDERMAN_CPP +
        QString(" \\ ") +
        QString("\n");
    str = str +
        TAB +
        outputSrcDir +
        FILE_OGRE3_WIDGET_CPP +
        QString(" \\ ") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtOgre21Builder::createInclude(const QString &s)
{
    QString str = s;

    // Add the #include
    str = str +
        QString("#include \"") +
        FILE_OGRE3_RENDERMAN_H +
        QString("\"") +
        QString("\n");

    return str;
}

//****************************************************************************/
void QtOgre21Builder::copyOgreFiles(const QString &ogreRoot,
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
    fileUtil.copy(qtHeader + FILE_OGRE3_WIDGET_H, fullOutputHeaderDir + FILE_OGRE3_WIDGET_H); // Differentiates from Ogre 2.0
    fileUtil.copy(qtHeader + FILE_OGRE3_WIDGET_CAMERAMAN_H, fullOutputHeaderDir + FILE_OGRE3_WIDGET_CAMERAMAN_H); // Differentiates from Ogre 2.0
    fileUtil.copy(qtHeader + FILE_OGRE_WIDGET_COLRECT_H, fullOutputHeaderDir + FILE_OGRE_WIDGET_COLRECT_H);
    fileUtil.copy(qtHeader + FILE_OGRE3_RENDERMAN_H, fullOutputHeaderDir + FILE_OGRE3_RENDERMAN_H); // Differentiates from Ogre 2.0
    fileUtil.copy(qtSrc + FILE_OGRE3_WIDGET_CPP, fullOutputSrcDir + FILE_OGRE3_WIDGET_CPP); // Differentiates from Ogre 2.0
    fileUtil.copy(qtSrc + FILE_OGRE3_RENDERMAN_CPP, fullOutputSrcDir + FILE_OGRE3_RENDERMAN_CPP); // Differentiates from Ogre 2.0

    // Copy the Ogre DLL's (MUST be present, otherwise the generated application crashes)
    fileUtil.copy(ogreRoot + DIR_OGRE_BIN_RELEASE + FILE_OGRE_MAIN_DLL, fullOutputBinDir + FILE_OGRE_MAIN_DLL);
    fileUtil.copy(ogreRoot + DIR_OGRE_BIN_DEBUG + FILE_OGRE_MAIN_D_DLL, fullOutputBinDir + FILE_OGRE_MAIN_D_DLL);
    fileUtil.copy(ogreRoot + DIR_OGRE_BIN_RELEASE + FILE_OGRE_GL3PLUS_DLL, fullOutputBinDir + FILE_OGRE_GL3PLUS_DLL);
    fileUtil.copy(ogreRoot + DIR_OGRE_BIN_DEBUG + FILE_OGRE_GL3PLUS_D_DLL, fullOutputBinDir + FILE_OGRE_GL3PLUS_D_DLL);
    fileUtil.copy(ogreRoot + DIR_OGRE_BIN_RELEASE + FILE_OGRE_3D11_DLL, fullOutputBinDir + FILE_OGRE_3D11_DLL);
    fileUtil.copy(ogreRoot + DIR_OGRE_BIN_DEBUG + FILE_OGRE_3D11_D_DLL, fullOutputBinDir + FILE_OGRE_3D11_D_DLL);
    fileUtil.copy(ogreRoot + DIR_OGRE_BIN_RELEASE + FILE_OGRE_HLMS_PBS_DLL, fullOutputBinDir + FILE_OGRE_HLMS_PBS_DLL);
    fileUtil.copy(ogreRoot + DIR_OGRE_BIN_DEBUG + FILE_OGRE_HLMS_PBS_D_DLL, fullOutputBinDir + FILE_OGRE_HLMS_PBS_D_DLL);
    fileUtil.copy(ogreRoot + DIR_OGRE_BIN_RELEASE + FILE_OGRE_HLMS_UNLIT_DLL, fullOutputBinDir + FILE_OGRE_HLMS_UNLIT_DLL);
    fileUtil.copy(ogreRoot + DIR_OGRE_BIN_DEBUG + FILE_OGRE_HLMS_UNLIT_D_DLL, fullOutputBinDir + FILE_OGRE_HLMS_UNLIT_D_DLL);

    // Copy the plugin and resourcefiles
    fileUtil.copy(ogreDir + FILE_OGRE_PLUGINS_D, fullOutputBinDir + FILE_OGRE_PLUGINS_D);
    fileUtil.copy(ogreDir + FILE_OGRE_PLUGINS, fullOutputBinDir + FILE_OGRE_PLUGINS);
    fileUtil.copy(ogreDir + FILE_OGRE_RESOURCES_D, fullOutputBinDir + FILE_OGRE_RESOURCES_D);
    fileUtil.copy(ogreDir + FILE_OGRE_RESOURCES, fullOutputBinDir + FILE_OGRE_RESOURCES);

    // Copy the media
    copyDirectoryRecursively (ogreDir, fullOutputOgreDir);
}

//****************************************************************************/
void QtOgre21Builder::copyDirectoryRecursively(const QString& source, const QString& target)
{
    QFile fileUtil;

    // Create the target directory first
    QDir dirTarget;
    dirTarget.mkpath(target);

    // Get all filenames from dir and all subdirs
    QDir dir(source);
    dir.makeAbsolute();

    if (dir.exists())
    {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst))
        {
            if (info.isDir())
            {
                QString fullTarget = target + QString("/") + info.fileName();
                copyDirectoryRecursively(info.absoluteFilePath(), fullTarget);
            }
            else
            {
                QString fileName = info.fileName();
                if (fileName != FILE_OGRE_PLUGINS_D &&
                    fileName != FILE_OGRE_PLUGINS &&
                    fileName != FILE_OGRE_RESOURCES_D &&
                    fileName != FILE_OGRE_RESOURCES)
                {
                    QString fullFileName = info.absoluteFilePath();
                    fileUtil.copy(fullFileName, target + QString("/") + fileName);
                }
            }
        }
    }
}


