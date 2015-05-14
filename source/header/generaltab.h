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

#ifndef MAGUS_GENERALTAB_H
#define MAGUS_GENERALTAB_H

#include <QtWidgets>
#include <QVBoxLayout>
#include <QCheckBox>

class MainWindow;
class QLabel;

/****************************************************************************
 Represents the 'General' tab of the main window
****************************************************************************/
class GeneralTab : public QWidget
{
    Q_OBJECT

    public:
        GeneralTab(MainWindow* parent = 0);
        void setLayoutImage(const QString& name);
        QLineEdit* mProjectValue;
        QString mIconName;
        QLineEdit* mDescriptionValue;
        QLabel* mTypeValue;
        QLabel* mStyleValue;
        QCheckBox* mUseAssetWidgetCheckBox;
        QCheckBox* mUseOgreAssetWidgetCheckBox;
        QCheckBox* mUseNodeEditorCheckBox;
        QCheckBox* mUseToolsCheckBox;

    public slots:
        void addWindow();

    private:
        MainWindow* mParent;
        QLabel* mLayoutImage;
};

//****************************************************************************/
#endif
