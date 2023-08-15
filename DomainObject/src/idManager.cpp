#include "../include/idManager.h"
#include <functional>
#include <iostream>

IdManager *IdManager::instance = nullptr;

IdManager::IdManager()
{
}

IdManager::~IdManager()
{
}

void IdManager::deleteInstance()
{
    if(instance)
    {
        instance->nextId = 0;
        delete instance;
    }
}

IdManager* IdManager::getInstance()
{
    if(!IdManager::instance)
        IdManager::instance = new IdManager();
    return instance;
}

int IdManager::getNextId()
{
    int id = nextId;
    nextId++;
    return id;
}