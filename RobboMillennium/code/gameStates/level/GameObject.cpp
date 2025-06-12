#include "GameObject.h"

GameObject::GameObject(GameObjectName objectName, Coordinates position) : objectName(objectName), position(position)
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