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

#include "qtbuilderaction.h"
#include "constants.h"
#include "qtbuilder.h"
#include "utils.h"
#include "applicationtemplate.h"

//****************************************************************************/
QtActionBuilder::QtActionBuilder()
{
}

//****************************************************************************/
QtActionBuilder::~QtActionBuilder()
{
}

//****************************************************************************/
QString QtActionBuilder::createInclude(const QString &s)
{
    QString str = s;

    // Add the #include
    str = str +
        QString("#include <QAction>") +
        QString("\n");
    str = str +
        QString("#include <QMessageBox>") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtActionBuilder::createPrivateMembers(WindowProperties* windowProperties,
                                              WindowMenuProperties* windowMenuProperties,
                                              const QString &s)
{
    QString str = s;
    str = str + updatePrivateMembersMenu(windowMenuProperties);
    str = str + updatePrivateMembersToolbar(windowProperties);

    return str;
}

//****************************************************************************/
QString QtActionBuilder::createPrivateSlots(WindowProperties* windowProperties,
                                            WindowMenuProperties* windowMenuProperties,
                                            const QString &s)
{
    QString str = s;
    str = str + createPrivateSlotsForMenu(windowMenuProperties);
    str = str + createPrivateSlotsForToolbar(windowProperties);

    return str;
}

//****************************************************************************/
QString QtActionBuilder::createActions(WindowProperties* windowProperties,
                                       WindowMenuProperties* windowMenuProperties,
                                       const QString &s,
                                       const QString &iconDir,
                                       const QString &fullOutputIconDir)
{
    QString str = s;
    str = str + createActionsForMenu(windowMenuProperties);
    str = str + createActionsForToolbar(windowProperties, iconDir, fullOutputIconDir);

    return str;
}


//****************************************************************************/
QString QtActionBuilder::createDoActions(ApplicationTemplate* applicationTemplate,
                                         WindowProperties* windowProperties,
                                         WindowMenuProperties* windowMenuProperties,
                                         const QString &s)
{
    QString str = s;
    str = str + createDoActionsForMenu(applicationTemplate, windowProperties, windowMenuProperties);
    str = str + createDoActionsForToolbar(windowProperties);

    return str;
}

/****************************************************************************
 Generates code related to actions (.h code)
****************************************************************************/
QString QtActionBuilder::updatePrivateMembersMenu(WindowMenuProperties* windowMenuProperties)
{
    QString str;
    QString subMenuItemName;
    WindowMenuItemProperties* item = 0;
    WindowMenuSubItemProperties* subItem = 0;
    if (windowMenuProperties)
    {
        // Private members for the menu
        QVectorIterator<WindowMenuItemProperties*> itemList(windowMenuProperties->mWindowMenuItemPropertiesList);
        while (itemList.hasNext())
        {
            item = itemList.next();
            QVectorIterator<WindowMenuSubItemProperties*> subItemList(item->mWindowMenuSubItemPropertiesList);
            while (subItemList.hasNext())
            {
                subItem = subItemList.next();
                subMenuItemName = Utils::makePrivateAttribute (subItem->mSubItemName) + QString("MenuAction");

                // Define QAction members
                str = str +
                    TAB +
                    TAB +
                    QString("QAction* ") +
                    subMenuItemName +
                    QString(";") +
                    QString("\n");
            }
        }
    }
    return str;
}

/****************************************************************************
 Generates private member code for toolbars (.h code)
****************************************************************************/
QString QtActionBuilder::updatePrivateMembersToolbar(WindowProperties* windowProperties)
{
    QString str;
    QString iconAction;
    ToolbarProperties* toolbarProperties = 0;

    // Horizontal toolbar
    if (!windowProperties->mHToolbarPropertiesList.empty())
    {
        // Private members for the toolbars
        // Define an actions to be used by the toolbar (based on the icon name)
        QVectorIterator<ToolbarProperties*> hList(windowProperties->mHToolbarPropertiesList);
        hList.toFront();
        while (hList.hasNext())
        {
            // Define QAction members
            toolbarProperties = hList.next();

            if (toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR1 &&
                toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR2)
            {
                iconAction = toolbarProperties->mIcon;
                iconAction = Utils::stripExtension(iconAction);
                iconAction = Utils::makePrivateAttribute(iconAction) + POST_ACTION_HTOOLBAR;

                str = str +
                    TAB +
                    TAB +
                    QString("QAction* ") +
                    iconAction +
                    QString(";") +
                    QString("\n");
            }
        }
    }

    // Vertical toolbar
    if (!windowProperties->mVToolbarPropertiesList.empty())
    {
        // Define an actions to be used by the toolbar (based on the icon name)
        QVectorIterator<ToolbarProperties*> vList(windowProperties->mVToolbarPropertiesList);
        vList.toFront();
        while (vList.hasNext())
        {
            // Define QAction members
            toolbarProperties = vList.next();

            if (toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR1 &&
                toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR2)
            {
                iconAction = toolbarProperties->mIcon;
                iconAction = Utils::stripExtension(iconAction);
                iconAction = Utils::makePrivateAttribute(iconAction) + POST_ACTION_VTOOLBAR;

                str = str +
                    TAB +
                    TAB +
                    QString("QAction* ") +
                    iconAction +
                    QString(";") +
                    QString("\n");
            }
        }
    }

    // Toolbar widgets
    if (windowProperties->mUseTransformationWidget)
    {
        str = str +
            TAB +
            TAB +
            QString("Magus::TransformationWidget* mTransformationWidget;") +
            QString("\n");
    }

    return str;
}

/****************************************************************************
 Generates code for private slots on behalf of the menu (.h code)
****************************************************************************/
QString QtActionBuilder::createPrivateSlotsForMenu(WindowMenuProperties* windowMenuProperties)
{
    QString str;
    WindowMenuItemProperties* item = 0;
    WindowMenuSubItemProperties* subItem = 0;

    if (windowMenuProperties)
    {
        QVectorIterator<WindowMenuItemProperties*> itemList(windowMenuProperties->mWindowMenuItemPropertiesList);
        while (itemList.hasNext())
        {
            item = itemList.next();
            QVectorIterator<WindowMenuSubItemProperties*> subItemList(item->mWindowMenuSubItemPropertiesList);
            while (subItemList.hasNext())
            {
                subItem = subItemList.next();

                // Define a function (do Action) for each menu action
                str = str +
                    TAB +
                    TAB +
                    QString("void do") +
                    Utils::stripSpecialCharacters(subItem->mSubItemName) +
                    QString("MenuAction(void);") +
                    QString("\n");
            }
        }
    }

    return str;
}

/****************************************************************************
 Generates code for private slots on behalf of the toolbars (.h code)
****************************************************************************/
QString QtActionBuilder::createPrivateSlotsForToolbar(WindowProperties* windowProperties)
{
    QString str;
    QString stripped;
    QString iconAction;
    //ToolbarProperties* toolbarProperties = 0;

    // Define a function (do Action) for each toolbar action
    // Horizontal toolbar
    if (!windowProperties->mHToolbarPropertiesList.empty())
    {
        QVectorIterator<ToolbarProperties*> hList(windowProperties->mHToolbarPropertiesList);
        str = str + createPrivateSlotForOneToolbar(windowProperties, &hList, POST_ACTION_HTOOLBAR);
    }

    // Vertical toolbar
    if (!windowProperties->mVToolbarPropertiesList.empty())
    {
        QVectorIterator<ToolbarProperties*> vList(windowProperties->mVToolbarPropertiesList);
        str = str + createPrivateSlotForOneToolbar(windowProperties, &vList, POST_ACTION_VTOOLBAR);
    }

    // Toolbar widgets
    if (windowProperties->mUseTransformationWidget)
    {
        str = str +
            TAB +
            TAB +
            QString("void doTransformationWidgetValueChanged(void);") +
            QString("\n");
    }

    return str;
}

/****************************************************************************
 Generates code for a private slot for one toolbar, horizontal or vertical (.h code)
****************************************************************************/
QString QtActionBuilder::createPrivateSlotForOneToolbar(WindowProperties* windowProperties,
                                                        QVectorIterator<ToolbarProperties*>* list,
                                                        const QString &postPriveSlotName)
{
    QString str;
    QString stripped;
    QString iconAction;
    ToolbarProperties* toolbarProperties = 0;
    list->toFront();
    while (list->hasNext())
    {
        // Define a function (do Action) for each toolbar action
        toolbarProperties = list->next();

        if (toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR1 &&
            toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR2)
        {
            stripped = toolbarProperties->mIcon;
            stripped = Utils::stripExtension(stripped);
            stripped = Utils::firstCapital(stripped);
            iconAction = Utils::stripSpecialCharacters(stripped) + postPriveSlotName;
            str = str +
                TAB +
                TAB +
                QString("void do") +
                iconAction +
                QString("(void);") +
                QString("\n");
        }
    }

    return str;
}

/****************************************************************************
 Generates code for the createAction function on behalf of the menu (.cpp code)
****************************************************************************/
QString QtActionBuilder::createActionsForMenu(WindowMenuProperties* windowMenuProperties)
{
    QString str;
    QString subMenuItemName;
    WindowMenuItemProperties* item = 0;
    WindowMenuSubItemProperties* subItem = 0;
    if (windowMenuProperties)
    {
        // Create actions for the menu
        QVectorIterator<WindowMenuItemProperties*> itemList(windowMenuProperties->mWindowMenuItemPropertiesList);
        while (itemList.hasNext())
        {
            item = itemList.next();
            QVectorIterator<WindowMenuSubItemProperties*> subItemList(item->mWindowMenuSubItemPropertiesList);
            while (subItemList.hasNext())
            {
                subItem = subItemList.next();
                subMenuItemName = Utils::makePrivateAttribute(subItem->mSubItemName) + QString("MenuAction");

                // Define the code that creates the actions
                str = str +
                    TAB +
                    subMenuItemName +
                    QString(" = new QAction(QString(\"") +
                    subItem->mSubItemName +
                    QString("\"), this);") +
                    QString("\n");


                // Connect it to the doAction function
                str = str +
                    TAB +
                    QString("connect(") +
                    subMenuItemName +
                    QString(", SIGNAL(triggered()), this, SLOT(do") +
                    Utils::stripSpecialCharacters(subItem->mSubItemName) +
                    QString("MenuAction()));") +
                    QString("\n");
            }
        }
    }

    return str;
}

/****************************************************************************
 Generates code for the createAction function on behalf of the toolbars
 (.cpp code)
****************************************************************************/
QString QtActionBuilder::createActionsForToolbar(WindowProperties* windowProperties,
                                                 const QString &iconDir,
                                                 const QString &fullOutputIconDir)
{
    QString str;
    QString stripped;
    QString iconAction;
    //ToolbarProperties* toolbarProperties = 0;

    // Create actions for the toolbars
    // Horizontal toolbar
    if (!windowProperties->mHToolbarPropertiesList.empty())
    {
        QVectorIterator<ToolbarProperties*> hList(windowProperties->mHToolbarPropertiesList);
        str = str + createActionsForOneToolbar(windowProperties, &hList, POST_ACTION_HTOOLBAR, iconDir, fullOutputIconDir);
    }

    // Vertical toolbar
    if (!windowProperties->mVToolbarPropertiesList.empty())
    {
        QVectorIterator<ToolbarProperties*> vList(windowProperties->mVToolbarPropertiesList);
        str = str + createActionsForOneToolbar(windowProperties, &vList, POST_ACTION_VTOOLBAR, iconDir, fullOutputIconDir);
    }

    return str;
}

/****************************************************************************
 Generates code for the createAction function on behalf of one toolbar,
 horizontal or vertical (.cpp code)
****************************************************************************/
QString QtActionBuilder::createActionsForOneToolbar(WindowProperties* windowProperties,
                                                    QVectorIterator<ToolbarProperties*> *list,
                                                    const QString &postPriveSlotName,
                                                    const QString &iconDir,
                                                    const QString &fullOutputIconDir)
{
    QString str;
    QString stripped;
    QString iconAction;
    ToolbarProperties* toolbarProperties = 0;

    // Define actions to be used by the toolbar (based on the icon name)
    QFile fileUtil;
    list->toFront();
    while (list->hasNext())
    {
        toolbarProperties = list->next();

        if (toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR1 &&
            toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR2)
        {
            stripped = toolbarProperties->mIcon;
            stripped = Utils::stripExtension(stripped);
            stripped = Utils::stripSpecialCharacters(stripped);
            stripped = Utils::firstCapital(stripped);
            iconAction = Utils::makePrivateAttribute (stripped) + postPriveSlotName;

            // Copy the icon
            fileUtil.copy(iconDir + toolbarProperties->mIcon, fullOutputIconDir + toolbarProperties->mIcon);

            // Define the code that creates the actions
            str = str +
                TAB +
                iconAction +
                QString(" = new QAction(QIcon(\"") +
                iconDir +
                toolbarProperties->mIcon +
                QString("\"), QString(\"Insert tooltip for <") +
                iconAction +
                QString("> here\"), this);") +
                QString("\n");

            // Connect it to the doAction function
            str = str +
                TAB +
                QString("connect(") +
                iconAction +
                QString(", SIGNAL(triggered()), this, SLOT(do") +
                stripped +
                postPriveSlotName +
                QString("()));") +
                QString("\n");
        }
    }

    return str;
}


/****************************************************************************
 Generates code for the do...Action functions in behalf of the menu (.cpp code)
****************************************************************************/
QString QtActionBuilder::createDoActionsForMenu(ApplicationTemplate* applicationTemplate,
                                                WindowProperties* windowProperties,
                                                WindowMenuProperties* windowMenuProperties)
{
    QString str;
    QString className;
    WindowMenuItemProperties* item = 0;
    WindowMenuSubItemProperties* subItem = 0;

    if (windowMenuProperties)
    {
        if (windowProperties->mOrder == 0)
        {
            className = QString("MainWindow");
        }
        else
        {
            className = Utils::stripSpecialCharacters(windowProperties->mTitle) + QString("DockWidget");
            //className = windowProperties->mTitle + QString("DockWidget");
        }

        // Create doActions for the menu
        QVectorIterator<WindowMenuItemProperties*> itemList(windowMenuProperties->mWindowMenuItemPropertiesList);
        while (itemList.hasNext())
        {
            item = itemList.next();
            QVectorIterator<WindowMenuSubItemProperties*> subItemList(item->mWindowMenuSubItemPropertiesList);
            while (subItemList.hasNext())
            {
                subItem = subItemList.next();

                // Separator
                str = str +
                    QString("//****************************************************************************/") +
                    QString("\n");

                // Function definition
                str = str +
                    QString("void ") +
                    className +
                    QString("::do") +
                    Utils::stripSpecialCharacters(subItem->mSubItemName) +
                    QString("MenuAction(void)") +
                    QString("\n");

                str = str +
                    QString("{") +
                    QString("\n");

                // Perform default action if checked
                if (windowProperties->mUseDefaultActionExit &&
                    Utils::stripSpecialCharacters(subItem->mSubItemName) == Utils::stripSpecialCharacters(KEYWORD_MENU_EXIT))
                {
                    str = str +
                        TAB +
                        QString("close();") +
                        QString("\n");
                }
                else if (windowProperties->mUseDefaultActionQuit &&
                    Utils::stripSpecialCharacters(subItem->mSubItemName) == Utils::stripSpecialCharacters(KEYWORD_MENU_QUIT))
                {
                    str = str +
                        TAB +
                        QString("close();") +
                        QString("\n");
                }
                else if (windowProperties->mUseDefaultActionAbout &&
                    Utils::stripSpecialCharacters(subItem->mSubItemName) == Utils::stripSpecialCharacters(KEYWORD_MENU_ABOUT))
                {
                    // Display an About messagebox
                    str = str +
                        TAB +
                        QString("QMessageBox::about(this, QString(\"About\"), QString(\"Copyright 2016\"));") +
                        QString("\n");
                }
                else if (windowProperties->mUseDefaultActionResetWindows &&
                    Utils::stripSpecialCharacters(subItem->mSubItemName) == Utils::stripSpecialCharacters(KEYWORD_MENU_RESET_WINDOWS))
                {
                    if (windowProperties->mOrder == 0)
                    {
                        // Adjust the window layouts; this can only be done for the mainwindow
                        str = str + getResetWindowLayoutString(applicationTemplate, windowProperties);
                    }
                }
                else
                {
                    // Display a messagebox
                    str = str +
                        TAB +
                        QString("// Replace the code in this function with your own code.") +
                        QString("\n");
                    str = str +
                        TAB +
                        QString("QMessageBox::information(this, QString(\"QAction\"), QString(\"Menu item <") +
                        subItem->mSubItemName +
                        QString("> selected;\\n") +
                        className +
                        QString("::do") +
                        Utils::stripSpecialCharacters(subItem->mSubItemName) +
                        QString("MenuAction()") +
                        QString(" called\"));") +
                        QString("\n");
                }

                str = str +
                    QString("}") +
                    QString("\n\n");
            }
        }
    }

    return str;
}

/****************************************************************************
 Generates code for the do...Action functions in behalf of the toolbars (.cpp code)
****************************************************************************/
QString QtActionBuilder::createDoActionsForToolbar(WindowProperties* windowProperties)
{
    QString str;
    QString stripped;
    QString iconAction;
    QString className;
    //ToolbarProperties* toolbarProperties = 0;

    // Create doActions for the toolbars
    if (windowProperties->mOrder == 0)
    {
        className = QString("MainWindow");
    }
    else
    {
        className = Utils::stripSpecialCharacters(windowProperties->mTitle) + QString("DockWidget");
        //className = windowProperties->mTitle + QString("DockWidget");
    }

    // Horizontal toolbar
    if (!windowProperties->mHToolbarPropertiesList.empty())
    {
        QVectorIterator<ToolbarProperties*> hList(windowProperties->mHToolbarPropertiesList);
        str = str + createDoActionForOneToolbar(windowProperties, &hList, className, POST_ACTION_HTOOLBAR);
    }

    // Vertical toolbar
    if (!windowProperties->mVToolbarPropertiesList.empty())
    {
        QVectorIterator<ToolbarProperties*> vList(windowProperties->mVToolbarPropertiesList);
        str = str + createDoActionForOneToolbar(windowProperties, &vList, className, POST_ACTION_VTOOLBAR);
    }

    // In addition, toolbar widgets
    if (windowProperties->mUseTransformationWidget)
    {
        // Separator
        str = str +
            QString("//****************************************************************************/") +
            QString("\n");

        // Function definition
        str = str +
            QString("void ") +
            className +
            QString("::doTransformationWidgetValueChanged(void)") +
            QString("\n");

        str = str +
            QString("{") +
            QString("\n");

        // Define the inner code
        str = str +
            TAB +
            QString("// Replace the code in this function with your own code.") +
            QString("\n");

        str = str +
            TAB +
            QString("switch (mTransformationWidget->getCurrentTransformation())") +
            QString("\n");

        str = str +
            TAB +
            QString("{") +
            QString("\n");

        str = str +
            TAB + TAB +
            QString("case Magus::TransformationWidget::POSITION:") +
            QString("\n");

        str = str +
            TAB + TAB + TAB +
            QString("QMessageBox::information(this, QString(\"TransformationWidget\"),") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QString(\"Value Position changed: \") +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QVariant(mTransformationWidget->getPosition().x()).toString() +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QString(\", \") +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QVariant(mTransformationWidget->getPosition().y()).toString() +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QString(\", \") +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QVariant(mTransformationWidget->getPosition().z()).toString());") +
            QString("\n");

        str = str +
            TAB + TAB +
            QString("break;") +
            QString("\n");

        str = str +
            TAB + TAB +
            QString("case Magus::TransformationWidget::ROTATION:") +
            QString("\n");

        str = str +
            TAB + TAB + TAB +
            QString("QMessageBox::information(this, QString(\"TransformationWidget\"),") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QString(\"Value Rotation changed: \") +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QVariant(mTransformationWidget->getRotation().x()).toString() +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QString(\", \") +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QVariant(mTransformationWidget->getRotation().y()).toString() +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QString(\", \") +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QVariant(mTransformationWidget->getRotation().z()).toString());") +
            QString("\n");

        str = str +
            TAB + TAB +
            QString("break;") +
            QString("\n");

        str = str +
            TAB + TAB +
            QString("case Magus::TransformationWidget::SCALE:") +
            QString("\n");

        str = str +
            TAB + TAB + TAB +
            QString("QMessageBox::information(this, QString(\"TransformationWidget\"),") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QString(\"Value Scale changed: \") +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QVariant(mTransformationWidget->getScale().x()).toString() +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QString(\", \") +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QVariant(mTransformationWidget->getScale().y()).toString() +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QString(\", \") +") +
            QString("\n");

        str = str +
            TAB + TAB + TAB + TAB +
            QString("QVariant(mTransformationWidget->getScale().z()).toString());") +
            QString("\n");

        str = str +
            TAB + TAB +
            QString("break;") +
            QString("\n");

        str = str +
            TAB +
            QString("}") +
            QString("\n");

        str = str +
            QString("}") +
            QString("\n\n");
    }

    return str;
}

/****************************************************************************
 Generates code for the do...Action functions in behalf of one toolbar (.cpp code)
****************************************************************************/
QString QtActionBuilder::createDoActionForOneToolbar(WindowProperties* windowProperties,
                                                     QVectorIterator<ToolbarProperties*>* list,
                                                     const QString &className,
                                                     const QString &postPriveSlotName)
{
    QString str;
    QString stripped;
    QString iconAction;
    ToolbarProperties* toolbarProperties = 0;

    // do..Actions for the icons
    list->toFront();
    while (list->hasNext())
    {
        // Define a function (do Action) for each toolbar action
        toolbarProperties = list->next();

        if (toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR1 &&
            toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR2)
        {
            stripped = toolbarProperties->mIcon;
            stripped = Utils::stripExtension(stripped);
            stripped = Utils::firstCapital(stripped);
            iconAction = Utils::stripSpecialCharacters(stripped) + postPriveSlotName;

            // Separator
            str = str +
                QString("//****************************************************************************/") +
                QString("\n");

            // Function definition
            str = str +
                QString("void ") +
                className +
                QString("::do") +
                iconAction +
                QString("(void)") +
                QString("\n");

            str = str +
                QString("{") +
                QString("\n");

            // Display a messagebox
            str = str +
                TAB +
                QString("// Replace the code in this function with your own code.") +
                QString("\n");

            str = str +
                TAB +
                QString("QMessageBox::information(this, QString(\"QAction\"), QString(\"Toolbar item <m") +
                iconAction +
                QString("> selected;\\n") +
                className +
                QString("::do") +
                stripped +
                QString("MenuAction()") +
                QString(" called\"));") +
                QString("\n");

            str = str +
                QString("}") +
                QString("\n\n");
        }
    }

    return str;
}

/****************************************************************************
 Generates code to reset the window layout (.cpp code)
****************************************************************************/
QString QtActionBuilder::getResetWindowLayoutString(ApplicationTemplate* applicationTemplate,
                                                    WindowProperties* currentWindowProperties)
{
    // Define code to show all dockwidgets; this can only be done for the mainwindow
    QString str;
    QString area;
    QString privateAttribute;
    QVectorIterator<WindowProperties*> windowPropertiesList(applicationTemplate->mWindowPropertiesList);
    WindowProperties* windowProperties = 0;
    while (windowPropertiesList.hasNext())
    {
        windowProperties = windowPropertiesList.next();
        if (windowProperties->mOrder != 0)
        {
            // It is a dockwidget, show it
            str = str +
                TAB +
                Utils::makePrivateAttribute(windowProperties->mTitle) + QString("DockWidget->show();") +
                QString("\n");

            // Move the dockwidget to its orignal area
            str = str + getDockWidgetToAreaString(windowProperties);
        }
    }

    return str;
}

/****************************************************************************
 Generates code to add the DockWidget to the Mainwindow, with the proper area (.cpp code)
****************************************************************************/
QString QtActionBuilder::getDockWidgetToAreaString(WindowProperties* currentWindowProperties)
{
    // Set the dockwidget to its orignal area
    QString privateAttribute = Utils::makePrivateAttribute(currentWindowProperties->mTitle) + QString("DockWidget");
    QString str;
    QString area;
    if (currentWindowProperties->mArea == AREA_CENTER)
    {
        // Center the widget in the mainwindow
        str = str +
            TAB +
            QString("setCentralWidget(") +
            privateAttribute +
            QString(");") +
            QString("\n");
    }
    else
    {
        area = QString("Qt::LeftDockWidgetArea"); // The default
        if (currentWindowProperties->mArea == AREA_RIGHT)
            area = QString("Qt::RightDockWidgetArea");
        else
            if (currentWindowProperties->mArea == AREA_TOP)
                area = QString("Qt::TopDockWidgetArea");
            else
                if (currentWindowProperties->mArea == AREA_BOTTOM)
                    area = QString("Qt::BottomDockWidgetArea");

        str = str +
            TAB +
            QString("addDockWidget(") +
            area +
            QString(", ") +
            privateAttribute +
            QString(");") +
            QString("\n");
    }

    return str;
}
