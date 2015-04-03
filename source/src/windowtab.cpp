
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
#include "mainwindow.h"
#include "windowtab.h"
#include "iconcombobox.h"
#include "namedicon.h"
#include "utils.h"
#include "bin.h"

//****************************************************************************/
WindowTab::WindowTab(WindowProperties* windowProperties, IconReader* iconReader, MainWindow* parent): QWidget(parent), mParent(parent), mIconReader(iconReader)
{
    if (!parent)
        return;

    mGroup = windowProperties->mGroup;
    mUseOgreControlVisuals = windowProperties->mUseOgreControlVisuals;
    mOrder = windowProperties->mOrder;

    mTreeView = 0;
    mTreeModel = 0;
    mSelectionList = 0;
    mHorizontalToolbarList = 0;
    mVerticalToolbarList = 0;
    mSelectionModel = 0;
    mHorizontalToolbarModel = 0;
    mVerticalToolbarModel = 0;
    mCategoryComboBox = 0;
    mOrderValue = 0;
    mTabWidget = new CustomTabWidget(this, parent->getMainApplication(), iconReader, parent->getIconDir());
    connect(mTabWidget, SIGNAL(tabTextChanged(int)), this, SLOT(ogreTargetChanged(int)));

    // Fill the tabs to construct a window, depending on the 'type' (type of gui)
    // Get the correct builder to determine which gui components are implemented
    Builder* builder = mParent->getCurrentBuilder();

    mMainLayout = new QVBoxLayout;
    mMainMenuAndToolbarLayout = new QHBoxLayout;
    mMainTabAndOgreLayout = new QHBoxLayout;

    // Create widgets for window properties
    createWindowPropertyWidgets(windowProperties);

    if (builder->isMenuAvailable())
    {
        // Create menu construction widgets
        createMenuWidgets(windowProperties);
    }

    // Create the toolbar widgets
    createToolbarWidgets(windowProperties);

    // Create the tab widgets
    createTabWidgets(windowProperties);


    if (builder->isOgre3dControlAvailable())
    {
        // Create Ogre3d settings
        createOgre3dControlWidgets(windowProperties);
    }
    mMainLayout->addLayout(mMainTabAndOgreLayout);
    mMainLayout->addStretch(1);
    setLayout(mMainLayout);
}

