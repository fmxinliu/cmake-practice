#include <QApplication>
#include <QTranslator>
#include "mainwindow.h"
#include "login.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 从资源文件加载翻译
    QTranslator translator;
    if (translator.load(":/translations/cmake_qt_zh_CN.qm")) {
        qDebug() << "Load translation success";
        Q_ASSERT(app.installTranslator(&translator));
    } else {
        qDebug() << "Load failed. Check path or qrc file";
    }

    Login login;
    MainWindow w;

    QObject::connect(&login, &Login::login, &w, &MainWindow::show);
    QObject::connect(&login, &Login::exit, &app, &QApplication::quit);

    login.show();

    return app.exec();
}
