#include "../../../../../include/gameStates/level/gameObjects/staticObjects/MirrorGroup.h"
#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Robbo.h"

MirrorGroup::MirrorGroup(std::vector<Mirror*>* mirrors)
{
    this->mirrors = *mirrors;
}

void MirrorGroup::TeleportToNext(Robbo* robbo, int mirrorId, Direction out)
{
    //TODO iterate through mirrors and find next possible
    //TODO if no possible mirrors, then return to current mirror
}