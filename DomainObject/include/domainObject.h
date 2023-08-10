#ifndef DOMAIN_OBJECT_H
#define DOMAIN_OBJECT_H

#include "idManager.h"

class DomainObject
{
private:
    int id;
public:
    int getId()
    {
        return id;
    }
    DomainObject()
    {
        id = IdManager::getInstance()->getNextId();
    }
};

#endif