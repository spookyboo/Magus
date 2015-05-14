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

#include <QtWidgets>
#include <QMessageBox>
#include "constants.h"
#include "templatereader.h"

// ****************************************************************************
TemplateReader::TemplateReader()
{
}

//****************************************************************************/
TemplateReader::~TemplateReader()
{
}

//****************************************************************************/
void TemplateReader::readGeneral(ApplicationTemplate* applicationTemplate, const QString &fileName, QSettings::Format format)
{
    // Get the general properties
    QSettings settings(fileName, format);
    applicationTemplate->mProject = settings.value(TEMPLATE_KEY_PROJECT).toString();
    applicationTemplate->mDescription = settings.value(TEMPLATE_KEY_DESCRIPTION).toString();
    applicationTemplate->mIconName = settings.value(TEMPLATE_KEY_ICON).toString();
    applicationTemplate->mType = settings.value(TEMPLATE_KEY_TYPE).toString();
    applicationTemplate->mStyle = settings.value(TEMPLATE_KEY_STYLE).toString();
    applicationTemplate->mUseAssetWidget = settings.value(TEMPLATE_KEY_USE_ASSET_WIDGET).toBool();
    applicationTemplate->mUseOgreAssetWidgets = settings.value(TEMPLATE_KEY_USE_OGRE_ASSET).toBool();
    applicationTemplate->mUseNodeEditor = settings.value(TEMPLATE_KEY_USE_NODE_EDITOR).toBool();
    applicationTemplate->mUseTools = settings.value(TEMPLATE_KEY_USE_TOOLS).toBool();
}

//****************************************************************************/
void TemplateReader::readAll(ApplicationTemplate* applicationTemplate, const QString &fileName, QSettings::Format format)
{
    // Get the general properties first
    QSettings settings(fileName, format);
    applicationTemplate->mProject = settings.value(TEMPLATE_KEY_PROJECT).toString();
    applicationTemplate->mDescription = settings.value(TEMPLATE_KEY_DESCRIPTION).toString();
    applicationTemplate->mIconName = settings.value(TEMPLATE_KEY_ICON).toString();
    applicationTemplate->mType = settings.value(TEMPLATE_KEY_TYPE).toString();
    applicationTemplate->mStyle = settings.value(TEMPLATE_KEY_STYLE).toString();
    applicationTemplate->mUseAssetWidget = settings.value(TEMPLATE_KEY_USE_ASSET_WIDGET).toBool();
    applicationTemplate->mUseOgreAssetWidgets = settings.value(TEMPLATE_KEY_USE_OGRE_ASSET).toBool();
    applicationTemplate->mUseNodeEditor = settings.value(TEMPLATE_KEY_USE_NODE_EDITOR).toBool();
    applicationTemplate->mUseTools = settings.value(TEMPLATE_KEY_USE_TOOLS).toBool();

    // Read Windows group; create a vector with all window properties. The list is in the form:
    // [WINDOWS]
    // window[0] = MAIN
    // window[1] = PROPERTIES
    // window[2] = 3D_EDIT
    // window[3] = OUTPUT
    settings.beginGroup(WINDOWS_GROUP);
    bool end = false;
    QString key;
    QString group;
    int i = 0;
    while (!end)
    {
        // Read list of windows (each one forms a group)
        QVariant var(i);
        key = TEMPLATE_KEY_WINDOW + QString("[") + var.toString() + QString("]");
        group = settings.value(key).toString();
        if (group.isEmpty())
        {
            end = true;
        }
        else
        {
            applicationTemplate->mWindowPropertiesList.append(new WindowProperties(group));
            i++;
        }
    }
    settings.endGroup();

    // Run through all window WindowProperties and fill each object with the right values
    WindowProperties* windowProperties;
    QVectorIterator<WindowProperties*> list(applicationTemplate->mWindowPropertiesList);
    while (list.hasNext())
    {
        windowProperties = list.next();
        readIndividualProperties(&settings, windowProperties);
        readMenu(&settings, windowProperties);
        readToolbar(&settings, windowProperties, TOOLBARGROUP_HORIZONTAL);
        readToolbar(&settings, windowProperties, TOOLBARGROUP_VERTICAL);
        readTabs(&settings, windowProperties);
    }
}

