#include "usermanager.h"
#include "configsaver.h"
#include "common.h"

UserManager *UserManager::instance()
{
    static UserManager inst;
    return &inst;
}

UserManager::~UserManager()
{
    delete m_userconfig;
}

UserManager::UserManager(QObject *parent)
    : QObject(parent)
{
    m_userconfig = new ConfigSaver(Common::configFilepath(), "users");
    m_userconfig->save("admin", "admin");
    m_userconfig->save("user", "123");
}


bool UserManager::login(const QString &username, const QString &password)
{
    return m_userconfig->load(username) == password;
}

bool UserManager::addUser(const QString &username, const QString &password)
{
    if (hasUser(username))
        return false;

    m_userconfig->save(username, password);
    return true;
}

bool UserManager::modifyUser(const QString &username, const QString &password)
{
    if (!hasUser(username))
        return false;

    m_userconfig->save(username, password);
    return true;
}

bool UserManager::hasUser(const QString &username)
{
    return m_userconfig->hasKey(username);
}

bool UserManager::delUser(const QString &username)
{
    if (!hasUser(username))
        return false;

    return m_userconfig->delKey(username);
}
