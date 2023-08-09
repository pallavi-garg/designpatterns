#include "../include/domainObject.h"
#include "../include/idManager.h"

DomainObject::DomainObject()
{
    id = IdManager::getInstance()->getNextId();
}

DomainObject::DomainObject(const DomainObject&)
{
    //do not copy the same id of the object
    this->id = IdManager::getInstance()->getNextId();
}

int DomainObject::getId()
{
    return id;
}