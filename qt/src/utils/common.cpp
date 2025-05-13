#include "common.h"
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QRandomGenerator>
#else
#include <QTime>
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QRegularExpression>
#else
#include <QRegExp>
#endif

QString Common::generateRandomPassword(int num)
{
    const QString possibleCharacters(
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789");

    QString randomString;

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    for (int i = 0; i < num; ++i)
    {
        int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
        randomString.append(possibleCharacters.at(index));
    }
#else
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime())); // 初始化随机种子
    for (int i = 0; i < num; ++i)
    {
        int index = qrand() % possibleCharacters.length();
        randomString.append(possibleCharacters.at(index));
    }
#endif

    return randomString;
}

bool Common::regularMatched(const QString &str, const QString &pattern)
{
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    QRegularExpression regex(pattern);
    return regex.match(str).hasMatch();
#else
    QRegExp regex(pattern);
    return regex.exactMatch(str);
#endif
}

bool Common::regularContains(const QString &str, const QStringList &patterns)
{
    #if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
        QStringList patternList;
        Q_FOREACH(const QString &pattern, patterns)
        {
            patternList.append(QString("(?=.*%1)").arg(pattern));
        }
        patternList.insert(0, "^");
        patternList.append(".+$");

        QRegularExpression regex(patternList.join(""));
        return regex.match(str).hasMatch();
    #else
        Q_FOREACH(const QString &pattern, patterns)
        {
            if (!str.contains(QRegExp(pattern)))
            {
                return false;
            }
        }
        return true;
    #endif
}

