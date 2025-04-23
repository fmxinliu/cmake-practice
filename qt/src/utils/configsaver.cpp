#include "configsaver.h"
#include <QSettings>


ConfigSaver::ConfigSaver(const QString &path, const QString &section)
    : m_section(section)
    , m_filepath(path)
{
}

ConfigSaver::~ConfigSaver()
{
}

void ConfigSaver::save(const QString &key, const QString &value)
{
    QSettings iniAccess(m_filepath, QSettings::IniFormat);
    iniAccess.setValue(m_section + "/" + key, value);
}

QString ConfigSaver::load(const QString &key)
{
    QSettings iniAccess(m_filepath, QSettings::IniFormat);
    return iniAccess.value(m_section + "/" + key).toString();
}
