#include "../../../../../include/gameStates/level/gameObjects/collectibles/Life.h"
#include "../../../../../include/gameStates/level/Level.h"

Life::Life(Coordinates position, Level* level) : GameObject(LIFE, position, false, false, level)
{
    ;
}

void Life::PickUp(Robbo *other)
{
    this->level->AddLife();
    this->level->SetLifeAsTaken(this->position);
    Collectible::PickUp(other);
}