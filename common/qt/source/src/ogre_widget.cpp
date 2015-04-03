/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Ilija Boshkov <Mind Calamity> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

/*/////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2012 Ilija Boshkov
//
/// The MIT License
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
////////////////////////////////////////////////////////////////////////////////*/

#include "ogre_widget.h"
using namespace QOgre;

//----------------------------------------------------------------------------------------
void OverlayWidget::paintEvent(QPaintEvent* evt)
{
    QPainter painter(this);
    painter.setClipRect(0,0,width(),height());
    painter.setBrush(QBrush(QColor(0,0,0)));
    painter.fillRect(QRectF(0,0,width(),height()), QColor(0,0,0));
    painter.setPen(QColor(210,210,210));
    painter.drawText(QRectF(0,0,width(),height()),msgstr,QTextOption(Qt::AlignVCenter | Qt::AlignHCenter));
}
//----------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
Widget::Widget(QWidget *parent)
    : QWidget(parent),
    mRoot(0),
    mCamera(0),
    mEntity(0),
    mSceneMgr(0),
    mWindow(0),
    mShutDown(false),
    mPassedSM(false),
    mSystemInitialized(false),
    mTimeSinceLastFrame(0.0f)
{
    mResourcesCfg = "";
    mPluginsCfg = "";
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_PaintOnScreen);
    setMinimumSize(240,240);
    resize(800,600);
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
    mOverlayWidget = new OverlayWidget(this);
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setMargin(0);
    layout->addWidget(mOverlayWidget);
    setLayout(layout);
    mOverlayWidget->setMessageString("Application -> Start Rendering");
}

//-------------------------------------------------------------------------------------
Widget::~Widget(void)
{
}

//-------------------------------------------------------------------------------------
bool Widget::configure(void)
{
    // Show the configuration dialog and initialise the system
    // You can skip this and use root.restoreConfig() to load configuration
    // settings if you were sure there are valid ones saved in ogre.cfg

    Ogre::String widgetHandle = Ogre::StringConverter::toString((size_t)((HWND)this->winId()));
    Ogre::NameValuePairList  viewConfig;
    viewConfig["externalWindowHandle"] = widgetHandle;
    // The line below utilizes the root's timer in order to generate a unique name for each widget instance
    mWindow = mRoot->createRenderWindow(Ogre::StringConverter::toString(mRoot->getTimer()->getMicroseconds()),
		width(), height(), false, &viewConfig);
    return true;
}
//-------------------------------------------------------------------------------------
void Widget::chooseSceneManager(void)
{
    // Get the SceneManager, in this case a generic one
    mOverlayWidget->setMessageString("Creating Scene Manager");
    mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);
}
//-------------------------------------------------------------------------------------
void Widget::createCamera(void)
{
    mOverlayWidget->setMessageString("Creating Camera");
    // Create the camera
    mCamera = mSceneMgr->createCamera(Ogre::StringConverter::toString(mRoot->getTimer()->getMicroseconds()));

    // Position it at 500 in Z direction
    mCamera->setPosition(Ogre::Vector3(0,0,80));
    // Look back along -Z
    mCamera->lookAt(Ogre::Vector3(0,0,-300));
    mCamera->setNearClipDistance(0.1);
    mCameraMan = new QOgre::CameraMan(mCamera);
}
//-------------------------------------------------------------------------------------
QPaintEngine* Widget::paintEngine() const
{
    // We don't want another paint engine to get in the way for our Ogre based paint engine.
    // So we return nothing.
    return NULL;
}
//-------------------------------------------------------------------------------------
void Widget::destroyScene(void)
{
}
//-------------------------------------------------------------------------------------
void Widget::createViewports(void)
{
    // Create one viewport, entire window
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

    // Alter the camera aspect ratio to match the viewport
    mCamera->setAspectRatio(
	Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));

    mOverlayWidget->setMessageString("Creating viewports...");
}
//-------------------------------------------------------------------------------------
void Widget::setupResources(void)
{
    // Load resource paths from config file
    Ogre::ConfigFile cf;
    cf.load(mResourcesCfg);
    mOverlayWidget->setMessageString("Loading resource paths from \n" + QString::fromStdString(mResourcesCfg));
    // Go through all sections & settings in the file
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    Ogre::String secName, typeName, archName;
    while (seci.hasMoreElements())
    {
	secName = seci.peekNextKey();
	Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
	Ogre::ConfigFile::SettingsMultiMap::iterator i;
	for (i = settings->begin(); i != settings->end(); ++i)
	{
	    typeName = i->first;
	    archName = i->second;
	    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
		archName, typeName, secName);
	    mOverlayWidget->setMessageString("Loading resource section '"
					     + QString::fromStdString(secName)
					     + "' (" + QString::fromStdString(typeName) + ")");
	}
    }
}
//-------------------------------------------------------------------------------------
void Widget::createResourceListener(void)
{

}
//-------------------------------------------------------------------------------------
void Widget::paintEvent(QPaintEvent *e)
{

}
//-------------------------------------------------------------------------------------
void Widget::resizeEvent(QResizeEvent *e)
{
    if(e->isAccepted())
    {
	const QSize &newSize = e->size();
	if(mRoot && mCamera)
	{
	    mWindow->resize(newSize.width(), newSize.height());
	    mWindow->windowMovedOrResized();

	    Ogre::Real aspectRatio = Ogre::Real(newSize.width()) / Ogre::Real(newSize.height());
	    mCamera->setAspectRatio(aspectRatio);
	}
    }
}
//-------------------------------------------------------------------------------------
void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if (mSystemInitialized)
    {
	Ogre::Vector2 oldPos = mAbsolute;
	mAbsolute = Ogre::Vector2(e->pos().x(), e->pos().y());
	mRelative = mAbsolute - oldPos;
	mCameraMan->injectMouseMove(mRelative);
    }
}

