#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Magnet.h"
#include "../../../../../include/gameStates/level/Level.h"

Magnet::Magnet(Coordinates position, Direction rotation, Level* level) : GameObject(MAGNET, position, false, false, level),
                                                                         RotatingObject(rotation)
{
    ;
}

void Magnet::Run()
{
    Coordinates positionChecking = this->position;
    GameObjectName otherName = NULL_OBJECT;
    bool firstField = true;
    while(true)
    {
        positionChecking = positionChecking.GetNext(this->rotation);
        otherName = this->level->GetObjectNameFromPosition(positionChecking);
        if(otherName == ROBBO)
        {
            Robbo* robbo = dynamic_cast<Robbo*>(this->level->GetObjectFromPosition(positionChecking));
            if(firstField)
            {
                robbo->Destroy();
            }
            this->AttractRobbo(robbo);
            break;
        }
        else if(otherName != NULL_OBJECT)
        {
            break;
        }
        firstField = false;
    }
}

void Magnet::AttractRobbo(Robbo *robbo)
{
    robbo->Move(robbo->GetPosition().GetDirectionTorwards(this->position));
    robbo->SetAction(NOTHING);
}