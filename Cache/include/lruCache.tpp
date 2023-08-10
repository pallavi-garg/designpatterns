#include <istream>

template <typename T, typename K>
LruCache<T,K>::LruCache(int capacity)
{
    this->capacity = capacity;
    head = new CacheNode<T, K>();
    tail = new CacheNode<T, K>();
    head->next = tail;
    tail->prev = head;
}

template <typename T, typename K>
T* LruCache<T, K>::get(K key)
{
    CacheNode<T, K> *cachedEntry = getCachedEntry(key);
    T* data = nullptr;
    if(cachedEntry and cachedEntry->key == key)
    {
        data = cachedEntry->data;
        removeFromList(cachedEntry);
        this->moveToFront(cachedEntry);
    }
    return data;
}

template <typename T, typename K>
void LruCache<T, K>::put(K key, T *value)
{
    CacheNode<T, K> *cachedEntry = getCachedEntry(key);
    if(cachedEntry)
    {
        cachedEntry->data = value;
        removeFromList(cachedEntry);
    }
    if(!cachedEntry)
    {
        if((int)this->data.size() >= this->capacity)
            deleteLeastUsed();
        
        cachedEntry = new CacheNode<T, K>();
        cachedEntry->data = value;
        cachedEntry->key = key;
        this->data[key] = cachedEntry;
    }
    this->moveToFront(cachedEntry);
}

template <typename T, typename K>
CacheNode<T, K> *LruCache<T, K>::getCachedEntry(K key)
{
    CacheNode<T, K> *cachedEntry = nullptr;
    for(auto it : this->data)
    {
        if(it.first == key)
        {
            cachedEntry = it.second;
            break;
        }
    }
    return cachedEntry;
}

template <typename T, typename K>
void LruCache<T, K>::deleteLeastUsed()
{
    if(this->tail and this->tail->prev != this->head)
    {
        CacheNode<T, K>* lruNode = this->tail->prev;
        this->tail->prev = lruNode->prev;
        this->tail->prev->next = this->tail;
        this->data.erase(lruNode->key);
        lruNode = nullptr;
        delete lruNode;
    }
}

template <typename T, typename K>
void LruCache<T, K>::removeFromList(CacheNode<T, K> *node)
{
    if(node)
    {
        if(node->prev)
            node->prev->next = node->next;
        if(node->next)
            node->next->prev = node->prev;
    }
}

template <typename T, typename K>
void LruCache<T, K>::moveToFront(CacheNode<T, K> *node)
{
    if(node and head)
    {
        node->next = head->next;
        if(head->next)
            head->next->prev = node;
        head->next = node;
    }
}

template <typename T, typename K>
void LruCache<T, K>:: erase(K key)
{
    CacheNode<T, K> *cachedEntry = getCachedEntry(key);
    if(cachedEntry)
    {
        removeFromList(cachedEntry);
        this->data.erase(key);
    }
}

template <typename T, typename K>
void LruCache<T, K>:: print()
{
    for(auto d : this->data)
    {
        std::cout<<" "<<d.first;
    }
    std::cout<<std::endl;
}
