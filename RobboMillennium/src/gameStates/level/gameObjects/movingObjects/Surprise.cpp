#include "../../../../../include/gameStates/level/gameObjects/movingObjects/Surprise.h"
#include "../../../../../include/gameStates/level/Level.h"

Surprise::Surprise(Coordinates position, Level *level) : GameObject(SURPRISE, position, false, false, level),
                                                         MovingObject(true)
{
    ;
}

void Surprise::Destroy()
{
    this->Open();
}

void Surprise::Destroy(GameObjectName source)
{
    if(source != BOMB)
    {
        this->Open();
    }
    else
    {
        GameObject::Destroy();
    }
}

void Surprise::Open()
{
    this->level->RemoveObject(this);

    GameObjectName objectToCreate = NULL_OBJECT;
    int random = rand() % SURPRISES_SUM;
    if((random -= SURPRISE_SCREW) < 0)
    {
        objectToCreate = SCREW;
    }
    else if((random -= SURPRISE_KEY) < 0)
    {
        objectToCreate = KEY;
    }
    else if((random -= SURPRISE_SMOKE) < 0)
    {
        objectToCreate = SMOKE;
    }
    else if((random -= SURPRISE_SURPRISE) < 0)
    {
        objectToCreate = SURPRISE;
    }
    else if((random -= SURPRISE_AMMO) < 0)
    {
        objectToCreate = AMMO;
    }
    else if((random -= SURPRISE_BOMB) < 0)
    {
        objectToCreate = BOMB;
    }
    else if((random -= SURPRISE_EXIT) < 0)
    {
        this->level->CreateOpenShip(position);
        return;
    }
    else if((random -= SURPRISE_CANNON) < 0)
    {
        objectToCreate = ROTATING_CANNON;
    }
    else if((random -= SURPRISE_LIFE) < 0)
    {
        objectToCreate = LIFE;
    }
    else if((random -= SURPRISE_EYE) < 0)
    {
        objectToCreate = EYE;
    }
    else if((random -= SURPRISE_SUPER) < 0)
    {
        objectToCreate = LIFE;
        level->RemoveAllKillingObjects();
        level->RemoveAllDoors();
        level->ReplaceObjects(MAGNET, WALL);
    }
    this->level->CreateObject(objectToCreate, position.x, position.y);
}