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

#ifndef MAGUS_BUILDER_H
#define MAGUS_BUILDER_H

#include "constants.h"

class ApplicationTemplate;

/****************************************************************************
 The builder class is a pure virtual class, used to actually build the gui
 sources. You should subclass from the Builder class and implement the
 building actions for a particular type of gui (Qt, WxWidgets, WPF, ...)
 Standard in the Magus package are a Qt builder and a WxWidgets builder.
 Additional builders are custom.
****************************************************************************/
class Builder
{
    public:
        Builder(void){};
        virtual ~Builder(void){};

        // Get the type of the builder
        virtual const QString getType(void) const = 0;

        // Set the directory where the files are written
        virtual void setOutputDir (const QString& outputDir) = 0;

        // Set Ogre location
        virtual void setOgre (const QString& ogreRootEnv, const QString& ogreRoot) = 0;

        // Define which gui items are available
        virtual bool isMenuAvailable() = 0;
        virtual bool isHorizontalToolbarAvailable() = 0;
        virtual bool isVerticalToolbarAvailable() = 0;
        virtual bool isOgre3dControlAvailable() = 0;

        // Build it
        virtual void build(ApplicationTemplate* applicationTemplate) = 0;
};

//****************************************************************************/
#endif
