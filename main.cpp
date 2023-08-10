#include <cstddef>
#include <string>
#include <iostream>
#include "DomainObject/include/domainObject.h"
#include "DomainObject/include/idManager.h"
#include "DomainObject/include/person.h"
#include "Cache/include/lruCache.h"
#include "Cache/include/cacheNode.h"

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

template class LruCache<Person, int>;

int main()
{
    Cache<Person*, int> *cache = new LruCache<Person*, int>(3);

    Person *person1 = new Person("A", 29);
    cache->put(person1->getId(), person1);

    Person *person2 = new Person("B", 30);
    cache->put(person2->getId(), person2);

    Person *person3 = new Person("C", 30);
    cache->put(person3->getId(), person3);

    cache->print();
    Person *person4 = new Person("D", 30);
    cache->put(person4->getId(), person4);
    
    cache->print();
    cache->put(1, person1);
    cache->print();
    cache->put(5, person1);
    cache->print();
    cache->erase(5);
    cache->print();


    /*
    //call copy constructor
    Person person3 = *person2;
    //cache->put(person3.getId(), &person3);
    printDetails(person3);

    //call copy constructor
    Person *person4 = new Person(*person2);
    //cache->put(person4->getId(), person4);
    printDetails(person4);

    Person person5 = Person("Pallavi", 29);
    printDetails(person5);

    ////call copy constructor
    Person person6 = person5;
    printDetails(person6);
    */

    return 0;
}