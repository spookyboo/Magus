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

#ifndef MAGUS_APPLICATION_H
#define MAGUS_APPLICATION_H

#include <QApplication>
#include <QWidget>
#include <QString>
#include <QVector>

/****************************************************************************
 Custom event hander
****************************************************************************/
class CustomEventHandler
{
    public:
        CustomEventHandler(void){};
        virtual ~CustomEventHandler(void){};
        virtual void handleEvent(QEvent* event) = 0;
};

/****************************************************************************
 QApplication that handles all events
****************************************************************************/
class MainApplication : public QApplication
{
    public:
        MainApplication(int argc, char *argv[]) : QApplication(argc, argv)
        {
            installEventFilter(this);
        };
        virtual ~MainApplication(void){};
        void registerForMouseButtonDblClick(CustomEventHandler* handler)
        {
            mHandlerList.append(handler);
        };
        void unregisterForMouseButtonDblClick(CustomEventHandler* handler)
        {
            int i = 0;
            QVectorIterator<CustomEventHandler*> l(mHandlerList);
            while (l.hasNext())
            {
                 if (l.next() == handler)
                 {
                     mHandlerList.remove(i);
                 }
                 i++;
            }
        };

    protected:
        bool eventFilter(QObject* obj, QEvent* event)
        {
            if (event->type() == QEvent::MouseButtonDblClick)
            {
                QVectorIterator<CustomEventHandler*> l(mHandlerList);
                CustomEventHandler* handler;
                while (l.hasNext())
                {
                    handler = l.next();
                    handler->handleEvent(event);
                }
            }
            return false; // Always return false to prevent that events are not passed through
        }

    private:
        QVector<CustomEventHandler*> mHandlerList;
};

//****************************************************************************/
#endif
