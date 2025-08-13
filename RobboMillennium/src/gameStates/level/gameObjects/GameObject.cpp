#include "../../../../include/gameStates/level/gameObjects/GameObject.h"
#include "../../../../include/gameStates/level/Level.h"

GameObject::GameObject(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant, Level* level) :
    objectName(objectName), position(position), explosion_resistant(explosion_resistant), projectile_resistant(projectile_resistant), level(level)
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

void GameObject::Destroy()
{
    //TODO here should be called function that summons smoke
    //TODO there will be 7 stages of explode for now
    //TODO make sure if in original game there are 7 explode stages
    this->level->RemoveObject(this);
}