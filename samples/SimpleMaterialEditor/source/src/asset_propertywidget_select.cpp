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
#include <QVBoxLayout>
#include <QLabel>
#include <QStringListModel>
#include "asset_propertywidget_select.h"

namespace Magus
{
    //****************************************************************************/
    QtSelectProperty::QtSelectProperty(const QString& title, QWidget* parent) : QtProperty(parent)
    {
        selectedText = QString("");
        QVBoxLayout* mainLayout = new QVBoxLayout;
        QHBoxLayout* horizontalLayout = new QHBoxLayout;
        mainLayout->setContentsMargins(5, 0, 5, 0);
        QLabel* label = new QLabel(title);
        mList = new QComboBox;
        connect(mList, SIGNAL(currentIndexChanged(QString)), this, SLOT(propertyValueChanged(void)));

        // Layout
        horizontalLayout->addWidget(label, 1);
        horizontalLayout->addWidget(mList, 2);
        mainLayout->addLayout(horizontalLayout);
        setLayout(mainLayout);
        mType = SELECT;
    }

    //****************************************************************************/
    void QtSelectProperty::addValues(const QStringList& stringList, int maxVisibleItems)
    {
        QStringListModel* model = new QStringListModel(stringList);
        mList->setModel(model);
        mList->setMaxVisibleItems(maxVisibleItems);
    }

    //****************************************************************************/
    int QtSelectProperty::getCurrentIndex(void)
    {
        return mList->currentIndex();
    }

    //****************************************************************************/
    const QString& QtSelectProperty::getCurrentText(void)
    {
        selectedText = mList->currentText();
        return selectedText;
    }

    //****************************************************************************/
    void QtSelectProperty::setCurentIndex(int index)
    {
        mList->setCurrentIndex(index);
    }

    //****************************************************************************/
    void QtSelectProperty::setCurrentText(const QString& value)
    {
        mList->setCurrentText(value);
    }

    //****************************************************************************/
    void QtSelectProperty::propertyValueChanged(void)
    {
        emit valueChanged(this);
    }
}
