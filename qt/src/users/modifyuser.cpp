#include "modifyuser.h"
#include "ui_modifyuser.h"
#include "namingrules.h"
#include "usermanager.h"
#include <QMessageBox>


ModifyUser::ModifyUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModifyUser)
{
    ui->setupUi(this);

    // 去掉对话框上的问号
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);

    // 禁用调整窗口大小
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint, true);
}

ModifyUser::~ModifyUser()
{
    delete ui;
}

void ModifyUser::onModifyUser()
{
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    if (!UserManager::instance()->hasUser(username))
    {
        ui->leUsername->setFocus();
        ui->leUsername->selectAll();
        ui->lblMessage->setText(tr("The user not found"));
        return;
    }

    NamingRules rules;
    if (!rules.isValidPassword(password))
    {
        ui->lePassword->setFocus();
        ui->lePassword->selectAll();
        ui->lblMessage->setText(rules.checkMessage());
        return;
    }

    UserManager::instance()->modifyUser(username, password);
    QMessageBox::information(this, tr("User"), tr("Modify Success"));

    ui->leUsername->clear();
    ui->lePassword->clear();
}

void ModifyUser::onEdit()
{
    ui->lblMessage->clear();
}
