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
#include "constants.h"
#include "applicationtemplate.h"

//****************************************************************************/
WindowMenuSubItemProperties::WindowMenuSubItemProperties(const QString subItemName)
{
        mSubItemName = subItemName;
}

// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
WindowMenuItemProperties::WindowMenuItemProperties(void)
{
    initWindowMenuItemProperties();
}

//****************************************************************************/
WindowMenuItemProperties::WindowMenuItemProperties(const QString group)
{
    mGroup = group;
    initWindowMenuItemProperties();
}

// ****************************************************************************
WindowMenuItemProperties::~WindowMenuItemProperties(void)
{
    // Delete all objects from the mWindowMenuSubItemPropertiesList
    QVectorIterator<WindowMenuSubItemProperties*> list(mWindowMenuSubItemPropertiesList);
    WindowMenuSubItemProperties* windowMenuSubItemProperties = 0;
    while (list.hasNext())
    {
        windowMenuSubItemProperties = list.next();
        if (windowMenuSubItemProperties)
            delete windowMenuSubItemProperties;
    }
    mWindowMenuSubItemPropertiesList.clear();
}

// ****************************************************************************
void WindowMenuItemProperties::initWindowMenuItemProperties(void)
{
    // Still nothing to do
}

// ****************************************************************************
WindowMenuSubItemProperties* WindowMenuItemProperties::createWindowMenuSubItemProperties(const QString subItemName)
{
    WindowMenuSubItemProperties* windowMenuSubItemProperties = new WindowMenuSubItemProperties(subItemName);
    mWindowMenuSubItemPropertiesList.append(windowMenuSubItemProperties);
    return windowMenuSubItemProperties;
}

// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
WindowMenuProperties::WindowMenuProperties(void)
{
    initWindowMenuProperties();
}

//****************************************************************************/
WindowMenuProperties::WindowMenuProperties(const QString group)
{
    mGroup = group;
    initWindowMenuProperties();
}

//****************************************************************************/
WindowMenuProperties::~WindowMenuProperties(void)
{
    // Delete all objects from the mWindowMenuSubItemPropertiesList
    QVectorIterator<WindowMenuItemProperties*> list(mWindowMenuItemPropertiesList);
    list.toFront();
    WindowMenuItemProperties* windowMenuItemProperties = 0;
    while (list.hasNext())
    {
        windowMenuItemProperties = list.next();
        if (windowMenuItemProperties)
            delete windowMenuItemProperties;
    }
    mWindowMenuItemPropertiesList.clear();
}

// ****************************************************************************
void WindowMenuProperties::initWindowMenuProperties(void)
{
}

// ****************************************************************************
WindowMenuItemProperties* WindowMenuProperties::createWindowMenuItemProperties(const QString group)
{
    WindowMenuItemProperties* windowMenuItemProperties = new WindowMenuItemProperties(group);
    mWindowMenuItemPropertiesList.append(windowMenuItemProperties);
    return windowMenuItemProperties;
}

// ****************************************************************************
int WindowMenuProperties::getNumberOfItems(void)
{
    return mWindowMenuItemPropertiesList.size();
}

// ****************************************************************************
WindowMenuItemProperties* WindowMenuProperties::getItem(int position)
{
    return mWindowMenuItemPropertiesList.at(position);
}


// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
WindowProperties::WindowProperties(void)
{
    initWindowProperties();
}

// ****************************************************************************
WindowProperties::WindowProperties(QString group)
{
    mGroup = group;
    initWindowProperties();
}

