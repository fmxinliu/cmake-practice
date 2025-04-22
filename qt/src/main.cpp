#include <QApplication>
#include "mainwindow.h"
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login login;
    MainWindow w;

    QObject::connect(&login, &Login::login, &w, &MainWindow::show);
    QObject::connect(&login, &Login::exit, &a, &QApplication::quit);

    login.show();

    return a.exec();
}
