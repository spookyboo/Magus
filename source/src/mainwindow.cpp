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

#include <QtWidgets>
#include <QTabWidget>
#include <QFile>

#include "constants.h"
#include "utils.h"
#include "mainwindow.h"
#include "generaltab.h"
#include "windowtab.h"
#include "templatereader.h"
#include "templatewriter.h"
#include "templatedialog.h"
#include "customtabwidget.h"
#include "configdialog.h"
#include "pages.h"

//****************************************************************************/
MainWindow::MainWindow(MainApplication* app)
{
    mApplicationTemplate = new ApplicationTemplate(); // Begin with an empty template
    mTabWidget = 0;
    fileMenu = 0;
    toolMenu = 0;
    helpMenu = 0;
    newAct = 0;
    openAct = 0;
    saveAct = 0;
    buildAct = 0;
    exitAct = 0;
    configAct = 0;
    aboutAct = 0;
    infoLabel = 0;
    mApp = app;

    // Prepare the builder factory
    mBuilderFactory[mQtBuilder.getType()] = &mQtBuilder;
    mBuilderFactory[mWxWidgetsBuilder.getType()] = &mWxWidgetsBuilder;

    // Load the global settings
    QSettings globalSettings (GLOBAL_CONFIG_FILE,  QSettings::IniFormat);
    mTemplateDir = globalSettings.value(CONFIG_KEY_TEMPLATE_DIR).toString();
    mIconDir = globalSettings.value(CONFIG_KEY_ICON_DIR).toString();;
    mLayoutDir = globalSettings.value(CONFIG_KEY_LAYOUT_DIR).toString(); // TODO: Crashes the application after change + restore
    mQtDir = globalSettings.value(CONFIG_KEY_QT_DIR).toString();

    // Set the stylesheet of the application
    QFile File(mQtDir + STYLE_DARK);
    File.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(File.readAll());
    setStyleSheet(styleSheet);

    createActions();
    createMenus();

    infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to "
                              "invoke a context menu</i>"));

    setWindowTitle(tr("Magus"));
    setMinimumSize(800, 600);
    showMaximized();
}

//****************************************************************************/
MainWindow::~MainWindow(void)
{
    // Delete the application template
    if (mApplicationTemplate)
        delete mApplicationTemplate;

    mBuilderFactory.clear(); // The objects in the map are destroyed when the MainWindow is destroyed
}

//****************************************************************************/
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.exec(event->globalPos());
}

//****************************************************************************/
void MainWindow::newProject(void)
{
    // Create a new Magus project from a template

    // Open the dialog to select a template; The dialog performs a callback to set the selected template
    if (selectTemplate())
    {
        // Create the design screen, based on the template
        createTabs();
    }
}

//****************************************************************************/
bool MainWindow::selectTemplate(void)
{
    // Create new/empty application template
    if (mApplicationTemplate)
        delete mApplicationTemplate;

    mApplicationTemplate = new ApplicationTemplate();

    // Open the dialog to select a template; The dialog performs a callback to set the selected template
    TemplateDialog dialog (this);
    if (dialog.exec())
    {
        // After selecting a template, parse the complete template file
        if (!mSelectedTemplateName.isEmpty())
        {
            mTemplateReader.readAll(mApplicationTemplate, mTemplateDir + mSelectedTemplateName, QSettings::IniFormat);
            return true;
        }
    }
    return false;
}

//****************************************************************************/
void MainWindow::createTabs(void)
{
    // Create tabs to design a window; create a tab for each window in the file
    if (mTabWidget)
    {
        delete mTabWidget; // First delete the old tab widget
        mTabWidget = 0;
    }

    WindowTab* windowTab;
    mWindowTabList.clear();

    if (mApplicationTemplate)
    {
        if (!mApplicationTemplate->mWindowPropertiesList.empty())
        {
            mTabWidget = new QTabWidget(this);
            mGeneralTab = new GeneralTab(this);
            mTabWidget->addTab(mGeneralTab, tr("General"));
            QVectorIterator<WindowProperties*> list(mApplicationTemplate->mWindowPropertiesList);
            WindowProperties* windowProperties;
            while (list.hasNext())
            {
                windowProperties = list.next();
                windowTab = new WindowTab(windowProperties, &mIconReader, this);
                mTabWidget->addTab(windowTab, windowProperties->mGroup);
                mWindowTabList.append(windowTab);
            }
            setCentralWidget(mTabWidget);
            mTabWidget->show();
        }
    }
}