//****************************************************************************/
//****************************************************************************/
void WindowTab::createWindowPropertyWidgets(WindowProperties* windowProperties)
{
    QGroupBox* windowPropertiesGroup = new QGroupBox(tr("Window"));
    mMainLayout->addWidget(windowPropertiesGroup);
    mMainLayout->addSpacing(12);
    QHBoxLayout* mainPropertiesLayout = new QHBoxLayout;
    QVBoxLayout* propertiesColumn1Layout = new QVBoxLayout;
    QVBoxLayout* propertiesColumn2Layout = new QVBoxLayout;

    // Title
    QLabel* titleLabel = new QLabel(tr("Title:"));
    titleLabel->setMinimumWidth(FIXED_LABEL_SIZE);
    titleLabel->setMaximumWidth(FIXED_LABEL_SIZE);
    mTitleEdit = new QLineEdit;
    mTitleEdit->setText(windowProperties->mTitle);
    mTitleEdit->setMinimumWidth(FIXED_MEDIUM_EDIT_SIZE);
    mTitleEdit->setMaximumWidth(FIXED_MEDIUM_EDIT_SIZE);

    mTitleVisibleCheckBox = new QCheckBox(QString("Display the title of the window"));
    if (windowProperties->mDisplayTitle)
    {
        mTitleVisibleCheckBox->setChecked(true);
    }
    QHBoxLayout* titleLayout = new QHBoxLayout;
    titleLayout->addWidget(titleLabel, 0, Qt::AlignLeft | Qt::AlignTop);
    titleLayout->addWidget(mTitleEdit, 0, Qt::AlignLeft | Qt::AlignTop);
    titleLayout->addWidget(mTitleVisibleCheckBox, 0, Qt::AlignLeft | Qt::AlignTop);
    titleLayout->addSpacing(1000);
    propertiesColumn1Layout->addLayout(titleLayout);

    // Order
    QLabel* orderLabel = new QLabel(tr("Order:"));
    orderLabel->setMinimumWidth(FIXED_LABEL_SIZE);
    orderLabel->setMaximumWidth(FIXED_LABEL_SIZE);
    QString orderText = QVariant(windowProperties->mOrder).toString();
    if (windowProperties->mOrder == 0)
    {
        orderText = orderText + QString(" (Mainwindow)");
    }
    else
    {
        orderText = orderText + QString(" (Dockable Window)");
    }
    mOrderValue = new QLabel(QVariant(orderText).toString());
    mOrderValue->setMinimumWidth(FIXED_LABEL_SIZE);
    mOrderValue->setMaximumWidth(FIXED_LABEL_SIZE);
    QHBoxLayout* orderLayout = new QHBoxLayout;
    orderLayout->addWidget(orderLabel, 0, Qt::AlignLeft | Qt::AlignTop);
    orderLayout->addWidget(mOrderValue, 0, Qt::AlignLeft | Qt::AlignTop);
    orderLayout->addSpacing(1000);
    propertiesColumn1Layout->addLayout(orderLayout);

    // Area
    if (windowProperties->mOrder != 0)
    {
        QGroupBox* radioGroupBox = new QGroupBox(QString("Dock area"));
        mAreaLeft = new QRadioButton(QString("Left"));
        mAreaRight = new QRadioButton(QString("Right"));
        mAreaTop = new QRadioButton(QString("Top"));
        mAreaBottom = new QRadioButton(QString("Bottom"));
        mAreaCenter = new QRadioButton(QString("Center"));
        if (windowProperties->mArea == AREA_LEFT)
        {
            mAreaLeft->setChecked(true);
        }
        else if (windowProperties->mArea == AREA_RIGHT)
        {
            mAreaRight->setChecked(true);
        }
        else if (windowProperties->mArea == AREA_TOP)
        {
            mAreaTop->setChecked(true);
        }
        else if (windowProperties->mArea == AREA_BOTTOM)
        {
            mAreaBottom->setChecked(true);
        }
        else if (windowProperties->mArea == AREA_CENTER)
        {
            mAreaCenter->setChecked(true);
        }
        else
        {
            windowProperties->mArea = AREA_LEFT;
            mAreaLeft->setChecked(true);
        }

        QVBoxLayout* radioLayout = new QVBoxLayout;
        radioLayout->addWidget(mAreaLeft);
        radioLayout->addWidget(mAreaRight);
        radioLayout->addWidget(mAreaTop);
        radioLayout->addWidget(mAreaBottom);
        radioLayout->addWidget(mAreaCenter);
        radioGroupBox->setLayout(radioLayout);
        propertiesColumn1Layout->addWidget(radioGroupBox);
    }

    // Test
//    QLabel* testLabel = new QLabel(tr("Test:"));
//    testLabel->setMinimumWidth(FIXED_LABEL_SIZE);
//    testLabel->setMaximumWidth(FIXED_LABEL_SIZE);
//    QLineEdit* testEdit = new QLineEdit;
//    testEdit->setMinimumWidth(FIXED_LARGE_EDIT_SIZE);
//    testEdit->setMaximumWidth(FIXED_LARGE_EDIT_SIZE);
//    QHBoxLayout* testLayout = new QHBoxLayout;
//    testLayout->addWidget(testLabel, 0, Qt::AlignLeft | Qt::AlignTop);
//    testLayout->addWidget(testEdit, 0, Qt::AlignLeft | Qt::AlignTop);
//    testLayout->addSpacing(1000);
//    propertiesColumn2Layout->addLayout(testLayout); // TEST


    // Delete window button
    if (windowProperties->mOrder != 0)
    {
        // Delete this window button (only allowed for dockwidgets)
        QLabel* deleteWindowLabel = new QLabel(tr("Delete this window:"));
        deleteWindowLabel->setMinimumWidth(FIXED_LABEL_SIZE);
        deleteWindowLabel->setMaximumWidth(FIXED_LABEL_SIZE);
        QPushButton* deleteWindowButton = new QPushButton(this);
        deleteWindowButton->setIcon(QIcon(mParent->getIconDir() + ICON_DELETE));
        deleteWindowButton->setMinimumWidth(80);
        deleteWindowButton->setMaximumWidth(80);
        QHBoxLayout* deleteWindowLayout = new QHBoxLayout;
        deleteWindowLayout->addWidget(deleteWindowLabel, 0, Qt::AlignLeft | Qt::AlignTop);
        deleteWindowLayout->addWidget(deleteWindowButton, 0, Qt::AlignLeft | Qt::AlignTop);
        deleteWindowLayout->addSpacing(1000);
        propertiesColumn2Layout->addLayout(deleteWindowLayout);
        connect(deleteWindowButton, SIGNAL(clicked()), this, SLOT(deleteThisWindow()));
    }
    propertiesColumn2Layout->addStretch(12);

    // Layout
    mainPropertiesLayout->addLayout(propertiesColumn1Layout);
    mainPropertiesLayout->addLayout(propertiesColumn2Layout);
    windowPropertiesGroup->setLayout(mainPropertiesLayout);
}

