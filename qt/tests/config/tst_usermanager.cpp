#include <QTest>
#include "usermanager.h"
#include "common.h"

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

void tst_UserManager::modifyUser()
{
    QString username = "test_user";
    QString password = Common::generateRandomPassword(6);
    if (!UserManager::instance()->hasUser(username))
    {
        UserManager::instance()->addUser(username, "test_user");
    }

    QVERIFY(UserManager::instance()->modifyUser(username, password));
    QVERIFY(UserManager::instance()->login(username, password));
}


QTEST_MAIN(tst_UserManager)
#include "tst_usermanager.moc"
