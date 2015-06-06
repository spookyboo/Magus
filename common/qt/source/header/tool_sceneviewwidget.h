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

#ifndef MAGUS_TOOL_SCENEVIEW_WIDGET_H
#define MAGUS_TOOL_SCENEVIEW_WIDGET_H

#include <QMenu>
#include <QWidget>
#include <QMouseEvent>
#include <QTreeWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

namespace Magus
{
    static const int TOOL_SCENEVIEW_ICON_WIDTH = 24;
    static const int TOOL_SCENEVIEW_COLUMN_ICON = 0;
    static const int TOOL_SCENEVIEW_COLUMN_ASSET_NAME = 0;
    static const int TOOL_SCENEVIEW_COLUMN_ASSET_VISIBILITY = 2;
    static const int TOOL_SCENEVIEW_COLUMN_ASSET_CLOSE = 3;
    static const int TOOL_SCENEVIEW_COLUMN_GROUP_NAME = 1;
    static const int TOOL_SCENEVIEW_COLUMN_GROUP_VISIBILITY = 2;
    static const int TOOL_SCENEVIEW_COLUMN_GROUP_CLOSE = 3;
    static const int TOOL_SCENEVIEW_KEY_GROUPID = 1;
    static const int TOOL_SCENEVIEW_KEY_ASSETID = 1;
    static const int TOOL_SCENEVIEW_KEY_ITEM_TYPE = 2;
    static const int TOOL_SCENEVIEW_KEY_VISIBLE = 3;
    static const int TOOL_SCENEVIEW_KEY_ITEM_TYPE_GROUP = 1;
    static const int TOOL_SCENEVIEW_KEY_ITEM_TYPE_ASSET = 2;
    static const QString TOOL_SCENEVIEW_ICON_VISIBLE = QString("view_visible_bold.png");
    static const QString TOOL_SCENEVIEW_ICON_INVISIBLE = QString("view_invisible_bold.png");
    static const QString TOOL_SCENEVIEW_ICON_CLOSE = QString("close_bold.png");
    static const QString TOOL_SCENEVIEW_ICON_SEARCH = QString("search_bold.png");

    /****************************************************************************
    Struct for asset group info
    ***************************************************************************/
    struct QtAssetGroup
    {
        int groupId;
        QString groupIcon;
        QString groupName;
    };


    /****************************************************************************
    Main class for scene view widget. This widget contains a tree structure with
    asset groups in the most top-level and asset items in each group.
    ***************************************************************************/
    class QtSceneViewWidget : public QWidget
    {
        Q_OBJECT

        public:
            QtSceneViewWidget(const QString iconDir, QWidget* parent = 0);
            virtual ~QtSceneViewWidget(void);
            bool eventFilter(QObject* object, QEvent* event);

            // Add a sceneview to the scene. Each sceneview contains multiple assets
            QTreeWidget* createSceneView (int sceneId);

            // Delete a sceneview.
            void deleteSceneView (int sceneId);

            // Display/hides a sceneview
            void setSceneViewVisible (int sceneId, bool visible);

            // Set a sceneview visible
            void setSceneViewVisible (int sceneId);

            // Return a sceneview
            QTreeWidget* getSceneView (int sceneId);

            // Return a sceneId
            int getSceneId (QTreeWidget* sceneView);

            // Set all sceneviews invisible
            void setSceneViewsInvisible (void);

            // Visibility icons are not visible for both groups and assets
            void setVisibilityIconVisible (bool visible);

            // Visibility icons are not visible for groups
            void setVisibilityIconVisibleForGroups (bool visible);

            // Visibility icons are not visible for assets
            void setVisibilityIconVisibleForAssets (bool visible);

            // Deletion icons are not visible for both groups and assets
            void setDeletionIconVisible (bool visible);

            // Deletion icons are not visible for groups
            void setDeletionIconVisibleForGroups (bool visible);

            // Deletion icons are not visible for assets
            void setDeletionIconVisibleForAssets (bool visible);

            // Add a group (and icon) to all sceneviews
            // The group info is internally stored. All newly created sceneviews will also get the groups
            // Note, that groupIcon must be a base filename. E.g. "mesh_icon.png"
            void addGroup (int groupId, const QString& iconName, const QString& groupName);

