#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::onLogin()
{
    QString username = ui->leUsername->text().trimmed();
    QString password = ui->lePassword->text().trimmed();

    qDebug() << "Button(Login) clicked";

    if (username.isEmpty() || password.isEmpty())
    {
        ui->lblMessage->setText("Please input username and password");
        return;
    }

    if (username == "admin" && password == "admin")
    {
        hide();
        Q_EMIT login();
    }
    else
    {
        ui->lblMessage->setText("Username or Password is incorrect");
    }
}

void Login::onExit()
{
    qDebug() << "Button(Exit) clicked";
    Q_EMIT exit();
}

void Login::onEdit()
{
    ui->lblMessage->clear();
}
