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

#include "qtbuildertoolbar.h"
#include "qtbuilder.h"
#include "applicationtemplate.h"
#include "utils.h"

//****************************************************************************/
QtToolbarBuilder::QtToolbarBuilder()
{
}

//****************************************************************************/
QtToolbarBuilder::~QtToolbarBuilder()
{
}

//****************************************************************************/
QString QtToolbarBuilder::createInclude(WindowProperties* windowProperties, const QString &s)
{
    QString str = s;
    if (windowProperties)
    {
        // Add the #include
        str = str +
            QString("#include <QToolBar>") +
            QString("\n");

        if (windowProperties->mUseTransformationWidget)
        {
            // Add the #include
            str = str +
                QString("#include \"") +
                FILE_TRANSFORMATION_WIDGET_H +
                QString("\"") +
                QString("\n");
        }
    }

    return str;
}

//****************************************************************************/
QString QtToolbarBuilder::createPrivateMembers(WindowProperties* windowProperties, const QString &s)
{
    QString str = s;
    QString iconAction;
    if (windowProperties)
    {
        // Define private members
        if (!windowProperties->mHToolbarPropertiesList.empty() || windowProperties->mUseTransformationWidget)
        {
            str = str +
                TAB +
                TAB +
                QString("QToolBar* mHToolBar; ") +
                QString("\n");
        }
        if (!windowProperties->mVToolbarPropertiesList.empty())
        {
            str = str +
                TAB +
                TAB +
                QString("QToolBar* mVToolBar; ") +
                QString("\n");
        }
    }

    return str;
}

//****************************************************************************/
QString QtToolbarBuilder::createToolbars(WindowProperties* windowProperties, const QString &s)
{
    QString str = s;
    QString iconAction;
    if (windowProperties)
    {
        if (windowProperties->mOrder == 0)
        {
            str = str + createToolbarsForMainWindow(windowProperties);
        }
        else
        {
            str = str + createToolbarsForDockWindow(windowProperties);
        }
    }

    return str;
}

/****************************************************************************
 Generates code to create the toolbars for the mainwindow (.cpp code)
****************************************************************************/
QString QtToolbarBuilder::createToolbarsForMainWindow(WindowProperties* windowProperties)
{
    QString str;
    if (windowProperties->mOrder != 0)
        return str;

    // Create the toolbars
    // Horizontal toolbar (create it if the list is not empty or if there is a special toolbar widget)
    QString iconAction;
    if (!windowProperties->mHToolbarPropertiesList.empty() || windowProperties->mUseTransformationWidget)
    {
        // Define a horizontal toolbar
        str = str +
            TAB +
            QString("mHToolBar = new QToolBar();") +
            QString("\n");

        str = str +
            TAB +
            QString("addToolBar(Qt::TopToolBarArea, mHToolBar);") +
            QString("\n");

        // Set the height of the toolbar to a fixed size
        str = str +
            TAB +
            QString("mHToolBar->setMinimumHeight(32);") +
            QString("\n");

        // Set the width of the toolbar to a fixed size
        str = str +
            TAB +
            QString("mHToolBar->setMinimumWidth(") +
            QVariant(windowProperties->mHToolbarPropertiesList.size()).toString() +
            QString(" * 32);") +
            QString("\n");
    }
    if (!windowProperties->mHToolbarPropertiesList.empty())
    {
        ToolbarProperties* toolbarProperties = 0;
        QVectorIterator<ToolbarProperties*> hList(windowProperties->mHToolbarPropertiesList);
        hList.toFront();
        while (hList.hasNext())
        {
            // Add actions to the toolbar
            toolbarProperties = hList.next();

            if (toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR1 &&
                toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR2)
            {
                iconAction = toolbarProperties->mIcon;
                iconAction = Utils::stripExtension(iconAction);
                iconAction = Utils::makePrivateAttribute (iconAction) + POST_ACTION_HTOOLBAR;
                str = str +
                    TAB +
                    QString("mHToolBar->addAction(") +
                    iconAction +
                    QString(");") +
                    QString("\n");
            }
            else
            {
                str = str +
                    TAB +
                    QString("mHToolBar->addSeparator();") +
                    QString("\n");
            }
        }
    }

    // Add code to create the widgets
    str = str + createHToolbarWidgets(windowProperties);

    // Vertical toolbar
    if (!windowProperties->mVToolbarPropertiesList.empty())
    {
        // Define a vertical toolbar
        str = str +
            TAB +
            QString("mVToolBar = new QToolBar();") +
            QString("\n");

        str = str +
            TAB +
            QString("addToolBar(Qt::LeftToolBarArea, mVToolBar);") +
            QString("\n");

        // Set the height of the toolbar to a fixed size
        str = str +
            TAB +
            QString("mVToolBar->setMinimumHeight(") +
            QVariant(windowProperties->mVToolbarPropertiesList.size()).toString() +
            QString(" * 32);") +
            QString("\n");

        // Set the width of the toolbar to a fixed size
        str = str +
            TAB +
            QString("mVToolBar->setMinimumWidth(32);") +
            QString("\n");

        ToolbarProperties* toolbarProperties = 0;
        QVectorIterator<ToolbarProperties*> vList(windowProperties->mVToolbarPropertiesList);
        vList.toFront();
        while (vList.hasNext())
        {
            // Add actions to the toolbar
            toolbarProperties = vList.next();

            if (toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR1 &&
                toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR2)
            {
                iconAction = toolbarProperties->mIcon;
                iconAction = Utils::stripExtension(iconAction);
                iconAction = Utils::makePrivateAttribute (iconAction) + POST_ACTION_VTOOLBAR;
                str = str +
                    TAB +
                    QString("mVToolBar->addAction(") +
                    iconAction +
                    QString(");") +
                    QString("\n");
            }
            else
            {
                str = str +
                    TAB +
                    QString("mVToolBar->addSeparator();") +
                    QString("\n");
            }
        }
    }

    return str;
}

