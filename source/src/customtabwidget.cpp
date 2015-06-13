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

#include <QMessageBox>
#include <QVariant>
#include "application.h"
#include "icondialog.h"
#include "namedicon.h"
#include "customtabwidget.h"

//****************************************************************************/
CustomTabWidget::CustomTabWidget(QWidget* parent,
                                 MainApplication* app,
                                 IconReader* iconReader,
                                 QString iconDir) : QTabWidget(parent), mApp(app), mIconReader(iconReader)
{
    setMouseTracking(true);
    tabBar()->setMouseTracking(true);
    mMouseOver = false;
    mIconDir = iconDir;
    app->registerForMouseButtonDblClick(this);
}

//****************************************************************************/
CustomTabWidget::~CustomTabWidget(void)
{
    mApp->unregisterForMouseButtonDblClick(this);
}

//****************************************************************************/
void CustomTabWidget::mouseMoveEvent(QMouseEvent* event)
{
    mMouseOver = isOver(event);
    return QTabWidget::mouseMoveEvent(event);
}

//****************************************************************************/
int CustomTabWidget::addTab(QWidget* page, const NamedIcon &icon, const QString &label)
{
    int index = QTabWidget::addTab (page, icon, label);
    mNames.insert(index, icon.mName);
    return index;
}

//****************************************************************************/
void CustomTabWidget::removeTab (int index)
{
    mNames.removeAt(index);
    QTabWidget::removeTab(index);
}

//****************************************************************************/
const QString CustomTabWidget::getIconName(int index) const
{
    return mNames.value(index);
}

//****************************************************************************/
const QString CustomTabWidget::getTabName(int index) const
{
    return tabText(index);
}

//****************************************************************************/
void CustomTabWidget::handleEvent(QEvent* event)
{
    // Handling a doubleclick on a tab is not standard. It is done by registering at the application
    // and checking whether the mouse is over one of the tabs
    if (mMouseOver && event->type() == QEvent::MouseButtonDblClick)
    {
        QMouseEvent* e = static_cast<QMouseEvent*>(event);
        if (isOver(e))
        {
            // Open the dialog to select an icon and enter a name (of the tab)
            IconDialog dialog (mIconReader,
                               mIconDir,
                               tabText(currentIndex()),
                               mNames.value(currentIndex()),
                               this);
            dialog.move(e->screenPos().x(), e->screenPos().y() - (ICON_DIALOG_SELECTION_HEIGHT + 32));
            if (dialog.exec())
            {
                // Set the selected name and icon
                setTabIcon(QVariant(currentIndex()).toInt(), QIcon(mIconDir + dialog.getIconName()));
                mNames.removeAt(currentIndex());
                mNames.insert(currentIndex(), dialog.getIconName());
                int index = QVariant(currentIndex()).toInt();
                setTabText(index, dialog.getTabName());
                emit tabTextChanged(index);
            }

            mMouseOver = false;
        }
    }
}

//****************************************************************************/
bool CustomTabWidget::isOver(QMouseEvent* mouseEvent)
{
    QTabBar* wid = tabBar();
    return (wid && wid->tabAt(mouseEvent->pos()) != -1);
}
