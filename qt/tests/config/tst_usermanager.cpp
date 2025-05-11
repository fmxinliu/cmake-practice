#include <QTest>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QRandomGenerator>
#else
#include <QTime>
#endif
#include "usermanager.h"

class tst_UserManager : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void addUser_data();
    void addUser();
    void modifyUser();
};


void tst_UserManager::addUser_data()
{
    QTest::addColumn<QString>("username");
    QTest::addColumn<QString>("password");

    QTest::newRow("add new user") << "abc" << "123";
    QTest::newRow("add exists user") << "abc" << "456";
}

void tst_UserManager::addUser()
{
    QFETCH(QString, username);
    QFETCH(QString, password);

    if (UserManager::instance()->hasUser(username))
    {
        QVERIFY(!UserManager::instance()->addUser(username, password));
    }
    else
    {
        QVERIFY(UserManager::instance()->addUser(username, password));
        QVERIFY(UserManager::instance()->login(username, password));
    }
}


static QString generateRandomPassword(int num)
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

void tst_UserManager::modifyUser()
{
    QString username = "test_user";
    QString password = generateRandomPassword(6);
    if (!UserManager::instance()->hasUser(username))
    {
        UserManager::instance()->addUser(username, "test_user");
    }

    QVERIFY(UserManager::instance()->modifyUser(username, password));
    QVERIFY(UserManager::instance()->login(username, password));
}


QTEST_MAIN(tst_UserManager)
#include "tst_usermanager.moc"
