#ifndef CACHE_NODE_H
#define CACHE_NODE_H

template <class T, class K>
class CacheNode
{
    const K key;
    T *data;
    CacheNode<T, K> *prev = nullptr;
    CacheNode<T, K> *next = nullptr;
};

#endif