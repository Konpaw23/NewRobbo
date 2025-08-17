#include "../../../../../include/gameStates/level/gameObjects/staticObjects/Mirror.h"
#include "../../../../../include/gameStates/level/gameObjects/staticObjects/MirrorGroup.h"
#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Robbo.h"
#include "../../../../../include/gameStates/level/Level.h"


//TODO is mirror explosion resistant?
Mirror::Mirror(Coordinates position, Level* level, MirrorGroup* group, int id) :
    GameObject(MIRROR, position, true, true, level), connectedMirrors(group)
{
    ;
}

void Mirror::Enter(Robbo *robbo, Direction out)
{
    this->level->HideRobbo();
    this->connectedMirrors->TeleportToNext(robbo, id, out);
}

bool Mirror::Exit(Robbo *robbo, Direction out)
{
    //TODO check if there is empty field next to mirror (start with Direction out, next right, left, and in other side)
    //TODO through robbo on empty field and return true
    //TODO return false when no empty field
}