            // Add a group (and icon) to a particular sceneview.
            // The addGroupToMapFlag determines whether the group is also added to the overall map of this widget.
            // Creation of subsequent sceneviews also get these added groups.
            void addGroupToSceneView (int sceneId,
                                      const QString& iconName,
                                      int groupId,
                                      const QString& groupName,
                                      bool addGroupToMapFlag = true);
            void addGroupToSceneView (QTreeWidget* sceneView,
                                      const QString& iconName,
                                      int groupId,
                                      const QString& groupName,
                                      bool addGroupToMapFlag = true);

            // Add an asset item to a particular sceneview (identified by sceneView or id).
            // The asset is associated with a group (identified by means of the groupId).
            void addAssetToSceneView (int sceneId, int groupId, int assetId, const QString& assetName);
            void addAssetToSceneView (QTreeWidget* sceneView, int groupId, int assetId, const QString& assetName);

            // Get the currently selected item in the tree; this can  be both a group item or an asset item
            // (by id and by sceneView)
            QTreeWidgetItem* getCurrentItem(int sceneId);
            QTreeWidgetItem* getCurrentItem(QTreeWidget* sceneView);

            // Get the currently selected item in the tree, of the first visisble scene;
            // this can  be both a group item or an asset item.
            QTreeWidgetItem* getCurrentItemOfCurrentScene (void);

            // Get the first visible scene
            QTreeWidget* getCurrentVisibleScene (void);

            // Returns a list of all items belonging to a certain group
            QVector<QTreeWidgetItem*> getAssetItemsOfGroup (int sceneId, int groupId);

            // Determine whether an item is a group
            bool itemIsGroup(QTreeWidgetItem* item);

            // Determine whether an item is an asset
            bool itemIsAsset(QTreeWidgetItem* item);

            // Check whether an asset with the given criteria already exists in a sceneView
            bool assetExists (int sceneId, int groupId, int assetId);
            bool assetExists (QTreeWidget* sceneView, int groupId, int assetId);

            // Check whether a group with the groupId already exists in a sceneView
            bool groupExists (int sceneId, int groupId);
            bool groupExists (QTreeWidget* sceneView, int groupId);

            // Define whether this widget cant be used for drag and drop
            void enableDragAndDrop (bool enabled);

            // Return groupId of the currently selected group
            int getCurrentGroupId(int sceneId);

            // Return groupId of the item; item can be a group or an asset
            int getCurrentGroupId(QTreeWidgetItem* item);

            // Return the group id, in case the QTreeWidgetItem is a group
            int getGroupIdOfGroupItem(QTreeWidgetItem* groupItem);

            // Return the group name, in case the QTreeWidgetItem is a group
            const QString& getGroupNameOfGroupItem(QTreeWidgetItem* groupItem);

            // Return the group id, in case the QTreeWidgetItem is an asset
            int getGroupIdOfAssetItem(QTreeWidgetItem* assetItem);

            // Return the asset id, in case the QTreeWidgetItem is an asset
            int getAssetIdOfAssetItem(QTreeWidgetItem* assetItem);

            // Return the asset name, in case the QTreeWidgetItem is an asset
            const QString& getAssetNameOfAssetItem(QTreeWidgetItem* assetItem);

            // Check wheter a sceneview already has a certain group
            bool sceneViewHasGroup(QTreeWidget* sceneView, int groupId);

            // Return the item of a group in a sceneview
            QTreeWidgetItem* getGroupItem(int sceneId, int groupId);
            QTreeWidgetItem* getGroupItem(QTreeWidget* sceneView, int groupId);

            // Return the item of an asset in a sceneview
            QTreeWidgetItem* getAssetItem(int sceneId, int assetId);
            QTreeWidgetItem* getAssetItem(QTreeWidget* sceneView, int assetId);

            // Return an info object
            const QtAssetGroup& getGroupInfo(int groupId);

            // Set the visibility icon of a certain group
            void setVisibilityOfGroup(int sceneId, int groupId, bool visible);
            void setVisibilityOfGroup(QTreeWidgetItem* groupItem, bool visible);

