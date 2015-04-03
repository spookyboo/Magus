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

#include <QtWidgets>

#include "constants.h"
#include "mainwindow.h"
#include "generaltab.h"
#include "utils.h"

//****************************************************************************/
GeneralTab::GeneralTab(MainWindow* parent): QWidget(parent), mParent(parent)
{
    if (!parent)
        return;

    QGroupBox* generalGroup = new QGroupBox(tr("General settings"));
    QGroupBox* actionGroup = new QGroupBox(tr("Actions"));

    // Project
    QLabel* projectLabel = new QLabel(tr("Project:"));
    mProjectValue = new QLineEdit;
    mProjectValue->setText(Utils::stripSpecialCharacters(parent->getApplicationTemplate()->mProject));

    // Layout
    QLabel* layoutLabel = new QLabel(tr("Layout:"));
    mLayoutImage = new QLabel("");
    mIconName = parent->getApplicationTemplate()->mIconName;
    QImage image(parent->getLayoutDir() + mIconName);
    QPixmap pixMap = QPixmap::fromImage(image).scaled(TEMPLATE_DIALOG_ICON_WIDTH, TEMPLATE_DIALOG_ICON_HEIGHT);
    mLayoutImage->setPixmap(pixMap);

    // Description
    QLabel* descriptionLabel = new QLabel(tr("Description:"));
    mDescriptionValue = new QLineEdit;
    mDescriptionValue->setText(parent->getApplicationTemplate()->mDescription);

    // Type
    QLabel* typeLabel = new QLabel(tr("Type:"));
    mTypeValue = new QLabel(parent->getApplicationTemplate()->mType);

    // Style
    QLabel* styleLabel = new QLabel(tr("Style:"));
    mStyleValue = new QLabel(parent->getApplicationTemplate()->mStyle);

    // Add window button
    QHBoxLayout* addWindowLayout = new QHBoxLayout;
    QLabel* newWindowLabel = new QLabel(tr("New docking window:"));
    newWindowLabel->setMinimumWidth(FIXED_LABEL_SIZE);
    newWindowLabel->setMaximumWidth(FIXED_LABEL_SIZE);
    QPushButton* addWindowButton = new QPushButton(this);
    addWindowButton->setIcon(QIcon(parent->getIconDir() + ICON_ADD));
    addWindowButton->setMinimumWidth(80);
    addWindowButton->setMaximumWidth(80);
    addWindowLayout->addWidget(newWindowLabel);
    addWindowLayout->addWidget(addWindowButton);
    addWindowLayout->addStretch(12);
    connect(addWindowButton, SIGNAL(clicked()), this, SLOT(addWindow()));

    // Use Asset widgets
    mUseAssetWidgetCheckBox = new QCheckBox(QString("Use generic asset library"));
    mUseAssetWidgetCheckBox->setChecked(parent->getApplicationTemplate()->mUseAssetWidget);
    mUseOgreAssetWidgetCheckBox = new QCheckBox();
    if (parent->getApplicationTemplate()->isOgreUsed())
    {
        mUseOgreAssetWidgetCheckBox->setText(TEXT_USE_OGRE_ASSETS);
        mUseOgreAssetWidgetCheckBox->setChecked(parent->getApplicationTemplate()->mUseOgreAssetWidgets);
    }
    else
    {
        // Disable the checkbox; it is enabled when the ogre control checkbox on the other windows is checked
        mUseOgreAssetWidgetCheckBox->setText(TEXT_USE_OGRE_ASSETS_DISABLED);
        mUseOgreAssetWidgetCheckBox->setEnabled(false);
    }

    // Use Node editor
    mUseNodeEditorCheckBox = new QCheckBox(QString("Use node editor library"));
    mUseNodeEditorCheckBox->setChecked(parent->getApplicationTemplate()->mUseNodeEditor);

    // General Layout
    QGridLayout* generalLayout = new QGridLayout;
    generalLayout->setColumnStretch(1, 10); // Stretch the second column, so it is closer to the label
    generalLayout->addWidget(projectLabel, 0, 0);
    generalLayout->addWidget(mProjectValue, 0, 1);
    generalLayout->addWidget(layoutLabel, 1, 0);
    generalLayout->addWidget(mLayoutImage, 2, 1);
    generalLayout->addWidget(descriptionLabel, 3, 0);
    generalLayout->addWidget(mDescriptionValue, 3, 1);
    generalLayout->addWidget(typeLabel, 4, 0);
    generalLayout->addWidget(mTypeValue, 4, 1);
    generalLayout->addWidget(styleLabel, 5, 0);
    generalLayout->addWidget(mStyleValue, 5, 1);
    generalGroup->setLayout(generalLayout);

    // Action Layout
    QVBoxLayout* actionLayout = new QVBoxLayout;
    actionLayout->addLayout(addWindowLayout);
    actionLayout->addWidget(mUseAssetWidgetCheckBox);
    actionLayout->addWidget(mUseOgreAssetWidgetCheckBox);
    actionLayout->addWidget(mUseNodeEditorCheckBox);
    actionGroup->setLayout(actionLayout);

    // Main layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(generalGroup);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(actionGroup);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

//****************************************************************************/
void GeneralTab::setLayoutImage(const QString& name)
{
    mIconName = name;
    mParent->getApplicationTemplate()->mIconName = name;
    QImage image(mParent->getLayoutDir() + name);
    QPixmap pixMap = QPixmap::fromImage(image).scaled(TEMPLATE_DIALOG_ICON_WIDTH, TEMPLATE_DIALOG_ICON_HEIGHT);
    mLayoutImage->setPixmap(pixMap);
}

//****************************************************************************/
void GeneralTab::addWindow(void)
{
    if (mParent)
    {
        mParent->newTab();
        setLayoutImage(NO_IMAGE);
        QMessageBox::information(this, "Magus", "New dock window added");
    }
}
