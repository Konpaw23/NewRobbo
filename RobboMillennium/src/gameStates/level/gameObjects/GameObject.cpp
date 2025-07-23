#include "../../../../include/gameStates/level/gameObjects/GameObject.h"

GameObject::GameObject(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant) :
    objectName(objectName), position(position), explosion_resistant(explosion_resistant), projectile_resistant(projectile_resistant)
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