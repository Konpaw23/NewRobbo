#include "code/gameStates/GameState.h"
#include "code/gameStates/menu/MenuState.h"
#include "code/gameStates/level/LevelState.h"

#include "code/basicProjectHeaders.h"

int main(int argc, char* argv[])
{
    //creates window where entire game will be printed
    Window* window = new Window("Robbo Millennium", SCREEN_WIDTH, SCREEN_HEIGHT);

    //declares gamestate that points current state of game
    GameState* state = new MenuState(window);

    //game states loop
    while(1)
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
            case LEVEL:
                state = new LevelState(window);
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