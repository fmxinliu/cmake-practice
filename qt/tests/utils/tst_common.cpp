#include <QTest>
#include "randomstringthread.h"
#include "common.h"

class tst_Common : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void tst_generateRandomStr_MulThread();
    void tst_generateRandomStr_SingleThread();

    void tst_regularMatched_data();
    void tst_regularMatched();

    void tst_regularContains_data();
    void tst_regularContains();
};

void tst_Common::tst_generateRandomStr_MulThread()
{
    for (int i = 0; i < 100; ++i)
    {
        QCOMPARE(RandomStringThread::startTest(10, 100), 1000);
    }
}

void tst_Common::tst_generateRandomStr_SingleThread()
{
    for (int i = 0; i < 100; ++i)
    {
        QCOMPARE(RandomStringThread::startTest(1, 1000), 1000);
    }
}

void tst_Common::tst_regularMatched_data()
{
    QTest::addColumn<QString>("str");
    QTest::addColumn<bool>("result");

    QTest::newRow("empty string") << "" << false;
    QTest::newRow("only contains numbers") << "123456" << false;
    QTest::newRow("only contains letters") << "abcdef" << false;
    QTest::newRow("only contains other character") << "@*#" << false;
    QTest::newRow("contains numbers and letters") << "1a2b3d4e5f" << true;
    QTest::newRow("contains numbers and other character") << "1@2*3&4" << true;
    QTest::newRow("contains letters and other character") << "a@b*c&d" << true;
    QTest::newRow("contains numbers, letters and other character") << "1a2&3c4@" << true;
}

void tst_Common::tst_regularMatched()
{
    QFETCH(QString, str);
    QFETCH(bool, result);

    // 正则表达式：至少包含数字、字母、特殊字符中的两种
    QString pattern =
        "^(?:"
        "(?=.*\\d)(?=.*[a-zA-Z])"          // 数字 + 字母
        "|"
        "(?=.*\\d)(?=.*[^a-zA-Z0-9])"      // 数字 + 特殊字符
        "|"
        "(?=.*[a-zA-Z])(?=.*[^a-zA-Z0-9])" // 字母 + 特殊字符
        ").+$";

    QCOMPARE(Common::regularMatched(str, pattern), result);
}

void tst_Common::tst_regularContains_data()
{
    QTest::addColumn<QString>("str");
    QTest::addColumn<bool>("result");

    QTest::newRow("empty string") << "" << false;
    QTest::newRow("only contains letters") << "abcdef" << false;
    QTest::newRow("only contains numbers") << "123456" << false;
    QTest::newRow("only contains white-space character") << " " << false;
    QTest::newRow("contains numbers and letters") << "1a2b3d4e5f" << false;
    QTest::newRow("contains numbers and letters, and white-space character") << "1a2b3 d4e5f" << true;
}

void tst_Common::tst_regularContains()
{
    QFETCH(QString, str);
    QFETCH(bool, result);

    // 正则表达式：同时包含数字、字母和空白字符
    QStringList patterns;
    patterns << "\\d"      // 匹配数字
             << "[a-zA-Z]" // 匹配字母
             << "\\s";     // 匹配空白字符

    QCOMPARE(Common::regularContains(str, patterns), result);
}

QTEST_MAIN(tst_Common)
#include "tst_common.moc"
