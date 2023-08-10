#ifndef CACHE_NODE_H
#define CACHE_NODE_H

template <typename T, typename K>
class CacheNode
{
    public:
        K key;
        T *data;
        CacheNode<T, K> *prev = nullptr;
        CacheNode<T, K> *next = nullptr;
};

#endif