//****************************************************************************/
void WindowTab::createMenuWidgets (WindowProperties* windowProperties)
{
    // Create menu construction widgets
    QGroupBox* menuConstructionGroup = new QGroupBox(tr("Menu"));
    mMainMenuAndToolbarLayout->addWidget(menuConstructionGroup);

    QVBoxLayout* globalMenuLayout = new QVBoxLayout;
    QHBoxLayout* buttonAndActionLayout = new QHBoxLayout;
    QVBoxLayout* buttonLayout = new QVBoxLayout;
    QVBoxLayout* actionLayout = new QVBoxLayout;
    QStringList headers;
    headers << tr("Add menu items and submenu items. Doubleclick on the items to edit the text.");
    mTreeModel = new TreeModel(headers);
    mTreeView = new QTreeView;
    mTreeView->setModel(mTreeModel);

    for (int column = 0; column < mTreeModel->columnCount(); ++column)
        mTreeView->resizeColumnToContents(column);
    globalMenuLayout->addWidget(mTreeView);

    // Fill the tree with data
    if (windowProperties->mWindowMenuProperties)
    {
        QVectorIterator<WindowMenuItemProperties*> itemList(windowProperties->mWindowMenuProperties->mWindowMenuItemPropertiesList);
        WindowMenuItemProperties* item = 0;
        while (itemList.hasNext())
        {
            item = itemList.next();
            insertItemInTree(item->mItemName);
            mGroupItemMap[item->mItemName] = item->mGroup;
            gotoNextTreeRow();

            // Iterate over item->mWindowMenuSubItemPropertiesList in reversed order, retrieve the WindowMenuSubItemProperties objects
            // and get mSubItemName for each of them. Add Children to the tree.
            QVectorIterator<WindowMenuSubItemProperties*> subItemList(item->mWindowMenuSubItemPropertiesList);
            subItemList.toBack();
            WindowMenuSubItemProperties* subItem = 0;
            while (subItemList.hasPrevious())
            {
                subItem = subItemList.previous();
                insertChildInTree(subItem->mSubItemName);
                gotoParentInTree(); // Step back to the parent item, otherwise, the tree keeps expanding
            }
        }

        for (int column = 0; column < mTreeModel->columnCount(); ++column)
            mTreeView->resizeColumnToContents(column);
        mTreeView->expandAll(); // Notify repainting mTreeView
    }

    // Add buttons
    QLabel* itemLabel = new QLabel(tr("Add menu item:"));
    itemLabel->setMinimumWidth(FIXED_LABEL_SIZE);
    itemLabel->setMaximumWidth(FIXED_LABEL_SIZE);
    QPushButton *addItemButton = new QPushButton(this);
    addItemButton->setIcon(QIcon(mParent->getIconDir() + ICON_ADD));
    addItemButton->setMinimumWidth(80);
    addItemButton->setMaximumWidth(80);
    connect(addItemButton, SIGNAL(clicked()), this, SLOT(addItem()));

    QLabel* subItemLabel = new QLabel(tr("Add submenu item:"));
    subItemLabel->setMinimumWidth(FIXED_LABEL_SIZE);
    subItemLabel->setMaximumWidth(FIXED_LABEL_SIZE);
    QPushButton *addSubItemButton = new QPushButton(this);
    addSubItemButton->setIcon(QIcon(mParent->getIconDir() + ICON_ADD));
    addSubItemButton->setMinimumWidth(80);
    addSubItemButton->setMaximumWidth(80);
    connect(addSubItemButton, SIGNAL(clicked()), this, SLOT(addSubItem()));

    QLabel* deleteItemSubItemLabel = new QLabel(tr("Remove item/subitem:"));
    deleteItemSubItemLabel->setMinimumWidth(FIXED_LABEL_SIZE);
    deleteItemSubItemLabel->setMaximumWidth(FIXED_LABEL_SIZE);
    QPushButton *deleteItemSubItemButton = new QPushButton(this);
    deleteItemSubItemButton->setIcon(QIcon(mParent->getIconDir() + ICON_DELETE));
    deleteItemSubItemButton->setMinimumWidth(80);
    deleteItemSubItemButton->setMaximumWidth(80);
    connect(deleteItemSubItemButton, SIGNAL(clicked()), this, SLOT(deleteItemSubItem()));

    // Add default 'Action' checkboxes
    QLabel* actionLabel = new QLabel(tr("Associate menuitems (with the exact name) with default actions"));
    QGroupBox* defaultActionGroup = new QGroupBox(tr("Default Actions"));
    mResetWindowCheckBox = new QCheckBox(KEYWORD_MENU_RESET_WINDOWS + tr(" - Displays the windows according to their original state"));
    if (windowProperties->mUseDefaultActionResetWindows)
    {
        mResetWindowCheckBox->setChecked(true);
    }
    mExitCheckBox = new QCheckBox(KEYWORD_MENU_EXIT + tr("- End the application / close the dockwindow"));
    if (windowProperties->mUseDefaultActionExit)
    {
        mExitCheckBox->setChecked(true);
    }
    mQuitCheckBox = new QCheckBox(KEYWORD_MENU_QUIT + tr("- End the application / close the dockwindow"));
    if (windowProperties->mUseDefaultActionQuit)
    {
        mQuitCheckBox->setChecked(true);
    }
    mAboutCheckBox= new QCheckBox(KEYWORD_MENU_ABOUT + tr("- Shows an 'about' messagebox"));
    if (windowProperties->mUseDefaultActionAbout)
    {
        mAboutCheckBox->setChecked(true);
    }
    actionLayout->addWidget(actionLabel);
    actionLayout->addWidget(mResetWindowCheckBox);
    actionLayout->addWidget(mExitCheckBox);
    actionLayout->addWidget(mQuitCheckBox);
    actionLayout->addWidget(mAboutCheckBox);
    actionLayout->addStretch(20);

    // Layout
    QHBoxLayout* itemButtonLayout = new QHBoxLayout;
    itemButtonLayout->addWidget(itemLabel, 2);
    itemButtonLayout->addWidget(addItemButton, 1);
    itemButtonLayout->addStretch(6);
    QHBoxLayout* subItemButtonLayout = new QHBoxLayout;
    subItemButtonLayout->addWidget(subItemLabel, 2);
    subItemButtonLayout->addWidget(addSubItemButton, 1);
    subItemButtonLayout->addStretch(6);
    QHBoxLayout* deleteItemSubItemButtonLayout = new QHBoxLayout;
    deleteItemSubItemButtonLayout->addWidget(deleteItemSubItemLabel, 2);
    deleteItemSubItemButtonLayout->addWidget(deleteItemSubItemButton, 1);
    deleteItemSubItemButtonLayout->addStretch(6);
    buttonLayout->addLayout(itemButtonLayout, Qt::AlignTop);
    buttonLayout->addLayout(subItemButtonLayout, Qt::AlignTop);
    buttonLayout->addLayout(deleteItemSubItemButtonLayout, Qt::AlignTop);
    buttonLayout->addStretch(20);
    buttonAndActionLayout->addLayout(buttonLayout, 1);
    buttonAndActionLayout->addWidget(defaultActionGroup, 2);
    defaultActionGroup->setLayout(actionLayout);
    globalMenuLayout->addLayout(buttonAndActionLayout);
    menuConstructionGroup->setLayout(globalMenuLayout);
}

