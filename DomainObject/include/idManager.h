#ifndef ID_MANAGER
#define ID_MANAGER

class IdManager
{
    private:
        int nextId = 1;
        IdManager();
        ~IdManager();
        static IdManager *instance;

    public:

        static IdManager* getInstance();
        int getNextId();
        //copy contructor
        IdManager(const IdManager& other) = delete;
};

#endif