/****************************************************************************
 Create a new tab, which means that a new (dock)window is added
****************************************************************************/
void MainWindow::newTab(void)
{
    // Get last order and create the tab
    int order = mTabWidget->count() - 1;
    QString group = QString ("DOCK") + QVariant(order).toString();
    WindowProperties* windowProperties = new WindowProperties(group);
    windowProperties->mOrder = order;
    WindowTab* windowTab = new WindowTab(windowProperties, &mIconReader, this);
    windowTab->mTitleEdit->setText(QString ("Dock") + QVariant(order).toString());
    mTabWidget->addTab(windowTab, group);
    mWindowTabList.append(windowTab);
}

/****************************************************************************
 Delete a tab (or, a dock window is deleted)
****************************************************************************/
//****************************************************************************/
void MainWindow::removeCurrentTab(void)
{
    // General may not be deleted
    int index = mTabWidget->currentIndex();
    if (index == 0)
        return;

    // First check if you are sure
    int ret = QMessageBox::warning(this, QString("Magus"),
                                   QString("You are about to delete this tab.\n"
                                      "Do you want to proceed?"),
                                   QMessageBox::Ok | QMessageBox::Cancel,
                                   QMessageBox::Ok);

    if (ret == QMessageBox::Cancel)
        return;


    // Ok, start deleting the tab
    mTabWidget->removeTab(index);
    --index; // subtract 1, because the first index of mTabWidget is the General tab, while the first index of mWindowTabList is the Main tab
    mWindowTabList.removeAt(index);

    // Reorder
    index = 1;
    QVectorIterator<WindowTab*> list(mWindowTabList);
    WindowTab* windowTab;
    list.toFront();
    QString orderText;
    QString groupText;
    QString titleText;
    QString oldOrderString;
    while (list.hasNext())
    {
        // Only reorder the dockwidgets
        windowTab = list.next();
        if (windowTab->mOrder != 0)
        {
            // Set the right order
            oldOrderString = QVariant(windowTab->mOrder).toString();
            windowTab->mOrder = index;
            orderText = QVariant(index).toString() + QString(" (Dockable Window)");
            windowTab->mOrderValue->setText(orderText);

            // Rename the group (if possible) and update the order in the title (if possible)
            groupText = windowTab->mGroup;
            titleText = windowTab->mTitleEdit->text();
            groupText.replace(oldOrderString, QVariant(index).toString());
            titleText.replace(oldOrderString, QVariant(index).toString());
            if (windowTab->mGroup.toUpper() == windowTab->mTitleEdit->text().toUpper())
            {
                // Also update the Title if it has a similar name as the group
                windowTab->mTitleEdit->setText(titleText);
            }

            windowTab->mGroup = groupText;
            mTabWidget->setTabText(index + 1, groupText);

            // Increase index
            ++index;
        }
    }
    mGeneralTab->setLayoutImage(NO_IMAGE);
}

//****************************************************************************/
void MainWindow::openProject(void)
{
    // Open a Magus project
    QString fileName = QFileDialog::getOpenFileName(this, QString("Open Project"), "", QString("Files (*.*)"));
    if (fileName.isEmpty())
        return;

    // Create new/empty application template
    if (mApplicationTemplate)
        delete mApplicationTemplate;

    mApplicationTemplate = new ApplicationTemplate();
    mTemplateReader.readAll(mApplicationTemplate, fileName, QSettings::IniFormat);

    // Create the design screen, based on the template
    createTabs();
}

//****************************************************************************/
void MainWindow::saveProject(void)
{
    // Save a Magus project (first validate)
    if (!validateWidgetValues())
        return;

    createApplicationTemplateFromWidgets();
    if (mApplicationTemplate && !mApplicationTemplate->mWindowPropertiesList.empty())
    {
        QString fileName = QFileDialog::getSaveFileName(this,
                QString("Save current project"), mApplicationTemplate->mProject,
                QString("Magus project (*.ide);;All Files (*)"));

        if (fileName.isEmpty())
        {
            return;
        }
        else
        {
            TemplateWriter writer;
            writer.writeAll(mApplicationTemplate, fileName);
        }
    }
}

