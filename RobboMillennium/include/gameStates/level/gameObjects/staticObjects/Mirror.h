#pragma once
#include "../StaticObject.h"

class Robbo;
class MirrorGroup;

class Mirror : public StaticObject
{
public:
    Mirror(Coordinates position, Level* level, MirrorGroup* group, int id);
    void Enter(Robbo* robbo, Direction out);
    bool Exit(Robbo* robbo, Direction out);

private:
    MirrorGroup* connectedMirrors;
    //every group of mirrors contains teleports with different id
    int id;
};