#include "gameStates/menu/PlanetChoiceMenu.h"

PlanetChoiceMenu::PlanetChoiceMenu(Window* window) : GameState(window), mousePosition(0,0)
{
    this->state = PLANET_MENU;

    this->m_window->Clear();

    AddAllButtons();
}

void PlanetChoiceMenu::ProcessInput()
{
    SDL_Event e;
    SDL_GetMouseState(&this->mousePosition.x, &this->mousePosition.y);
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.button.button == SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN)
        {
            if(m_buttons["Blue"]->IsHovered())
                state = BLUE_PLANET_LEVELS;
            else if(m_buttons["Red"]->IsHovered())
                state = RED_PLANET_LEVELS;
            else if(m_buttons["Wyjscie"]->IsHovered())
                state = MENU;
        }
        else
            GameState::ProcessInput();
    }
}

void PlanetChoiceMenu::Update()
{
    for(auto& pair : m_buttons)
    {
        pair.second->HandleMouseMovement(mousePosition);
    }

    if(state == MENU || state == BLUE_PLANET_LEVELS || state == RED_PLANET_LEVELS)
    {
        m_running = false;
    }
}

void PlanetChoiceMenu::Render()
{
    this->m_window->PutTexture(MENU_TLO, 0, 0);

    for(auto& pair : m_buttons)
    {
        pair.second->PutTexture();
    }
    GameState::Render();

    this->m_window->Present();
}

void PlanetChoiceMenu::AddButton(std::string buttonName, TextureName textureInactive, TextureName textureActive, Coordinates position)
{
    Coordinates size = m_window->TextureSize(textureInactive);
    m_buttons[buttonName] = new Button(m_window, position, size, textureInactive, textureActive);
}

void PlanetChoiceMenu::AddAllButtons()
{
    Coordinates scr_size = this->m_window->GetScreenSize();

    //Coordinates position = Coordinates((scr_size.x - m_window->TextureSize(BLUE_PLANET_BUTTON).x) / 2, scr_size.y/10.8);
    Coordinates position = Coordinates((GAME_WIDTH - m_window->TextureSize(BLUE_PLANET_BUTTON).x) / 2, 100);
    AddButton("Blue", BLUE_PLANET_BUTTON, BLUE_PLANET_BUTTON_ACTIVE, position);

    //position = Coordinates((scr_size.x - m_window->TextureSize(RED_PLANET_BUTTON).x) / 2, scr_size.y/2.7);
    position = Coordinates((GAME_WIDTH - m_window->TextureSize(RED_PLANET_BUTTON).x) / 2, 400);
    AddButton("Red", RED_PLANET_BUTTON, RED_PLANET_BUTTON_ACTIVE, position);

    //position = Coordinates((scr_size.x - m_window->TextureSize(PRZYCISK_WYJSCIE).x) / 2, scr_size.y/1.54);
    position = Coordinates((GAME_WIDTH - m_window->TextureSize(PRZYCISK_WYJSCIE).x) / 2, 700);
    AddButton("Wyjscie", PRZYCISK_WYJSCIE, PRZYCISK_WYJSCIE_AKTYWNY, position);
}

void PlanetChoiceMenu::DeleteButtons()
{
    for(auto& pair : m_buttons)
    {
        delete pair.second;
    }
    m_buttons.clear();
}

PlanetChoiceMenu::~PlanetChoiceMenu()
{
    this->DeleteButtons();
}