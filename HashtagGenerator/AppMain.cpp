#include "AppMain.h"
#include <QtDebug>

AppMain::AppMain()
    : m_rootObject(nullptr)
    , m_adapter(nullptr)
    , m_hashtagGenerator(nullptr)
{
    m_adapter = new Adapter();
    m_hashtagGenerator = new HashtagGenerator();
    //Initialize HOME screen
    m_view.setSource(QUrl(m_screenList.getScreen(SCREENLIST::HOME)));
    m_view.setWidth(400);
    m_view.setHeight(600);
    m_view.show();
    m_rootObject = m_view.rootObject()->findChild<QObject*>(MAIN_LOADER);
    m_adapter->setRootObject(m_rootObject);
    //Register context property to using in QML
    m_view.rootContext()->setContextProperty("UIBridge", &m_uiBridge);
    connectSignalSlot();
    //Open default screen
    changeScreen(SCREENLIST::SCREEN1);
}

AppMain::~AppMain()
{
    delete m_rootObject;
}

void AppMain::connectSignalSlot()
{
    QObject::connect(&m_uiBridge,SIGNAL(eventSentString(QString)),this,SLOT(onEventSentString(QString)));
}

void AppMain::changeScreen(SCREENLIST screenId)
{
    if (m_rootObject != nullptr)
    {
        QString screenSource = m_screenList.getScreen(screenId);
        m_rootObject->setProperty("source", screenSource);
    }
}

void AppMain::onEventSentString(QString str)
{
    if (m_hashtagGenerator != nullptr)
    {
        QString result = m_hashtagGenerator->generate(str);
        m_adapter->onRespondEventSentString(result);
    }
}
