#include "../../../../include/gameStates/level/gameObjects/GameObject.h"
#include "../../../../include/gameStates/level/Level.h"

GameObject::GameObject(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant, Level* level) :
    objectName(objectName), position(position), explosion_resistant(explosion_resistant), projectile_resistant(projectile_resistant), level(level)
{
    ;
}
GameObject::GameObject() : objectName(NULL_OBJECT), position(-1, -1), explosion_resistant(true), projectile_resistant(false), level(nullptr)
{
    ;
}
GameObject::~GameObject()
{
    ;
}

GameObjectName GameObject::GetObjectName()
{
    return objectName;
}

Coordinates GameObject::GetPosition()
{
    return position;
}

bool GameObject::IsProjectileResistant()
{
    return projectile_resistant;
}

bool GameObject::IsExplosionResistant()
{
    return explosion_resistant;
}

bool GameObject::IsActive()
{
    return isActive;
}

void GameObject::SetToDelete()
{
    this->isActive = false;
}

void GameObject::Destroy()
{
    if(isActive)
    //TODO make sure if in original game there are 7 explode stages
        this->level->RemoveObject(this);
        this->level->SpawnSmoke(this->position);
}

void GameObject::Destroy(GameObjectName source)
{
    this->Destroy();
}