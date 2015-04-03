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

#ifndef MAGUS_TEMPLATE_DIALOG_H
#define MAGUS_TEMPLATE_DIALOG_H

#include <QDialog>
#include <QTableView>

QT_BEGIN_NAMESPACE
class QDialog;
class QQTableView;
class QModelIndex;
QT_END_NAMESPACE

class MainWindow;

/****************************************************************************
 Selection dialog of template (ide) files.
****************************************************************************/
class TemplateDialog : public QDialog
{
    Q_OBJECT

    public:
        TemplateDialog(MainWindow* parent);

    public slots:
        void doubleClick(QModelIndex index);
        void okAndAccept(void);

    private:
        MainWindow* mParent;
        QTableView *mTable;
};

//****************************************************************************/
#endif