            // Set the visibility icon of a all groups in a sceneView
            void setVisibilityOfAllGroups(int sceneId, bool visible);

            // Set the visibility icon of a certain asset
            void setVisibilityOfAsset(int sceneId, int assetId, bool visible);
            void setVisibilityOfAsset(QTreeWidgetItem* assetItem, bool visible);

            // Determine whether a group item is visible (status of the visibility icon)
            bool groupIsVisible(QTreeWidgetItem* groupItem);

            // Determine whether a parent group of a child asset item is visible (status of the visibility icon)
            bool groupOfAssetItemIsVisible(QTreeWidgetItem* assetItem);

            // Determine whether an asset item is visible (status of the visibility icon)
            bool assetIsVisible(QTreeWidgetItem* assetItem);

            // Delete a group
            void deleteGroup(int sceneId, int groupId);

            // Delete an asset
            void deleteAsset(int sceneId, int assetId);

        public slots:
            // Called when the search clearbutton is pressed
            void clearSearchLine(void);

            // Called when the search string changes
            void searchLineTextChanged(QString text);

        signals:
            // TODO
            // Emitted when a group is added to the sceneView tree
            void groupCreatedOrAdded(QTreeWidget* sceneView, int groupId);

            // Emitted when an asset is added to a group in the sceneView tree
            void assetCreatedOrAdded(QTreeWidget* sceneView, int groupId, int assetId);

            // Emitted when a group is removed (deleted) from the sceneView tree
            void groupDeleted(QTreeWidget* sceneView, int groupId);
            void groupDeleted(int sceneId, int groupId);

            // Emitted when an asset is removed (deleted) from a group in the sceneView tree
            void assetDeleted(QTreeWidget* sceneView, int groupId, int assetId);
            void assetDeleted(int sceneId, int groupId, int assetId);

            // Emitted when the visibility column of a group in the sceneView tree is toggled
            void groupVisibiltyChanged(QTreeWidget* sceneView, int groupId);

            // Emitted when the visibility column of an asset in the sceneView tree is toggled
            void assetVisibiltyChanged(QTreeWidget* sceneView, int groupId, int assetId);

            // Emitted when a group in the sceneView tree is selected
            void groupSelected(QTreeWidget* sceneView, int groupId);

            // Emitted when an asset in the sceneView tree is selected
            void assetSelected(QTreeWidget* sceneView, int groupId, int assetId);

        protected:
            void mouseClickHandler(QMouseEvent* event);
            void toggleVisibilityOfGroup(QTreeWidgetItem* groupItem);
            void toggleVisibilityOfAsset(QTreeWidgetItem* assetItem);
            void handleDeletionOfGroup(QTreeWidget* sceneView, QTreeWidgetItem* groupItem);
            void handleDeletionOfAsset(QTreeWidget* sceneView, QTreeWidgetItem* assetItem);
            void handleDeletionOfItem(QTreeWidget* sceneView, QTreeWidgetItem* item);
            void checkHeader(void);
            void setVisibilitySearchWidgets(bool visible);
            void addGroupToMap (int groupId, const QString& iconName, const QString& groupName);
            void findAndShowItems(QTreeWidget* sceneView, const QString& searchPattern);
            void resetSearch(void);

        private:
            QString mIconDir;
            QVBoxLayout* mTreeLayout;
            QHBoxLayout* mSearchLayout;
            QLineEdit* mSearchLine;
            QLabel* mSearchLabel;
            QPushButton* mSearchClearButton;
            QMap<int, QTreeWidget*> mSceneViewMap; // Multiple scenes (QTreeWidget) are possible
            QMap<int, QtAssetGroup*> mAssetGroupMap; // The groups
            QVector<QTreeWidgetItem*> mResultItemVec;
            QtAssetGroup mResultAssetGroupInfo;
            QString mResultText;
            bool mVisibilityIconVisibleForGroups;
            bool mVisibilityIconVisibleForAssets;
            bool mDeletionIconVisibleForGroups;
            bool mDeletionIconVisibleForAssets;
    };
}

#endif