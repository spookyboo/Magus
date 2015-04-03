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
#include <QMessageBox>
#include "constants.h"
#include "asset_containerwidget.h"
#include "sme_asset_material.h"
#include "asset_propertywidget_string.h"
#include "asset_propertywidget_select.h"
#include "sme_node_material.h"

namespace Magus
{
    //****************************************************************************/
    QtAssetMaterial::QtAssetMaterial(const QString& fileNameIcon, QWidget* parent) : QWidget(parent)
    {
        mMaterialNode = 0;
        QVBoxLayout* mainLayout = new QVBoxLayout;
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mAssetWidget = new QtAssetWidget(QString("Material"), fileNameIcon, this);
        mAssetWidget->setFileNameIconCollapsed(ASSET_ICON_COLLAPSE);
        mAssetWidget->setFileNameIconExpanded(ASSET_ICON_EXPAND);
        mAssetWidget->setHeaderTitleBold();
        connect(mAssetWidget, SIGNAL(valueChanged(QtProperty*)), this, SLOT(propertyValueChanged(QtProperty*)));

        // Create container - General
        QtContainerWidget* container = 0;
        container = mAssetWidget->createContainer(ASSET_CONTAINER_MATERIAL_GENERAL, QString("General"));
        container->setTitleIcon(ASSET_ICON_CUBE_BOLD);
        container->setTitleBold();
        mAssetWidget->createProperty(ASSET_CONTAINER_MATERIAL_GENERAL,
                                    ASSET_PROPERTY_MATERIAL_NAME,
                                    QString("Material name"),
                                    QtProperty::STRING);

        // Sceneblend
        QStringList stringListSceneBlend;
        stringListSceneBlend << QString("Transparent alpha") <<
                      QString("Transparent color") <<
                      QString("Add") <<
                      QString("Modulate")  <<
                      QString("Replace");
        QtSelectProperty* selectProperty = static_cast<QtSelectProperty*>
                                                    (mAssetWidget->createProperty(ASSET_CONTAINER_MATERIAL_GENERAL,
                                                    ASSET_PROPERTY_MATERIAL_SCENE_BLENDING,
                                                    QString("Scene Blending"),
                                                    QtProperty::SELECT));
        selectProperty->addValues(stringListSceneBlend);

        mainLayout->addWidget(mAssetWidget);
        setLayout(mainLayout);
        mAssetWidget->expandAllContainers();
    }

    //****************************************************************************/
    QtAssetMaterial::~QtAssetMaterial(void)
    {
    }

    //****************************************************************************/
    void QtAssetMaterial::setObject (QtNodeMaterial* materialNode)
    {
        if (!materialNode)
            return;

        mMaterialNode = materialNode;

        QtStringProperty* stringProperty;
        QtSelectProperty* selectProperty;

        // Material name
        stringProperty = static_cast<QtStringProperty*>(mAssetWidget->getPropertyWidget(ASSET_PROPERTY_MATERIAL_NAME));
        stringProperty->setString(materialNode->getMaterialName());

        // Scene blending
        selectProperty = static_cast<QtSelectProperty*>(mAssetWidget->getPropertyWidget(ASSET_PROPERTY_MATERIAL_SCENE_BLENDING));
        selectProperty->setCurrentText(materialNode->getSceneBlending());
    }

    //****************************************************************************/
    void QtAssetMaterial::propertyValueChanged(QtProperty* property)
    {
        if (!mMaterialNode || !property)
            return;

        QtStringProperty* stringProperty;
        QtSelectProperty* selectProperty;
        switch (property->mPropertyId)
        {
            case ASSET_PROPERTY_MATERIAL_NAME:
            {
                stringProperty = static_cast<QtStringProperty*>(property);
                QString text = stringProperty->getString();
                mMaterialNode->setMaterialName(text);
            }
            break;

            case ASSET_PROPERTY_MATERIAL_SCENE_BLENDING:
            {
                selectProperty = static_cast<QtSelectProperty*>(property);
                QString text = selectProperty->getCurrentText();
                mMaterialNode->setSceneBlending(text);
            }
            break;
        }
    }

}
