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

#ifndef MAGUS_APP_TEMPLATE_H
#define MAGUS_APP_TEMPLATE_H

#include <QSettings>
#include <QString>
#include <QVector>

QT_BEGIN_NAMESPACE
class QSettings;
class QString;
QT_END_NAMESPACE

/****************************************************************************
 TabProperties contains the data of one tab.
 ***************************************************************************/
class TabProperties
{
    public:
    TabProperties(const QString group) : mGroup(group){};
    virtual ~TabProperties(void){};
    QString mGroup;
    QString mName;
    QString mIcon;
};

/****************************************************************************
 ToolbarProperties contains the data of one item in a horizontal or vertical
 toolbar.
 ***************************************************************************/
class ToolbarProperties
{
    public:
    ToolbarProperties(const QString group) : mGroup(group){};
    virtual ~ToolbarProperties(void){};
    QString mGroup;
    QString mIcon;
};

/****************************************************************************
 WindowMenuSubItemProperties contains the data of the submenu items, defined
 in a template or project file.
 ***************************************************************************/
class WindowMenuSubItemProperties
{
    public:
        WindowMenuSubItemProperties(const QString subItemName);
        QString mSubItemName;
};

/****************************************************************************
 WindowMenuItemProperties contains the data of the main menu items, defined
 in a template or project file.
 ***************************************************************************/
class WindowMenuItemProperties
{
    public:
        WindowMenuItemProperties(void);
        WindowMenuItemProperties(const QString group);
        virtual ~WindowMenuItemProperties(void);
        WindowMenuSubItemProperties* createWindowMenuSubItemProperties(const QString subItemName);

        QString mGroup; // This is the group in the .ide template
        QString mItemName;
        QVector<WindowMenuSubItemProperties*> mWindowMenuSubItemPropertiesList;

    private:
        void initWindowMenuItemProperties(void);
};

/****************************************************************************
 WindowMenuProperties contains the menu structure of one window, defined in
 a template or project file.
****************************************************************************/
class WindowMenuProperties
{
    public:
        WindowMenuProperties(void);
        WindowMenuProperties(const QString group);
        virtual ~WindowMenuProperties(void);
        WindowMenuItemProperties* createWindowMenuItemProperties(const QString group);
        int getNumberOfItems(void);
        WindowMenuItemProperties* getItem(int position);

        QString mGroup; // This is the group in the .ide template
        QVector<WindowMenuItemProperties*> mWindowMenuItemPropertiesList;

    private:
        void initWindowMenuProperties(void);
};

/****************************************************************************
 WindowProperties contains the data of one window, defined in a template
 or project file.
****************************************************************************/
class WindowProperties
{
    public:
        WindowProperties(void);
        WindowProperties(QString group);
        virtual ~WindowProperties(void);
        WindowMenuProperties* createWindowMenuProperties(const QString group);
        ToolbarProperties* createHToolbarProperties(const QString group);
        ToolbarProperties* createVToolbarProperties(const QString group);
        TabProperties* createTabProperties(const QString group);

        QString mGroup; // This is the group in the .ide template
        QString mTitle;
        bool mDisplayTitle;
        QString mMenuGroup;
        QString mHToolbarGroup;
        QString mVToolbarGroup;
        QString mTabGroup;
        QVector<ToolbarProperties*> mHToolbarPropertiesList;
        QVector<ToolbarProperties*> mVToolbarPropertiesList;
        QVector<TabProperties*> mTabPropertiesList;
        bool mUseOgreControl;
        int mOgreTarget; // 0 is the window itself, 1..n is one of the tabs (if no tabs, the target is always 0)
        bool mUseOgreControlVisuals;
        int mOrder;
        QString mArea;
        bool mUseDefaultActionQuit;
        bool mUseDefaultActionExit;
        bool mUseDefaultActionAbout;
        bool mUseDefaultActionResetWindows;
        bool mUseTransformationWidget;
        WindowMenuProperties* mWindowMenuProperties;

    private:
        void initWindowProperties(void);
};


/****************************************************************************
 ApplicationTemplate contains the data to build an application. It is also
 used as a datastructure for reading and writing template files.
****************************************************************************/
class ApplicationTemplate
{
    public:
        ApplicationTemplate(void);
        virtual ~ApplicationTemplate(void);
        void clear(void);
        bool isOgreUsed(void);

        QString mProject;
        QString mDescription;
        QString mIconName;
        QString mType;
        QString mStyle;
        bool mUseAssetWidget;
        bool mUseOgreAssetWidgets;
        bool mUseNodeEditor;
        QVector<WindowProperties*> mWindowPropertiesList;
};

#endif