/****************************************************************************
 Generates code to create the toolbars for the dockwindow (.cpp code)
****************************************************************************/
QString QtToolbarBuilder::createToolbarsForDockWindow(WindowProperties* windowProperties)
{
    QString str;
    if (windowProperties->mOrder == 0)
        return str;

    QString iconAction;

    // Horizontal toolbar (create it if the list is not empty or if there is a special toolbar widget)
    if (!windowProperties->mHToolbarPropertiesList.empty() || windowProperties->mUseTransformationWidget)
    {
        // Define a toolbar
        str = str +
            TAB +
            QString("mHToolBar = new QToolBar();") +
            QString("\n");

        str = str +
            TAB +
            QString("mInnerMain->addToolBar(Qt::TopToolBarArea, mHToolBar);") +
            QString("\n");

        // Set the height of the toolbar to a fixed size
        str = str +
            TAB +
            QString("mHToolBar->setMinimumHeight(32);") +
            QString("\n");

        // Set the width of the toolbar to a fixed size
        str = str +
            TAB +
            QString("mHToolBar->setMinimumWidth(") +
            QVariant(windowProperties->mHToolbarPropertiesList.size()).toString() +
            QString(" * 32);") +
            QString("\n");
    }
    if (!windowProperties->mHToolbarPropertiesList.empty())
    {
        ToolbarProperties* toolbarProperties = 0;
        QVectorIterator<ToolbarProperties*> hList(windowProperties->mHToolbarPropertiesList);
        hList.toFront();
        while (hList.hasNext())
        {
            // Add actions to the toolbar
            toolbarProperties = hList.next();

            if (toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR1 &&
                toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR2)
            {
                iconAction = toolbarProperties->mIcon;
                iconAction = Utils::stripExtension(iconAction);
                iconAction = Utils::makePrivateAttribute (iconAction) + POST_ACTION_HTOOLBAR;
                str = str +
                    TAB +
                    QString("mHToolBar->addAction(") +
                    iconAction +
                    QString(");") +
                    QString("\n");
            }
            else
            {
                str = str +
                    TAB +
                    QString("mHToolBar->addSeparator();") +
                    QString("\n");
            }
        }
    }

    // Add code to create the widgets
    str = str + createHToolbarWidgets(windowProperties);

    // Vertical toolbar
    if (!windowProperties->mVToolbarPropertiesList.empty())
    {
        // Define a toolbar
        str = str +
            TAB +
            QString("mVToolBar = new QToolBar();") +
            QString("\n");

        str = str +
            TAB +
            QString("mInnerMain->addToolBar(Qt::LeftToolBarArea, mVToolBar);") +
            QString("\n");

        // Set the height of the toolbar to a fixed size
        str = str +
            TAB +
            QString("mVToolBar->setMinimumHeight(") +
            QVariant(windowProperties->mVToolbarPropertiesList.size()).toString() +
            QString(" * 32);") +
            QString("\n");

        // Set the width of the toolbar to a fixed size
        str = str +
            TAB +
            QString("mVToolBar->setMinimumWidth(32);") +
            QString("\n");

        ToolbarProperties* toolbarProperties = 0;
        QVectorIterator<ToolbarProperties*> vList(windowProperties->mVToolbarPropertiesList);
        vList.toFront();
        while (vList.hasNext())
        {
            // Add actions to the toolbar
            toolbarProperties = vList.next();

            if (toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR1 &&
                toolbarProperties->mIcon != KEYWORD_ICON_SEPARATOR2)
            {
                iconAction = toolbarProperties->mIcon;
                iconAction = Utils::stripExtension(iconAction);
                iconAction = Utils::makePrivateAttribute (iconAction) + POST_ACTION_VTOOLBAR;
                str = str +
                    TAB +
                    QString("mVToolBar->addAction(") +
                    iconAction +
                    QString(");") +
                    QString("\n");
            }
            else
            {
                str = str +
                    TAB +
                    QString("mVToolBar->addSeparator();") +
                    QString("\n");
            }
        }
    }

    return str;
}

/****************************************************************************
 Generates code to create widgets on the horizontal toolbar (.cpp code)
****************************************************************************/
QString QtToolbarBuilder::createHToolbarWidgets(WindowProperties* windowProperties)
{
    QString str;

    if (windowProperties->mUseTransformationWidget)
    {
        str = str +
            TAB +
            QString("mTransformationWidget = new TransformationWidget(mHToolBar);") +
            QString("\n");

        str = str +
            TAB +
            QString("mHToolBar->addSeparator();") +
            QString("\n");

        str = str +
            TAB +
            QString("mHToolBar->addWidget(mTransformationWidget);") +
            QString("\n");

        str = str +
            TAB +
            QString("mTransformationWidget->setMaximumWidth(320);") +
            QString("\n");

        str = str +
            TAB +
            QString("connect(mTransformationWidget, SIGNAL(valueChanged()), this, SLOT(doTransformationWidgetValueChanged()));") +
            QString("\n");
    }

    return str;
}
