#include <string>
#include "../include/person.h"
#include "../include/domainObject.h"

#include <iostream>

Person::Person()
{
    this->name = "";
    this->age = -1;
}

Person::Person(std::string name, unsigned short age) 
{
    this->name = name;
    this->age = age;
}

//copy constructor
Person::Person(const Person& other) 
{
    std::cout<<"***Copy contructor called for Person***"<<std::endl;
    this->name = other.name;
    this->age = other.age;
}

std::string Person::getName()
{
    return this->name;
}

void Person::setName(std::string name)
{
    this->name = name;
}

unsigned short Person::getAge()
{
    return this->age;
}

void Person::setAge(unsigned short age)
{
    this->age = age;
}