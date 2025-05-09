#include <QTest>
#include <QIcon>

class tst_ImagesQrc : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void tst_load_icon_data();
    void tst_load_icon();
};


void tst_ImagesQrc::tst_load_icon_data()
{
    QTest::addColumn<QString>("path");
    QTest::addColumn<bool>("result");

    QTest::addRow("empty path") << "" << false;
    QTest::addRow("not exists path") << "path/to/image.png" << false;
    QTest::addRow("load from file-path") << APP_ICON_PATH << true;
    QTest::addRow("load from qrc-path") << ":images/app.ico" << true;
}

void tst_ImagesQrc::tst_load_icon()
{
    QFETCH(QString, path);
    QFETCH(bool, result);

    bool iconLoaded = false;
    if (QFile::exists(path))
    {
        qDebug() << path;

        QIcon icon(path);
        if (!icon.isNull() && !icon.availableSizes().isEmpty())
        {
            iconLoaded = true;
        }
    }

    QCOMPARE(iconLoaded, result);
}


QTEST_MAIN(tst_ImagesQrc)
#include "tst_images_qrc.moc"
