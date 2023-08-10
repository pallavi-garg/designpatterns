#ifndef CACHE_H
#define CACHE_H

#include <unordered_map>
#include "cacheNode.h"

template <class T, class K>
class Cache
{
    private:
        int capacity = 5;
        CacheNode<T, K> *head = nullptr;
        CacheNode<T, K> *tail = nullptr;
        std::unordered_map<K, CacheNode<T, K>*> data;

    public:
        Cache(int capacity);
        void put(K key, T object);
        T get(K key);
};

#endif