// ****************************************************************************
WindowProperties::~WindowProperties(void)
{
    // Delete the menu properties (if available)
    if (mWindowMenuProperties)
        delete mWindowMenuProperties;

    // Delete all objects from the mHToolbarPropertiesList
    QVectorIterator<ToolbarProperties*> hList(mHToolbarPropertiesList);
    ToolbarProperties* toolbarProperties = 0;
    hList.toFront();
    while (hList.hasNext())
    {
        toolbarProperties = hList.next();
        if (toolbarProperties)
            delete toolbarProperties;
    }
    mHToolbarPropertiesList.clear();

    // Delete all objects from the mVToolbarPropertiesList
    QVectorIterator<ToolbarProperties*> vList(mVToolbarPropertiesList);
    vList.toFront();
    while (vList.hasNext())
    {
        toolbarProperties = vList.next();
        if (toolbarProperties)
            delete toolbarProperties;
    }
    mVToolbarPropertiesList.clear();

    // Delete all objects from the mTabPropertiesList
    QVectorIterator<TabProperties*> tabList(mTabPropertiesList);
    TabProperties* tabProperties = 0;
    tabList.toFront();
    while (tabList.hasNext())
    {
        tabProperties = tabList.next();
        if (tabProperties)
            delete tabProperties;
    }
    mTabPropertiesList.clear();
}

// ****************************************************************************
void WindowProperties::initWindowProperties(void)
{
    mWindowMenuProperties = 0;
    mTitle = DEFAULT_WINDOW_TITLE;
    mDisplayTitle = true;
    mUseOgreControl = false;
    mOgreTarget = 0;
    mUseOgreControlVisuals = false;
    mMenuGroup = QString("");
    mHToolbarGroup = QString("");
    mVToolbarGroup = QString("");
    mHToolbarGroup = QString("");
    mVToolbarGroup = QString("");
    mOrder = 0;
    mArea = QString("");
    mUseDefaultActionQuit = false;
    mUseDefaultActionExit = false;
    mUseDefaultActionAbout = false;
    mUseDefaultActionResetWindows = false;
    mUseTransformationWidget = false;
}

// ****************************************************************************
WindowMenuProperties* WindowProperties::createWindowMenuProperties(const QString group)
{
    mWindowMenuProperties = new WindowMenuProperties(group);
    return mWindowMenuProperties;
}

// ****************************************************************************
ToolbarProperties* WindowProperties::createHToolbarProperties(const QString group)
{
    ToolbarProperties* toolbarProperties = new ToolbarProperties(group);
    mHToolbarPropertiesList.append(toolbarProperties);
    return toolbarProperties;
}

// ****************************************************************************
ToolbarProperties* WindowProperties::createVToolbarProperties(const QString group)
{
    ToolbarProperties* toolbarProperties = new ToolbarProperties(group);
    mVToolbarPropertiesList.append(toolbarProperties);
    return toolbarProperties;
}

// ****************************************************************************
TabProperties* WindowProperties::createTabProperties(const QString group)
{
    TabProperties* tabProperties = new TabProperties(group);
    mTabPropertiesList.append(tabProperties);
    return tabProperties;
}

// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
ApplicationTemplate::ApplicationTemplate (void)
{
    mProject = QString("");
    mDescription = DEFAULT_DESCRIPTION;
    mIconName = DEFAULT_ICON_NAME;
    mType = DEFAULT_TYPE;
    mStyle = DEFAULT_STYLE;
    mUseAssetWidget = false;
    mUseOgreAssetWidgets = false;
    mUseNodeEditor = false;
    mUseTools = false;
}

// ****************************************************************************
ApplicationTemplate::~ApplicationTemplate (void)
{
    clear();
}

//****************************************************************************/
void ApplicationTemplate::clear(void)
{
    // Delete all objects from the mWindowPropertiesList
    QVectorIterator<WindowProperties*> list(mWindowPropertiesList);
    WindowProperties* windowProperties = 0;
    list.toFront();
    while (list.hasNext())
    {
        windowProperties = list.next();
        if (windowProperties)
            delete windowProperties;
    }
    mWindowPropertiesList.clear();
}

//****************************************************************************/
bool ApplicationTemplate::isOgreUsed(void)
{
    QVectorIterator<WindowProperties*> list(mWindowPropertiesList);
    WindowProperties* windowProperties = 0;
    list.toFront();
    while (list.hasNext())
    {
        windowProperties = list.next();
        if (windowProperties->mUseOgreControl)
            return true;
    }
    return false;
}