//****************************************************************************/
void WindowTab::createToolbarWidgets (WindowProperties* windowProperties)
{
    Builder* builder = mParent->getCurrentBuilder();

    // Create toolbar construction widgets
    QGroupBox* toolbarConstructionGroup = new QGroupBox(tr("Toolbar"));
    mMainMenuAndToolbarLayout->addWidget(toolbarConstructionGroup);
    mMainLayout->addLayout(mMainMenuAndToolbarLayout);
    mMainLayout->addSpacing(12);

    QVBoxLayout* globalToolbarLayout = new QVBoxLayout;
    QHBoxLayout* horizontalToolbarLayout = new QHBoxLayout;
    QVBoxLayout* comboboxAndBinLayout = new QVBoxLayout;
    QVBoxLayout* verticalToolbarLayout = new QVBoxLayout;
    QHBoxLayout* toolbarAndSelectionLayout = new QHBoxLayout;
    QVBoxLayout* selectionLayout = new QVBoxLayout;

    // Define horizontal toolbar widget (QListView)
    mHorizontalToolbarList = new QListView;
    mHorizontalToolbarList->setViewMode(QListView::IconMode);
    mHorizontalToolbarList->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    //mHorizontalToolbarList->setGridSize(QSize(ICON_SIZE - 16, ICON_SIZE - 16));
    mHorizontalToolbarList->setSpacing(8);
    mHorizontalToolbarList->setMovement(QListView::Snap);
    mHorizontalToolbarList->setFlow(QListView::LeftToRight);
    mHorizontalToolbarList->setWrapping(false);
    mHorizontalToolbarList->setDragEnabled(true);
    mHorizontalToolbarList->setAcceptDrops(true);
    mHorizontalToolbarList->setDropIndicatorShown(true);
    mHorizontalToolbarModel = new IconSelectionModel(IconSelectionModel::HTOOLBAR);
    mHorizontalToolbarList->setModel(mHorizontalToolbarModel);

    // Fill the horizontal toolbar widget
    QVectorIterator<ToolbarProperties*> hList(windowProperties->mHToolbarPropertiesList);
    ToolbarProperties* item = 0;
    while (hList.hasNext())
    {
        item = hList.next();
        mHorizontalToolbarModel->addIcon(QPixmap(mParent->getIconDir() + item->mIcon).scaled(
                                             TEMPLATE_DIALOG_ICON_WIDTH,
                                             TEMPLATE_DIALOG_ICON_HEIGHT,
                                             Qt::KeepAspectRatio,
                                             Qt::SmoothTransformation),
                                         item->mIcon);
    }

    // Define vertical toolbar widget (QListView)
    mVerticalToolbarList = new QListView;
    mVerticalToolbarList->setViewMode(QListView::IconMode);
    mVerticalToolbarList->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    //mVerticalToolbarList->setGridSize(QSize(ICON_SIZE - 16, ICON_SIZE - 16));
    mVerticalToolbarList->setSpacing(8);
    mVerticalToolbarList->setMovement(QListView::Snap);
    mVerticalToolbarList->setFlow(QListView::TopToBottom);
    mVerticalToolbarList->setWrapping(false);
    mVerticalToolbarList->setDragEnabled(true);
    mVerticalToolbarList->setAcceptDrops(true);
    mVerticalToolbarList->setDropIndicatorShown(true);
    mVerticalToolbarModel = new IconSelectionModel(IconSelectionModel::VTOOLBAR);
    mVerticalToolbarList->setModel(mVerticalToolbarModel);

    // Fill the vertical toolbar widget
    QVectorIterator<ToolbarProperties*> vList(windowProperties->mVToolbarPropertiesList);
    while (vList.hasNext())
    {
        item = vList.next();
        mVerticalToolbarModel->addIcon(QPixmap(mParent->getIconDir() + item->mIcon).scaled(
                                           TEMPLATE_DIALOG_ICON_WIDTH,
                                           TEMPLATE_DIALOG_ICON_HEIGHT,
                                           Qt::KeepAspectRatio,
                                           Qt::SmoothTransformation),
                                       item->mIcon);
    }

    // Define selection widget (QListView)
    mSelectionList = new QListView;
    mSelectionList->setViewMode(QListView::IconMode);
    mSelectionList->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    //mSelectionList->setGridSize(QSize(ICON_SIZE - 16, ICON_SIZE - 16));
    mSelectionList->setSpacing(8);
    mSelectionList->setMovement(QListView::Snap);
    mSelectionList->setFlow(QListView::LeftToRight);
    mSelectionList->setWrapping(true);
    mSelectionList->setDragEnabled(true);
    mSelectionList->setAcceptDrops(false);
    mSelectionList->setDropIndicatorShown(true);
    mSelectionModel = new IconSelectionModel(IconSelectionModel::SELECTION);
    mSelectionList->setModel(mSelectionModel);

    // Define combobox to select the category and fill it with the categories from iconReader
    // Signal/slot (handleSelectionChanged) must be defined between the IconComboBox and the WindoTab,
    // but is routed back to the IconComboBox
    mCategoryComboBox = new IconComboBox(mIconReader, mSelectionModel, mParent->getIconDir(), this);
    connect(mCategoryComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSelectionCategoryChanged(int)));

    // Define Bin
    Bin* bin = new Bin(mParent->getIconDir());
    bin->setMinimumSize(QSize(BIN_SIZE, BIN_SIZE));
    connect(bin, SIGNAL(iconDeleted(QString)), this, SLOT(deleteIconFromToolbar(QString)), Qt::QueuedConnection);

    // Define complex toolbar widgets
    QGroupBox* complexWidgetsGroup = new QGroupBox(tr("Toolbar widgets"));
    QVBoxLayout* complexWidgetLayout = new QVBoxLayout;
    mTransformationCheckBox = new QCheckBox(QString("Transformation - Enter position, (euler) rotation, scale (horizontal toolbar widget)"));
    if (windowProperties->mUseTransformationWidget)
    {
        mTransformationCheckBox->setChecked(true);
    }

    // Layout
    horizontalToolbarLayout->addWidget(mHorizontalToolbarList);
    verticalToolbarLayout->addWidget(mVerticalToolbarList);
    selectionLayout->addWidget(mSelectionList);
    if (builder->isVerticalToolbarAvailable())
        toolbarAndSelectionLayout->addLayout(verticalToolbarLayout, 1);
    comboboxAndBinLayout->addWidget(mCategoryComboBox, 0, Qt::AlignTop);
    comboboxAndBinLayout->addWidget(bin, 0, Qt::AlignHCenter | Qt::AlignBottom);
    toolbarAndSelectionLayout->addLayout(comboboxAndBinLayout, 1);
    toolbarAndSelectionLayout->addLayout(selectionLayout, 8);
    if (builder->isHorizontalToolbarAvailable())
        globalToolbarLayout->addLayout(horizontalToolbarLayout, 1);
    globalToolbarLayout->addLayout(toolbarAndSelectionLayout, 8);
    complexWidgetLayout->addWidget(mTransformationCheckBox);
    complexWidgetsGroup->setLayout(complexWidgetLayout);
    globalToolbarLayout->addWidget(complexWidgetsGroup);
    toolbarConstructionGroup->setLayout(globalToolbarLayout);
}

