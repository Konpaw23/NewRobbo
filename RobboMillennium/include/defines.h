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
#define SURPRISE_SCREW double(20)/100
#define SURPRISE_KEY double(20)/100
#define SURPRISE_SMOKE double(10)/100
#define SURPRISE_SURPRISE double(10)/100
#define SURPRISE_AMMO double(20)/100
#define SURPRISE_BOMB double(19)/100
#define SURPRISE_EXIT double(1)/100

#define SURPRISES_SUM SURPRISE_SCREW+SURPRISE_KEY+SURPRISE_SMOKE+SURPRISE_SURPRISE+SURPRISE_AMMO+SURPRISE_BOMB