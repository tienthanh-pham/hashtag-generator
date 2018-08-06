#include "Adapter.h"
#include "AppDefine.h"

Adapter::Adapter()
    : m_object(nullptr)
{
}

Adapter::~Adapter()
{
    delete  m_object;
}

void Adapter::setRootObject(QObject* object)
{
    m_object = object;
}

void Adapter::onRespondEventSentString(QString str)
{
    if (m_object != nullptr)
    {
        QObject* object = m_object->findChild<QObject*>(HASHTAG_RESULT);
        if (object != nullptr)
        {
            object->setProperty("text", QVariant(str));
        }
    }
}
