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

#ifndef MAGUS_TEMPLATEREADER_H
#define MAGUS_TEMPLATEREADER_H

#include <QSettings>
#include <QString>
#include <QVector>
#include "applicationtemplate.h"

QT_BEGIN_NAMESPACE
class QSettings;
class QString;
QT_END_NAMESPACE

/****************************************************************************
 A TemplateReader parses the data of a template or project file and stores
 the data in ApplicationTemplate datastructures, so it can be used to build
 the widgets in the  Magus application.
 A template file is a file with .ide extension. It contains the definition
 of a project (e.g. layout, menu structure, number of windows, ...).
 Project files are derived from template files, and can be customized in the
 Magus application.
****************************************************************************/
class TemplateReader
{
    public:
        TemplateReader(void);
        virtual ~TemplateReader(void);
        void clear(void);
        void readGeneral (ApplicationTemplate* applicationTemplate, const QString &fileName, QSettings::Format format);
        void readAll (ApplicationTemplate* applicationTemplate, const QString &fileName, QSettings::Format format);

    private:
        enum ToolbarGroup {TOOLBARGROUP_HORIZONTAL, TOOLBARGROUP_VERTICAL};
        void readIndividualProperties(QSettings* settings, WindowProperties* windowProperties);
        void readMenu(QSettings* settings, WindowProperties* windowProperties);
        void readToolbar(QSettings* settings, WindowProperties* windowProperties, ToolbarGroup parentGroup);
        void readTabs(QSettings* settings, WindowProperties* windowProperties);

};

//****************************************************************************/
#endif
