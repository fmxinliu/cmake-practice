#include <QTest>
#include "namingrules.h"

class tst_NamingRules : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void tst_isValidUsername_data();
    void tst_isValidUsername();
    void tst_isValidPassword_data();
    void tst_isValidPassword();
};


void tst_NamingRules::tst_isValidUsername_data()
{
    QTest::addColumn<QString>("username");
    QTest::addColumn<bool>("result");

    QTest::addRow("Username is empty") << "" << false;
    QTest::addRow("Username is all white characters") << " " << false;
    QTest::addRow("Username start with white character") << " abc" << false;
    QTest::addRow("Username ends with white character") << "abc " << false;
    QTest::addRow("Username contains not allow character") << "abc@" << false;
    QTest::addRow("Username is all numbers") << "123" << true;
    QTest::addRow("Username is all letters") << "abc" << true;
    QTest::addRow("Username only contains letter and white character") << "ab c" << true;
    QTest::addRow("Username only contains number and white character") << "12 3" << true;
    QTest::addRow("Username only contains number and letter") << "Abc1" << true;
    QTest::addRow("Username only contains number, letter and white character") << "Abc 1" << true;
    QTest::addRow("Username only contains number, letter, white character and _") << "Abc 1_" << true;
}

void tst_NamingRules::tst_isValidUsername()
{
    QFETCH(QString, username);
    QFETCH(bool, result);

    NamingRules reles;
    QCOMPARE(reles.isValidUsername(username), result);
}

void tst_NamingRules::tst_isValidPassword_data()
{
    QTest::addColumn<QString>("password");
    QTest::addColumn<bool>("result");

    QTest::addRow("Password length < 3") << "12" << false;
    QTest::addRow("Password length > 10") << "123456789012" << false;

    QTest::addRow("Password only contains letter") << "abc" << false;
    QTest::addRow("Password only contains number") << "123" << false;
    QTest::addRow("Password contains number and letter") << "abc123" << true;
    QTest::addRow("Password contains number, letter and symbol") << "abc123 @" << true;
    QTest::addRow("Password contains number, letter and white character") << "abc 123" << true;
}

void tst_NamingRules::tst_isValidPassword()
{
    QFETCH(QString, password);
    QFETCH(bool, result);

    NamingRules reles;
    QCOMPARE(reles.isValidPassword(password), result);
}


QTEST_MAIN(tst_NamingRules)
#include "tst_namingrules.moc"
