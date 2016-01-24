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
        virtual QString createInclude(const QString &s);
        virtual QString createPublicMemberForMainWindow(const QString &s);
        virtual QString createPrivateMemberForMainWindow(const QString &s);
        virtual QString createPrivateMemberQtOgreWidget(const QString &s);
        virtual QString createConstructorEntryForMainWindow(const QString &s);
        virtual QString createQtOgreWidgetForMainWindow(WindowProperties* windowProperties, const QString &s);
        virtual QString createQtOgreWidgetForDockWindow(WindowProperties* windowProperties, const QString &s);
        virtual QString createQtOgreWidgetForTab(WindowProperties* windowProperties, int index, const QString &s);
        //virtual QString ogreCloseForMainWindow(const QString &s);
        //virtual QString ogreCloseForDockWindow(const QString &s);
        virtual QString createDestructorEntryForMainWindow(const QString &s);
        virtual QString createUpdateEntryForMainWindow(const QString &s);
        virtual QString createInitializeEntryForMainWindow(const QString &s);
        virtual QString createRootForPro(const QString &ogreRoot, const QString &s);
        virtual QString createIncludeForPro(const QString &s);
        virtual QString createLibForPro(const QString &s);
        virtual QString createHeaderForPro(const QString &outputHeaderDir, const QString &s);
        virtual QString createSrcForPro(const QString &outputSrcDir, const QString &s);
        virtual QString createOgreAssetHeaderForPro(const QString& outputHeaderDir, const QString& s);
        virtual QString createOgreAssetSrcForPro(const QString& outputSrcDir, const QString& s);
        virtual void copyOgreAssetFiles(const QString& qtHeader,
                                        const QString& qtSrc,
                                        const QString& iconDir,
                                        const QString& fullOutputHeaderDir,
                                        const QString& fullOutputSrcDir,
                                        const QString& fullOutputIconDir);
        virtual void copyOgreFiles(const QString &ogreRoot,
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
