/****************************************************************************
**
** Copyright (C) 2014
**
** This file is generated by the Magus toolkit
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

// Include
#include <QString>
#include <QFile>
#include <QMenuBar>
#include "tool_resourcewidget_main.h"
#include "tool_resourcewidget_assets.h"

namespace Magus
{
    //****************************************************************************/
    QtResourceMain::QtResourceMain(const QString& iconDir, QWidget* parent) : QMainWindow(parent), mIsClosing(false)
    {
        mIconDir = iconDir;

        // Perform standard functions
        createActions();
        createMenus();
        createToolBars();
        createStatusBar();
        createDockWindows();

        // Set the title
        setWindowTitle(QString("ContentBrowser"));
        showMaximized();
    }

    //****************************************************************************/
    QtResourceMain::~QtResourceMain(void)
    {
    }

    //****************************************************************************/
    QVector<QtResourceInfo*>& QtResourceMain::getResources (void)
    {
        // Delegate to mSourcesDockWidget
        return mSourcesDockWidget->getResources();
    }

    //****************************************************************************/
    void QtResourceMain::closeEvent(QCloseEvent* event)
    {
        mIsClosing = true;
    }

    //****************************************************************************/
    void QtResourceMain::createActions(void)
    {
        mNewHToolbarAction = new QAction(QIcon(mIconDir + "new.png"), QString("Clear resource tree"), this);
        connect(mNewHToolbarAction, SIGNAL(triggered()), this, SLOT(doNewHToolbarAction()));
        mLoadHToolbarAction = new QAction(QIcon(mIconDir + "open.png"), QString("Load resource tree"), this);
        connect(mLoadHToolbarAction, SIGNAL(triggered()), this, SLOT(doLoadHToolbarAction()));
        mSaveHToolbarAction = new QAction(QIcon(mIconDir + "save.png"), QString("Save resource tree"), this);
        connect(mSaveHToolbarAction, SIGNAL(triggered()), this, SLOT(doSaveHToolbarAction()));
        mShowCollectionsHToolbarAction = new QAction(QIcon(mIconDir + "color.png"), QString("Show/hide Collections area"), this);
        connect(mShowCollectionsHToolbarAction, SIGNAL(triggered()), this, SLOT(doShowCollectionsHToolbarAction()));
    }

    //****************************************************************************/
    void QtResourceMain::createMenus(void)
    {
    }

    //****************************************************************************/
    void QtResourceMain::createToolBars(void)
    {
        mHToolBar = new QToolBar();
        addToolBar(Qt::TopToolBarArea, mHToolBar);
        mHToolBar->setMinimumHeight(TB_ICON_AND_SPACING);
        mHToolBar->setMinimumWidth(4 * TB_ICON_AND_SPACING);
        mHToolBar->addAction(mNewHToolbarAction);
        mHToolBar->addAction(mLoadHToolbarAction);
        mHToolBar->addAction(mSaveHToolbarAction);
        mHToolBar->addAction(mShowCollectionsHToolbarAction);
    }

    //****************************************************************************/
    void QtResourceMain::createStatusBar(void)
    {
    }

    //****************************************************************************/
    void QtResourceMain::createDockWindows(void)
    {
        // Sources (tree)
        mSourcesDockWidget = new QtSourcesDockWidget(mIconDir, QString("Sources"), this);
        connect(mSourcesDockWidget, SIGNAL(resourceSelected(int,int,int,const QString&,const QString&)), this, SLOT(handleResourceSelected(int,int,int,const QString&,const QString&)));
        connect(mSourcesDockWidget, SIGNAL(resourceAdded(int,int,int,const QString&,const QString&)), this, SLOT(handleResourceAdded(int,int,int,const QString&,const QString&)));
        connect(mSourcesDockWidget, SIGNAL(resourceDeleted(int,int,int,const QString&,const QString&)), this, SLOT(handleResourceDeleted(int,int,int,const QString&,const QString&)));
        connect(mSourcesDockWidget, SIGNAL(resourceSearched(QString)), this, SLOT(handleResourceSearched(QString)));
        connect(mSourcesDockWidget, SIGNAL(resourceSearchReset()), this, SLOT(handleResourceSearchReset()));
        addDockWidget(Qt::LeftDockWidgetArea, mSourcesDockWidget);

        // Assets
        mAssetsDockWidget = new QtAssetsDockWidget(mIconDir, QString("Assets"), this);
        connect(mAssetsDockWidget, SIGNAL(tabChanged(int)), this, SLOT(handleTabChanged(int)));
        addDockWidget(Qt::RightDockWidgetArea, mAssetsDockWidget);

        // Collections
        mCollectionsDockWidget = new QtCollectionsDockWidget(mIconDir, QString("Collections"), this);
        addDockWidget(Qt::LeftDockWidgetArea, mCollectionsDockWidget);
        mCollectionsDockWidget->setMinimumHeight(100);
        mCollectionsDockWidget->hide();
    }

    //****************************************************************************/
    void QtResourceMain::doNewHToolbarAction(void)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Test", "Are you sure to clear the resource tree?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            mSourcesDockWidget->clearContent();
            mAssetsDockWidget->clearContent();
        }
    }

    //****************************************************************************/
    void QtResourceMain::doLoadHToolbarAction(void)
    {
        emit loadButtonClicked();
    }

    //****************************************************************************/
    void QtResourceMain::doSaveHToolbarAction(void)
    {
        emit saveButtonClicked();
    }

    //****************************************************************************/
    void QtResourceMain::doShowCollectionsHToolbarAction(void)
    {
        if (mCollectionsDockWidget->isVisible())
            mCollectionsDockWidget->hide();
        else
            mCollectionsDockWidget->show();
    }

    //****************************************************************************/
    void QtResourceMain::update(void)
    {
    }

    //****************************************************************************/
    void QtResourceMain::handleResourceSelected(int toplevelId, int parentId, int resourceId, const QString& name, const QString& baseName)
    {
        // Select the appropriate tab, based on the provided information
        mAssetsDockWidget->selectTab(toplevelId, parentId, resourceId, name, baseName);
    }

    //****************************************************************************/
    void QtResourceMain::handleResourceAdded(int toplevelId, int parentId, int resourceId, const QString& name, const QString& baseName)
    {
        // Add name to the mAssetsDockWidget
        mAssetsDockWidget->addAsset(toplevelId, parentId, resourceId, name, baseName);
    }

    //****************************************************************************/
    void QtResourceMain::handleResourceDeleted(int toplevelId, int parentId, int resourceId, const QString& name, const QString& baseName)
    {
        // Delete name from mAssetsDockWidget
        //mAssetsDockWidget->deleteAsset(toplevelId, name);
        mAssetsDockWidget->deleteAsset(toplevelId, name, baseName);
    }

    //****************************************************************************/
    void QtResourceMain::handleResourceSearched(const QString& searchPattern)
    {
        // Apply filtering to mAssetsDockWidget
        mAssetsDockWidget->filter(searchPattern);
    }

    //****************************************************************************/
    void QtResourceMain::handleResourceSearchReset(void)
    {
        // Reset the filtering in mAssetsDockWidget
        mAssetsDockWidget->resetFilter();
    }

    //****************************************************************************/
    void QtResourceMain::handleTabChanged(int toplevelId)
    {
        // Set the correct toplevel group in mSourcesDockWidget, based on the selected tab
        mSourcesDockWidget->selectTopLevel(toplevelId);
    }

}
