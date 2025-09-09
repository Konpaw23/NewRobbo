#pragma once
#include "enums.h"

Direction GetOppositeDirection(Direction dir);
Direction GetDirectionToLeft(Direction dir);
Direction GetDirectionToRight(Direction dir);
Direction GetDirectionNextTo(Direction initial, Direction rotate);
Axis GetAxis(Direction dir);