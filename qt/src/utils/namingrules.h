#ifndef NAMINGRULES_H
#define NAMINGRULES_H

#include <QString>

class NamingRules
{
public:
    bool isValidUsername(const QString &username);
    bool isValidPassword(const QString &password);

    const QString &checkMessage() const;

private:
    QString m_message;
};


#endif // NAMINGRULES_H
