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
    Direction possibleFields[4] = {};
    switch(out)
    {
        case LEFT:
            possibleFields[0] = LEFT;
            possibleFields[1] = UP;
            possibleFields[2] = DOWN;
            possibleFields[3] = RIGHT;
            break;
        case RIGHT:
            possibleFields[0] = RIGHT;
            possibleFields[1] = DOWN;
            possibleFields[2] = UP;
            possibleFields[3] = LEFT;
            break;
        case UP:
            possibleFields[0] = UP;
            possibleFields[1] = RIGHT;
            possibleFields[2] = LEFT;
            possibleFields[3] = DOWN;
            break;
        case DOWN:
            possibleFields[0] = DOWN;
            possibleFields[1] = LEFT;
            possibleFields[2] = RIGHT;
            possibleFields[3] = UP;
            break;
    }

    for(int i = 0; i < 4; i++)
    {
        Coordinates* outPosition = this->level->GetNextPosition(this->position, possibleFields[i]);
        if(outPosition != nullptr)
        {
            if(this->level->GetObjectFromPosition(*outPosition) == nullptr)
            {
                robbo->Teleport(*outPosition);
                delete outPosition;
                return true;
            }
            delete outPosition;
        }
    }
    return false;
}