//****************************************************************************/
void WindowTab::createTabWidgets (WindowProperties* windowProperties)
{
    // Create the tabs (only allowed if this is a dock widget)
    if (windowProperties && windowProperties->mOrder == 0)
        return;

    // Create tab construction widgets
    QGroupBox* tabConstructionGroup = new QGroupBox(tr("Tab"));
    mMainTabAndOgreLayout->addWidget(tabConstructionGroup, 1);

    // Create the layouts
    QVBoxLayout* globalTabLayout = new QVBoxLayout;
    QHBoxLayout* buttonAndActionLayout = new QHBoxLayout;
    QVBoxLayout* buttonLayout = new QVBoxLayout;
    //QVBoxLayout* actionLayout = new QVBoxLayout;

    // Create the tabs
    if (!windowProperties->mTabPropertiesList.empty())
    {
        QVectorIterator<TabProperties*> tabList(windowProperties->mTabPropertiesList);
        TabProperties* tabProperties = 0;
        tabList.toFront();
        while (tabList.hasNext())
        {
            tabProperties = tabList.next();
            NamedIcon icon(tabProperties->mIcon, mParent->getIconDir() + tabProperties->mIcon);
            mTabWidget->addTab(new QWidget(this), icon, tabProperties->mName);
        }
    }

    // Create the buttons and actions
    QLabel* addTabLabel = new QLabel(tr("Add tab:"));
    addTabLabel->setMinimumWidth(FIXED_LABEL_SIZE);
    addTabLabel->setMaximumWidth(FIXED_LABEL_SIZE);
    QPushButton *addTabButton = new QPushButton(this);
    addTabButton->setIcon(QIcon(mParent->getIconDir() + ICON_ADD));
    addTabButton->setMinimumWidth(80);
    addTabButton->setMaximumWidth(80);
    connect(addTabButton, SIGNAL(clicked()), this, SLOT(addTab()));

    QLabel* deleteTabLabel = new QLabel(tr("Remove selected tab:"));
    deleteTabLabel->setMinimumWidth(FIXED_LABEL_SIZE);
    deleteTabLabel->setMaximumWidth(FIXED_LABEL_SIZE);
    QPushButton *deleteTabButton = new QPushButton(this);
    deleteTabButton->setIcon(QIcon(mParent->getIconDir() + ICON_DELETE));
    deleteTabButton->setMinimumWidth(80);
    deleteTabButton->setMaximumWidth(80);
    connect(deleteTabButton, SIGNAL(clicked()), this, SLOT(deleteTab()));

    // Layout
    QHBoxLayout* addTabButtonLayout = new QHBoxLayout;
    addTabButtonLayout->addWidget(addTabLabel, 2);
    addTabButtonLayout->addWidget(addTabButton, 1);
    addTabButtonLayout->addStretch(6);
    QHBoxLayout* deleteTabButtonLayout = new QHBoxLayout;
    deleteTabButtonLayout->addWidget(deleteTabLabel, 2);
    deleteTabButtonLayout->addWidget(deleteTabButton, 1);
    deleteTabButtonLayout->addStretch(6);
    buttonLayout->addLayout(addTabButtonLayout, Qt::AlignTop);
    buttonLayout->addLayout(deleteTabButtonLayout, Qt::AlignTop);
    buttonLayout->addStretch(20);
    buttonAndActionLayout->addLayout(buttonLayout); // No actions yet
    globalTabLayout->addWidget(mTabWidget);
    globalTabLayout->addLayout(buttonAndActionLayout);
    tabConstructionGroup->setLayout(globalTabLayout);
}

