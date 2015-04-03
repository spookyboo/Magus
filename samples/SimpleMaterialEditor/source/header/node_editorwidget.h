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

#ifndef MAGUS_NODE_EDITOR_WIDGET_H
#define MAGUS_NODE_EDITOR_WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMenu>
#include <QAction>

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

namespace Magus
{
    class QtNode;
    class QtConnection;
    class QtCompoundNode;
    class QtNodeGraphicsScene;

    /****************************************************************************
    Main class for node editor
    ***************************************************************************/
    class QtNodeEditor : public QWidget
    {
        Q_OBJECT

        public:
            QtNodeEditor(QWidget* parent = 0);
            virtual ~QtNodeEditor(void);
            bool eventFilter(QObject* object, QEvent* event);

            // If true, a context menu is displayed when the right mousebutton is selected.
            void setContextMenuEnabled(bool enabled);
            bool isContextMenuEnabled(void);

            // If true, the context menu is extended with an option to zoom in/out.
            void setMenuZoomEnabled(bool enabled);
            bool isMenuZoomEnabled(void);

            // If true, the context menu is extended with an option to crop the selected nodes to a compound.
            void setMenuSelectionToCompoundEnabled(bool enabled);
            bool isMenuSelectionToCompoundEnabled(void);

            // If true, the context menu is extended with an option to exand/collapse all nodes.
            void setMenuCollapseExpandEnabled(bool enabled);
            bool isMenuCollapseExpandEnabled(void);

            // If true, the context menu is extended with an option to expand all compounds. This
            // deletes all compound and releases the enclosed inner nodes. This action is done
            // recursively.
            void setMenuExpandCompoundsEnabled(bool enabled);
            bool isMenuExpandCompoundsEnabled(void);

            // If true, the context menu is extended with an option to view in fisheye view.
            void setMenuFisheyeViewEnabled(bool enabled);
            bool isMenuFisheyeViewEnabled(void);

            // Set the filename for the compound (created by the context menu); if applicable.
            void setCompoundHeaderTitleIcon(const QString& fileNameIcon);

            // Set the action 1 icon for the compound (created by the context menu); if applicable.
            void setCompoundAction1Icon(const QString& fileNameIcon);

            // Set the action 2 icon for the compound (created by the context menu); if applicable.
            void setCompoundAction2Icon(const QString& fileNameIcon);

            // Add a node to the scene (editor widget).
            void addNode(QtNode* node);

            // Add a node to the scene (editor widget).
            QVector<QtNode*>getNodes(void);

            // Remove a node from the scene and destroy it.
            // If cascade = true, any compound node is expanded (the compound itself is deleted) and the nodes
            // inside become visible.
            void removeNode(QtNode* node, bool cascade = false);

            // Removes (and destroys) all selected nodes and connections from the scene (editor widget).
            void removeAllSelelected(void);

            // Center all nodes
            void center(void);

            // Remove a connection from the scene (editor widget) and destroy it.
            void removeConnection(QtConnection* connection);

            // Remove AND delete all items from the node editor scene.
            void clear(void);

            // If there is a selected node, return the last one that was selected.
            QtNode* getLastSelectedNode(void);

            // Return a vector with all the currently selected nodes.
            QVector<QtNode*> getSelectedNodes (void);

            // Return a vector with all the currently selected connections.
            QVector<QtConnection*> getSelectedConnections (void);

            // Return a pointer to the last removed node.
            // Note, that the node is already deleted at this point, so this pointer does not point
            // to a valid piece of memory. This function is only used to inform the caller about the deleted note.
            // Prefered is to use a 'signal' (nodeToBeRemoved).
            QtNode* getRemovedNode(void);

            // Moves a node to front; before all other nodes.
            void toFront(QtNode* node);

            // Moves all other nodes in front of the given node.
            void toBack (QtNode* node);

            // Scale all nodes with the zoom factor.
            void setZoom(qreal zoom);

