#ifndef CONFIGSAVER_H
#define CONFIGSAVER_H

#include <QString>

class ConfigSaver
{
public:
    ConfigSaver(const QString &path, const QString &section);
    ~ConfigSaver();

    void save(const QString &key, const QString &value);
    QString load(const QString &key);

private:
    QString m_section;
    QString m_filepath;
};


#endif // CONFIGSAVER_H
