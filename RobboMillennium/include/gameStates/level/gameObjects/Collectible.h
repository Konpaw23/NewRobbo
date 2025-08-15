#pragma once
#include "../../../basicProjectHeaders.h"
#include "StaticObject.h"
#include "activeObjects/Robbo.h"

class Collectible : virtual public StaticObject
{
public:
    Collectible();
    virtual void PickUp(Robbo* other);
};