            // Scale all nodes with the zoom factor.
            void setFisheyeView(bool enabled, qreal maxZoom = 1.0f, unsigned int steps = 5);

        public slots:
            // Activated when a contextmenu item is selected
            void contextMenuItemSelected(QAction* action);

        signals:
            // Emitted when a node is added to the node editor
            void nodeAdded(QtNode*);

            // Emitted when a node is going to be removed from the node editor
            void nodeToBeRemoved(QtNode*);

            // Emitted when a node is selected
            void nodeSelected(QtNode*);

            // Emitted when one or more nodes are to be added to a compound; get these
            // nodes by means of QtNodeEditor::getSelectedNodes
            // This signal is typically emitted when the contextmenu item is selected
            // with function "Create compound from selected items".
            void selectedNodesToBeAddedToCompound(void);

        protected:
            QGraphicsItem* itemAtExceptActiveConnection(const QPointF& pos);
            QtCompoundNode* nodeOverCompound(QtNode* node);
            bool mouseClickHandler(QGraphicsSceneMouseEvent* mouseEvent);
            bool mouseDoubleClickHandler(QGraphicsSceneMouseEvent* mouseEvent);
            bool mouseMoveHandler(QGraphicsSceneMouseEvent* mouseEvent);
            bool mouseReleaseHandler(QGraphicsSceneMouseEvent* mouseEvent);
            virtual void keyPressEvent(QKeyEvent* event);
            void rubberbandSelection(QGraphicsSceneMouseEvent* mouseEvent);
            void fisheyeZoom(QGraphicsSceneMouseEvent* mouseEvent);
            void deselectAll(void);
            void deleteAllActiveConnections(void);
            bool isActiveConnection(void);
            void deselectConnections(void);
            void deselectNodes(void);
            void selectNode(QtNode* node, QGraphicsSceneMouseEvent* mouseEvent);
            void selectConnection(QtConnection* connection);
            QtNode* getNodeWithActiveConnection(void);
            bool ctrlPressed(void);
            bool isNodeAlreadySelected(QtNode* node);
            bool isConnectionAlreadySelected(QtConnection* connection);
            void showContextMenu(const QPoint& pos);
            QAction* getActionFromContextMenu(const QString& actionText);
            void setZoomForAction(qreal zoom, QAction* action);
            void resetZoomSubmenu(void);
            void setFisheyeForAction(QAction* action, bool enabled, qreal maxZoom = 1.0f, unsigned int steps = 5);
            void resetFisheySubmenu(void);
            bool isNode(QGraphicsItem* item);
            bool isCompoundNode(QGraphicsItem* item);
            bool isConnection(QGraphicsItem* item);
            void wheelEvent (QWheelEvent* event);

        private:
            qreal mZoom;
            bool mContextMenuEnabled;
            bool mMenuZoomEnabled;
            bool mMenuSelectionToCompoundEnabled;
            bool mMenuCollapseExpandEnabled;
            bool mMenuExpandCompoundsEnabled;
            bool mMenuFisheyeViewEnabled;
            bool mFisheyeViewEnabled;
            QMenu* mContextMenu;
            QMenu* mZoomSubMenu;
            QMenu* mFisheyeViewSubMenu;
            QGraphicsView* mView;
            QtNodeGraphicsScene* mScene;
            QVector<QtNode*> mCurrentlySelectedNodes;
            QVector<QtConnection*> mCurrentlySelectedConnections;
            QtNode* mLastRemovedNode;
            QGraphicsRectItem* mRubberBand;
            bool mRubberbandSelection;
            QPointF mLastMousePosition;
            QtCompoundNode* mCompoundNodeDropped;
            QString mHeaderTitleIcon;
            QString mAction1Icon;
            QString mAction2Icon;
            qreal mFisheyeMaxZoom;
            unsigned int mFisheyeSteps;
    };
}

#endif
