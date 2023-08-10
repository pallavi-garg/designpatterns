#ifndef CACHE_H
#define CACHE_H

#include <unordered_map>
#include "cacheNode.h"

template <typename T, typename K>
class Cache
{
    public:
        virtual void put(K key, T value) = 0;
        virtual T get(K key) = 0;
        virtual void erase(K key) = 0;
        virtual void print() = 0;
};

#endif