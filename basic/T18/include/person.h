#ifndef PERSON_H
#define PERSON_H

#include "dllexport.h"

class DLL_API Person
{
public:
    Person(int id=0);
    static const char *getClassName() { return s_className; }

    int getId() const { return m_id; }
    void setId(int id) { m_id = id; }

private:
    static const char *s_className;
    int m_id;
};

#endif // PERSON_H
