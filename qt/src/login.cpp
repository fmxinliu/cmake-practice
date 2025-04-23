#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include "configsaver.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    m_userconfig = new ConfigSaver("config.ini", "users");
    m_userconfig->save("admin", "admin");
    m_userconfig->save("user", "123");
}

Login::~Login()
{
    delete m_userconfig;
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

    if (m_userconfig->load(username) == password)
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
