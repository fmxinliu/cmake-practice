#include "namingrules.h"
#include <QRegularExpression>
#include <QRegExp>

bool NamingRules::isValidUsername(const QString &username)
{
    // 检查是否为空
    if (username.isEmpty()) {
        m_message = QObject::tr("Username is empty");
        return false;
    }

    // 检查是否全为空白字符
    if (username.isEmpty()) {
        m_message = QObject::tr("Username is all white characters");
        return false;
    }

    // 检查是否以空格开头
    if (username.startsWith(' ')) {
        m_message = QObject::tr("Username start with white character");
        return false;
    }

    // 检查是否以空格结尾
    if (username.endsWith(' ')) {
        m_message = QObject::tr("Username end with white character");
        return false;
    }

    // 只允许字母、数字、下划线和空格
    QRegularExpression regex("^[a-zA-Z0-9_ ]+$");
    if (!regex.match(username).hasMatch()) {
        m_message = QObject::tr("Username contains not allow character");
        return false;
    }

    m_message.clear();
    return true;
}

const int PASSWORD_LENGTH_MIN = 3;
const int PASSWORD_LENGTH_MAX = 10;

bool NamingRules::isValidPassword(const QString &password)
{
    // 密码长度限制
    if (password.length() < PASSWORD_LENGTH_MIN || password.length() > PASSWORD_LENGTH_MAX)
    {
        m_message = QString(QObject::tr("Password length must be between %1-%2 \ncharacters")).arg(PASSWORD_LENGTH_MIN).arg(PASSWORD_LENGTH_MAX);
        return false;
    }

    // 必须包含字母、数字
    bool isValid = false;
    if (password.contains(QRegExp("[0-9]{1,}")) && password.contains(QRegExp("[a-zA-Z]{1,}")))
    {
        isValid = true;
        m_message.clear();
    }
    else
    {
        m_message = QObject::tr("Password must contain letter(s) and digit(s)");
    }

    return isValid;
}

const QString &NamingRules::checkMessage() const
{
    return m_message;
}
