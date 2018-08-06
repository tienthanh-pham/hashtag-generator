#ifndef SCREENLIST_H
#define SCREENLIST_H

#include <QtQuick>

enum SCREENLIST
{
    HOME = 0,
    SCREEN1
};

class ScreenList
{
private:
    QMap<SCREENLIST, QString> m_screenList;
public:
    ScreenList()
    {
        m_screenList.insert(SCREENLIST::HOME,"qrc:/main.qml");
        m_screenList.insert(SCREENLIST::SCREEN1,"qrc:/page/Screen1.qml");
    }
public:
    QString getScreen(SCREENLIST screenId)
    {
        return m_screenList.take(screenId);
    }
};

#endif // SCREENLIST_H
