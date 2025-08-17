#include "../../../../../include/gameStates/level/gameObjects/staticObjects/TeleportGroup.h"

TeleportGroup::TeleportGroup(std::vector<Teleport*>* teleports)
{
    this->teleports = *teleports;
}