//****************************************************************************/
void TemplateReader::readIndividualProperties(QSettings* settings, WindowProperties* windowProperties)
{
    // Do not use nested groups/sections in the template/project file
    settings->beginGroup(windowProperties->mGroup);
    QString title = settings->value(TEMPLATE_KEY_WINDOW_TITLE).toString();
    if (!title.isEmpty())
    {
        windowProperties->mTitle = title;
    }

    QString displayTitleElement = settings->value(TEMPLATE_KEY_DISPLAY_TITLE).toString();
    if (displayTitleElement == "false")
    {
        // Only set it to false if it is explicitly set
        windowProperties->mDisplayTitle = false;
    }
    windowProperties->mOrder = settings->value(TEMPLATE_KEY_WINDOW_ORDER).toInt();
    windowProperties->mArea = settings->value(TEMPLATE_KEY_WINDOW_AREA).toString();
    windowProperties->mMenuGroup = settings->value(TEMPLATE_KEY_WINDOW_MENU_GROUP).toString();
    windowProperties->mHToolbarGroup = settings->value(TEMPLATE_KEY_WINDOW_HTOOLBAR_GROUP).toString();
    windowProperties->mVToolbarGroup = settings->value(TEMPLATE_KEY_WINDOW_VTOOLBAR_GROUP).toString();
    windowProperties->mUseTransformationWidget = settings->value(TEMPLATE_KEY_WINDOW_USE_TRANS_WIDGET).toBool();
    windowProperties->mTabGroup = settings->value(TEMPLATE_KEY_WINDOW_TAB_GROUP).toString();
    windowProperties->mUseOgreControl = settings->value(TEMPLATE_KEY_USE_OGRE_CONTROL).toBool();
    windowProperties->mOgreTarget = settings->value(TEMPLATE_KEY_OGRE_TARGET).toInt();
    windowProperties->mUseOgreControlVisuals = settings->value(TEMPLATE_KEY_USE_OGRE_CONTROL_VISUALS).toBool();
    windowProperties->mUseDefaultActionExit = settings->value(TEMPLATE_KEY_USE_DEFAULT_ACTION_EXIT).toBool();
    windowProperties->mUseDefaultActionQuit = settings->value(TEMPLATE_KEY_USE_DEFAULT_ACTION_QUIT).toBool();
    windowProperties->mUseDefaultActionAbout = settings->value(TEMPLATE_KEY_USE_DEFAULT_ACTION_ABOUT).toBool();
    windowProperties->mUseDefaultActionResetWindows = settings->value(TEMPLATE_KEY_USE_DEFAULT_ACTION_RESET_WINDOWS).toBool();
    settings->endGroup();
}

//****************************************************************************/
void TemplateReader::readMenu(QSettings* settings, WindowProperties* windowProperties)
{
    if (!windowProperties->mMenuGroup.isEmpty())
    {
        settings->beginGroup(windowProperties->mMenuGroup);

        // Create a new WindowMenuProperties object and add it to the passed windowProperties
        WindowMenuProperties* windowMenuProperties = windowProperties->createWindowMenuProperties(windowProperties->mMenuGroup);

        // Iterate through the file
        QVector<QString> itemGroupList;
        bool end = false;
        QString key;
        QString menugroup;
        int i = 0;
        while (!end)
        {
            // Read list of main menu items (each one forms a new group)
            QVariant var(i);
            key = TEMPLATE_KEY_MENU + QString("[") + var.toString() + QString("]");
            menugroup = settings->value(key).toString();
            if (menugroup.isEmpty())
            {
                end = true;
            }
            else
            {
                // Add the menugroups to a list. It is needed to have a flat list, beause grouped sections in a Qsettings
                // object turns out to be problematic.
                itemGroupList.append(menugroup);
                i++;
            }
        }
        settings->endGroup();

        // Iterate through the itemGroupList
        QVectorIterator<QString> list(itemGroupList);
        QString name;
        QString subItem;
        WindowMenuItemProperties* itemProperties = 0;
        while (list.hasNext())
        {
            menugroup = list.next();
            itemProperties = windowMenuProperties->createWindowMenuItemProperties(menugroup);

            settings->beginGroup(menugroup);
            itemProperties->mItemName = settings->value(TEMPLATE_KEY_MENU_ITEM).toString();

            // Read list of submenu items
            end = false;
            i = 0;
            while (!end)
            {
                // Read a submenu item
                QVariant var(i);
                key = TEMPLATE_KEY_MENU_SUBITEM + QString("[") + var.toString() + QString("]");
                subItem = settings->value(key).toString();
                if (subItem.isEmpty())
                {
                    end = true;
                }
                else
                {
                    itemProperties->createWindowMenuSubItemProperties(subItem);
                    i++;
                }
            }
            settings->endGroup();
        }
    }
}

