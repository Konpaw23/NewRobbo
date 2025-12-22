#include "gameStates/level/gameObjects/collectibles/Stop.h"
#include "gameStates/level/Level.h"

Stop::Stop(Coordinates position, Level *level) : GameObject(STOP, position, false, true, level)
{
    ;
}

void Stop::PickUp(Robbo* other)
{
    this->level->ActivateStop(this->stopDuration);
    Collectible::PickUp(other);
}