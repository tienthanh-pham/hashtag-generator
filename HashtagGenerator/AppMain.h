#ifndef APPMAIN_H
#define APPMAIN_H

#include <QtQuick>
#include <QObject>
#include "AppDefine.h"
#include "ScreenList.h"
#include "UiBridge.h"
#include "Adapter.h"
#include "HashtagGenerator.h"

class AppMain : public QObject
{
    Q_OBJECT
private:
    QQuickView m_view;
    ScreenList m_screenList;
    QObject* m_rootObject;

    UiBridge m_uiBridge;
    Adapter* m_adapter;
    HashtagGenerator* m_hashtagGenerator;
public:
    AppMain();
    ~AppMain();
private:
    void connectSignalSlot();
    void changeScreen(SCREENLIST screenId);
public slots:
    void onEventSentString(QString str);
};

#endif // APPMAIN_H
