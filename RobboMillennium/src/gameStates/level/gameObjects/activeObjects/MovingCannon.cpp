#include "../../../../../include/gameStates/level/gameObjects/activeObjects/MovingCannon.h"
#include "../../../../../include/gameStates/level/Level.h"

MovingCannon::MovingCannon(Coordinates position, Level *level) : GameObject(MOVING_CANNON, position, false, true, level),
                                                                 MovingObject(true), Cannon(position, UP, level)
{
    ;
}

void MovingCannon::Run()
{
    if(move)
    {
        if(!this->Move(moveDirection))
        {
            this->moveDirection = GetOppositeDirection(this->moveDirection);
        }
    }
    else
    {
        Cannon::Run();
    }
    this->move = !this->move;
}