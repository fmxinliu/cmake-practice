#include <QTest>
#include "usermanager.h"
#include "common.h"
#include <QFile>

class tst_UserManager : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void addUser_data();
    void addUser();

    void modifyUser_data();
    void modifyUser();

    void delUser_data();
    void delUser();

    void initTestCase();
    void cleanupTestCase();
};


void tst_UserManager::initTestCase()
{
    QFile::remove(Common::configFilepath());
}

void tst_UserManager::cleanupTestCase()
{
    QFile::remove(Common::configFilepath());
}

void tst_UserManager::addUser_data()
{
    QTest::addColumn<QString>("username");
    QTest::addColumn<QString>("password");

    QTest::newRow("add new user") << "aaa" << "123";
    QTest::newRow("add exists user") << "aaa" << "456";
}

void tst_UserManager::addUser()
{
    QFETCH(QString, username);
    QFETCH(QString, password);

    if (UserManager::instance()->hasUser(username))
    {
        QVERIFY(!UserManager::instance()->addUser(username, password));
        QVERIFY(!UserManager::instance()->login(username, password));
    }
    else
    {
        QVERIFY(UserManager::instance()->addUser(username, password));
        QVERIFY(UserManager::instance()->login(username, password));
    }
}

void tst_UserManager::modifyUser_data()
{
    QTest::addColumn<QString>("username");
    QTest::addColumn<QString>("password");
    QTest::addColumn<QString>("new_password");

    QTest::newRow("modify non-exists user") << "mmm1" << "123456" << "abcd";

    QString username = "mmm2";;
    QString password = "123456";
    QString new_password = "abcd";
    UserManager::instance()->addUser(username, password);
    QTest::newRow("modify exists user") << username << password << new_password;
}

void tst_UserManager::modifyUser()
{
    QFETCH(QString, username);
    QFETCH(QString, password);
    QFETCH(QString, new_password);

    if (UserManager::instance()->hasUser(username))
    {
        QVERIFY(UserManager::instance()->modifyUser(username, new_password));
        QVERIFY(UserManager::instance()->login(username, new_password));
    }
    else
    {
        QVERIFY(!UserManager::instance()->modifyUser(username, new_password));
        QVERIFY(!UserManager::instance()->login(username, password));
    }
}

void tst_UserManager::delUser_data()
{
    QTest::addColumn<QString>("username");
    QTest::addColumn<QString>("password");

    QTest::newRow("delete non-exists user") << "ddd1" << "123";

    QString username = "ddd2";
    QString password = "123";
    UserManager::instance()->addUser(username, password);
    QTest::newRow("modify exists user") << username << password;
}

void tst_UserManager::delUser()
{
    QFETCH(QString, username);
    QFETCH(QString, password);

    if (UserManager::instance()->hasUser(username))
    {
        QVERIFY(UserManager::instance()->delUser(username));
        QVERIFY(!UserManager::instance()->hasUser(username));
        QVERIFY(!UserManager::instance()->login(username, password));
    }
    else
    {
        QVERIFY(!UserManager::instance()->delUser(username));
        QVERIFY(!UserManager::instance()->login(username, password));
    }
}

QTEST_MAIN(tst_UserManager)
#include "tst_usermanager.moc"
