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

#ifndef MAGUS_ASSET_CURVE_DIALOG_H
#define MAGUS_ASSET_CURVE_DIALOG_H

#include <QtWidgets>
#include <QMenu>
#include <QDialog>
#include <QAction>
#include <QToolBar>
#include <QTabWidget>
#include <QGraphicsView>
#include <QStringListModel>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QSlider>
#include "asset_curve_grid.h"

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

namespace Magus
{
    static const int CURVE_DIALOG_WIDTH = 800;
    static const int CURVE_DIALOG_HEIGHT = 640;
    static const QString CURVE_ICON_FIT_HORIZONTAL = QString("curve_fit_hor.png");
    static const QString CURVE_ICON_FIT_VERTICAL = QString("curve_fit_vert.png");
    static const QString CURVE_ICON_ZOOM_IN = QString("curve_zoom_in.png");
    static const QString CURVE_ICON_ZOOM_OUT = QString("curve_zoom_out.png");
    static const QString CURVE_ICON_EDIT = QString("curve_edit.png");
    static const QString CURVE_ICON_EDIT_ON = QString("curve_edit_on.png");
    static const QString CURVE_ICON_SELECT = QString("curve_rubberband.png");
    static const QString CURVE_ICON_SELECT_ON = QString("curve_rubberband_on.png");
    static const QString CURVE_ICON_MOVE = QString("curve_move.png");
    static const QString CURVE_ICON_MOVE_ON = QString("curve_move_on.png");
    static const QString CURVE_ICON_PIVOT = QString("curve_pivot.png");
    static const QString CURVE_ICON_DELETE = QString("delete.png");
    static const int CURVE_EDIT_WIDTH = 80;
    static const int CURVE_SLIDER_WIDTH = 120;

    /****************************************************************************
    This class represents a curve dialog
    ***************************************************************************/
    class QtCurveDialog : public QDialog
    {
        Q_OBJECT

        public:
            QtCurveDialog(const QString& iconDir, QWidget* parent = 0);
            ~QtCurveDialog(void);
            void addPoint(qreal x, qreal y);
            void addPoint(QPointF point);
            void setPoints(QVector<QPointF>& points);
            QVector<QPointF>& getPoints(void);
            void refresh (void);
            QPixmap mCurvePixmap;

        public slots:
            void accept (void);

        protected:
            void createActions(void);
            void createMenus(void);
            void createToolBars(void);
            virtual void wheelEvent (QWheelEvent* event);
            virtual void resizeEvent (QResizeEvent* event);
            virtual void keyPressEvent(QKeyEvent* event);
            void refreshToolbarValues(void);

        private slots:
            void doCurveFitHorToolbarAction(void);
            void doCurveFitVertToolbarAction(void);
            void doCurveZoomInToolbarAction(void);
            void doCurveZoomOutToolbarAction(void);
            void doCurveEditToolbarAction(void);
            void doCurveSelectToolbarAction(void);
            void doCurveMoveToolbarAction(void);
            void doPivotToolbarAction(void);
            void doDeletePointsToolbarAction(void);
            void handleSelectionChanged(int index);
            void sliderXValueChanged(int);
            void sliderYValueChanged(int);
            void xMinEditChanged(QString);
            void xStepEditChanged(QString);
            void yMinEditChanged(QString);
            void yStepEditChanged(QString);

        private:
            QDialogButtonBox* mButtonBox;
            QString mIconDir;
            QMainWindow* mInnerMain;
            QStringListModel* mModel;
            QComboBox* mLineTypeCombobox;
            QAction* mCurveFitHorToolbarAction;
            QAction* mCurveFitVertToolbarAction;
            QAction* mCurveZoomInToolbarAction;
            QAction* mCurveZoomOutToolbarAction;
            QAction* mCurveEditToolbarAction;
            QAction* mCurveSelectToolbarAction;
            QAction* mCurveMoveToolbarAction;
            QAction* mPivotToolbarAction;
            QAction* mDeletePointsToolbarAction;
            QToolBar* mHToolBar;
            QtCurveGrid* mScene;
            QGraphicsView* mView;
            QLineEdit* mXminEdit;
            QLineEdit* mXstepEdit;
            QSlider* mXdecimalSlider;
            QLineEdit* mYminEdit;
            QLineEdit* mYstepEdit;
            QSlider* mYdecimalSlider;
            //QVector<QPointF> mPoints;
    };
}

#endif
