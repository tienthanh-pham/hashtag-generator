#ifndef ADAPTER_H
#define ADAPTER_H

#include <QObject>
#include <QtQuick>

class Adapter : public QObject
{
    Q_OBJECT
private:
    QObject* m_object;
public:
    Adapter();
    ~Adapter();
public:
    void setRootObject(QObject *object);
    void onRespondEventSentString(QString str);
};

#endif // ADAPTER_H
