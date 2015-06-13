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

#ifndef MAGUS_QTBUILDER_OGRE_H
#define MAGUS_QTBUILDER_OGRE_H

#include <QString>

/****************************************************************************
 Implementation of an Ogre 3D builder class for Qt.
****************************************************************************/
class WindowProperties;

class QtOgreBuilder
{
    public:
        QtOgreBuilder();
        virtual ~QtOgreBuilder();
        QString createInclude(const QString &s);
        QString createPublicMemberForMainWindow(const QString &s);
        QString createPrivateMemberForMainWindow(const QString &s);
        QString createPrivateMemberQtOgreWidget(const QString &s);
        QString createConstructorEntryForMainWindow(const QString &s);
        QString createQtOgreWidgetForMainWindow(WindowProperties* windowProperties, const QString &s);
        QString createQtOgreWidgetForDockWindow(WindowProperties* windowProperties, const QString &s);
        QString createQtOgreWidgetForTab(WindowProperties* windowProperties, int index, const QString &s);
        QString ogreCloseForMainWindow(const QString &s);
        QString ogreCloseForDockWindow(const QString &s);
        QString createDestructorEntryForMainWindow(const QString &s);
        QString createUpdateEntryForMainWindow(const QString &s);
        QString createRootForPro(const QString &ogreRoot, const QString &s);
        QString createIncludeForPro(const QString &s);
        QString createLibForPro(const QString &s);
        QString createHeaderForPro(const QString &outputHeaderDir, const QString &s);
        QString createSrcForPro(const QString &outputSrcDir, const QString &s);
        QString createOgreAssetHeaderForPro(const QString& outputHeaderDir, const QString& s);
        QString createOgreAssetSrcForPro(const QString& outputSrcDir, const QString& s);
        void copyOgreAssetFiles(const QString& qtHeader,
                                const QString& qtSrc,
                                const QString& iconDir,
                                const QString& fullOutputHeaderDir,
                                const QString& fullOutputSrcDir,
                                const QString& fullOutputIconDir);

        void copyOgreFiles(const QString &ogreRoot,
                           const QString &ogreDir,
                           const QString &qtHeader,
                           const QString &qtSrc,
                           const QString &fullOutputHeaderDir,
                           const QString &fullOutputSrcDir,
                           const QString &fullOutputBinDir,
                           const QString &fullOutputOgreDir);
};

//****************************************************************************/
#endif
