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
#include "sme_node_pass.h"
#include "sme_node_porttype.h"
#include "constants.h"

namespace Magus
{
    //****************************************************************************/
    QtNodePass::QtNodePass(QString title, QGraphicsItem* parent) : QtNode(title, parent)
    {
        mDepthCheck = true;
        mDepthWrite = true;
        mLighting = true;
        mAmbient = QColor(Qt::white);
        mDiffuse = QColor(Qt::white);
        mSpecular = QColor(Qt::black);

        // Define the connection policy
        QtTechniqueInPortType techniqueInPortType;
        QtPassInPortType passInPortType;
        QtPassOutPortType passOutPortType;
        QtTextureUnitOutPortType textureUnitOutPortType;
        techniqueInPortType.addPortTypeToConnectionPolicy(passOutPortType);
        textureUnitOutPortType.addPortTypeToConnectionPolicy(passInPortType);

        // Custome node settings
        setTitleColor(Qt::white);
        setHeaderTitleIcon(ICON_PASS_BOLD);
        setAction1Icon(ICON_MINMAX);
        setAction2Icon(ICON_CLOSE);
        alignTitle(ALIGNED_LEFT);
        setHeaderColor(QColor("#5D964E"));
        createPort(PORT_ID_PASS,
                    PORT_TECHNIQUE_IN,
                    techniqueInPortType,
                    QColor("#874E96"),
                    PORT_SHAPE_CIRCLE,
                    ALIGNED_LEFT,
                    QColor("#874E96"));
        createPort(PORT_ID_PASS + 1,
                    PORT_TEXTURE_OUT,
                    textureUnitOutPortType,
                    QColor("#C74E4C"),
                    PORT_SHAPE_CIRCLE,
                    ALIGNED_RIGHT,
                    QColor("#C74E4C"));
        createPort(PORT_ID_PASS + 2,
                    PORT_TEXTURE_OUT,
                    textureUnitOutPortType,
                    QColor("#C74E4C"),
                    PORT_SHAPE_CIRCLE,
                    ALIGNED_RIGHT,
                    QColor("#C74E4C"));
        createPort(PORT_ID_PASS + 3,
                    PORT_TEXTURE_OUT,
                    textureUnitOutPortType,
                    QColor("#C74E4C"),
                    PORT_SHAPE_CIRCLE,
                    ALIGNED_RIGHT,
                    QColor("#C74E4C"));
        createPort(PORT_ID_PASS + 4,
                    PORT_TEXTURE_OUT,
                    textureUnitOutPortType,
                    QColor("#C74E4C"),
                    PORT_SHAPE_CIRCLE,
                    ALIGNED_RIGHT,
                    QColor("#C74E4C"));
        createPort(PORT_ID_PASS + 5,
                    PORT_TEXTURE_OUT,
                    textureUnitOutPortType,
                    QColor("#C74E4C"),
                    PORT_SHAPE_CIRCLE,
                    ALIGNED_RIGHT,
                    QColor("#C74E4C"));
        createPort(PORT_ID_PASS + 6,
                    PORT_TEXTURE_OUT,
                    textureUnitOutPortType,
                    QColor("#C74E4C"),
                    PORT_SHAPE_CIRCLE,
                    ALIGNED_RIGHT,
                    QColor("#C74E4C"));
        createPort(PORT_ID_PASS + 7,
                    PORT_TEXTURE_OUT,
                    textureUnitOutPortType,
                    QColor("#C74E4C"),
                    PORT_SHAPE_CIRCLE,
                    ALIGNED_RIGHT,
                    QColor("#C74E4C"));
        createPort(PORT_ID_PASS + 8,
                    PORT_TEXTURE_OUT,
                    textureUnitOutPortType,
                    QColor("#C74E4C"),
                    PORT_SHAPE_CIRCLE,
                    ALIGNED_RIGHT,
                    QColor("#C74E4C"));
        setPortNameColor(Qt::white);
        setZoom(0.9);
    }

    //****************************************************************************/
    QtNodePass::~QtNodePass(void)
    {
    }

    //****************************************************************************/
    bool QtNodePass::isDepthCheck(void) const
    {
        return mDepthCheck;
    }

    //****************************************************************************/
    bool QtNodePass::isDepthWrite(void) const
    {
        return mDepthWrite;
    }

    //****************************************************************************/
    bool QtNodePass::isLighting(void) const
    {
        return mLighting;
    }

    //****************************************************************************/
    void QtNodePass::setDepthCheck(bool depthCheck)
    {
        mDepthCheck = depthCheck;
    }

    //****************************************************************************/
    void QtNodePass::setDepthWrite(bool depthWrite)
    {
        mDepthWrite = depthWrite;
    }

    //****************************************************************************/
    void QtNodePass::setLighting(bool lighting)
    {
        mLighting = lighting;
    }

    //****************************************************************************/
    const QColor& QtNodePass::getAmbient(void)
    {
        return mAmbient;
    }

    //****************************************************************************/
    const QColor& QtNodePass::getDiffuse(void)
    {
        return mDiffuse;
    }

    //****************************************************************************/
    const QColor& QtNodePass::getSpecular(void)
    {
        return mSpecular;
    }

    //****************************************************************************/
    void QtNodePass::setAmbient(const QColor& col)
    {
        mAmbient = col;
    }

    //****************************************************************************/
    void QtNodePass::setDiffuse(const QColor& col)
    {
        mDiffuse = col;
    }

    //****************************************************************************/
    void QtNodePass::setSpecular(const QColor& col)
    {
        mSpecular = col;
    }

}
