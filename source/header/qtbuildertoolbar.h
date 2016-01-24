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

#ifndef MAGUS_QTBUILDER_TOOLBAR_H
#define MAGUS_QTBUILDER_TOOLBAR_H

#include <QString>

/****************************************************************************
 Implementation of a toolbar builder class for Qt.
****************************************************************************/
class WindowProperties;

class QtToolbarBuilder
{
    public:
        QtToolbarBuilder();
        virtual ~QtToolbarBuilder();
        QString createInclude(WindowProperties* windowProperties, const QString &s);
        QString createPrivateMembers(WindowProperties* windowProperties, const QString &s);
        QString createToolbars(WindowProperties* windowProperties, const QString &s);

    private:
        QString createToolbarsForMainWindow(WindowProperties* windowProperties);
        QString createToolbarsForDockWindow(WindowProperties* windowProperties);
        QString createHToolbarWidgets(WindowProperties* windowProperties);
};

//****************************************************************************/
#endif
