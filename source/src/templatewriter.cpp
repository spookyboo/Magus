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

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "constants.h"
#include "templatewriter.h"

// ****************************************************************************
TemplateWriter::TemplateWriter()
{
}

//****************************************************************************/
TemplateWriter::~TemplateWriter()
{
}

//****************************************************************************/
void TemplateWriter::writeAll(ApplicationTemplate* applicationTemplate, const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QMessageBox::information(0, QString("Unable to open file"), file.errorString());
        return;
    }

    // Write file
    QTextStream out(&file);

    out << QString("[GENERAL]");
    out << QString ("\n");

    out << TEMPLATE_KEY_PROJECT;
    out << QString (" = \"");
    out << applicationTemplate->mProject;
    out << QString ("\"\n");

    out << TEMPLATE_KEY_ICON;
    out << QString (" = ");
    out << applicationTemplate->mIconName;
    out << QString ("\n");

    out << TEMPLATE_KEY_DESCRIPTION;
    out << QString (" = \"");
    out << applicationTemplate->mDescription;
    out << QString ("\"\n");

    out << TEMPLATE_KEY_TYPE;
    out << QString (" = ");
    out << applicationTemplate->mType;
    out << QString ("\n");

    out << TEMPLATE_KEY_STYLE;
    out << QString (" = ");
    out << applicationTemplate->mStyle;
    out << QString ("\n\n");

    out << TEMPLATE_KEY_USE_ASSET_WIDGET;
    out << QString (" = ");
    out << boolToString(applicationTemplate->mUseAssetWidget);
    out << QString ("\n\n");

    out << TEMPLATE_KEY_USE_OGRE_ASSET;
    out << QString (" = ");
    out << boolToString(applicationTemplate->mUseOgreAssetWidgets);
    out << QString ("\n");

    out << TEMPLATE_KEY_USE_NODE_EDITOR;
    out << QString (" = ");
    out << boolToString(applicationTemplate->mUseNodeEditor);
    out << QString ("\n\n");

    out << TEMPLATE_KEY_USE_TOOLS;
    out << QString (" = ");
    out << boolToString(applicationTemplate->mUseTools);
    out << QString ("\n\n");

    out << QString ("[WINDOWS]");
    out << QString ("\n");

    // Iterate through the windows and write the groups
    QVectorIterator<WindowProperties*> list(applicationTemplate->mWindowPropertiesList);
    WindowProperties* windowProperties;
    int index = 0;
    while (list.hasNext())
    {
        windowProperties = list.next();
        out << QString ("window[");
        out << QVariant(index).toString();
        out << QString ("] = ");
        out << windowProperties->mGroup;
        out << "\n";
        ++index;
    }
    out << "\n";

    // Iterate again and write each individual group
    list.toFront();
    while (list.hasNext())
    {
        windowProperties = list.next();

        // Window group
        out << "\n################################################################\n";
        out << QString ("[");
        out << windowProperties->mGroup;
        out << QString ("]");
        out << QString ("\n");

        // Individual window properties
        out << TEMPLATE_KEY_WINDOW_TITLE;
        out << QString (" = \"");
        out << windowProperties->mTitle;
        out << QString ("\"\n");


        out << TEMPLATE_KEY_DISPLAY_TITLE;
        out << QString (" = ");
        out << boolToString(windowProperties->mDisplayTitle);
        out << QString ("\n");

        out << TEMPLATE_KEY_WINDOW_ORDER;
        out << QString (" = ");
        out << windowProperties->mOrder;
        out << QString ("\n");

        out << TEMPLATE_KEY_USE_DEFAULT_ACTION_QUIT;
        out << QString (" = ");
        out << boolToString(windowProperties->mUseDefaultActionQuit);
        out << QString ("\n");

        out << TEMPLATE_KEY_USE_DEFAULT_ACTION_EXIT;
        out << QString (" = ");
        out << boolToString(windowProperties->mUseDefaultActionExit);
        out << QString ("\n");


        out << TEMPLATE_KEY_USE_DEFAULT_ACTION_ABOUT;
        out << QString (" = ");
        out << boolToString(windowProperties->mUseDefaultActionAbout);
        out << QString ("\n");

        out << TEMPLATE_KEY_USE_DEFAULT_ACTION_RESET_WINDOWS;
        out << QString (" = ");
        out << boolToString(windowProperties->mUseDefaultActionResetWindows);
        out << QString ("\n");


        out << TEMPLATE_KEY_WINDOW_USE_TRANS_WIDGET;
        out << QString (" = ");
        out << boolToString(windowProperties->mUseTransformationWidget);
        out << QString ("\n");


        if (!windowProperties->mArea.isEmpty())
        {
            out << TEMPLATE_KEY_WINDOW_AREA;
            out << QString (" = ");
            out << windowProperties->mArea;
            out << QString ("\n");
        }

        out << TEMPLATE_KEY_USE_OGRE_CONTROL;
        out << QString (" = ");
        out << boolToString(windowProperties->mUseOgreControl);
        out << QString ("\n");

        out << TEMPLATE_KEY_OGRE_TARGET;
        out << QString (" = ");
        out << windowProperties->mOgreTarget;
        out << QString ("\n");

        out << TEMPLATE_KEY_USE_OGRE_CONTROL_VISUALS;
        out << QString (" = ");
        out << boolToString(windowProperties->mUseOgreControlVisuals);
        out << QString ("\n");

        if (!windowProperties->mHToolbarGroup.isEmpty())
        {
            out << TEMPLATE_KEY_WINDOW_HTOOLBAR_GROUP;
            out << QString (" = ");
            out << windowProperties->mHToolbarGroup;
            out << QString ("\n");
        }

        if (!windowProperties->mVToolbarGroup.isEmpty())
        {
            out << TEMPLATE_KEY_WINDOW_VTOOLBAR_GROUP;
            out << QString (" = ");
            out << windowProperties->mVToolbarGroup;
            out << QString ("\n");
        }

        if (!windowProperties->mTabGroup.isEmpty())
        {
            out << TEMPLATE_KEY_WINDOW_TAB_GROUP;
            out << QString (" = ");
            out << windowProperties->mTabGroup;
            out << QString ("\n");
        }

        // The menu
        if (!windowProperties->mMenuGroup.isEmpty())
        {
            out << TEMPLATE_KEY_WINDOW_MENU_GROUP;
            out << QString (" = ");
            out << windowProperties->mMenuGroup;
            out << QString ("\n");

            out << "\n#--------------------------------------------------------------#\n";
            out << QString ("[");
            out << windowProperties->mMenuGroup;
            out << QString ("]");
            out << QString ("\n");

            WindowMenuProperties* windowMenuProperties = windowProperties->mWindowMenuProperties;
            if (windowMenuProperties)
            {
                // Iterate through the menu items
                QVectorIterator<WindowMenuItemProperties*> menuList(windowMenuProperties->mWindowMenuItemPropertiesList);
                WindowMenuItemProperties* windowMenuItemProperties;
                index = 0;
                while (menuList.hasNext())
                {
                    windowMenuItemProperties = menuList.next();
                    out << QString ("menu[");
                    out << QVariant(index).toString();
                    out << QString ("] = ");
                    out << windowMenuItemProperties->mGroup;
                    out << "\n";
                    ++index;
                }
                out << "\n";

                // Iterate again and write each individual item group
                menuList.toFront();
                while (menuList.hasNext())
                {
                    windowMenuItemProperties = menuList.next();
                    out << QString ("[");
                    out << windowMenuItemProperties->mGroup;
                    out << QString ("]");
                    out << QString ("\n");

                    out << TEMPLATE_KEY_MENU_ITEM;
                    out << QString (" = \"");
                    out << windowMenuItemProperties->mItemName;
                    out << QString ("\"\n");

                    // Iterate trough the subitems
                    QVectorIterator<WindowMenuSubItemProperties*> submenuList(windowMenuItemProperties->mWindowMenuSubItemPropertiesList);
                    WindowMenuSubItemProperties* windowMenuSubItemProperties;
                    index = 0;
                    while (submenuList.hasNext())
                    {
                        windowMenuSubItemProperties = submenuList.next();
                        out << TEMPLATE_KEY_MENU_SUBITEM;
                        out << QString ("[");
                        out << QVariant(index).toString();
                        out << QString ("] = \"");
                        out << windowMenuSubItemProperties->mSubItemName;
                        out << "\"\n";
                        ++index;
                    }
                    out << "\n";
                }
            }
        }

        // The horizontal toolbar
        if (!windowProperties->mHToolbarGroup.isEmpty())
        {
            out << "\n#--------------------------------------------------------------#\n";
            out << QString ("[");
            out << windowProperties->mHToolbarGroup;
            out << QString ("]");
            out << QString ("\n");

            // Iterate through the toolbar items
            QVectorIterator<ToolbarProperties*> hToolbarList(windowProperties->mHToolbarPropertiesList);
            ToolbarProperties* toolbarProperties;
            index = 0;
            while (hToolbarList.hasNext())
            {
                toolbarProperties = hToolbarList.next();
                out << TEMPLATE_KEY_ICON;
                out << QString ("[");
                out << QVariant(index).toString();
                out << QString ("] = ");
                out << toolbarProperties->mGroup;
                out << "\n";
                ++index;
            }
            out << "\n";

            // Iterate again
            hToolbarList.toFront();
            while (hToolbarList.hasNext())
            {
                toolbarProperties = hToolbarList.next();
                out << QString ("[");
                out << toolbarProperties->mGroup;
                out << QString ("]");
                out << "\n";

                out << TEMPLATE_KEY_ICON;
                out << QString (" = ");
                out << toolbarProperties->mIcon;
                out << "\n\n";
            }
        }

        // The vertical toolbar
        if (!windowProperties->mVToolbarGroup.isEmpty())
        {
            out << "\n#--------------------------------------------------------------#\n";
            out << QString ("[");
            out << windowProperties->mVToolbarGroup;
            out << QString ("]");
            out << QString ("\n");

            // Iterate through the toolbar items
            QVectorIterator<ToolbarProperties*> vToolbarList(windowProperties->mVToolbarPropertiesList);
            ToolbarProperties* toolbarProperties;
            index = 0;
            while (vToolbarList.hasNext())
            {
                toolbarProperties = vToolbarList.next();
                out << TEMPLATE_KEY_ICON;
                out << QString ("[");
                out << QVariant(index).toString();
                out << QString ("] = ");
                out << toolbarProperties->mGroup;
                out << "\n";
                ++index;
            }
            out << "\n";

            // Iterate again
            vToolbarList.toFront();
            while (vToolbarList.hasNext())
            {
                toolbarProperties = vToolbarList.next();
                out << QString ("[");
                out << toolbarProperties->mGroup;
                out << QString ("]");
                out << "\n";

                out << TEMPLATE_KEY_ICON;
                out << QString (" = ");
                out << toolbarProperties->mIcon;
                out << "\n\n";
            }
        }

        // The tabs
        if (!windowProperties->mTabGroup.isEmpty())
        {
            out << "\n#--------------------------------------------------------------#\n";
            out << QString ("[");
            out << windowProperties->mTabGroup;
            out << QString ("]");
            out << QString ("\n");

            // Iterate through the tabs
            QVectorIterator<TabProperties*> tabList(windowProperties->mTabPropertiesList);
            TabProperties* tabProperties;
            index = 0;
            while (tabList.hasNext())
            {
                tabProperties = tabList.next();
                out << TEMPLATE_KEY_TAB;
                out << QString ("[");
                out << QVariant(index).toString();
                out << QString ("] = ");
                out << tabProperties->mGroup;
                out << "\n";
                ++index;
            }
            out << "\n";

            // Iterate again
            tabList.toFront();
            while (tabList.hasNext())
            {
                tabProperties = tabList.next();
                out << QString ("[");
                out << tabProperties->mGroup;
                out << QString ("]");
                out << "\n";

                out << TEMPLATE_KEY_NAME;
                out << QString (" = \"");
                out << tabProperties->mName;
                out << "\"\n";

                out << TEMPLATE_KEY_ICON;
                out << QString (" = ");
                out << tabProperties->mIcon;
                out << "\n\n";
            }
        }
    }

    file.close();
}

//****************************************************************************/
const QString TemplateWriter::boolToString(const bool boolValue)
{
    QString str;
    if (boolValue)
    {
        str = QString("true");
    }
    else
    {
        str = QString("false");
    }

    return str;
}
