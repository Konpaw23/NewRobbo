#include "../../../../../include/gameStates/level/gameObjects/activeObjects/PurpleSeahorse.h"
#include "../../../../../include/gameStates/level/Level.h"

PurpleSeahorse::PurpleSeahorse(Coordinates position, Direction initialDirection, Level* level) :
        GameObject(PURPLE_SEAHORSE, position, false, false, level), movementAxis(GetAxis(initialDirection)), RotatingObject(initialDirection)
{
    ;
}

PurpleSeahorse::PurpleSeahorse(Coordinates position, Direction initialDirection, int initialMovePause, Level* level) :
        movePause(initialMovePause), GameObject(PURPLE_SEAHORSE, position, false, false, level), movementAxis(GetAxis(initialDirection)), RotatingObject(initialDirection)
{
    ;
}

void PurpleSeahorse::Run()
{
    if(movePause > 0)
    {
        movePause--;
    }
    else if(!Move(this->rotation))
    {
        this->RotateToOpposite();
        movePause++;
    }

    KillingObject::Run();
}