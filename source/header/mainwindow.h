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

#ifndef MAGUS_MAINWINDOW_H
#define MAGUS_MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QTabWidget>
#include <QVBoxLayout>
#include "applicationtemplate.h"
#include "templatereader.h"
#include "qtbuilder.h"
#include "wxwidgetsbuilder.h"
#include "iconreader.h"
#include "generaltab.h"

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
class QSettings;
class QTabWidget;
class QVBoxLayout;
QT_END_NAMESPACE

class MainApplication;
class WindowTab;

/****************************************************************************
 Main window of the Magus application.
****************************************************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(MainApplication* app);
        virtual ~MainWindow();
        const QString getTemplateDir (void) const;
        const QString getIconDir (void) const;
        const QString getLayoutDir (void) const;
        void setSelectedTemplateName(QString selectedTemplateName);
        const TemplateReader* getTemplateReader(void) const;
        ApplicationTemplate* getApplicationTemplate(void) const;
        Builder* getCurrentBuilder(void) const;
        MainApplication* getMainApplication(void) const;
        void newTab(void);
        void removeCurrentTab(void);
        bool isOgreUsed(void);
        GeneralTab* mGeneralTab; // Make it public, so that it can be used in other widgets

    protected:
        void contextMenuEvent(QContextMenuEvent *event);

    private slots:
        void newProject(void);
        bool selectTemplate(void);
        void createTabs(void);
        void openProject(void);
        void saveProject(void);
        void build(void);
        void config(void);
        void about(void);

    private:
        void createActions(void);
        void createMenus(void);
        void createApplicationTemplateFromWidgets(void);
        bool validateWidgetValues(void);

        MainApplication* mApp;
        QMap<QString, Builder*> mBuilderFactory;
        QtBuilder mQtBuilder;
        WxWidgetsBuilder mWxWidgetsBuilder;

        QTabWidget* mTabWidget;
        QMenu* fileMenu;
        QMenu* toolMenu;
        QMenu* helpMenu;
        QAction* newAct;
        QAction* openAct;
        QAction* saveAct;
        QAction* buildAct;
        QAction* exitAct;
        QAction* configAct;
        QAction* aboutAct;
        QLabel* infoLabel;

        QString mTemplateDir;
        QString mIconDir;
        QString mLayoutDir;
        QString mQtDir;
        QString mSelectedTemplateName;

        TemplateReader mTemplateReader;
        ApplicationTemplate* mApplicationTemplate;
        IconReader mIconReader;

        QVector<WindowTab*> mWindowTabList;
};

//****************************************************************************/
#endif
