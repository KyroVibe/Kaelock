#ifndef _BRATVA_ENTITYS
#define _BRATVA_ENTITYS

typedef int Entity;

class EntityManager {
private:
    static EntityManager _instance;

    EntityManager();
    ~EntityManager();

public:
    static const EntityManager* getInstance() {
        _instance = EntityManager();
        return &_instance;
    }
};

#endif
