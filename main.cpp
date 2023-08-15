#include <cstddef>
#include <memory>
#include <string>
#include <iostream>
#include "DomainObject/include/domainObject.h"
#include "DomainObject/include/idManager.h"
#include "DomainObject/include/person.h"
#include "Cache/include/lruCache.h"
#include "Cache/include/cacheNode.h"

using namespace std;

void printDetails(std::shared_ptr<Person> person)
{
    cout<<"\n***Details of Person with id = "<<person->getId()<<" are:***"<<endl;
    cout<<"Name: "<<person->getName()<<endl;
    cout<<"Age: "<<person->getAge()<<endl<<endl;
}

void printDetails(Person &person)
{
    cout<<"\n***Details of Person with id = "<<person.getId()<<" are:***"<<endl;
    cout<<"Name: "<<person.getName()<<endl;
    cout<<"Age: "<<person.getAge()<<endl<<endl;
}

template class LruCache<std::shared_ptr<Person>, int>;

int main()
{
    std::unique_ptr<Cache<std::shared_ptr<Person>, int>> cache (new LruCache<std::shared_ptr<Person>, int>(3));

    std::shared_ptr<Person> person1 = std::shared_ptr<Person>(new Person("A", 29));
    cache->put(person1->getId(), person1);

    std::shared_ptr<Person> person2(new Person("B", 30));
    cache->put(person2->getId(), person2);

    std::shared_ptr<Person> person3 (new Person("C", 30));
    cache->put(person3->getId(), person3);

    cache->print();
    std::shared_ptr<Person> person4 (new Person("D", 30));
    cache->put(person4->getId(), person4);
    
    cache->print();
    
    cache->clear();
    cache->put(1, person1);
    cache->print();

    std::shared_ptr<Person> p = cache->get(1);
    cache->clear();
    printDetails(p);
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