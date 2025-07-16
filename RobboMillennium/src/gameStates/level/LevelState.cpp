#include "../../../include/gameStates/level/LevelState.h"

LevelState::LevelState(Window* window) : GameState(window)
{
    this->m_window->Clear();
    this->state = LEVEL;
    this->levelNumber = 1;
    this->level = new Level(m_window, levelNumber);

    sequenceTime = clock();
}

LevelState::LevelState(Window* window, int level_number) : GameState(window)
{
    this->m_window->Clear();
    this->state = LEVEL;
    this->levelNumber = level_number;
    this->level = new Level(m_window, levelNumber);
}

void LevelState::ProcessInput()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        if(e.key.type == SDL_KEYDOWN)
        {
            switch(e.key.keysym.sym)
            {
                case SDLK_LEFT:
                    isPressedLeft = true;
                    lastActionPressed = GO_LEFT;
                    break;
                case SDLK_RIGHT:
                    isPressedRight = true;
                    lastActionPressed = GO_RIGHT;
                    break;
                case SDLK_UP:
                    isPressedUp = true;
                    lastActionPressed = GO_UP;
                    break;
                case SDLK_DOWN:
                    isPressedDown = true;
                    lastActionPressed = GO_DOWN;
                    break;
                case SDLK_F10:
                    state = MENU;
                    m_running = false;
            }
        }
        else if(e.key.type == SDL_KEYUP)
        {
            switch(e.key.keysym.sym)
            {
                case SDLK_LEFT:
                    isPressedLeft = false;
                    break;
                case SDLK_RIGHT:
                    isPressedRight = false;
                    break;
                case SDLK_UP:
                    isPressedUp = false;
                    break;
                case SDLK_DOWN:
                    isPressedDown = false;
                    break;
            }
        }
        else
        {
            GameState::ProcessInput();
        }
    }
}

void LevelState::Update()
{
    deltaSequenceTime = clock() - sequenceTime;
    if(deltaSequenceTime >= SEQUENCE_DURATION * CLOCKS_PER_SEC)
    {
        SetPlayerMove();
        if(level->IsPlayerAlive())
        {
            level->SetPlayerAction(playerAction);
            level->RunSequence();
        }
        else
        {
            delete level;
            level = new Level(m_window, levelNumber);
        }
        sequenceTime = clock();
    }
    level->UpdateLevelPosition(deltaTime);
}

void LevelState::Render()
{
    level->PutLevelPicture();
    m_window->Present();
}

void LevelState::SetPlayerMove()
{
    //TODO optimize
    if(isPressedRight && playerAction == GO_RIGHT)
    {
        playerAction = GO_RIGHT;
    }
    else if(isPressedLeft && playerAction == GO_LEFT)
    {
        playerAction = GO_LEFT;
    }
    else if(isPressedUp && playerAction == GO_UP)
    {
        playerAction = GO_UP;
    }
    else if(isPressedDown && playerAction == GO_DOWN)
    {
        playerAction = GO_DOWN;
    }
    else if(isPressedRight)
    {
        playerAction = GO_RIGHT;
    }
    else if(isPressedLeft)
    {
        playerAction = GO_LEFT;
    }
    else if(isPressedUp)
    {
        playerAction = GO_UP;
    }
    else if(isPressedDown)
    {
        playerAction = GO_DOWN;
    }
    else
    {
        playerAction = NOTHING;
    }
    if(lastActionPressed != NOTHING)
    {
        playerAction = lastActionPressed;
    }

    lastActionPressed = NOTHING;
}