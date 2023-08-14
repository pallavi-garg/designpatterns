#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>
#include "cache.h"
#include "cacheNode.h"

template <typename T, typename K>
class LruCache: public Cache<T, K>
{
    private:
        std::unordered_map<K, CacheNode<T, K>*> data;

        CacheNode<T, K> *head = nullptr;
        CacheNode<T, K> *tail = nullptr;
        int capacity = 5;

        void moveToFront(CacheNode<T, K> *node);
        void removeFromList(CacheNode<T, K> *node);
        CacheNode<T, K> *getCachedEntry(K key);
        void deleteLeastUsed();

    public:
        LruCache(int capacity);
        ~LruCache();
        void put(K key, T *value) override;
        T* get(K key) override;
        void erase(K key) override;
        void print() override;
        void clear() override;
};

#include "lruCache.tpp"

#endif