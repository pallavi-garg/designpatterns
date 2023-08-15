#ifndef PERSON_H
#define PERSON_H

#include "domainObject.h"
#include <string>

class Person : public DomainObject
{
private:
    std::string name = "";
    unsigned short age = 0;

public:
    Person();
    ~Person();
    Person(std::string name, unsigned short age);
    Person(const Person&);
    std::string getName();
    unsigned short getAge();
    void setName(std::string name);
    void setAge(unsigned short age);
};

#endif