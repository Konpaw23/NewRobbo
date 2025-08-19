#pragma once
#include "../StaticObject.h"

class Robbo;
class MirrorGroup;

//TODO teleporting still can have problems when all ways blocked after entering mirror
class Mirror : public StaticObject
{
public:
    Mirror(Coordinates position, Level* level, MirrorGroup* group);
    ~Mirror();
    void Enter(Robbo* robbo, Direction out);
    bool Exit(Robbo* robbo, Direction out);

private:
    MirrorGroup* connectedMirrors;
    //every group of mirrors contains teleports with different id
    int id;
};