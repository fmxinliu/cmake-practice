#include <QTest>
#include <QTranslator>
#include <QDebug>

#define STR_TO_CHARS(text) QString(text).toUtf8().constData()


class tst_TranslationsQrc : public QObject
{
    Q_OBJECT

public:
    tst_TranslationsQrc();
    ~tst_TranslationsQrc();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private Q_SLOTS:
    void tst_load_translation_data() { init_test_data(); }
    void tst_load_translation();

    void tst_install_translation_data() { init_test_data(); }
    void tst_install_translation();

private:
    void init_test_data();
    int languageChangeEventCounter;
};


tst_TranslationsQrc::tst_TranslationsQrc()
    : languageChangeEventCounter(0)
{
    qApp->installEventFilter(this);
}

tst_TranslationsQrc::~tst_TranslationsQrc()
{
    qApp->removeEventFilter(this);
}

bool tst_TranslationsQrc::eventFilter(QObject *, QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
        ++languageChangeEventCounter;
    return false;
}

void tst_TranslationsQrc::init_test_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<QString>("context");
    QTest::addColumn<QString>("sourceText");
    QTest::addColumn<QString>("translationText");

    QTest::addRow("zh_CN") << ":/translations/cmake_qt_zh_CN.qm" << "AddUser" << "Password" << "密 码";
    QTest::addRow("en_US") << ":/translations/cmake_qt_en_US.qm" << "AddUser" << "Password" << "Password";
}

void tst_TranslationsQrc::tst_load_translation()
{
    QFETCH(QString, path);
    QFETCH(QString, context);
    QFETCH(QString, sourceText);
    QFETCH(QString, translationText);

    QTranslator translator;
    QVERIFY(QFile::exists(path));
    QVERIFY(translator.load(path));

    QCOMPARE(translator.translate(STR_TO_CHARS(context), STR_TO_CHARS(sourceText)), translationText);
}

void tst_TranslationsQrc::tst_install_translation()
{
    QFETCH(QString, path);

    languageChangeEventCounter = 0;
    QTranslator *translator = new QTranslator;

    // 多语言未安装
    QVERIFY(translator->load(path));
    qApp->sendPostedEvents();
    qApp->sendPostedEvents();
    QCOMPARE(languageChangeEventCounter, 0);

    // 安装多语言
    QVERIFY(qApp->installTranslator(translator));
    qApp->sendPostedEvents();
    qApp->sendPostedEvents();
    QCOMPARE(languageChangeEventCounter, 1);

    // 安装后加载
    QVERIFY(translator->load(path));
    qApp->sendPostedEvents();
    qApp->sendPostedEvents();
    QCOMPARE(languageChangeEventCounter, 2);

    // 重复加载
    QVERIFY(translator->load(path));
    qApp->sendPostedEvents();
    qApp->sendPostedEvents();
    QCOMPARE(languageChangeEventCounter, 3);

    // 加载不存在的多语言
    QVERIFY(!translator->load("not exists pm file"));
    qApp->sendPostedEvents();
    qApp->sendPostedEvents();
    QCOMPARE(languageChangeEventCounter, 4);

    // 再次加载
    QVERIFY(translator->load(path));
    qApp->sendPostedEvents();
    qApp->sendPostedEvents();
    QCOMPARE(languageChangeEventCounter, 5);

    // 卸载
    QVERIFY(qApp->removeTranslator(translator));
    qApp->sendPostedEvents();
    qApp->sendPostedEvents();
    QCOMPARE(languageChangeEventCounter, 6);

    // 再次安装
    QVERIFY(qApp->installTranslator(translator));
    qApp->sendPostedEvents();
    qApp->sendPostedEvents();
    QCOMPARE(languageChangeEventCounter, 7);

    // 删除多语言
    delete translator;
    qApp->sendPostedEvents();
    qApp->sendPostedEvents();
    QCOMPARE(languageChangeEventCounter, 8);
}


QTEST_MAIN(tst_TranslationsQrc)
#include "tst_translations_qrc.moc"
