#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = Q_NULLPTR);
    ~Login();

Q_SIGNALS:
    void login();
    void exit();

private Q_SLOTS:
    void onLogin();
    void onExit();
    void onEdit();
    void onRegister();
    void onForgetPassword();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
