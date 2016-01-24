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

#ifndef MAGUS_TEMPLATEWRITER_H
#define MAGUS_TEMPLATEWRITER_H

#include <QSettings>
#include <QString>
#include <QVector>
#include "applicationtemplate.h"

QT_BEGIN_NAMESPACE
class QSettings;
class QString;
QT_END_NAMESPACE


/****************************************************************************
 A TemplateWriter reads the datastructures containing the current state of
 the Magus editor and writes the data to a project file (this is the same as
 a template (ide) file.
 The datastructures (GeneralProperties and WindowProperties objects) must be
 filled already.
****************************************************************************/
class TemplateWriter
{
    public:
        TemplateWriter(void);
        virtual ~TemplateWriter(void);
        void writeAll(ApplicationTemplate* applicationTemplate, const QString &fileName);

    private:
        const QString boolToString(const bool boolValue);
};

//****************************************************************************/
#endif
