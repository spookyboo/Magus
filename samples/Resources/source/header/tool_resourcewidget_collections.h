/****************************************************************************
**
** Copyright (C) 2016
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

#ifndef MAGUS_TOOL_RESOURCES_COLLECTIONS_H
#define MAGUS_TOOL_RESOURCES_COLLECTIONS_H

#include <QtWidgets>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QToolBar>
#include <QTabWidget>

QT_BEGIN_NAMESPACE
class QDockWidget;
QT_END_NAMESPACE

namespace Magus
{
    /****************************************************************************
    This class represents a DockWidget
    ***************************************************************************/
    class QtCollectionsDockWidget : public QDockWidget
    {
        Q_OBJECT

        public:
            QtCollectionsDockWidget(const QString& iconDir, const QString& title, QMainWindow* parent, Qt::WindowFlags flags = 0);
            ~QtCollectionsDockWidget(void);
            void createActions(void);
            void createMenus(void);
            void createToolBars(void);

        private slots:

        private:
            QMainWindow* mParent;
            QMainWindow* mInnerMain;
            QString mIconDir;
    };
}

#endif

