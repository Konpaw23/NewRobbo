#include "gameStates/GameState.h"
#include "gameStates/menu/MenuState.h"
#include "gameStates/menu/PlanetChoiceMenu.h"
#include "gameStates/level/LevelState.h"

#include "basicProjectHeaders.h"

int main(int argc, char* argv[])
{
    //creates window where entire game will be printed
    Window* window = new Window("Robbo Millennium");

    //declares gamestate that points current state of game
    GameState* state = new MenuState(window);

    srand(time(NULL));

    //game states loop
    while(true)
    {
        if(state == nullptr)
            break;
        state->Run();
        GameStateName currentState = state->GetState();
        delete state;
        switch(currentState)
        {
            case MENU:
                state = new MenuState(window);
                break;
            case PLANET_MENU:
                state = new PlanetChoiceMenu(window);
                break;
            case BLUE_PLANET_LEVELS:
                state = new LevelState(window, BLUE_PLANET_LEVELS);
                break;
            case RED_PLANET_LEVELS:
                state = new LevelState(window, RED_PLANET_LEVELS);
                break;
            case TEST_LEVELS:
                state = new LevelState(window, TEST_LEVELS);
                break;
            case EXIT:
                state = nullptr;
                break;
        }
    }

    //deleting window at game closing
    delete window;

    return 0;
}