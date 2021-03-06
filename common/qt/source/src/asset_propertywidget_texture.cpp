/****************************************************************************
**
** Copyright (C) 2016
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
#include "asset_assetconstants.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QFileInfo>
#include <QImageReader>
#include <QFileDialog>
#include "asset_propertywidget_texture.h"
#include "magus_core.h"

namespace Magus
{
    //****************************************************************************/
    QtTextureProperty::QtTextureProperty(const QString& title, QWidget* parent) : QtProperty(parent)
    {
        mFileNameTexture = QString("");
        mBaseFileNameTexture = QString("");
        mPathTexture = QString("");
        mSearchPath = QString("");
        QVBoxLayout* mainLayout = new QVBoxLayout;
        QHBoxLayout* horizontalLayout = new QHBoxLayout;
        QHBoxLayout* textureAndButtonLayout = new QHBoxLayout;
        QHBoxLayout* textureNameLayout = new QHBoxLayout;
        mainLayout->setContentsMargins(5, 0, 5, 0);
        QLabel* label = new QLabel(title);
        mTextureLabel = new QLabel();
        mTextureNameLabel = new QLineEdit();
        mTextureLabel->setStyleSheet(QString("border: 1px solid #000000;"));
        mTextureSize.setWidth(128);
        mTextureSize.setHeight(64);
        mTextureLabel->setMaximumWidth(mTextureSize.width());
        mDialogButton = new QPushButton(QString(" .. "));
        connect(mDialogButton, SIGNAL(clicked(bool)), this, SLOT(dialogButtonClicked(void)));
        connect(mTextureNameLabel, SIGNAL(textChanged(QString)), this, SLOT(propertyValueChanged(void)));
        mTextureNameLabel->setEnabled(false);

        // Layout
        textureAndButtonLayout->addWidget(mTextureLabel, 1);
        textureAndButtonLayout->addWidget(mDialogButton, 1);
        textureAndButtonLayout->addStretch(9);
        textureNameLayout->addStretch(1);
        textureNameLayout->addWidget(mTextureNameLabel, 2);
        horizontalLayout->addWidget(label, 1);
        horizontalLayout->addLayout(textureAndButtonLayout, 2);
        mainLayout->addLayout(horizontalLayout);
        mainLayout->addLayout(textureNameLayout);
        setLayout(mainLayout);
        mType = TEXTURE;
    }

    //****************************************************************************/
    void QtTextureProperty::setTextureFileName(const QString& fileNameTexture)
    {
        if (fileNameTexture.isEmpty())
        {
            // Clear the current image
            mFileNameTexture = QString("");
            mBaseFileNameTexture = QString("");
            mPathTexture = QString("");
            mTextureNameLabel->setText(mBaseFileNameTexture);
            mTextureLabel->clear();
            return;
        }

        // Check whether the file is an image (based on the extension)
        if (!isTypeBasedOnExtension(fileNameTexture, MAGUS_SUPPORTED_IMAGE_FORMATS, MAGUS_SUPPORTED_IMAGE_FORMATS_LENGTH))
            return;

        QFile f(fileNameTexture);
        QFileInfo fileInfo(f.fileName());
        mFileNameTexture = fileNameTexture;
        mBaseFileNameTexture = fileInfo.fileName();
        mPathTexture = fileInfo.absolutePath();
        mTextureNameLabel->setText(mBaseFileNameTexture);
        mTexturePixmap = QPixmap(fileNameTexture).scaled(mTextureSize.width(),
                                                         mTextureSize.height(),
                                                         Qt::KeepAspectRatio,
                                                         Qt::SmoothTransformation);
        mTextureLabel->setPixmap(mTexturePixmap);
        mTextureLabel->setMaximumWidth(mTextureSize.width());
        mTextureLabel->setMaximumHeight(mTextureSize.height());
    }

    //****************************************************************************/
    const QString& QtTextureProperty::getTextureFileName(void)
    {
        return mFileNameTexture;
    }

    //****************************************************************************/
    const QString& QtTextureProperty::getTextureBaseFileName(void)
    {
        return mBaseFileNameTexture;
    }

    //****************************************************************************/
    const QString& QtTextureProperty::getPathTexture(void)
    {
        return mPathTexture;
    }

    //****************************************************************************/
    void QtTextureProperty::setSearchPath(const QString& searchPath)
    {
        mSearchPath = searchPath;
    }

    //****************************************************************************/
    void QtTextureProperty::setTextureSize(const QSize& size)
    {
        mTextureSize.setHeight(size.height());
        mTextureSize.setWidth(size.width());
        setTextureFileName(mFileNameTexture);
    }

    //****************************************************************************/
    void QtTextureProperty::dialogButtonClicked(void)
    {
        QString fileName = QFileDialog::getOpenFileName(this, QString("Select an image file"), mSearchPath);

        if (!fileName.isEmpty())
            setTextureFileName(fileName);
    }

    //****************************************************************************/
    void QtTextureProperty::propertyValueChanged(void)
    {
        emit valueChanged(this);
    }
}
