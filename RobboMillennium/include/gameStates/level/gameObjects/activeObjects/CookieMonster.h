#pragma once
#include "PurpleSeahorse.h"

class CookieMonster : public PurpleSeahorse
{
public:
    CookieMonster(Coordinates position, Direction initialRotation, Level* level);

    void Run() override;

private:
    void Shoot();
};