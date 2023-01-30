#include "ecs/Entitys.hpp"

#include <stdio.h>

EntityManager::EntityManager() {
    const EntityManager* em = EntityManager::getInstance();
}

EntityManager::~EntityManager() {
    printf("EntityManager Destroyed");
}
