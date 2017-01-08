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

#include <QtWidgets>
#include <QMessageBox>
#include "constants.h"
#include "pages.h"

//****************************************************************************/
GeneralPage::GeneralPage(QWidget *parent)
    : QWidget(parent)
{
    // Create widgets
    QGroupBox* packagesGroup = new QGroupBox(tr("General settings"));
    QLabel* iconDirLabel = new QLabel(tr("Icon directory:"));
    mIconDirEdit = new QLineEdit;
    //QLabel* templateDirLabel = new QLabel(tr("Template directory:"));
    mTemplateDirEdit = new QLineEdit;
    //QLabel* layoutDirLabel = new QLabel(tr("Layout directory:"));
    mLayoutDirEdit = new QLineEdit;
    mRestoreButton = new QPushButton(tr("Restore to original values"));

    // Set initial values
    restoreValues(GLOBAL_CONFIG_FILE);

    // Connect
    connect(mIconDirEdit, SIGNAL(textEdited(QString)), this, SLOT(textEdited()));
    connect(mTemplateDirEdit, SIGNAL(textEdited(QString)), this, SLOT(textEdited()));
    connect(mLayoutDirEdit, SIGNAL(textEdited(QString)), this, SLOT(textEdited()));
    connect(mRestoreButton, SIGNAL(clicked()), this, SLOT(restorePushed()));

    // Layout
    // Remark: template- and layout dir disabled; is this really needed?
    QGridLayout *packagesLayout = new QGridLayout;
    packagesLayout->addWidget(iconDirLabel, 0, 0);
    packagesLayout->addWidget(mIconDirEdit, 0, 1);
    //packagesLayout->addWidget(templateDirLabel, 1, 0);
    //packagesLayout->addWidget(mTemplateDirEdit, 1, 1);
    //packagesLayout->addWidget(layoutDirLabel, 2, 0);
    //packagesLayout->addWidget(mLayoutDirEdit, 2, 1);
    packagesGroup->setLayout(packagesLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(packagesGroup);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(mRestoreButton);
    mainLayout->addStretch(1000);
    setLayout(mainLayout);
}

//****************************************************************************/
const QString& GeneralPage::getIconDir(void) const
{
    return mIconDir;
}

//****************************************************************************/
const QString& GeneralPage::getTemplateDir(void) const
{
    return mTemplateDir;
}

//****************************************************************************/
const QString& GeneralPage::getLayoutDir(void) const
{
    return mLayoutDir;
}


//****************************************************************************/
void GeneralPage::restoreValues(const QString& configFileName)
{
    QSettings globalSettings (configFileName,  QSettings::IniFormat);
    mIconDir = globalSettings.value(CONFIG_KEY_ICON_DIR).toString();
    mIconDirEdit->setText(mIconDir);
    mTemplateDir = globalSettings.value(CONFIG_KEY_TEMPLATE_DIR).toString();
    mTemplateDirEdit->setText(mTemplateDir);
    mLayoutDir = globalSettings.value(CONFIG_KEY_LAYOUT_DIR).toString();
    mLayoutDirEdit->setText(mLayoutDir);
}

//****************************************************************************/
void GeneralPage::textEdited(void)
{
    mIconDir = mIconDirEdit->text();
    mTemplateDir = mTemplateDirEdit->text();
    mLayoutDir = mLayoutDirEdit->text();
}

//****************************************************************************/
void GeneralPage::restorePushed(void)
{
    restoreValues(GLOBAL_ORIGINAL_CONFIG_FILE);
    //QMessageBox::information(0, "test", "test"); // Test
}

//****************************************************************************/
//****************************************************************************/
//****************************************************************************/
BuildPage::BuildPage(QWidget *parent)
    : QWidget(parent)
{
    // Create widgets
    QGroupBox* packagesGroup = new QGroupBox(tr("Build settings"));
    QLabel* outputDirLabel = new QLabel(tr("Output directory:"));
    mOutputDirEdit = new QLineEdit;
    mRestoreButton = new QPushButton(tr("Restore to original values"));

    // Set initial values
    restoreValues(GLOBAL_CONFIG_FILE);

    // Connect
    connect(mOutputDirEdit, SIGNAL(textEdited(QString)), this, SLOT(textEdited()));
    connect(mRestoreButton, SIGNAL(clicked()), this, SLOT(restorePushed()));

    // Layout
    QGridLayout *packagesLayout = new QGridLayout;
    packagesLayout->addWidget(outputDirLabel, 0, 0);
    packagesLayout->addWidget(mOutputDirEdit, 0, 1);
    packagesGroup->setLayout(packagesLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(packagesGroup);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(mRestoreButton);
    mainLayout->addStretch(1000);
    setLayout(mainLayout);
}

//****************************************************************************/
const QString& BuildPage::getOutputDir(void) const
{
    return mOutputDir;
}

//****************************************************************************/
void BuildPage::restoreValues(const QString& configFileName)
{
    QSettings globalSettings (configFileName,  QSettings::IniFormat);
    mOutputDir = globalSettings.value(CONFIG_KEY_OUTPUT_DIR).toString();
    mOutputDirEdit->setText(mOutputDir);
}

//****************************************************************************/
void BuildPage::textEdited(void)
{
    mOutputDir = mOutputDirEdit->text();
}

//****************************************************************************/
void BuildPage::restorePushed(void)
{
    restoreValues(GLOBAL_ORIGINAL_CONFIG_FILE);
}

//****************************************************************************/
//****************************************************************************/
//****************************************************************************/
OgrePage::OgrePage(QWidget *parent)
    : QWidget(parent)
{
    // Create widgets
    QGroupBox* packagesGroup = new QGroupBox(tr("Ogre settings"));

    // Ogre Version (1.9, 2.0 and 2.1)
    QGroupBox* radioGroupBoxVersion = new QGroupBox(QString("Ogre version"));
    mOgreVersion19Radio = new QRadioButton(QString("Version 1.9"));
    mOgreVersion20Radio = new QRadioButton(QString("Version 2.0"));
    mOgreVersion21Radio = new QRadioButton(QString("Version 2.1"));
    mOgreVersion = "2.1";

    // Ogre root environment variable / root directory
    QGroupBox* radioGroupBoxRoot = new QGroupBox(QString("Use enviroment variable or enter Ogre root"));
    mOgreRootEnvRadio = new QRadioButton(QString("Ogre root env. variable"));
    mOgreRootRadio = new QRadioButton(QString("Ogre rootdirectory"));
    mOgreRootEnvEdit = new QLineEdit;
    mOgreRootEdit = new QLineEdit;
    mOgreRootEdit->setStyleSheet(QString("color : darkgray;"));
    mOgreRootEdit->setEnabled(false);

    // Ogre build directory
    QGroupBox* groupBoxBuild = new QGroupBox(QString("Ogre build directory (subdirectory of ogre root)"));
    QLabel* buildDirLabel = new QLabel(tr("Ogre buid directory (eg. \"VCBuild\"):"));
    mOgreBuildDirEdit = new QLineEdit;
    mOgreBuildDirEdit->setStyleSheet(QString("color : black;"));
    QGridLayout *ogreBuildLayout = new QGridLayout;
    ogreBuildLayout->addWidget(buildDirLabel, 0, 0);
    ogreBuildLayout->addWidget(mOgreBuildDirEdit, 0, 1);

    // Misc
    mRestoreButton = new QPushButton(tr("Restore to original values"));

    // Set initial values
    restoreValues(GLOBAL_CONFIG_FILE);

    // Connect Version
    connect(mOgreVersion19Radio, SIGNAL(toggled(bool)), this, SLOT(toggledOgreVersion19(bool)));
    connect(mOgreVersion20Radio, SIGNAL(toggled(bool)), this, SLOT(toggledOgreVersion20(bool)));
    connect(mOgreVersion21Radio, SIGNAL(toggled(bool)), this, SLOT(toggledOgreVersion21(bool)));

    // Connect Root
    connect(mOgreRootEnvRadio, SIGNAL(toggled(bool)), this, SLOT(toggledOgreRoot(bool)));
    connect(mOgreRootEnvEdit, SIGNAL(textEdited(QString)), this, SLOT(textEdited()));
    connect(mOgreRootEdit, SIGNAL(textEdited(QString)), this, SLOT(textEdited()));
    connect(mOgreBuildDirEdit, SIGNAL(textEdited(QString)), this, SLOT(textEdited()));
    connect(mRestoreButton, SIGNAL(clicked()), this, SLOT(restorePushed()));

    // Layout Version
    QVBoxLayout* radioLayoutVersion = new QVBoxLayout;
    radioLayoutVersion->addWidget(mOgreVersion19Radio, 1);
    radioLayoutVersion->addWidget(mOgreVersion20Radio, 1);
    radioLayoutVersion->addWidget(mOgreVersion21Radio, 1);

    // Layout Root
    QVBoxLayout* radioLayoutRoot = new QVBoxLayout;
    QHBoxLayout* rootEnvLayout = new QHBoxLayout;
    QHBoxLayout* rootLayout = new QHBoxLayout;
    rootEnvLayout->addWidget(mOgreRootEnvRadio, 1);
    rootEnvLayout->addWidget(mOgreRootEnvEdit, 3);
    rootLayout->addWidget(mOgreRootRadio, 1);
    rootLayout->addWidget(mOgreRootEdit, 3);

    // Layout Main
    radioLayoutRoot->addLayout(rootEnvLayout);
    radioLayoutRoot->addLayout(rootLayout);
    radioGroupBoxRoot->setLayout(radioLayoutRoot);
    radioGroupBoxVersion->setLayout(radioLayoutVersion);
    groupBoxBuild->setLayout(ogreBuildLayout);
    QGridLayout *packagesLayout = new QGridLayout;
    packagesLayout->addWidget(radioGroupBoxVersion);
    packagesLayout->addWidget(radioGroupBoxRoot);
    packagesLayout->addWidget(groupBoxBuild);
    packagesGroup->setLayout(packagesLayout);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(packagesGroup);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(mRestoreButton);
    mainLayout->addStretch(1000);
    setLayout(mainLayout);
}

//****************************************************************************/
const QString& OgrePage::getOgreRootEnv(void)
{
    return mOgreRootEnv;
}

//****************************************************************************/
bool OgrePage::isOgreRootUseEnv(void)
{
    return mOgreRootUseEnv;
}

//****************************************************************************/
const QString& OgrePage::getOgreRoot(void)
{
    return mOgreRoot;
}

//****************************************************************************/
const QString& OgrePage::getOgreBuildDir(void)
{
    return mOgreBuildDir;
}

//****************************************************************************/
const QString& OgrePage::getOgreVersion(void)
{
    return mOgreVersion;
}

//****************************************************************************/
void OgrePage::restoreValues(const QString& configFileName)
{
    QSettings globalSettings (configFileName,  QSettings::IniFormat);
    mOgreRootEnv = globalSettings.value(CONFIG_KEY_OGRE_ROOT_ENV).toString();
    mOgreRootUseEnv = globalSettings.value(CONFIG_KEY_OGRE_ROOT_USE_ENV).toBool();
    mOgreBuildDir = globalSettings.value(CONFIG_KEY_OGRE_BUILD_DIR).toString();
    mOgreRootEnvEdit->setText(mOgreRootEnv);
    mOgreRoot = globalSettings.value(CONFIG_KEY_OGRE_ROOT).toString();
    mOgreRootEdit->setText(mOgreRoot);
    mOgreBuildDirEdit->setText(mOgreBuildDir);
    mOgreVersion = globalSettings.value(CONFIG_KEY_OGRE_VERSION).toString();
    if (mOgreVersion == "2.1")
         mOgreVersion21Radio->setChecked(true);
    else if (mOgreVersion == "2.0")
        mOgreVersion20Radio->setChecked(true);
    else
        mOgreVersion19Radio->setChecked(true);

    toggledOgreRoot(mOgreRootUseEnv);
}

//****************************************************************************/
void OgrePage::textEdited(void)
{
    mOgreRootEnv = mOgreRootEnvEdit->text();
    mOgreRoot = mOgreRootEdit->text();
    mOgreBuildDir = mOgreBuildDirEdit->text();
}

//****************************************************************************/
void OgrePage::restorePushed(void)
{
    restoreValues(GLOBAL_ORIGINAL_CONFIG_FILE);
}

//****************************************************************************/
void OgrePage::toggledOgreVersion19(bool on)
{
    mOgreVersion = "1.9";
}

//****************************************************************************/
void OgrePage::toggledOgreVersion20(bool on)
{
    mOgreVersion = "2.0";
}

//****************************************************************************/
void OgrePage::toggledOgreVersion21(bool on)
{
    mOgreVersion = "2.1";
}

//****************************************************************************/
void OgrePage::toggledOgreRoot(bool on)
{
    if (on)
    {
        mOgreRootEnvEdit->setStyleSheet(QString("color : black;"));
        mOgreRootEnvEdit->setEnabled(true);
        mOgreRootEnvEdit->setText(mOgreRootEnv);
        mOgreRootEdit->setStyleSheet(QString("color : darkgray;"));
        mOgreRootEdit->setEnabled(false);
        mOgreRootEnvRadio->setChecked(true);
        mOgreRootUseEnv = true;
    }
    else
    {
        mOgreRootEnvEdit->setStyleSheet(QString("color : darkgray;"));
        mOgreRootEnvEdit->setEnabled(false);
        mOgreRootEdit->setStyleSheet(QString("color : black;"));
        mOgreRootEdit->setEnabled(true);
        mOgreRootRadio->setChecked(true);
        mOgreRootUseEnv = false;
    }
}
