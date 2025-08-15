#include "../../../../../include/gameStates/level/gameObjects/collectibles/Key.h"

Key::Key(Coordinates position, Level* level) : GameObject(KEY, position, false, true, level),
    Collectible(KEY, position, false, true, level)
{
    ;
}

void Key::PickUp(Robbo *other)
{
    other->GiveKey();
    Collectible::PickUp(other)
}