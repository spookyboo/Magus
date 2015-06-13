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

#ifndef MAGUS_QTBUILDER_MENU_H
#define MAGUS_QTBUILDER_MENU_H

#include <QString>

/****************************************************************************
 Implementation of a menu builder class for Qt.
****************************************************************************/
class WindowMenuProperties;

class QtMenuBuilder
{
    public:
        QtMenuBuilder();
        virtual ~QtMenuBuilder();
        QString createInclude(const QString &s);
        QString createPrivateMembers(WindowMenuProperties* windowMenuProperties, const QString &s);
        QString createMenuMainWindow(WindowMenuProperties* windowMenuProperties, const QString &s);
        QString createMenuDockWidget(WindowMenuProperties* windowMenuProperties, const QString &s);
};

//****************************************************************************/
#endif
