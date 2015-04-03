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

#include "qtbuildermenu.h"
#include "constants.h"
#include "applicationtemplate.h"
#include "utils.h"

//****************************************************************************/
QtMenuBuilder::QtMenuBuilder()
{
}

//****************************************************************************/
QtMenuBuilder::~QtMenuBuilder()
{
}

//****************************************************************************/
QString QtMenuBuilder::createInclude(const QString &s)
{
    // Add the #include
    QString str = s;
    str = str +
    QString("#include <QMenu>") +
    QString("\n");
    return str;
}

//****************************************************************************/
QString QtMenuBuilder::createPrivateMembers(WindowMenuProperties* windowMenuProperties, const QString &s)
{
    QString str = s;
    QString menuItemName;
    QString subMenuItemName;
    WindowMenuItemProperties* item = 0;
    if (windowMenuProperties)
    {
        QVectorIterator<WindowMenuItemProperties*> itemList(windowMenuProperties->mWindowMenuItemPropertiesList);

        // Define private members
        while (itemList.hasNext())
        {
            item = itemList.next();
            menuItemName = Utils::makePrivateAttribute (item->mItemName) + QString("Menu");

            // Define private members
            str = str +
                TAB +
                TAB +
                QString("QMenu* ") +
                menuItemName +
                QString(";") +
                QString("\n");
        }
    }
    return str;
}

//****************************************************************************/
QString QtMenuBuilder::createMenuMainWindow(WindowMenuProperties* windowMenuProperties, const QString &s)
{
    QString str = s;
    QString menuItemName;
    QString subMenuItemName;
    WindowMenuItemProperties* item = 0;
    WindowMenuSubItemProperties* subItem = 0;
    if (windowMenuProperties)
    {
        QVectorIterator<WindowMenuItemProperties*> itemList(windowMenuProperties->mWindowMenuItemPropertiesList);

        // Create the menu entries for a QMainWindow; QMainWindow differs from QDockQWidget
        while (itemList.hasNext())
        {
            item = itemList.next();
            menuItemName = Utils::makePrivateAttribute (item->mItemName) + QString("Menu");

            // Define a menu item (to be connected to the menubar)
            str = str +
                TAB +
                menuItemName +
                QString(" = menuBar()->addMenu(QString(\"") +
                item->mItemName +
                QString("\"));") +
                QString("\n");

            QVectorIterator<WindowMenuSubItemProperties*> subItemList(item->mWindowMenuSubItemPropertiesList);
            while (subItemList.hasNext())
            {
                subItem = subItemList.next();
                subMenuItemName = Utils::makePrivateAttribute (subItem->mSubItemName) + QString("MenuAction");

                // Define code that adds an action to a menu item
                str = str +
                    TAB +
                    menuItemName +
                    QString("->addAction(") +
                    subMenuItemName +
                    QString(");") +
                    QString("\n");
            }
        }
    }
    return str;
}

//****************************************************************************/
QString QtMenuBuilder::createMenuDockWidget(WindowMenuProperties* windowMenuProperties, const QString &s)
{
    QString str = s;
    QString menuItemName;
    QString subMenuItemName;
    WindowMenuItemProperties* item = 0;
    WindowMenuSubItemProperties* subItem = 0;
    if (windowMenuProperties)
    {
        QVectorIterator<WindowMenuItemProperties*> itemList(windowMenuProperties->mWindowMenuItemPropertiesList);
        // Create the menu entries for a QDockQWidget; QDockQWidget differs from QMainWindow
        while (itemList.hasNext())
        {
            item = itemList.next();
            menuItemName = Utils::makePrivateAttribute (item->mItemName) + QString("Menu");

            // Define a menu item (to be connected to the menubar); this differs a bit from the method in UPDATE_CREATE
            str = str +
                TAB +
                menuItemName +
                QString(" = mInnerMain->menuBar()->addMenu(QString(\"") +
                item->mItemName +
                QString("\"));") +
                QString("\n");

            QVectorIterator<WindowMenuSubItemProperties*> subItemList(item->mWindowMenuSubItemPropertiesList);
            while (subItemList.hasNext())
            {
                subItem = subItemList.next();
                subMenuItemName = Utils::makePrivateAttribute (subItem->mSubItemName) + QString("MenuAction");

                // Add action to a menu item
                str = str +
                    TAB +
                    menuItemName +
                    QString("->addAction(") +
                    subMenuItemName +
                    QString(");") +
                    QString("\n");
            }
        }
    }
    return str;
}
