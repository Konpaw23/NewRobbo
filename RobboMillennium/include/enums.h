#pragma once

enum GameStateName
{
    MENU,
    LEVEL,
    EXIT,
};

enum TextureName
{
    MENU_TLO,
    PRZYCISK_GRA,
    PRZYCISK_GRA_AKTYWNY,
    PRZYCISK_WYJSCIE,
    PRZYCISK_WYJSCIE_AKTYWNY,
    NULL_TEXTURE,

    LEVEL_FLOOR,
    LEVEL_ROBBO,
    LEVEL_WALL,
    LEVEL_CHEST,
    LEVEL_SCREW,

    LEVEL_PANEL,
};

enum GameObjectName
{
    WALL,
    DOOR,
    OBSTACLE,
    MIRROR,
    SHIP,

    CHEST,
    BOMB,

    LASER,

    SCREW,
    KEY,
    AMMO,

    ROBBO,

    NULL_OBJECT,
};

enum RobboAction
{
    GO_LEFT,
    GO_RIGHT,
    GO_UP,
    GO_DOWN,

    NOTHING,
};

enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
};