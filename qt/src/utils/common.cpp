#include "common.h"
#if QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)
#include <QRandomGenerator>
#else
#include "randomgenerator.h"
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QRegularExpression>
#else
#include <QRegExp>
#endif

#include <QCoreApplication>

QString Common::configFilepath()
{
    return QCoreApplication::applicationDirPath() + "/config.ini";
}

QString Common::generateRandomStr(int num)
{
    const QString possibleCharacters(
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789");

    QString randomString;

    for (int i = 0; i < num; ++i)
    {
#if QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)
        int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
#else
        int index = RandomGenerator::bounded(0U, possibleCharacters.length());
#endif
        randomString.append(possibleCharacters.at(index));
    }

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

