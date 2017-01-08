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

#ifndef MAGUS_WXWIDGETSBUILDER_H
#define MAGUS_WXWIDGETSBUILDER_H

#include <QMessageBox>
#include "builder.h"

/****************************************************************************
 Implementation of a builder class for WxWidgets.
****************************************************************************/
class WxWidgetsBuilder : public Builder
{
    public:
        WxWidgetsBuilder(){};
        virtual ~WxWidgetsBuilder(){};

        const QString getType(void) const {return BUILDER_TYPE_WXWIDGETS;};
        void setOutputDir (const QString& outputDir){};
        void setOgre (bool ogreRootUseEnv,
                      const QString& ogreRootEnv,
                      const QString& ogreRoot,
                      const QString& ogreBuildDir,
                      const QString& ogreVersion){};
        bool isMenuAvailable(){return true;};
        bool isHorizontalToolbarAvailable(){return false;};
        bool isVerticalToolbarAvailable(){return false;};
        bool isOgre3dControlAvailable(){return false;};
        void build(ApplicationTemplate* applicationTemplate)
        {
            QMessageBox::information(0, QString("Build"), QString("Not implemented yet for wxWidgets"));
        };
};

//****************************************************************************/
#endif
