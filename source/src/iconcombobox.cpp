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

#include <QStringListModel>
#include <QMessageBox>
#include "constants.h"
#include "iconreader.h"
#include "iconcombobox.h"

//****************************************************************************/
IconComboBox::IconComboBox (IconReader* iconReader,
                            IconSelectionModel* iconSelectionModel,
                            const QString &iconDir,
                            QWidget* parent) :
    QComboBox(parent),
    mIconReader(iconReader),
    mIconSelectionModel(iconSelectionModel)
{
    mIconReader = iconReader;
    mIconSelectionModel = iconSelectionModel;
    mIconDir = iconDir;
    QStringListModel* model = new QStringListModel(iconReader->getCategories(), this);
    setModel(model);
    setMaxVisibleItems(20);
    handleSelectionChanged(0);
}

//****************************************************************************/
void IconComboBox::handleSelectionChanged(int index)
{
    if (!mIconSelectionModel)
        return;

    // Fill the icon selection model
    QString category = itemText(index);
    QStringList icons = mIconReader->readIconNames(category);
    QStringList::const_iterator constIterator;
    mIconSelectionModel->clear();
    for (constIterator = icons.constBegin(); constIterator != icons.constEnd(); ++constIterator)
    {
        QString iconName = *constIterator;
        mIconSelectionModel->addIcon(QPixmap(mIconDir + iconName).scaled(
                                         TEMPLATE_DIALOG_ICON_WIDTH,
                                         TEMPLATE_DIALOG_ICON_HEIGHT,
                                         Qt::KeepAspectRatio,
                                         Qt::SmoothTransformation),
                                     iconName);
    }
}
