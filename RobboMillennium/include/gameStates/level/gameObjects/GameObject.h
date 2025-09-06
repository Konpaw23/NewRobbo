#pragma once
#include "../../../basicProjectHeaders.h"

/*
 * TODO in moving objects make two type of collisions:
 * in_collision and round_collision
 * (both will be activated after object moves??
 */

//TODO isActive may not be used in every objects, maybe only by Robbo cause Level checks if robbo is active
//TODO but it also may not be necessary for Robbo to have this field when it would be enough to check if Robbo is not deleted object

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
    bool IsActive();
    void SetToDelete();
    virtual void Destroy();
    virtual void Destroy(GameObjectName source);

protected:
    Coordinates position;

    //TODO maybe better to do it as struct?
    const bool explosion_resistant;
    const bool projectile_resistant;

    Level* level;

    bool isActive = true;

private:
    GameObjectName objectName;
};