//****************************************************************************/
void WindowTab::createOgre3dControlWidgets (WindowProperties* windowProperties)
{
    // Create Ogre3d settings
    QGroupBox* ogre3dConstructionGroup = new QGroupBox(tr("Ogre3d settings"));
    QVBoxLayout*  ogre3dGroupLayout = new QVBoxLayout;
    QHBoxLayout* ogreCheckAndTargetLayout = new QHBoxLayout;
    QHBoxLayout* targetLayout = new QHBoxLayout;
    mUseOgreCheckBox = new QCheckBox(QString("Use Ogre3D"));
    mTargetLabel = new QLabel(QString("Ogre target (tab):"), this); // Use 'this' as parent, to prevent flickering
    if (windowProperties->mUseOgreControl)
    {
        mUseOgreCheckBox->setChecked(true);
    }
    mOgreTargetComboBox = new QComboBox(this);
    connect(mUseOgreCheckBox, SIGNAL(stateChanged(int)), this, SLOT(ogreTargetChanged(int)));

    // Layout
    ogreCheckAndTargetLayout->addWidget(mUseOgreCheckBox, 1);
    targetLayout->addWidget(mTargetLabel, 1);
    targetLayout->addWidget(mOgreTargetComboBox, 3);
    targetLayout->addStretch(1);
    ogreCheckAndTargetLayout->addLayout(targetLayout, 1);
    fillOgreTargetComboBox(windowProperties->mOgreTarget);
    ogre3dGroupLayout->addLayout(ogreCheckAndTargetLayout);
    ogre3dGroupLayout->addStretch(100);
    ogre3dConstructionGroup->setLayout(ogre3dGroupLayout);
    mMainTabAndOgreLayout->addWidget(ogre3dConstructionGroup, 1);
    mMainLayout->addSpacing(12);
}

