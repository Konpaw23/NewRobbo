#include "../../../include/gameStates/level/LevelState.h"

LevelState::LevelState(Window* window) : GameState(window)
{
    this->m_window->Clear();
    this->state = LEVEL;
    this->levelNumber = 1;
    this->lives = 5;
    this->level = new Level(m_window, levelNumber, this);
    this->infoPanel = new InfoPanel(this->m_window, this->GetDataForInfoPanel());
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

InfoPanelData LevelState::GetDataForInfoPanel()
{
    return InfoPanelData
    (
        this->level->GetScrewsNumber(),
        this->level->GetAmmoNumber(),
        this->levelNumber,
        this->level->GetKeysNumber(),
        this->lives
    );
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
        if(e.key.type == SDL_KEYDOWN && e.key.repeat == 0)
        {
            switch(e.key.keysym.sym)
            {
                case SDLK_a:
                case SDLK_LEFT:
                    lastActionPressed = GO_LEFT;
                    break;
                case SDLK_d:
                case SDLK_RIGHT:
                    lastActionPressed = GO_RIGHT;
                    break;
                case SDLK_w:
                case SDLK_UP:
                    lastActionPressed = GO_UP;
                    break;
                case SDLK_s:
                case SDLK_DOWN:
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
        else
        {
            GameState::ProcessInput();
        }
    }

    const Uint8* keys = SDL_GetKeyboardState(nullptr);

    isPressedLeft = keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT];
    isPressedRight = keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT];
    isPressedUp = keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP];
    isPressedDown = keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN];
    isPressedSpace = keys[SDL_SCANCODE_SPACE];

//    SDL_Event e;
//    while (SDL_PollEvent(&e) != 0)
//    {
//        if(e.key.type == SDL_KEYDOWN && e.key.repeat == 0)
//        {
//            switch(e.key.keysym.sym)
//            {
//                case SDLK_a:
//                case SDLK_LEFT:
//                    isPressedLeft = true;
//                    lastActionPressed = GO_LEFT;
//                    break;
//                case SDLK_d:
//                case SDLK_RIGHT:
//                    isPressedRight = true;
//                    lastActionPressed = GO_RIGHT;
//                    break;
//                case SDLK_w:
//                case SDLK_UP:
//                    isPressedUp = true;
//                    lastActionPressed = GO_UP;
//                    break;
//                case SDLK_s:
//                case SDLK_DOWN:
//                    isPressedDown = true;
//                    lastActionPressed = GO_DOWN;
//                    break;
//                case SDLK_SPACE:
//                    isPressedSpace = true;
//                    break;
//                case SDLK_ESCAPE:
//                    lastActionPressed = SELF_DESTRUCT;
//                    break;
//                case SDLK_F10:
//                    state = MENU;
//                    m_running = false;
//                    break;
//            }
//        }
//        else if(e.key.type == SDL_KEYUP)
//        {
//            switch(e.key.keysym.sym)
//            {
//                case SDLK_a:
//                case SDLK_LEFT:
//                    isPressedLeft = false;
//                    break;
//                case SDLK_d:
//                case SDLK_RIGHT:
//                    isPressedRight = false;
//                    break;
//                case SDLK_w:
//                case SDLK_UP:
//                    isPressedUp = false;
//                    break;
//                case SDLK_s:
//                case SDLK_DOWN:
//                    isPressedDown = false;
//                    break;
//                case SDLK_SPACE:
//                    isPressedSpace = false;
//                    break;
//            }
//        }
//        else
//        {
//            GameState::ProcessInput();
//        }
//    }
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
    m_window->Clear();
    level->PutLevelPicture();
    PutInfoPanel();

    std::string pressInfo = "";
    if(isPressedSpace)
        pressInfo += "SHOOT ";
    if(isPressedRight)
        pressInfo += "R ";
    if(isPressedDown)
        pressInfo += "D ";
    if(isPressedUp)
        pressInfo += "U ";
    if(isPressedLeft)
        pressInfo += "L ";
    m_window->Write(pressInfo, 64);

    GameState::Render();

    m_window->Present();
}

void LevelState::PutInfoPanel()
{
    if(this->level->IsPlayerAlive())
        this->infoPanel->Update(this->GetDataForInfoPanel());
    this->infoPanel->Refresh();
}

void LevelState::SetPlayerMove()
{
    //TODO optimize
//    if(isPressedRight && (playerAction == GO_RIGHT || playerAction == SHOT_RIGHT))
//    {
//        playerAction = GO_RIGHT;
//    }
//    else if(isPressedLeft && (playerAction == GO_LEFT || playerAction == SHOT_LEFT))
//    {
//        playerAction = GO_LEFT;
//    }
//    else if(isPressedUp && (playerAction == GO_UP || playerAction == SHOT_UP))
//    {
//        playerAction = GO_UP;
//    }
//    else if(isPressedDown && (playerAction == GO_DOWN || playerAction == SHOT_DOWN))
//    {
//        playerAction = GO_DOWN;
//    }
//    else
    if(isPressedRight)
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