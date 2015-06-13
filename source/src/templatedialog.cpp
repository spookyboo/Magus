/****************************************************************************
**
** Copyright (C) 2015
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
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableWidgetItem>
#include "constants.h"
#include "applicationtemplate.h"
#include "mainwindow.h"
#include "templatereader.h"
#include "templatedialog.h"

//****************************************************************************/
TemplateDialog::TemplateDialog(MainWindow* parent) : QDialog(parent)
{
    mParent = parent;
    QString templateDir = mParent->getTemplateDir(); // Location of the template files
    QString layoutDir = mParent->getLayoutDir(); // Location of the icons/images

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(okAndAccept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    setWindowTitle(tr("Create new project - select a template"));
    resize(TEMPLATE_DIALOG_WIDTH, TEMPLATE_DIALOG_HEIGHT);
    mTable = new QTableView(this);
    mTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(buttonBox);
    layout->addWidget(mTable);
    setLayout(layout);

    // Read the list with templates to determine the number of templates. The list is in the form:
    //    template[0] = abc
    //    template[1] = xyz
    //    template[2] = mno
    QString templateName;
    QString key;
    int rows = -1;
    int line = 0;
    bool end = false;
    QSettings templateSettings(GLOBAL_TEMPLATES_FILE,  QSettings::IniFormat);
    templateSettings.beginGroup(TEMPLATES_GROUP);
    while (!end)
    {
        // Read templatename
        QVariant var(line);
        key = TEMPLATE_KEY_TEMPLATE + tr("[") + var.toString() + tr("]");
        templateName = templateSettings.value(key).toString();
        rows++;
        line++;
        end = templateName.isEmpty();
    }
    templateSettings.endGroup();

    // Create the model to fill in the table
    QStandardItemModel* model = new QStandardItemModel(rows, 3, this);
    model->setHorizontalHeaderItem(0, new QStandardItem(tr("Template")));
    model->setHorizontalHeaderItem(1, new QStandardItem(tr("Layout")));
    model->setHorizontalHeaderItem(2, new QStandardItem(tr("Description")));
    mTable->setModel(model);
    mTable->setColumnWidth(0, TEMPLATE_DIALOG_NAME_WIDTH);
    mTable->setColumnWidth(1, TEMPLATE_DIALOG_ICON_WIDTH);
    mTable->setColumnWidth(2, TEMPLATE_DIALOG_WIDTH - TEMPLATE_DIALOG_ICON_WIDTH - TEMPLATE_DIALOG_NAME_WIDTH - TEMPLATE_DIALOG_PADDING_WIDTH);
    QStandardItem *item = 0;

    // Loop througt the project templates list again and fill the table
    templateSettings.beginGroup(TEMPLATES_GROUP);
    TemplateReader templateReader; // Used to read all individual templates
    ApplicationTemplate applicationTemplate;
    QString description;
    line = 0;
    end = false;
    while (!end)
    {
        // Read templatename
        QVariant var(line);
        key = TEMPLATE_KEY_TEMPLATE + tr("[") + var.toString() + tr("]");
        templateName = templateSettings.value(key).toString();
        if (templateName.isEmpty())
        {
            end = true;
        }
        else
        {
            // Read each template file and retrieve the description and location of the icon file
            templateReader.readGeneral(&applicationTemplate, templateDir + templateName, QSettings::IniFormat);
            description = applicationTemplate.mDescription;

            // Column 'Template'
            item = new QStandardItem(templateName);
            model->setItem(line, 0, item);

            // Column 'Layout'
            item = new QStandardItem(templateName); // TODO: Incorrect copy-paste?
            QImage image(layoutDir + applicationTemplate.mIconName);
            item = new QStandardItem();
            QPixmap pixMap = QPixmap::fromImage(image).scaled(TEMPLATE_DIALOG_ICON_WIDTH, TEMPLATE_DIALOG_ICON_HEIGHT);
            item->setData(QVariant(pixMap), Qt::DecorationRole);
            model->setItem(line, 1, item);
            mTable->setRowHeight(line, TEMPLATE_DIALOG_ICON_HEIGHT);

            // Column 'Description'
            item = new QStandardItem(description);
            model->setItem(line, 2, item);
        }
        line++;
        end = templateName.isEmpty();
    }
    templateSettings.endGroup();

    // Show the table
    mTable->resize(TEMPLATE_DIALOG_WIDTH, TEMPLATE_DIALOG_HEIGHT);
    connect(mTable, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(doubleClick(QModelIndex)));
}

//****************************************************************************/
void TemplateDialog::doubleClick(QModelIndex index)
{
    int row = index.row();
    QString templateName = index.sibling(row, 0).data().toString();
    mParent->setSelectedTemplateName(templateName);
    accept();
}

//****************************************************************************/
void TemplateDialog::okAndAccept(void)
{
    QModelIndex index = mTable->selectionModel()->currentIndex();
    doubleClick(index);
}