//****************************************************************************/
void WindowTab::addItem(void)
{
    if (getCurrentDepthInTree() > 1)
        gotoParentInTree();

    insertItemInTree(QString("[item]"));
}

//****************************************************************************/
void WindowTab::addSubItem(void)
{
    if (getCurrentDepthInTree() > 1)
        gotoParentInTree();

    insertChildInTree(QString("[submenu item]"));
}

//****************************************************************************/
void WindowTab::deleteItemSubItem(void)
{
    removeRowFromTree();
}

//****************************************************************************/
void WindowTab::insertItemInTree(const QString itemName)
{
    QModelIndex index = mTreeView->selectionModel()->currentIndex();
    QAbstractItemModel* model = mTreeView->model();

    if (!model->insertRow(index.row()+1, index.parent()))
        return;

    for (int column = 0; column < model->columnCount(index.parent()); ++column)
    {
        QModelIndex child = model->index(index.row()+1, column, index.parent());
        model->setData(child, QVariant(itemName), Qt::EditRole);
        QString str = Utils::stripSpecialCharacters(itemName);
        mGroupItemMap[itemName] = str; // The group is also the itemname
    }
}

//****************************************************************************/
void WindowTab::removeRowFromTree(void)
{
    QModelIndex index = mTreeView->selectionModel()->currentIndex();
    QAbstractItemModel* model = mTreeView->model();
    QString str = model->data(index, Qt::DisplayRole).toString();
    mGroupItemMap.remove(str);
    model->removeRow(index.row(), index.parent());
}

//****************************************************************************/
void WindowTab::insertChildInTree(const QString childName)
{
    QModelIndex index = mTreeView->selectionModel()->currentIndex();
    QAbstractItemModel* model = mTreeView->model();

    if (model->columnCount(index) == 0) {
        if (!model->insertColumn(0, index))
            return;
    }

    if (!model->insertRow(0, index))
        return;

    for (int column = 0; column < model->columnCount(index); ++column) {
        QModelIndex child = model->index(0, column, index);
        model->setData(child, QVariant(childName), Qt::EditRole);
        if (!model->headerData(column, Qt::Horizontal).isValid())
            model->setHeaderData(column, Qt::Horizontal, QVariant("[No header]"), Qt::EditRole);
    }

    mTreeView->selectionModel()->setCurrentIndex(model->index(0, 0, index), QItemSelectionModel::ClearAndSelect);
}

//****************************************************************************/
void WindowTab::gotoNextTreeRow(void)
{
    QModelIndex index = mTreeView->selectionModel()->currentIndex();
    QAbstractItemModel* model = mTreeView->model();
    int rowCount = model->rowCount();

    if (index.row() < rowCount)
    {
        mTreeView->selectionModel()->setCurrentIndex(model->index(index.row() + 1, 0, index.parent()), QItemSelectionModel::ClearAndSelect);
    }
}

//****************************************************************************/
void WindowTab::gotoParentInTree(void)
{
    QModelIndex index = mTreeView->selectionModel()->currentIndex();
    //QAbstractItemModel* model = mTreeView->model();
    index = index.parent(); // Set the new index to the parent
    mTreeView->selectionModel()->setCurrentIndex(index, QItemSelectionModel::ClearAndSelect);
}

