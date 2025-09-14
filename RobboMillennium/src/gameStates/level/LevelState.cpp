#include "../../../include/gameStates/level/LevelState.h"

LevelState::LevelState(Window* window) : GameState(window)
{
    this->m_window->Clear();
    this->state = LEVEL;
    this->levelNumber = 26;
    this->lives = 5;
    this->level = new Level(m_window, levelNumber, this);
    sequenceTime = clock();
}

LevelState::LevelState(Window* window, int level_number) : GameState(window)
{
    this->m_window->Clear();
    this->state = LEVEL;
    this->levelNumber = level_number;
    this->level = new Level(m_window, levelNumber, this);
}

void LevelState::AddLife()
{
    this->lives++;
}

void LevelState::SetLivesPositions(std::vector<Coordinates> positions)
{
    if(levelLivesPositions.empty())
    {
        this->levelLivesPositions = positions;
    }
}

bool LevelState::IsLiveAtPositionAvailable(Coordinates position)
{
    for(int i = 0; i < this->levelLivesPositions.size(); i++)
    {
        if(levelLivesPositions[i].x == position.x && levelLivesPositions[i].y == position.y)
        {
            return true;
        }
    }
    return false;
}

void LevelState::RemoveLiveAtPosition(Coordinates position)
{
    for(int i = 0; i < this->levelLivesPositions.size(); i++)
    {
        if(levelLivesPositions[i].x == position.x && levelLivesPositions[i].y == position.y)
        {
            this->levelLivesPositions.erase(levelLivesPositions.begin() + i);
            break;
        }
    }
}

bool LevelState::IsFirstLevelGame()
{
    return this->isFirstLevelGame;
}

void LevelState::ActionMoveToShoot()
{
    switch(playerAction)
    {
        case GO_LEFT:
            playerAction = SHOT_LEFT;
            break;
        case GO_RIGHT:
            playerAction = SHOT_RIGHT;
            break;
        case GO_UP:
            playerAction = SHOT_UP;
            break;
        case GO_DOWN:
            playerAction = SHOT_DOWN;
            break;
    }
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
                case SDLK_SPACE:
                    isPressedSpace = true;
                    break;
                case SDLK_ESCAPE:
                    lastActionPressed = SELF_DESTRUCT;
                    break;
                case SDLK_F10:
                    state = MENU;
                    m_running = false;
                    break;
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
                case SDLK_SPACE:
                    isPressedSpace = false;
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
        //TODO delay after level finish/death
        if(level->IsPlayerAlive())
        {
            if(level->IsLevelFinished())
            {
                //TODO next level only if exists!
                delete level;
                this->isFirstLevelGame = true;
                this->levelLivesPositions.clear();
                levelNumber++;
                level = new Level(m_window, levelNumber, this);
            }
            level->SetPlayerAction(playerAction);
            level->RunSequence();
        }
        else if(lives > 0)
        {
            this->isFirstLevelGame = false;
            lives--;
            //TODO reset level method
            delete level;
            level = new Level(m_window, levelNumber, this);
        }
        else
        {
            this->state = MENU;
            this->m_running = false;
        }
        sequenceTime = clock();
    }
    level->UpdateLevelPosition(deltaTime);
}

void LevelState::Render()
{
    level->PutLevelPicture();
    PutInfoPanel();
    m_window->Present();
}

void LevelState::PutInfoPanel()
{
    m_window->PutTexture(LEVEL_PANEL, SCREEN_WIDTH/2-LEVEL_WIDTH*FIELD_SIZE/2, 10*FIELD_SIZE);
}

void LevelState::SetPlayerMove()
{
    //TODO optimize
    if(isPressedRight && (playerAction == GO_RIGHT || playerAction == SHOT_RIGHT))
    {
        playerAction = GO_RIGHT;
    }
    else if(isPressedLeft && (playerAction == GO_LEFT || playerAction == SHOT_LEFT))
    {
        playerAction = GO_LEFT;
    }
    else if(isPressedUp && (playerAction == GO_UP || playerAction == SHOT_UP))
    {
        playerAction = GO_UP;
    }
    else if(isPressedDown && (playerAction == GO_DOWN || playerAction == SHOT_DOWN))
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

    //shooting
    if(playerAction != NOTHING && isPressedSpace)
    {
        ActionMoveToShoot();
    }

    lastActionPressed = NOTHING;
}