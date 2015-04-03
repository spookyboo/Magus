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

#ifndef MAGUS_CUSTOM_TABWIDGET_H
#define MAGUS_CUSTOM_TABWIDGET_H

#include <QTabWidget>
#include <QTabBar>
#include <QMouseEvent>
#include <QMap>
#include "constants.h"
#include "application.h"

class IconReader;
class NamedIcon;

/****************************************************************************
 QTabWidget that handles mouse events
****************************************************************************/
class CustomTabWidget : public QTabWidget, CustomEventHandler
{
    Q_OBJECT

    public:
        CustomTabWidget(QWidget* parent,
                        MainApplication* app,
                        IconReader* iconReader,
                        QString iconDir);
        virtual ~CustomTabWidget(void);
        virtual void mouseMoveEvent(QMouseEvent* event);
        int addTab(QWidget* page, const NamedIcon &icon, const QString &label);
        virtual void removeTab (int index);
        const QString getIconName(int index) const;
        const QString getTabName(int index) const;
        void handleEvent(QEvent* event);

    signals:
        void tabTextChanged(int index);

    private:
        bool mMouseOver;
        QString mIconDir;
        MainApplication* mApp;
        IconReader* mIconReader;
        QList<QString>mNames;
        bool isOver(QMouseEvent* mouseEvent);
};

//****************************************************************************/
#endif