//****************************************************************************/
int WindowTab::getCurrentDepthInTree(void)
{
    QModelIndex index = mTreeView->selectionModel()->currentIndex();
    //QAbstractItemModel* model = mTreeView->model();
    int count = 0;
    while (index.isValid())
    {
        count++;
        index = index.parent();
    }
    return count;
}

//****************************************************************************/
void WindowTab::handleSelectionCategoryChanged(int index)
{
    mCategoryComboBox->handleSelectionChanged(index);
}

//****************************************************************************/
//void WindowTab::handleSelectionOgreTarget(int index)
//{
//    mOgreTarget = index + 1;
//}

//****************************************************************************/
void WindowTab::deleteIconFromToolbar(QString mimeType)
{
    if (mimeType == MIME_TYPE_HTOOLBAR && mHorizontalToolbarModel && mHorizontalToolbarList)
    {
        // Delete currently selected item of the horizontal toolbarwidget. This was the one that was dropped in the bin
        QModelIndex index = mHorizontalToolbarList->currentIndex();
        mHorizontalToolbarModel->removeRows (index.row(), 1, index.parent());
    }
    else if (mimeType == MIME_TYPE_VTOOLBAR && mVerticalToolbarModel && mVerticalToolbarList)
    {
        // Delete currently selected item of the vertical toolbarwidget. This was the one that was dropped in the bin
        QModelIndex index = mVerticalToolbarList->currentIndex();
        mVerticalToolbarModel->removeRows (index.row(), 1, index.parent());
    }
}

//****************************************************************************/
void WindowTab::addTab(void)
{
    NamedIcon icon(QString("info.png"), mParent->getIconDir() + QString("info.png"));
    mTabWidget->addTab(new QWidget(this), icon, QString("Doubleclick to edit"));
    fillOgreTargetComboBox(mTabWidget->count()); // There are tabs, use the tabs as a target
}

//****************************************************************************/
void WindowTab::deleteTab(void)
{
    mTabWidget->removeTab(mTabWidget->currentIndex());
    fillOgreTargetComboBox(mTabWidget->count()); // If there are tabs, use the tabs as a target
}

//****************************************************************************/
void WindowTab::deleteThisWindow(void)
{
    mParent->removeCurrentTab();
}

//****************************************************************************/
void WindowTab::ogreTargetChanged(int index)
{
    // Fill the target cpmbobox
    fillOgreTargetComboBox(1);

    // Disable the checkbox for the Ogre assets
    if (mParent)
    {
        QCheckBox* checkBox = mParent->mGeneralTab->mUseOgreAssetWidgetCheckBox;
        if (mParent->mGeneralTab && checkBox)
        {
            if (mUseOgreCheckBox->isChecked())
            {
                // Enable the checkbox on the general tab
                checkBox->setEnabled(true);
                checkBox->setText(TEXT_USE_OGRE_ASSETS);
            }
            else
            {
                // Check whether alle Ogre control checkboxes are disabled
                if (!mParent->isOgreUsed())
                {
                    // Disable it
                    checkBox->setEnabled(false);
                    checkBox->setText(TEXT_USE_OGRE_ASSETS_DISABLED);
                    checkBox->setChecked(false);
                }
            }
        }
    }
}

//****************************************************************************/
void WindowTab::fillOgreTargetComboBox(int target)
{
    if (!mOgreTargetComboBox)
        return;

    if (target == 0)
    {
        mOgreTargetComboBox->setVisible(false);
        mTargetLabel->setVisible(false);
        return;
    }

    if (mUseOgreCheckBox->isChecked())
    {
        if (mTabWidget->count() > 0)
        {
            // Fill combobox with items
            QStringListModel* model = new QStringListModel();
            QStringList list;
            int tabCount = mTabWidget->count();
            for (int t = 0; t < tabCount; ++t)
            {
                //list << QString("Tab index ") + QVariant(t).toString();
                list << mTabWidget->tabText(t);
            }
            model->setStringList(list);
            mOgreTargetComboBox->setModel(model);
            mOgreTargetComboBox->setCurrentIndex(target - 1);

            // Show the combobox
            mOgreTargetComboBox->setVisible(true);
            mTargetLabel->setVisible(true);
        }
        else
        {
            // Hide the combobox
            mOgreTargetComboBox->setVisible(false);
            mTargetLabel->setVisible(false);
        }
    }
    else
    {
        // Hide the combobox
        mOgreTargetComboBox->setVisible(false);
        mTargetLabel->setVisible(false);
    }
}
