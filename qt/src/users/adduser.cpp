#include "adduser.h"
#include "ui_adduser.h"
#include "namingrules.h"
#include "usermanager.h"
#include <QMessageBox>

AddUser::AddUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddUser)
{
    ui->setupUi(this);

    // 去掉对话框上的问号
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);

    // 禁用调整窗口大小
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint, true);
}

AddUser::~AddUser()
{
    delete ui;
}

void AddUser::onAddUser()
{
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();
    QString password2 = ui->lePassword_2->text();

    NamingRules rules;
    if (!rules.isValidUsername(username))
    {
        ui->leUsername->setFocus();
        ui->leUsername->selectAll();
        ui->lblMessage->setText(rules.checkMessage());
        return;
    }

    if (!rules.isValidPassword(password))
    {
        ui->lePassword->setFocus();
        ui->lePassword->selectAll();
        ui->lblMessage->setText(rules.checkMessage());
        return;
    }

    if (password != password2)
    {
        ui->lePassword_2->setFocus();
        ui->lePassword_2->selectAll();
        ui->lblMessage->setText(tr("The passwords entered twice are different"));
        return;
    }

    if (UserManager::instance()->hasUser(username))
    {
        ui->leUsername->setFocus();
        ui->leUsername->selectAll();
        ui->lblMessage->setText(tr("The username already exists"));
        return;
    }

    UserManager::instance()->addUser(username, password);
    QMessageBox::information(this, tr("User"), tr("Add Success"));

    ui->leUsername->clear();
    ui->lePassword->clear();
    ui->lePassword_2->clear();
}

void AddUser::onEdit()
{
    ui->lblMessage->clear();
}
