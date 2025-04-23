#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include "usermanager.h"
#include "adduser.h"
#include "modifyuser.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    // 禁用最大化按钮
    setWindowFlag(Qt::WindowMaximizeButtonHint, false);

    // 禁用调整窗口大小
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint, true);
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

    if (UserManager::instance()->login(username, password))
    {
        close();
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

void Login::onRegister()
{
    qDebug() << "Button(Register) clicked";
    hide();
    AddUser dialog;
    dialog.exec();
    show();
}

void Login::onForgetPassword()
{
    qDebug() << "Button(Forget) clicked";
    hide();
    ModifyUser dialog;
    dialog.exec();
    show();
}

