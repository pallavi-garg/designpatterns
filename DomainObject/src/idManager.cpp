#include "../include/idManager.h"

IdManager *IdManager::instance = nullptr;

IdManager::IdManager()
{
}

IdManager::~IdManager()
{
    nextId = 0;
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