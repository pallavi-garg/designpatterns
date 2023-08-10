#include "../include/cache.h"
#include "../include/cacheNode.h"

template <class T, class K>
Cache<T,K>::Cache(int capacity)
{
    this->capacity = capacity;
    head = new CacheNode<T, K>();
    tail = new CacheNode<T, K>();
    head->next = tail;
    tail->prev = head;
}

template <class T, class K>
void Cache<T, K>::put(K key, T value)
{
    
}