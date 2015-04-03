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

#include <QDialogButtonBox>
#include <QListView>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include "constants.h"
#include "icondialog.h"
#include "iconcombobox.h"
#include "iconmodel.h"
#include "iconreader.h"

//****************************************************************************/
IconDialog::IconDialog(IconReader* iconReader,
                       const QString &iconDir,
                       const QString &tabName,
                       const QString &iconName,
                       QWidget* parent) : QDialog(parent)
{
    QVBoxLayout* iconSelectionLayout = new QVBoxLayout;
    QHBoxLayout* tabLayout = new QHBoxLayout;

    mButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(mButtonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(mButtonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QLabel* tabLabel = new QLabel(tr("Tab name:"));
    tabLabel->setMinimumWidth(FIXED_LABEL_SIZE);
    tabLabel->setMaximumWidth(FIXED_LABEL_SIZE);
    mTabEdit = new QLineEdit;
    mTabName = tabName;
    mIconName = iconName;
    mTabEdit->setText(mTabName);

    // Define selection widget (QListView)
    mSelectionList = new QListView(this);
    mSelectionList->setViewMode(QListView::IconMode);
    mSelectionList->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    mSelectionList->setSpacing(8);
    mSelectionList->setMovement(QListView::Snap);
    mSelectionList->setFlow(QListView::LeftToRight);
    mSelectionList->setWrapping(true);
    mSelectionList->setDragEnabled(false);
    mSelectionList->setAcceptDrops(false);
    mSelectionList->setDropIndicatorShown(false);
    mSelectionList->setMinimumSize(ICON_DIALOG_SELECTION_WIDTH, ICON_DIALOG_SELECTION_HEIGHT);
    mSelectionModel = new IconSelectionModel(IconSelectionModel::SELECTION);
    mSelectionList->setModel(mSelectionModel);
    connect(mSelectionList, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(doubleClickedSlot(void)));

    // Define combobox to select the category and fill it with the categories from iconReader
    mCategoryComboBox = new IconComboBox(iconReader, mSelectionModel, iconDir, this);
    connect(mCategoryComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSelectionChanged(int)));

    // Layout
    tabLayout->addWidget(tabLabel);
    tabLayout->addWidget(mTabEdit);
    iconSelectionLayout->addLayout(tabLayout);
    iconSelectionLayout->addWidget(mCategoryComboBox);
    iconSelectionLayout->addWidget(mSelectionList);
    iconSelectionLayout->addWidget(mButtonBox);
    setLayout(iconSelectionLayout);
    mTabEdit->setFocus();
}

//****************************************************************************/
const QString IconDialog::getIconName(void) const
{
    return mIconName;
}

//****************************************************************************/
const QString IconDialog::getTabName(void) const
{
    return mTabName;
}

//****************************************************************************/
void IconDialog::handleSelectionChanged(int index)
{
    mCategoryComboBox->handleSelectionChanged(index);
}

//****************************************************************************/
void IconDialog::doubleClickedSlot(void)
{
    accept();
}

//****************************************************************************/
void IconDialog::accept (void)
{
    QModelIndex selectedIcon = mSelectionList->currentIndex();
    QString name = mSelectionModel->getName(selectedIcon);
    if (!name.isEmpty())
    {
        mIconName = mSelectionModel->getName(selectedIcon);
    }
    mTabName = mTabEdit->text();
    QDialog::accept();
}