//-------------------------------------------------------------------------------------
void Widget::mousePressEvent(QMouseEvent *e)
{
    if (mSystemInitialized)
	mCameraMan->injectMouseDown(e);
}

//-------------------------------------------------------------------------------------
void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    if (mSystemInitialized)
	mCameraMan->injectMouseUp(e);
}
//-------------------------------------------------------------------------------------
void Widget::wheelEvent(QWheelEvent *e)
{
    if (mSystemInitialized)
	mCameraMan->injectMouseWheel(e);
}

//-------------------------------------------------------------------------------------
void Widget::keyPressEvent(QKeyEvent *e)
{
    if (mSystemInitialized)
	mCameraMan->injectKeyDown(e);
}

//-------------------------------------------------------------------------------------
void Widget::keyReleaseEvent(QKeyEvent *e)
{
    if (mSystemInitialized)
	mCameraMan->injectKeyUp(e);
}
//-------------------------------------------------------------------------------------
void Widget::updateOgre(float timeSinceLastFrame)
{
    mTimeSinceLastFrame = timeSinceLastFrame;
    repaint();
    if (this->size() != this->parentWidget()->size())
	resize(this->parentWidget()->size());
}

//-------------------------------------------------------------------------------------
bool Widget::updateExternalSystems()
{
    return true;
}

//-------------------------------------------------------------------------------------
void Widget::loadResources(void)
{
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

//-------------------------------------------------------------------------------------
void Widget::go(Ogre::Root* root, Ogre::SceneManager* mgr)
{
#ifdef _DEBUG
    mResourcesCfg = "resources_d.cfg";
    mPluginsCfg = "plugins_d.cfg";
#else
    mResourcesCfg = "resources.cfg";
    mPluginsCfg = "plugins.cfg";
#endif

    mRoot = root;
    if (mgr)
    {
        mSceneMgr = mgr;
        mPassedSM = true;
    }

    if (!setup())
	return;

    // clean up
    destroyScene();
}
//-------------------------------------------------------------------------------------
bool Widget::setup(void)
{
    setupResources();

    bool carryOn = configure();
    if (!carryOn) return false;

    if (!mSceneMgr)
	chooseSceneManager();
    createCamera();
    createViewports();

    // Set default mipmap level (NB some APIs ignore this)
    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
    // Create any resource listeners (for loading screens)
    createResourceListener();

    // Load resources
    loadResources();

    mSystemInitialized = true;
    mOverlayWidget->hide();

    if (!mPassedSM)
    createScene();

    return true;
}
//-------------------------------------------------------------------------------------
void Widget::createScene(void)
{
    mOverlayWidget->setMessageString("Creating Scene");
    // create our model, give it the shader material, and place it at the origin
    mEntity = mSceneMgr->createEntity("The Big Head", "ogrehead.mesh");
    Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    node->attachObject(mEntity);

    mCameraMan->setTarget(mEntity->getParentSceneNode());

    mCamera->setFixedYawAxis(true);
    // Set ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    // Create a light
    mLight = mSceneMgr->createLight("MainLight");
    mLight->setPosition(20,80,50);
    Ogre::ColourValue blender	    = Ogre::ColourValue(0.223529, 0.223529, 0.223529, 1.0);
    Ogre::ColourValue top	    = Ogre::ColourValue(0.224, 0.224, 0.224, 1.0);
    Ogre::ColourValue bottom	    = Ogre::ColourValue(50 / 255.0f, 50 / 255.0f, 50 / 255.0f, 1.0);
    setViewportBackground(blender, blender);
}
//-------------------------------------------------------------------------------------
void Widget::setViewportBackground(Ogre::ColourValue top, Ogre::ColourValue bottom)
{
    // Create background material
    Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create("Background", "General");
    material->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
    material->getTechnique(0)->getPass(0)->setDepthWriteEnabled(false);
    material->getTechnique(0)->getPass(0)->setLightingEnabled(false);

    // Create background rectangle covering the whole screen
    QOgre::ColouredRectangle2D* rect = new QOgre::ColouredRectangle2D();
    rect->setCorners(-1.0, 1.0, 1.0, -1.0);
    rect->setMaterial("Background");

    // Set the colours
    rect->setColours(top, bottom, top, bottom);

    // Render the background before everything else
    rect->setRenderQueueGroup(Ogre::RENDER_QUEUE_BACKGROUND);

    // Use infinite AAB to always stay visible
    Ogre::AxisAlignedBox aabInf;
    aabInf.setInfinite();
    rect->setBoundingBox(aabInf);

    // Attach background to the scene
    Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Background");
    node->attachObject(rect);
}
//-------------------------------------------------------------------------------------
