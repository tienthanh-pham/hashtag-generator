#ifndef UIBRIDGE_H
#define UIBRIDGE_H

#include <QtQuick>
#include <QObject>

class UiBridge : public QObject
{
    Q_OBJECT
public:
    UiBridge();
public:
    Q_INVOKABLE void sentString(QString str);
signals:
    void eventSentString(QString str);
};

#endif // UIBRIDGE_H