//****************************************************************************/
void MainWindow::build(void)
{
    if (mApplicationTemplate && !mApplicationTemplate->mWindowPropertiesList.empty())
    {
        // First validate
        if (!validateWidgetValues())
            return;

        mApp->setOverrideCursor(QCursor(Qt::WaitCursor));

        // Create a new ApplicationTemplate from the widgets
        createApplicationTemplateFromWidgets();

        // Build a Magus project
        getCurrentBuilder()->build(mApplicationTemplate);
        mApp->setOverrideCursor(QCursor(Qt::ArrowCursor));
        QString currentProject = mApplicationTemplate->mProject;
        currentProject = Utils::stripSpecialCharacters(currentProject);
        QMessageBox::information(this, QString("Build"), QString("Project '") + currentProject + QString("' generated."));
    }
}

//****************************************************************************/
void MainWindow::config(void)
{
    ConfigDialog dialog(this);
    dialog.setMinimumWidth(800);
    if (dialog.exec())
    {
        QString iconDir = dialog.mGeneralPage->getIconDir();
        //QString layoutDir = dialog.mGeneralPage->getLayoutDir();
        //QString templateDir = dialog.mGeneralPage->getTemplateDir();
        QString outputDir = dialog.mBuildPage->getOutputDir();
        QString ogreRootEnv = dialog.mOgrePage->getOgreRootEnv();
        bool ogreRootUseEnv = dialog.mOgrePage->isOgreRootUseEnv();
        QString ogreRoot = dialog.mOgrePage->getOgreRoot();
        QString ogreBuildDir = dialog.mOgrePage->getOgreBuildDir();
        QString ogreVersion = dialog.mOgrePage->getOgreVersion();

        // Update the configuration file
        QSettings globalSettings (GLOBAL_CONFIG_FILE,  QSettings::IniFormat);
        globalSettings.setValue(CONFIG_KEY_ICON_DIR, iconDir);
        //globalSettings.setValue(CONFIG_KEY_LAYOUT_DIR, layoutDir);
        //globalSettings.setValue(CONFIG_KEY_TEMPLATE_DIR, templateDir);
        globalSettings.setValue(CONFIG_KEY_OUTPUT_DIR, outputDir);
        globalSettings.setValue(CONFIG_KEY_OGRE_ROOT_ENV, ogreRootEnv);
        globalSettings.setValue(CONFIG_KEY_OGRE_ROOT_USE_ENV, ogreRootUseEnv);
        globalSettings.setValue(CONFIG_KEY_OGRE_BUILD_DIR, ogreBuildDir);
        globalSettings.setValue(CONFIG_KEY_OGRE_ROOT, ogreRoot);
        globalSettings.setValue(CONFIG_KEY_OGRE_BUILD_DIR, ogreBuildDir);
        globalSettings.setValue(CONFIG_KEY_OGRE_VERSION, ogreVersion);

        // Activate the new settings
        mIconDir = iconDir;
        //mLayoutDir = layoutDir;
        //mTemplateDir = templateDir;
        getCurrentBuilder()->setOutputDir(outputDir);
        getCurrentBuilder()->setOgre(ogreRootUseEnv, ogreRootEnv, ogreRoot, ogreBuildDir, ogreVersion);
    }
}

//****************************************************************************/
void MainWindow::about(void)
{
    infoLabel->setText(tr("Invoked <b>Help|About</b>"));
    QMessageBox::about(this, tr("About"),
            tr("<center><b>Magus</b> V0.2<br></center>\n<center>2016</center>"));
}

