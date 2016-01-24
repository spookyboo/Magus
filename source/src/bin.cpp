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

#include <QMessageBox>
#include <QMimeData>
#include <QLabel>
#include <QPalette>
#include "bin.h"
#include "constants.h"
#include "mainwindow.h"

//****************************************************************************/
Bin::Bin (QString iconDir) : QWidget(0)
{
    QLabel* label = new QLabel(this);
    label->setPixmap(QPixmap(iconDir + ICON_BIN).scaled(BIN_SIZE, BIN_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    label->setAcceptDrops(false);
    setAcceptDrops(true);
}

//****************************************************************************/
void Bin::dragEnterEvent(QDragEnterEvent *event)
{
    // Icons from the selection table may not be dropped
    if (event->mimeData()->hasFormat(MIME_TYPE_SELECTION))
        event->ignore();
    else
        event->accept();
}

//****************************************************************************/
void Bin::dropEvent(QDropEvent* event)
{
    if (event->mimeData()->hasFormat(MIME_TYPE_SELECTION))
        return;

    if (event->mimeData()->hasFormat(MIME_TYPE_HTOOLBAR))
        iconDeleted(MIME_TYPE_HTOOLBAR);
    if (event->mimeData()->hasFormat(MIME_TYPE_VTOOLBAR))
        iconDeleted(MIME_TYPE_VTOOLBAR);
}
