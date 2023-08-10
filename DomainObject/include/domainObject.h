#ifndef DOMAIN_OBJECT_H
#define DOMAIN_OBJECT_H

#include "idManager.h"

class DomainObject
{
private:
    const int id = IdManager::getInstance()->getNextId();
public:
    int getId()
    {
        return id;
    }
};

#endif