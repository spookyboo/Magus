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

#ifndef MAGUS_QTBUILDER_OGRE21_H
#define MAGUS_QTBUILDER_OGRE21_H

#include "qtbuilderogre20.h"

/****************************************************************************
Implementation of a Qt Ogre 3D builder class for Ogre version 2.1
****************************************************************************/
class QtOgre21Builder : public QtOgre20Builder
{
    public:
        QtOgre21Builder();
        virtual ~QtOgre21Builder();
        virtual QString createIncludeForPro(const QString &ogreBuildDir, const QString &s);
        virtual QString createLibForPro(const QString &ogreBuildDir, const QString &s);
        virtual QString createHeaderForPro(const QString &outputHeaderDir, const QString &s);
        virtual QString createSrcForPro(const QString &outputSrcDir, const QString &s);
        virtual QString createInclude(const QString &s);
        virtual void copyOgreFiles(const QString &ogreRoot,
                                   const QString &ogreBuildDir,
                                   const QString &ogreDir,
                                   const QString &qtHeader,
                                   const QString &qtSrc,
                                   const QString &fullOutputHeaderDir,
                                   const QString &fullOutputSrcDir,
                                   const QString &fullOutputBinDir,
                                   const QString &fullOutputOgreDir);
    protected:
        void copyDirectoryRecursively(const QString& source, const QString& target);
};

//****************************************************************************/
#endif
