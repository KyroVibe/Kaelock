#ifndef _BRATVA_ENTITYS
#define _BRATVA_ENTITYS

typedef unsigned int Entity;

class EntityManager {
private:
    static EntityManager _instance;

    EntityManager();
    ~EntityManager();

    Entity* _entityArr;

public:
    static const EntityManager* getInstance() {
        _instance = EntityManager();
        return &_instance;
    }
};

#endif
