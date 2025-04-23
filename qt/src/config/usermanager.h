#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QObject>

class ConfigSaver;

class UserManager : public QObject
{
    Q_OBJECT

public:
    static UserManager *instance();
    ~UserManager();

public Q_SLOTS:
    bool login(const QString &username, const QString &password);
    bool addUser(const QString &username, const QString &password);
    bool modifyUser(const QString &username, const QString &password);
    bool hasUser(const QString &username);

private:
    UserManager(QObject *parent=Q_NULLPTR);
    Q_DISABLE_COPY(UserManager)
    ConfigSaver *m_userconfig;
};

#endif // USERMANAGER_H
