/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Ilija Boshkov <Mind Calamity> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#ifndef Widget_H
#define Widget_H

#include "ogre_prereqs.h"

// Boost + Qt5 workaround to avoid Macro argument mismatch error.
#ifndef Q_MOC_RUN
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>
#include "ogre_colouredrectangle.h"
#include "ogre_cameraman.h"
#endif

#define QTLIB	0
#define OISLIB	1

#define INPUTLIB QTLIB

namespace QOgre
{
    class OverlayWidget : public QWidget
    {
	Q_OBJECT

	public:
	OverlayWidget(QWidget *parent=0) : QWidget(parent)
	{
	    msgstr = QApplication::translate("Widget", "Initializing OGRE...");
	    setContextMenuPolicy( Qt::PreventContextMenu );
	}

	virtual ~OverlayWidget() {}

	void setMessageString(QString msg)
	{
	    if(msgstr != msg)
	    {
		msgstr = msg;
		this->repaint();
	    }
	}

	protected:
	    QString msgstr;

	    void paintEvent(QPaintEvent* evt);
    };

    class Widget : public QWidget
    {

	Q_OBJECT

    public:
	Widget(QWidget *parent);
	virtual ~Widget(void);
	virtual void	go(Ogre::Root* root, Ogre::SceneManager* mgr = NULL);
	QPaintEngine*	paintEngine() const; // Turn off QTs paint engine for the Ogre widget.
	Ogre::SceneManager* getSceneManager() {return mSceneMgr;}
	Ogre::String	mFPS;
    bool mSystemInitialized;
    Ogre::Camera* mCamera;
    Ogre::Entity *mEntity;
    Ogre::Light* mLight;
    virtual void	updateOgre(float timeSinceLastFrame);
	virtual void	setViewportBackground(Ogre::ColourValue top, Ogre::ColourValue bottom);

    protected:
	bool setup();
	bool configure(void);
	void chooseSceneManager(void);
	void createCamera(void);
	void createScene(void);
	void destroyScene(void);
	void createViewports(void);
	void setupResources(void);
	void createResourceListener(void);
	void loadResources(void);

	Ogre::Root*	    mRoot;
	Ogre::SceneManager* mSceneMgr;
	Ogre::RenderWindow* mWindow;
	Ogre::String	    mResourcesCfg;
	Ogre::String	    mPluginsCfg;
	Ogre::Real	    mTimeSinceLastFrame;
	QOgre::CameraMan*   mCameraMan;
	bool mShutDown;
	bool mPassedSM;

    private:
	void paintEvent(QPaintEvent *e);
	void resizeEvent(QResizeEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void wheelEvent(QWheelEvent *e);
	void keyPressEvent(QKeyEvent *e);
	void keyReleaseEvent(QKeyEvent *e);
	bool updateExternalSystems();
	Ogre::Vector2		    mAbsolute;
	Ogre::Vector2		    mRelative;
	QOgre::OverlayWidget*	    mOverlayWidget;
    };
}
#endif // Widget_H

