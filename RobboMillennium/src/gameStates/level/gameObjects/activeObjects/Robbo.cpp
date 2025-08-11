#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Robbo.h"
#include "../../../../../include/gameStates/level/Level.h"

//TODO when two constructors from both ActiveObject and MovingObject called, redundance of data
Robbo::Robbo(Coordinates position, Level* level) : ActiveObject(ROBBO, position, false, false, level),
    MovingObject(ROBBO, position, false, false, level), GameObject(ROBBO, position, false, false)
{
    this->ammo = 0;
}

void Robbo::SetAction(RobboAction action)
{
    this->action = action;
}

bool Robbo::Move(Direction dir)
{
    if(!MovingObject::Move(dir))
    {
        //TODO powalone rzeczy sie tu dzieja
        Coordinates* dest = this->level->GetNextPosition(this->position, dir);
        if(dest != nullptr)
        {
            GameObject* object = level->GetObjectFromPosition(*dest);
            MovingObject* movingObject = dynamic_cast<MovingObject*>(object);
            if(movingObject != nullptr)
            {
                if(movingObject->Move(dir))
                {
                    //can use this function because movable object is moved already (inside if statement above)
                    MovingObject::Move(dir);
                    return true;
                }
            }
        }

        //screws
        GameObject* other = level->GetObjectFromPosition(*dest);
        Collectible* item = dynamic_cast<Collectible*>(other);
        if(item != nullptr)
        {
            item->PickUp(this);
            level->MoveObject(this, *dest);
            this->position = *dest;
            delete dest;
            return true;
        }
    }
    return false;
}

void Robbo::GiveScrew()
{
    this->level->DecreaseScrewsNumber();
}

void Robbo::AddAmmo()
{
    ammo+=9;
}

void Robbo::Shot(Direction dir)
{
    if(ammo > 0)
    {
        ammo--;
        level->SpawnBullet(position.GetNext(dir), dir);
    }
}

void Robbo::Run()
{
    switch(action)
    {
        case GO_LEFT:
            Move(LEFT);
            break;
        case GO_RIGHT:
            Move(RIGHT);
            break;
        case GO_UP:
            Move(UP);
            break;
        case GO_DOWN:
            Move(DOWN);
            break;
        case SHOT_LEFT:
            Shot(LEFT);
            break;
        case SHOT_RIGHT:
            Shot(RIGHT);
            break;
        case SHOT_UP:
            Shot(UP);
            break;
        case SHOT_DOWN:
            Shot(DOWN);
            break;
    }
}