//****************************************************************************/
void TemplateReader::readToolbar(QSettings* settings, WindowProperties* windowProperties, ToolbarGroup parentGroup)
{
    if (parentGroup == TOOLBARGROUP_HORIZONTAL && !windowProperties->mHToolbarGroup.isEmpty())
    {
        settings->beginGroup(windowProperties->mHToolbarGroup);
    }
    else if (parentGroup == TOOLBARGROUP_VERTICAL && !windowProperties->mVToolbarGroup.isEmpty())
    {
        settings->beginGroup(windowProperties->mVToolbarGroup);
    }
    else
    {
        return;
    }

    // Run through the file and get the individual items of a horizontal toolbar; each item has its own group, so first get the groups
    QVector<QString> itemGroupList;
    bool end = false;
    QString key;
    QString toolbargroup;
    int i = 0;
    while (!end)
    {
        // Read list of toolbar items (each one forms a new group)
        QVariant var(i);
        key = TEMPLATE_KEY_ICON + QString("[") + var.toString() + QString("]");
        toolbargroup = settings->value(key).toString();
        if (toolbargroup.isEmpty())
        {
            end = true;
        }
        else
        {
            // Add the groups to a list.
            itemGroupList.append(toolbargroup);
            i++;
        }
    }
    settings->endGroup();

    // Create new ToolbarProperties objects and add them to the windowProperties
    QVectorIterator<QString> list(itemGroupList);
    ToolbarProperties* toolbarProperties = 0;
    while (list.hasNext())
    {
        toolbargroup = list.next();
        settings->beginGroup(toolbargroup);
        if (parentGroup == TOOLBARGROUP_HORIZONTAL)
        {
            toolbarProperties = windowProperties->createHToolbarProperties(toolbargroup);
        }
        else if (parentGroup == TOOLBARGROUP_VERTICAL)
        {
            toolbarProperties = windowProperties->createVToolbarProperties(toolbargroup);
        }
        toolbarProperties->mIcon = settings->value(TEMPLATE_KEY_ICON).toString();
        settings->endGroup();
    }
}

//****************************************************************************/
void TemplateReader::readTabs(QSettings* settings, WindowProperties* windowProperties)
{
    // Iterate through the file and read all the properties concerning tabs in a window
    settings->beginGroup(windowProperties->mTabGroup);
    bool end = false;
    QString key;
    QString tabItemGroup;
    QVector<QString> itemGroupList;
    int i = 0;
    while (!end)
    {
        // Read list of tab items (each one forms a new group)
        QVariant var(i);
        key = TEMPLATE_KEY_TAB + QString("[") + var.toString() + QString("]");
        tabItemGroup = settings->value(key).toString();
        if (tabItemGroup.isEmpty())
        {
            end = true;
        }
        else
        {
            // Add the groups to a list.
            itemGroupList.append(tabItemGroup);
            i++;
        }
    }
    settings->endGroup();

    // Create new TabProperties objects and add them to the windowProperties
    QVectorIterator<QString> list(itemGroupList);
    TabProperties* tabProperties = 0;
    while (list.hasNext())
    {
        tabItemGroup = list.next();
        settings->beginGroup(tabItemGroup);
        tabProperties = windowProperties->createTabProperties(tabItemGroup);
        tabProperties->mName = settings->value(TEMPLATE_KEY_NAME).toString();
        tabProperties->mIcon = settings->value(TEMPLATE_KEY_ICON).toString();
        settings->endGroup();
    }
}
