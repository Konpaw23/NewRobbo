#pragma once
#include "GameObject.h"

class KillingObject : virtual public GameObject
{
public:
    KillingObject();
    virtual void Run();

protected:
    void SearchAndKill();
};