#ifndef COMMON_H
#define COMMON_H

#include <QStringList>

class Common
{
public:
    static QString generateRandomPassword(int num);
    static bool regularMatched(const QString &str, const QString &pattern);
    static bool regularContains(const QString &str, const QStringList &patterns);
};


#endif // COMMON_H
