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
#include "tool_gradientmarker.h"

namespace Magus
{
    //****************************************************************************/
    QtGradientMarker::QtGradientMarker(QGraphicsItem* parent) : QGraphicsPathItem(parent)
    {
        mColor = QColor("#ffffff");
        mColoredSquare = new QGraphicsPathItem(this);
        mPointer = new QGraphicsPathItem(this);
        mSize.setWidth(16.0f);
        mSize.setHeight(16.0f);
        mPen = QPen(Qt::black);
    }

    //****************************************************************************/
    void QtGradientMarker::setMarkerSize (QSizeF size)
    {
        mSize = size;
        drawMarker();
    }

    //****************************************************************************/
    void QtGradientMarker::selectMarker(bool selected)
    {
        if (selected)
        {
            mPen.setColor("#cc7800");
            mPen.setWidth(2);
        }
        else
        {
            mPen.setColor(Qt::black);
            mPen.setWidth(1);
        }
        drawMarker();
    }

    //****************************************************************************/
    //****************************************************************************/
    //****************************************************************************/
    QtGradientMarkerColor::QtGradientMarkerColor(QGraphicsItem* parent) : QtGradientMarker(parent)
    {
        setData(KEY_GRADIENT_MARKER, QVariant(VALUE_GRADIENT_MARKER_COLOR));
        mColoredSquare->setData(KEY_GRADIENT_MARKER, QVariant(VALUE_GRADIENT_MARKER_COLOR));
        drawMarker();
    }

    //****************************************************************************/
    QtGradientMarkerColor::~QtGradientMarkerColor(void)
    {
    }

    //****************************************************************************/
    void QtGradientMarkerColor::setColor (const QColor& color)
    {
        mColor = color;
        drawMarker();
    }

    //****************************************************************************/
    void QtGradientMarkerColor::setAlpha (int alpha)
    {
        mColor.setAlpha(alpha);
        drawMarker();
    }

    //****************************************************************************/
    void QtGradientMarkerColor::drawMarker(void)
    {
        // Square
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(mColor);
        QPainterPath ps;
        ps.addRect(0, 0, mSize.width(), mSize.height());
        mColoredSquare->setPen(mPen);
        mColoredSquare->setPath(ps);
        mColoredSquare->setBrush(brush);

        // Pointer
        QPainterPath pp;
        qreal half = 0.5 * mSize.width();
        QPolygonF poly;
        QPointF point;
        point.setX(0.25 * mSize.width());
        point.setY(0);
        poly.append(point);
        point.setX(half);
        point.setY(-half);
        poly.append(point);
        point.setX(0.75 * mSize.width());
        point.setY(0);
        poly.append(point);
        pp.addPolygon(poly);
        mPointer->setPen(mPen);
        mPointer->setPath(pp);
    }

    //****************************************************************************/
    //****************************************************************************/
    //****************************************************************************/
    QtGradientMarkerAlpha::QtGradientMarkerAlpha(QGraphicsItem* parent) : QtGradientMarker(parent)
    {
        setData(KEY_GRADIENT_MARKER, QVariant(VALUE_GRADIENT_MARKER_ALPHA));
        mColoredSquare->setData(KEY_GRADIENT_MARKER, QVariant(VALUE_GRADIENT_MARKER_ALPHA));
        drawMarker();
    }

    //****************************************************************************/
    QtGradientMarkerAlpha::~QtGradientMarkerAlpha(void)
    {
    }

    //****************************************************************************/
    void QtGradientMarkerAlpha::setColor (const QColor& color)
    {
        mColor = color;
        drawMarker();
    }

    //****************************************************************************/
    void QtGradientMarkerAlpha::setAlpha (int alpha)
    {
        mColor.setAlpha(alpha);
        mColor.setRed(alpha);
        mColor.setGreen(alpha);
        mColor.setBlue(alpha);
        drawMarker();
    }

    //****************************************************************************/
    void QtGradientMarkerAlpha::drawMarker(void)
    {
        // Square
        QColor tmpColor = mColor;
        tmpColor.setAlpha(255);
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(tmpColor);
        QPainterPath ps;
        ps.addRect(0, 0, mSize.width(), mSize.height());
        mColoredSquare->setPen(mPen);
        mColoredSquare->setPath(ps);
        mColoredSquare->setBrush(brush);

        // Pointer
        QPainterPath pp;
        qreal half = 0.5 * mSize.width();
        QPolygonF poly;
        QPointF point;
        point.setX(0.25 * mSize.width());
        point.setY(mSize.height());
        poly.append(point);
        point.setX(half);
        point.setY(mSize.height() + half);
        poly.append(point);
        point.setX(0.75 * mSize.width());
        point.setY(mSize.height());
        poly.append(point);
        pp.addPolygon(poly);
        mPointer->setPen(mPen);
        mPointer->setPath(pp);
    }
}