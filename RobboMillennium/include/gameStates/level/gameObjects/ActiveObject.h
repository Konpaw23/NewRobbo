#pragma once
#include "../../../basicProjectHeaders.h"
#include "GameObject.h"

class ActiveObject : virtual public GameObject
{
public:
    ActiveObject();
    virtual void Run() = 0;
};