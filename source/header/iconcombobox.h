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

#ifndef MAGUS_ICON_COMBOBOX_H
#define MAGUS_ICON_COMBOBOX_H

#include <QComboBox>
#include <QString>
#include "iconmodel.h"

class IconReader;

/****************************************************************************
 Combobox for displaying icons
****************************************************************************/
class IconComboBox : public QComboBox
{
    public:
        IconComboBox(IconReader* iconReader,
                     IconSelectionModel* iconSelectionModel,
                     const QString &iconDir,
                     QWidget* parent = 0);
        virtual ~IconComboBox(void){};

    public slots:
        void handleSelectionChanged(int index);

    private:
        IconReader* mIconReader;
        IconSelectionModel* mIconSelectionModel;
        QString mIconDir;
};

//****************************************************************************/
#endif
