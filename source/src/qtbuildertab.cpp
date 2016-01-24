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

#include "qtbuildertab.h"
#include "qtbuilder.h"
#include "applicationtemplate.h"
#include "utils.h"

//****************************************************************************/
QtTabBuilder::QtTabBuilder()
{
}

//****************************************************************************/
QtTabBuilder::~QtTabBuilder()
{
}

//****************************************************************************/
QString QtTabBuilder::createInclude(WindowProperties* windowProperties, const QString &s)
{
    QString str = s;

    // Add the #include
    str = str +
        QString("#include <QTabWidget>") +
        QString("\n");

    return str;
}

//****************************************************************************/
QString QtTabBuilder::createPrivateMembers(WindowProperties* windowProperties, const QString &s)
{
    QString str = s;
    if (windowProperties)
    {
        // Define private members
        if (!windowProperties->mTabPropertiesList.empty())
        {
            str = str +
                TAB +
                TAB +
                QString("QTabWidget* mTabWidget;") +
                QString("\n");
        }
    }

    return str;
}

//****************************************************************************/
QString QtTabBuilder::createPrivateSlots(WindowProperties* windowProperties, const QString &s)
{
    QString str = s;
    if (windowProperties)
    {
        // Define private slots
        if (!windowProperties->mTabPropertiesList.empty())
        {
            str = str +
                TAB +
                TAB +
                QString("void tabSelected(int index);") +
                QString("\n");
        }
    }

    return str;
}

//****************************************************************************/
QString QtTabBuilder::createConnect(WindowProperties* windowProperties, const QString &s)
{
    QString str = s;
    if (windowProperties)
    {
        if (!windowProperties->mTabPropertiesList.empty())
        {
            str = str +
                TAB +
                QString("connect(mTabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabSelected(int)));") +
                QString("\n");
        }
    }

    return str;
}

//****************************************************************************/
QString QtTabBuilder::createTabs(WindowProperties* windowProperties,
                                 const QString &s,
                                 const QString &iconDir,
                                 const QString &fullOutputIconDir)
{
    QString str = s;
    if (windowProperties)
    {
        if (!windowProperties->mTabPropertiesList.empty())
        {
            if (windowProperties->mOrder != 0)
            {
                // Create the QTabWidget
                str = str +
                    TAB +
                    QString("mTabWidget = new QTabWidget(mInnerMain);") +
                    QString("\n");

                // Loop through the tab list of the window and add new tabs
                QFile fileUtil;
                QVectorIterator<TabProperties*> tabList(windowProperties->mTabPropertiesList);
                TabProperties* tabProperties = 0;
                tabList.toFront();
                while (tabList.hasNext())
                {
                    tabProperties = tabList.next();

                    // Copy the icon
                    fileUtil.copy(iconDir + tabProperties->mIcon, fullOutputIconDir + tabProperties->mIcon);

                    // Add tabs to the QTabWidget
                    str = str +
                        TAB +
                        QString("mTabWidget->addTab(new QWidget(this), QIcon(\"") +
                        iconDir +
                        tabProperties->mIcon +
                        QString("\"), QString(\"") +
                        tabProperties->mName +
                        QString("\"));") +
                        QString("\n");
                }

                // Centralize the QTabWidget in the mInnerMain
                str = str +
                    TAB +
                    QString("mInnerMain->setCentralWidget(mTabWidget);") +
                    QString("\n");

                // Check whether the title must be displayed (do not set the title if it is explicitly set to 'false')
                if (!windowProperties->mDisplayTitle)
                {
                    str = str +
                        TAB +
                        QString("setWindowTitle(QString(\"\"));") +
                        QString("\n");
                }

                str = str +
                    TAB +
                    QString("mTabWidget->show();") +
                    QString("\n");
            }
        }
    }

    return str;
}

//****************************************************************************/
QString QtTabBuilder::createTabSelected(WindowProperties* windowProperties, const QString &s)
{
    QString str = s;
    if (windowProperties)
    {
        QString className;
        if (!windowProperties->mTabPropertiesList.empty())
        {
            className = Utils::stripSpecialCharacters(windowProperties->mTitle) + QString("DockWidget");
            //className = windowProperties->mTitle + QString("DockWidget");
            str = str +
                QString("//****************************************************************************/") +
                QString("\n");
            str = str +
                QString("void ") +
                className +
                QString("::tabSelected(int index)") +
                QString("\n");
            str = str +
                QString("{") +
                QString("\n");
            str = str +
                TAB +
                QString("// Replace the code in this function with your own code.") +
                QString("\n");
            str = str +
                TAB +
                QString("QString message = QString(\"Tab with index <\") + QVariant(index).toString() + QString(\"> selected\");") +
                QString("\n");
            str = str +
                TAB +
                QString("QMessageBox::information(this, QString(\"QTabWidget\"), message);") +
                QString("\n");
            str = str +
                QString("}") +
                QString("\n\n");
        }
    }

    return str;
}
