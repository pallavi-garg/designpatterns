#include <cstddef>
#include <string>
#include <iostream>
#include "DomainObject/include/domainObject.h"
#include "DomainObject/include/idManager.h"
#include "DomainObject/include/person.h"

using namespace std;

void printDetails(Person *person)
{
    cout<<"Details of Person with id = "<<person->getId()<<" are:"<<endl;
    cout<<"Name: "<<person->getName()<<endl;
    cout<<"Age: "<<person->getAge()<<endl<<endl;
}

void printDetails(Person &person)
{
    cout<<"Details of Person with id = "<<person.getId()<<" are:"<<endl;
    cout<<"Name: "<<person.getName()<<endl;
    cout<<"Age: "<<person.getAge()<<endl<<endl;
}

int main()
{
    Person *person1 = new Person("Pallavi", 29);
    Person *person2 = new Person("Chaitanya", 30);

    printDetails(person1);
    printDetails(person2);

    //call copy constructor
    Person person3 = *person2;
    printDetails(person3);

    //call copy constructor
    Person *person4 = new Person(*person2);
    printDetails(person4);

    Person person5 = Person("Pallavi", 29);
    printDetails(person5);

    ////call copy constructor
    Person person6 = person5;
    printDetails(person6);

    delete person1;
    delete person2;
    delete person4;

    return 0;
}