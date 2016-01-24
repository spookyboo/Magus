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

#ifndef MAGUS_WINDOWTAB_H
#define MAGUS_WINDOWTAB_H

#include <QtWidgets>
#include <QVBoxLayout>
#include <QListView>
#include <QRadioButton>
#include "iconmodel.h"
#include "customtabwidget.h"
#include "iconreader.h"
#include "customtreemodel.h"

class MainWindow;
class WindowProperties;
class IconComboBox;

/****************************************************************************
 Each window defined in a template or project file is represented by its own
 'tab' in the main window.
****************************************************************************/
class WindowTab : public QWidget
{
    Q_OBJECT

    public:
        WindowTab(WindowProperties* windowProperties, IconReader* iconReader, MainWindow* parent = 0);
        void createWindowPropertyWidgets(WindowProperties* windowProperties);
        void createMenuWidgets (WindowProperties* windowProperties);
        void createToolbarWidgets (WindowProperties* windowProperties);
        void createTabWidgets (WindowProperties* windowProperties);
        void createOgre3dControlWidgets (WindowProperties* windowProperties);

        QString mGroup;
        QLineEdit* mTitleEdit;
        QCheckBox* mTitleVisibleCheckBox;
        bool mUseOgreControlVisuals;
        int mOrder;
        QCheckBox* mTransformationCheckBox;
        QCheckBox* mResetWindowCheckBox;
        QCheckBox* mExitCheckBox;
        QCheckBox* mQuitCheckBox;
        QCheckBox* mAboutCheckBox;
        QCheckBox* mUseOgreCheckBox;
        QComboBox* mOgreTargetComboBox;
        QCheckBox* mUseOgreAssetCheckBox;
        QLabel* mTargetLabel;
        IconSelectionModel* mHorizontalToolbarModel;
        IconSelectionModel* mVerticalToolbarModel;
        TreeModel* mTreeModel;
        QMap<QString, QString> mGroupItemMap;
        CustomTabWidget* mTabWidget;
        QRadioButton* mAreaLeft;
        QRadioButton* mAreaRight;
        QRadioButton* mAreaTop;
        QRadioButton* mAreaBottom;
        QRadioButton* mAreaCenter;
        QLabel* mOrderValue;

    public slots:
        void addItem(void);
        void addSubItem(void);
        void deleteItemSubItem(void);
        void handleSelectionCategoryChanged(int index);
        void deleteIconFromToolbar(QString mimeType);
        void addTab(void);
        void deleteTab(void);
        void deleteThisWindow(void);
        void ogreTargetChanged(int index);

    private:
        MainWindow* mParent;
        QTreeView* mTreeView;
        QVBoxLayout* mMainLayout;
        QHBoxLayout* mMainMenuAndToolbarLayout;
        QHBoxLayout* mMainTabAndOgreLayout;
        IconComboBox* mCategoryComboBox;
        QListView* mSelectionList;
        QListView* mHorizontalToolbarList;
        QListView* mVerticalToolbarList;
        IconSelectionModel* mSelectionModel;
        IconReader* mIconReader;
        void insertItemInTree(const QString itemName);
        void removeRowFromTree(void);
        void insertChildInTree(const QString childName);
        void gotoNextTreeRow(void);
        void gotoParentInTree(void);
        int getCurrentDepthInTree(void);
        void fillOgreTargetComboBox(int target);
};

//****************************************************************************/
#endif
