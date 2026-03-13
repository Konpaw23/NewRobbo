#include "../../../../../include/gameStates/level/gameObjects/staticObjects/Mirror.h"
#include "../../../../../include/gameStates/level/gameObjects/staticObjects/MirrorGroup.h"
#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Robbo.h"
#include "../../../../../include/gameStates/level/Level.h"


//TODO mirror can be destroyed by bomb!!! so I must make deleting mirror object during game safe
Mirror::Mirror(Coordinates position, Level* level, MirrorGroup* group) :
    GameObject(MIRROR, position, false, true, level), connectedMirrors(group)
{
    this->id = connectedMirrors->GetGroupSize();
    this->connectedMirrors->AddMirror(this);
}

Mirror::~Mirror()
{
    connectedMirrors->RemoveMirror(this->id);
    if(connectedMirrors->GetGroupSize() == 0)
    {
        delete connectedMirrors;
    }
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
            possibleFields[1] = DOWN;
            possibleFields[2] = UP;
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
        std::optional<Coordinates> outPosition = this->level->GetNextPosition(this->position, possibleFields[i]);
        if(outPosition.has_value() && this->level->GetObjectFromPosition(*outPosition) == nullptr)
        {
            robbo->Teleport(*outPosition);
            return true;
        }
    }
    return false;
}