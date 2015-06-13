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

#ifndef MAGUS_QTBUILDER_ACTION_H
#define MAGUS_QTBUILDER_ACTION_H

#include <QString>
#include <QVectorIterator>

/****************************************************************************
 Implementation of an action builder class for Qt.
****************************************************************************/
class ApplicationTemplate;
class WindowProperties;
class WindowMenuProperties;
class ToolbarProperties;

class QtActionBuilder
{
    public:
        QtActionBuilder();
        virtual ~QtActionBuilder();
        QString createInclude(const QString &s);
        QString createPrivateMembers(WindowProperties* windowProperties, WindowMenuProperties* windowMenuProperties, const QString &s);
        QString createPrivateSlots(WindowProperties* windowProperties, WindowMenuProperties* windowMenuProperties, const QString &s);
        QString createActions(WindowProperties* windowProperties,
                              WindowMenuProperties* windowMenuProperties,
                              const QString &s,
                              const QString &iconDir,
                              const QString &fullOutputIconDir);
        QString createDoActions(ApplicationTemplate* applicationTemplate,
                                WindowProperties* windowProperties,
                                WindowMenuProperties* windowMenuProperties,
                                const QString &s);
        QString getDockWidgetToAreaString(WindowProperties* currentWindowProperties);

    private:
        QString updatePrivateMembersMenu(WindowMenuProperties* windowMenuProperties);
        QString updatePrivateMembersToolbar(WindowProperties* windowProperties);
        QString createPrivateSlotsForMenu(WindowMenuProperties* windowMenuProperties);
        QString createPrivateSlotsForToolbar(WindowProperties* windowProperties);
        QString createPrivateSlotForOneToolbar(WindowProperties* windowProperties,
                                               QVectorIterator<ToolbarProperties*>* list,
                                               const QString &postPriveSlotName);
        QString createActionsForMenu(WindowMenuProperties* windowMenuProperties);
        QString createActionsForToolbar(WindowProperties* windowProperties,
                                        const QString &iconDir,
                                        const QString &fullOutputIconDir);
        QString createActionsForOneToolbar(WindowProperties* windowProperties,
                                           QVectorIterator<ToolbarProperties*> *list,
                                           const QString &postPriveSlotName,
                                           const QString &iconDir,
                                           const QString &fullOutputIconDir);
        QString createDoActionsForMenu(ApplicationTemplate* applicationTemplate,
                                       WindowProperties* windowProperties,
                                       WindowMenuProperties* windowMenuProperties);
        QString createDoActionsForToolbar(WindowProperties* windowProperties);
        QString createDoActionForOneToolbar(WindowProperties* windowProperties,
                                            QVectorIterator<ToolbarProperties*>* list,
                                            const QString &className,
                                            const QString &postPriveSlotName);
        QString getResetWindowLayoutString(ApplicationTemplate* applicationTemplate,
                                           WindowProperties* currentWindowProperties);
};

//****************************************************************************/
#endif
