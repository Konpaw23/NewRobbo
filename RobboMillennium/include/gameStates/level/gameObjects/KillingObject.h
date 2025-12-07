#pragma once
#include "GameObject.h"
#include "activeObjects/Robbo.h"

class KillingObject : virtual public GameObject
{
public:
    KillingObject();
    virtual void Run();

    // call when robbo is next to object
    void Touch(Robbo* robbo);

protected:
    void SearchAndKill();
};