#include <QApplication>
#include <QTranslator>
#include "mainwindow.h"
#include "login.h"
#include <QDebug>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 设置应用程序图标
    app.setWindowIcon(QIcon(":/images/app.ico"));

    // 从资源文件加载翻译
    QTranslator translator;
    if (translator.load(":/translations/cmake_qt_zh_CN.qm")) {
        qDebug() << "Load translation success";
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
        bool ret = app.installTranslator(&translator);
        qDebug() << "Install translation success:" << ret;
#else
        app.installTranslator(&translator);
#endif
    } else {
        qDebug() << "Load translation failed. Check path or qrc file";
    }

    Login login;
    MainWindow w;

    QObject::connect(&login, SIGNAL(login()), &w, SLOT(show()));
    QObject::connect(&login, SIGNAL(exit()), &app, SLOT(quit()));

    login.show();

    return app.exec();
}
