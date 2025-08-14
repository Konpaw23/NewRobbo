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
    LEVEL_BUSH,
    LEVEL_WALL,
    LEVEL_CHEST,
    LEVEL_SCREW,
    LEVEL_AMMO,
    LEVEL_BULLET,
    LEVEL_SMOKE01,
    LEVEL_SMOKE02,
    LEVEL_SMOKE03,
    LEVEL_SMOKE04,
    LEVEL_SMOKE05,
    LEVEL_SMOKE06,
    LEVEL_SMOKE07,

    LEVEL_PANEL,
};

enum GameObjectName
{
    WALL,
    DOOR,
    BUSH,
    MIRROR,
    SHIP,

    CHEST,
    BOMB,

    LASER,

    SCREW,
    KEY,
    AMMO,
    BULLET,
    SMOKE,

    ROBBO,

    NULL_OBJECT,
};

enum RobboAction
{
    GO_LEFT,
    GO_RIGHT,
    GO_UP,
    GO_DOWN,

    SHOT_LEFT,
    SHOT_RIGHT,
    SHOT_UP,
    SHOT_DOWN,

    NOTHING,
};

enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
};