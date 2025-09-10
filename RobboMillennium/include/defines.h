#pragma once

//screen size where game will be printed
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

//number of fields in cols and rows at basic level
#define LEVEL_WIDTH 16
#define LEVEL_HEIGHT 31

//field size in pixels (horizontal & vertical)
#define FIELD_SIZE 90

//sequence duration in seconds - how fast will objects move
//TODO still not sure if speed like in original game
#define SEQUENCE_DURATION (1.0/10.0)

//surprise chances
#define SURPRISE_SCREW 20
#define SURPRISE_KEY 20
#define SURPRISE_SMOKE 10
#define SURPRISE_SURPRISE 10
#define SURPRISE_AMMO 20
#define SURPRISE_BOMB 10
#define SURPRISE_EXIT 1
#define SURPRISE_CANNON 9
#define SURPRISE_LIFE 10

#define SURPRISES_SUM (SURPRISE_SCREW+SURPRISE_KEY+SURPRISE_SMOKE+SURPRISE_SURPRISE+SURPRISE_AMMO+SURPRISE_BOMB+SURPRISE_EXIT+SURPRISE_CANNON+SURPRISE_LIFE)