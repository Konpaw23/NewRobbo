#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Robbo.h"
#include "../../../../../include/gameStates/level/Level.h"
#include "../../../../../include/gameStates/level/gameObjects/staticObjects/Door.h"

//TODO when two constructors from both ActiveObject and MovingObject called, redundance of data
Robbo::Robbo(Coordinates position, Level* level) : GameObject(ROBBO, position, false, false, level)
{
    this->keys = 0;
    this->ammo = 0;
    this->shootDelay = 0;
}

void Robbo::SetAction(RobboAction action)
{
    this->action = action;
}

bool Robbo::Move(Direction dir)
{
    Coordinates initPos = position;

    if(!MovingObject::Move(dir))
    {
        std::optional<Coordinates> next_cords = this->level->GetNextPosition(this->position, dir);
        if(next_cords.has_value())
        {
            GameObject* other = level->GetObjectFromPosition(*next_cords);
            MovingObject* movingObject = dynamic_cast<MovingObject*>(other);
            if(movingObject != nullptr && movingObject->canBeMovedByRobbo)
            {
                if(movingObject->GetObjectName() == SHIP)
                {
                    Ship* ship = dynamic_cast<Ship*>(other);
                    if(ship->IsOpen())
                    {
                        this->level->FinishLevel();
                        return true;
                    }
                }
                if(movingObject->Move(dir))
                {
                    //can use this function because movable object is moved already (inside if statement above)
                    MovingObject::Move(dir);
                    return true;
                }
            }

            //screws & keys
            Collectible* item = dynamic_cast<Collectible*>(other);
            if(item != nullptr)
            {
                item->PickUp(this);
                level->MoveObject(this, *next_cords);
                this->position = *next_cords;
                return true;
            }

            Door* door = dynamic_cast<Door*>(other);
            if(door != nullptr && HasKey())
            {
                door->Open(this);
                return true;
            }

            Mirror* mirror = dynamic_cast<Mirror*>(other);
            if(mirror != nullptr)
            {
                mirror->Enter(this, dir);
                return true;
            }

            Push* push = dynamic_cast<Push*>(other);
            if(push != nullptr)
            {
                push->PushPush(dir);
            }

            Spikes* spikes = dynamic_cast<Spikes*>(other);
            if(spikes != nullptr)
            {
                this->Destroy();
            }
        }
    }

    if(initPos != this->position)
    {
        std::vector<Coordinates> fields = this->level->GetFieldsNextTo(this->position);
        for(int i = 0; i < fields.size(); i++)
        {
            GameObject* obj = this->level->GetObjectFromPosition(fields[i]);
            KillingObject* killingObject = dynamic_cast<KillingObject*>(obj);
            if(killingObject != nullptr)
            {
                killingObject->Touch(this);
            }
        }
    }

    return false;
}

void Robbo::Teleport(Coordinates newPosition)
{
    //Robbo should be teleported only if he is hidden (after entering mirror)
    if(!level->IsRobboVisible())
    {
        this->position = newPosition;
        this->level->ShowRobbo();
    }
}

void Robbo::GiveScrew()
{
    this->level->DecreaseScrewsNumber();
}

void Robbo::GiveKey()
{
    this->keys++;
}

int Robbo::GetKeysNumber()
{
    return this->keys;
}

int Robbo::GetAmmoNumber()
{
    return this->ammo;
}

bool Robbo::HasKey()
{
    if(keys > 0)
        return true;
    else
        return false;
}

void Robbo::UseKey()
{
    if(HasKey())
    {
        keys--;
    }
}

void Robbo::AddAmmo()
{
    ammo+=9;
}

void Robbo::Shot(Direction dir)
{
    if(ammo > 0 && shootDelay == 0 && !level->IsLevelStopped())
    {
        ammo--;
        shootDelay += 3;
        level->SpawnBullet(position.GetNext(dir), dir);
    }
}

void Robbo::Run()
{
    if(shootDelay > 0)
    {
        shootDelay--;
    }
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
        case SELF_DESTRUCT:
            this->Destroy();
            break;
    }
}

void Robbo::Destroy()
{
    this->level->DeselectRobbo(this);
    GameObject::Destroy();
}