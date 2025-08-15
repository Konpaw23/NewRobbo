#pragma once
#include "../../../basicProjectHeaders.h"

/*
 * TODO in moving objects make two type of collisions:
 * in_collision and round_collision
 * (both will be activated after object moves??
 */

class Level;

class GameObject
{
public:
    GameObject(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant, Level* level);
    GameObject();
    virtual ~GameObject();
    GameObjectName GetObjectName();
    Coordinates GetPosition();
    bool IsProjectileResistant();
    bool IsExplosionResistant();
    virtual void Destroy();

protected:
    Coordinates position;

    //TODO maybe better to do it as struct?
    const bool explosion_resistant;
    const bool projectile_resistant;

    Level* level;

private:
    GameObjectName objectName;
};