//****************************************************************************/
void MainWindow::createActions(void)
{
    newAct = new QAction(tr("&New project"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new project"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newProject()));

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing project"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(openProject()));

    saveAct = new QAction(tr("&Save project"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save a project"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveProject()));

    buildAct = new QAction(tr("&Build"), this);
    buildAct->setStatusTip(tr("Build a Gui"));
    connect(buildAct, SIGNAL(triggered()), this, SLOT(build()));

    configAct = new QAction(tr("&Config"), this);
    configAct->setStatusTip(tr("Configure the Magus application"));
    connect(configAct, SIGNAL(triggered()), this, SLOT(config()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Close the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

//****************************************************************************/
void MainWindow::createMenus(void)
{
    // File
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(buildAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    // Tools
    toolMenu = menuBar()->addMenu(tr("&Tools"));
    toolMenu->addAction(configAct);

    // Help
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}

/****************************************************************************
 Delete the datastructure that contains the intial properties (when 'new' or
 when 'open' was selected. This function rebuilds the datastructure again,
 based on the values of the widgets.
****************************************************************************/
void MainWindow::createApplicationTemplateFromWidgets(void)
{
    if (mApplicationTemplate)
        delete mApplicationTemplate;

    mApplicationTemplate = new ApplicationTemplate();

    // ------------------------ Create the general properties ------------------------
    if (mGeneralTab)
    {
        mApplicationTemplate->mDescription = mGeneralTab->mDescriptionValue->text();
        mApplicationTemplate->mIconName = mGeneralTab->mIconName;
        mApplicationTemplate->mProject = mGeneralTab->mProjectValue->text();
        mApplicationTemplate->mStyle = mGeneralTab->mStyleValue->text();
        mApplicationTemplate->mType = mGeneralTab->mTypeValue->text();
        mApplicationTemplate->mUseAssetWidget = mGeneralTab->mUseAssetWidgetCheckBox->isChecked();
        mApplicationTemplate->mUseOgreAssetWidgets = mGeneralTab->mUseOgreAssetWidgetCheckBox->isChecked();
        mApplicationTemplate->mUseNodeEditor = mGeneralTab->mUseNodeEditorCheckBox->isChecked();
        mApplicationTemplate->mUseTools = mGeneralTab->mUseToolsCheckBox->isChecked();
    }

    // ------------------------ Create the window properties ------------------------
    if (!mWindowTabList.empty())
    {
        QVectorIterator<WindowTab*> list(mWindowTabList);
        WindowTab* windowTab;
        WindowProperties* windowProperties;
        list.toFront();
        while (list.hasNext())
        {
            windowTab = list.next();
            windowProperties = new WindowProperties();

            // Copy data from windowTab to windowProperties
            windowProperties->mGroup = windowTab->mGroup;
            windowProperties->mTitle = windowTab->mTitleEdit->text();
            windowProperties->mDisplayTitle = windowTab->mTitleVisibleCheckBox->isChecked();
            windowProperties->mUseOgreControlVisuals = windowTab->mUseOgreControlVisuals; // No widgets yet
            windowProperties->mOrder = windowTab->mOrder;
            windowProperties->mUseTransformationWidget = windowTab->mTransformationCheckBox->isChecked();
            windowProperties->mUseDefaultActionQuit = windowTab->mQuitCheckBox->isChecked();
            windowProperties->mUseDefaultActionExit = windowTab->mExitCheckBox->isChecked();
            windowProperties->mUseDefaultActionAbout = windowTab->mAboutCheckBox->isChecked();
            windowProperties->mUseDefaultActionResetWindows = windowTab->mResetWindowCheckBox->isChecked();

            // Ogre
            windowProperties->mUseOgreControl = windowTab->mUseOgreCheckBox->isChecked();
            if (windowProperties->mUseOgreControl)
            {
                windowProperties->mOgreTarget = windowTab->mOgreTargetComboBox->currentIndex() + 1;
            }
            else
            {
                windowProperties->mOgreTarget = 0;
            }

            // Area
            if (windowTab->mOrder != 0)
            {
                if (windowTab->mAreaRight && windowTab->mAreaRight->isChecked())
                {
                    windowProperties->mArea = AREA_RIGHT;
                }
                else if (windowTab->mAreaTop && windowTab->mAreaTop->isChecked())
                {
                    windowProperties->mArea = AREA_TOP;
                }
                else if (windowTab->mAreaBottom && windowTab->mAreaBottom->isChecked())
                {
                    windowProperties->mArea = AREA_BOTTOM;
                }
                else if (windowTab->mAreaCenter && windowTab->mAreaCenter->isChecked())
                {
                    windowProperties->mArea = AREA_CENTER;
                }
                else
                {
                    windowProperties->mArea = AREA_LEFT;
                }
            }

            QModelIndex parent;

            // ------------------------ Create the menu properties ------------------------
            int items = windowTab->mTreeModel->rowCount(parent);
            if (items > 0)
            {
                // Create mWindowMenuProperties and iterate through windowTab->mTreeModel
                QString menuGroup = windowTab->mGroup + QString(".MENU");
                windowProperties->mMenuGroup = menuGroup;
                WindowMenuProperties* windowMenuProperties = windowProperties->createWindowMenuProperties(menuGroup);
                QModelIndex index;
                QModelIndex subIndex;
                WindowMenuItemProperties* windowMenuItemProperties;
                QString str;
                QString group;
                for (int i = 0; i < items; ++i)
                {
                    index = windowTab->mTreeModel->index(i,0);
                    str = (windowTab->mTreeModel->data(index, Qt::DisplayRole)).toString();
                    group = windowTab->mGroupItemMap[str];
                    if (group.isEmpty())
                    {
                        group = Utils::stripSpecialCharacters(str);
                    }
                    windowMenuItemProperties = windowMenuProperties->createWindowMenuItemProperties(group);
                    windowMenuItemProperties->mItemName = str;

                    // Iterate over the subitems
                    int subItems = windowTab->mTreeModel->rowCount(index);
                    if (subItems > 0)
                    {
                        for (int j = 0; j < subItems; ++j)
                        {
                            subIndex = windowTab->mTreeModel->index(j, 0, index);
                            str = (windowTab->mTreeModel->data(subIndex, Qt::DisplayRole)).toString();
                            windowMenuItemProperties->createWindowMenuSubItemProperties(str);
                        }
                    }
                }
            }

            // ------------------------ Horizontal Toolbar ------------------------
            int hIcons = windowTab->mHorizontalToolbarModel->mNames.size();
            ToolbarProperties* hToolbarProperties;
            QString str;
            if (hIcons > 0)
            {
                // Iterate through the toolbar list
                QString hToolbarGroup = windowTab->mGroup + QString(".HTOOLBAR");
                windowProperties->mHToolbarGroup = hToolbarGroup;
                QListIterator<QString> hlist(windowTab->mHorizontalToolbarModel->mNames);
                while (hlist.hasNext())
                {
                    str = hlist.next();
                    hToolbarProperties = windowProperties->createHToolbarProperties(QString(""));
                    hToolbarProperties->mIcon = str;
                    str = Utils::stripExtension(str);
                    str = str.toUpper();
                    hToolbarProperties->mGroup = hToolbarGroup + QString (".") + str;
                }
            }

            // ------------------------ Vertical Toolbar ------------------------
            int vIcons = windowTab->mVerticalToolbarModel->mNames.size();
            ToolbarProperties* vToolbarProperties;
            if (vIcons > 0)
            {
                // Iterate through the toolbar list
                QString vToolbarGroup = windowTab->mGroup + QString(".VTOOLBAR");
                windowProperties->mVToolbarGroup = vToolbarGroup;
                QListIterator<QString> vlist(windowTab->mVerticalToolbarModel->mNames);
                while (vlist.hasNext())
                {
                    str = vlist.next();
                    vToolbarProperties = windowProperties->createVToolbarProperties(QString(""));
                    vToolbarProperties->mIcon = str;
                    str = Utils::stripExtension(str);
                    str = str.toUpper();
                    vToolbarProperties->mGroup = vToolbarGroup + QString (".") + str;
                }
            }

            // ------------------------ Create the tabs ------------------------
            CustomTabWidget* windowTabWidget = windowTab->mTabWidget;
            if (windowTabWidget)
            {
                TabProperties* tabProperties;
                QString str;
                int tabCount = windowTabWidget->count();
                if (tabCount > 0)
                {
                    QString tabGroup = windowTab->mGroup + QString(".TAB");
                    windowProperties->mTabGroup = tabGroup;
                    for (int t = 0; t < tabCount; ++t)
                    {
                        str = windowTabWidget->getTabName(t);
                        str = Utils::stripSpecialCharacters(str);
                        str = str.toUpper();
                        str = tabGroup + QString (".") + str;
                        tabProperties = windowProperties->createTabProperties(str);
                        tabProperties->mIcon = windowTabWidget->getIconName(t);
                        tabProperties->mName = windowTabWidget->getTabName(t);
                    }
                }
            }

            // Add the windowProperties object to the list
            mApplicationTemplate->mWindowPropertiesList.append(windowProperties);
        }
    }
}

/****************************************************************************
 Validate the current settings of the widgets. First call this function,
 before a destructive operation (e.g. save, build) is performed.
****************************************************************************/
bool MainWindow::validateWidgetValues(void)
{
    if (mWindowTabList.isEmpty())
    {
        QMessageBox::information(0, QString("Validate"), QString("No windows. Nothing to process."));
        return false;
    }

    QVectorIterator<WindowTab*> list(mWindowTabList);
    int removed;
    QStringList titles;
    QStringList menuItems;
    QStringList menuSubItems;
    QStringList toolbarIcons;
    WindowTab* windowTab;
    list.toFront();
    while (list.hasNext())
    {
        windowTab = list.next();

        // Title must be mandatory
        if (windowTab->mTitleEdit && windowTab->mTitleEdit->text().isEmpty())
        {
            QMessageBox::information(0, QString("Validate"), QString("Error: The title of [") +
                                                                windowTab->mGroup +
                                                                QString("] was not filled."));
            return false;
        }

        titles << windowTab->mTitleEdit->text();

        // Menu items must have a unique name
        QModelIndex parent;
        int items = windowTab->mTreeModel->rowCount(parent);
        if (items > 0)
        {
            QModelIndex index;
            QModelIndex subIndex;
            QString str;
            for (int i = 0; i < items; ++i)
            {
                index = windowTab->mTreeModel->index(i,0);
                str = (windowTab->mTreeModel->data(index, Qt::DisplayRole)).toString();
                menuItems << str;

                // Iterate over the subitems; subitems must have a unique name
                int subItems = windowTab->mTreeModel->rowCount(index);
                if (subItems > 0)
                {
                    for (int j = 0; j < subItems; ++j)
                    {
                        subIndex = windowTab->mTreeModel->index(j, 0, index);
                        str = (windowTab->mTreeModel->data(subIndex, Qt::DisplayRole)).toString();
                        menuSubItems << str;
                    }
                }
            }
        }
        removed = menuItems.removeDuplicates();
        if (removed > 0)
        {
            QMessageBox::information(0, QString("Validate"), QString("Error: Duplicate menu items not allowed."));
            return false;
        }
        menuItems.clear();

        removed = menuSubItems.removeDuplicates();
        if (removed > 0)
        {
            QMessageBox::information(0, QString("Validate"), QString("Error: Duplicate submenu items not allowed."));
            return false;
        }
        menuSubItems.clear();


        // Horizontal toolbars must have unique icons (except for separators)
        QListIterator<QString> hlist(windowTab->mHorizontalToolbarModel->mNames);
        QString str;
        while (hlist.hasNext())
        {
            str = hlist.next();
            if (str != ICON_HSEPARATOR && str != ICON_VSEPARATOR )
                toolbarIcons << str;
        }
        removed = toolbarIcons.removeDuplicates();
        if (removed > 0)
        {
            QMessageBox::information(0, QString("Validate"), QString("Error: Duplicate icons on horizontal toolbar not allowed."));
            return false;
        }

        // Vertical toolbars must have unique icons (except for separators)
        toolbarIcons.clear();
        QListIterator<QString> vlist(windowTab->mVerticalToolbarModel->mNames);
        while (vlist.hasNext())
        {
            str = vlist.next();
            if (str != ICON_HSEPARATOR && str != ICON_VSEPARATOR )
                toolbarIcons << str;
        }
        removed = toolbarIcons.removeDuplicates();
        if (removed > 0)
        {
            QMessageBox::information(0, QString("Validate"), QString("Error: Duplicate icons on vertical toolbar not allowed."));
            return false;
        }
        toolbarIcons.clear();
    }

    // Titles must be unique
    removed = titles.removeDuplicates();
    if (removed > 0)
    {
        QMessageBox::information(0, QString("Validate"), QString("Error: Duplicate titles are not allowed."));
        return false;
    }

    return true;
}


//****************************************************************************/
const TemplateReader* MainWindow::getTemplateReader(void) const
{
    return &mTemplateReader;
}

//****************************************************************************/
Builder* MainWindow::getCurrentBuilder(void) const
{
    return mBuilderFactory[mApplicationTemplate->mType];
}

//****************************************************************************/
const QString MainWindow::getTemplateDir (void) const
{
    return mTemplateDir;
}

//****************************************************************************/
const QString MainWindow::getIconDir (void) const
{
    return mIconDir;
}

//****************************************************************************/
const QString MainWindow::getLayoutDir (void) const
{
    return mLayoutDir;
}

//****************************************************************************/
void MainWindow::setSelectedTemplateName(QString selectedTemplateName)
{
    mSelectedTemplateName = selectedTemplateName;
}

//****************************************************************************/
ApplicationTemplate* MainWindow::getApplicationTemplate(void) const
{
    return mApplicationTemplate;
}

//****************************************************************************/
MainApplication* MainWindow::getMainApplication(void) const
{
    return mApp;
}

//****************************************************************************/
bool MainWindow::isOgreUsed(void)
{
    // Run throug all the window tabs an check the status of the use Ogre checkbox
    QVectorIterator<WindowTab*> list(mWindowTabList);
    WindowTab* windowTab;
    list.toFront();
    while (list.hasNext())
    {
        windowTab = list.next();
        if (windowTab->mUseOgreCheckBox->isChecked())
            return true;
    }
    return false;
}
