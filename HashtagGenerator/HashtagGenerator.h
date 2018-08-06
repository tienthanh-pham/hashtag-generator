#ifndef HASHTAGGENERATOR_H
#define HASHTAGGENERATOR_H

#include <QtQuick>

enum HASHTAG_TYPE{
    NON = 0,
    FULL_OPTION,
};

class HashtagGenerator
{
public:
    HashtagGenerator();
public:
    QString generate(QString str);
private:
    QString generateNormal(QString str);
    QString generateNoSpace(QString str);
};

#endif // HASHTAGGENERATOR_H
