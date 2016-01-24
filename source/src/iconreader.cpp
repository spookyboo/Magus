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

#include <QString>
#include <QMessageBox>
#include "constants.h"
#include "iconreader.h"


//****************************************************************************/
IconReader::IconReader()
{
    mSettings = new QSettings(ICONS_CONFIG_FILE,  QSettings::IniFormat);
    readCategories();
}

//****************************************************************************/
IconReader::~IconReader()
{
    delete mSettings;
}

//****************************************************************************/
void IconReader::clear(void)
{
    mCategoriesList.clear();
}

//****************************************************************************/
void IconReader::readCategories(void)
{
    // Get the toolbar icons
    mSettings->beginGroup(CATEGORIES_GROUP);
    bool end = false;
    QString key;
    QString group;
    int i = 0;
    while (!end)
    {
        // Read list of categories
        QVariant var(i);
        key = TEMPLATE_KEY_CATEGORY + QString("[") + var.toString() + QString("]");
        group = mSettings->value(key).toString();
        if (group.isEmpty())
        {
            end = true;
        }
        else
        {
            mCategoriesList << group;
            i++;
        }
    }
    mSettings->endGroup();
}

//****************************************************************************/
const QStringList IconReader::readIconNames(QString category) const
{
    // Get the icon names
    QStringList iconNames;
    mSettings->beginGroup(category);
    bool end = false;
    QString key;
    QString iconName;
    int i = 0;
    while (!end)
    {
        // Read list of categories
        QVariant var(i);
        key = TEMPLATE_KEY_ICON + QString("[") + var.toString() + QString("]");
        iconName = mSettings->value(key).toString();
        if (iconName.isEmpty())
        {
            end = true;
        }
        else
        {
            iconNames << iconName;
            i++;
        }
    }
    mSettings->endGroup();
    return iconNames;
}


//****************************************************************************/
const QStringList IconReader::getCategories (void) const
{
    return mCategoriesList;
}
