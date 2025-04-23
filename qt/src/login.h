#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class ConfigSaver;

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

private:
    Ui::Login *ui;
    ConfigSaver *m_userconfig;
};

#endif // LOGIN_H
