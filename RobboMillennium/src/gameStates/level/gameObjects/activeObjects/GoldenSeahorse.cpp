#include "../../../../../include/gameStates/level/gameObjects/activeObjects/GoldenSeahorse.h"
#include "../../../../../include/gameStates/level/Level.h"

GoldenSeahorse::GoldenSeahorse(Coordinates position, Direction movementSide, Direction initialDirection, Level* level) :
        GameObject(GOLDEN_SEAHORSE, position, false, false, level), movementSide(movementSide), RotatingObject(initialDirection)
{
    ;
}

void GoldenSeahorse::Run()
{
    Direction holdingOnDirection = GetDirectionNextTo(this->rotation, this->movementSide);
    if(this->level->GetObjectNameFromPosition(this->position.GetNext(holdingOnDirection)) == NULL_OBJECT)
    {
        this->Move(holdingOnDirection);
        this->Rotate(this->movementSide);
    }
    else if(!Move(this->rotation))
    {
        this->Rotate(GetOppositeDirection(this->movementSide));
    }

    this->SearchAndKill();
}