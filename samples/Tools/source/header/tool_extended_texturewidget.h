/****************************************************************************
**
** Copyright (C) 2015
**
** This file is generated by the Magus toolkit
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

#ifndef MAGUS_TOOL_ETX_TEXTURE_WIDGET_H
#define MAGUS_TOOL_EXT_TEXTURE_WIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include "tool_glspherewidget.h"

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

/*
 * TODO:
 * - Implement double mouse click
*/

namespace Magus
{
    /****************************************************************************
    Helper class to combine the texture name and the texture
    ***************************************************************************/
    class QtTextureAndText : public QWidget
    {
        Q_OBJECT

        public:
            QtTextureAndText(const QPixmap& pixmap,
                             const QString& name,
                             const QString& baseName,
                             const QSize& size,
                             QWidget* parent = 0);
            virtual ~QtTextureAndText(void);

        signals:
            // Emitted when a texture is selected (via the mouse)
            void selected(const QString& name, const QString& baseName);

        protected slots:
            void handleSelected(const QString& name, const QString& baseName);

        private:
            QtGLSphereWidget* mSphereWidget;
            QString mBaseName;
            QString mName;
            QLineEdit* mBaseNameEdit;
    };

    //****************************************************************************/
    //****************************************************************************/
    /****************************************************************************
    Main class for extended texture selection widget
    ***************************************************************************/
    class QtExtendedTextureWidget : public QWidget
    {
        Q_OBJECT

        public:
            QtExtendedTextureWidget(QWidget* parent = 0);
            virtual ~QtExtendedTextureWidget(void);

            // Add a pixmap to this widget. The name is a (fully qualified) filename for example.
            // E.g. name = "c:/temp/Tools/common/icons/info.png"
            // E.g. baseName = "info.png"
            void addTexture(const QPixmap& pixmap, const QString name, const QString baseName);

            // Delete an item from the QtExtendedTextureWidget. Use the full qualified name as search criterium.
            void deleteTexture(const QString name);

            // If a texture is originated from a file, setOriginIsFile must be set to 'true'
            void setOriginIsFile(bool originIsFile);

            // Clear the content of the widget
            void clearContent(void);

            // Return the name of the selected texture
            // E.g. "c:/temp/Tools/common/icons/info.png"
            const QString& getNameTexture(void);

            // Return the base name of the selected texture
            // E.g. "info.png" in case the name of the texture is a full qualified filename.
            const QString& getBaseNameTexture(void);

            // Define the width and height of a texture in the selection box
            void setTextureSize (QSize size);

        signals:
            // Emitted when a texture is selected (via the mouse)
            void selected(const QString& name, const QString& baseName);

        protected slots:
            void handleSelected(const QString& name, const QString& baseName);

        private:
            QListWidget* mSelectionList;
            QSize mTextureSize;
            QString mNameTexture; // In case of a filename, this is the fully qualified filename (path + filename)
            QString mBaseNameTexture; // If mNameTexture is a filename, this is the basename.
            bool mOriginIsFile;
    };
}

#endif