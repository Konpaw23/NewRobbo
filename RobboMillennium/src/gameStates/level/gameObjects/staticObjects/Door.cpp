#include "../../../../../include/gameStates/level/gameObjects/staticObjects/Door.h"
#include "../../../../../include/gameStates/level/Level.h"

Door::Door(Coordinates position, Level *level) : GameObject(DOOR, position, false, true, level)
{
    ;
}

void Door::Open(Robbo* player)
{
    if(player->HasKey())
    {
        player->UseKey();
        this->level->RemoveObject(this);
    }
}