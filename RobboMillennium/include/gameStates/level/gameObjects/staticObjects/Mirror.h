#pragma once
#include "../StaticObject.h"
#include "../ActiveObject.h"

class Robbo;
class MirrorGroup;

//TODO teleporting still can have problems when all ways blocked after entering mirror
class Mirror : public StaticObject, public ActiveObject
{
public:
    Mirror(Coordinates position, Level* level, MirrorGroup* group);
    ~Mirror();
    void Enter(Robbo* robbo, Direction out);
    bool Exit(Robbo* robbo, Direction out);

    void Run() override;
    void Destroy() override;

private:
    MirrorGroup* connectedMirrors;

    Robbo* teleportingRobbo = nullptr;
    int ticksToTeleport = 0;
    int teleportingDelay = 5;
    Coordinates exitPosition = {0,0};
};