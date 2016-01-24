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

#ifndef MAGUS_ICON_DIALOG_H
#define MAGUS_ICON_DIALOG_H

#include <QDialog>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QDialog;
QT_END_NAMESPACE

class IconComboBox;
class QListView;
class IconReader;
class QDialogButtonBox;
class IconSelectionModel;
class QLineEdit;

/****************************************************************************
 Selection dialog of icons.
****************************************************************************/
class IconDialog : public QDialog
{
    Q_OBJECT

    public:
        IconDialog(IconReader* iconReader,
                   const QString &iconDir,
                   const QString &tabName,
                   const QString &iconName,
                   QWidget* parent = 0);
        virtual ~IconDialog(void){};
        const QString getIconName(void) const;
        const QString getTabName(void) const;

    public slots:
        virtual void accept (void);

    protected slots:
        void handleSelectionChanged(int index);
        void doubleClickedSlot(void);


    private:
        IconComboBox* mCategoryComboBox;
        IconSelectionModel* mSelectionModel;
        QListView* mSelectionList;
        QDialogButtonBox* mButtonBox;
        QLineEdit* mTabEdit;
        QString mIconName;
        QString mTabName;
};

//****************************************************************************/
#endif
