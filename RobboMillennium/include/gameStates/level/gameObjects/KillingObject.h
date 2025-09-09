#pragma once
#include "GameObject.h"

class KillingObject : virtual public GameObject
{
public:
    KillingObject();

protected:
    void SearchAndKill();
};