#include "MenuState.h"

MenuState::MenuState(Window* window) : GameState(window), mousePosition(0, 0)
{
    this->state = MENU;

    this->m_window->Clear();

    AddAllButtons();
}

void MenuState::ProcessInput()
{
    SDL_Event e;
    SDL_GetMouseState(&this->mousePosition.x, &this->mousePosition.y);
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.button.button == SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN)
        {
            if(m_buttons["Gra"]->IsHovered())
                state = LEVEL;
            else if(m_buttons["Wyjscie"]->IsHovered())
                state = EXIT;
        }
        else
            GameState::ProcessInput();
    }
}

void MenuState::Update()
{
    for(auto& pair : m_buttons)
    {
        pair.second->HandleMouseMovement(mousePosition);
    }

    if(state == EXIT || state == LEVEL)
    {
        m_running = false;
    }
}

void MenuState::Render()
{
    this->m_window->PutTexture(MENU_TLO, 0, 0);

    for(auto& pair : m_buttons)
    {
        pair.second->PutTexture();
    }

    this->m_window->Present();
}

void MenuState::AddButton(std::string buttonName, TextureName textureInactive, TextureName textureActive, Coordinates position)
{
    Coordinates size = m_window->TextureSize(textureInactive);
    m_buttons[buttonName] = new Button(m_window, position, size, textureInactive, textureActive);
}

void MenuState::AddAllButtons()
{
    Coordinates position = Coordinates((SCREEN_WIDTH - m_window->TextureSize(PRZYCISK_GRA).x) / 2, 200);
    AddButton("Gra", PRZYCISK_GRA, PRZYCISK_GRA_AKTYWNY, position);

    position = Coordinates((SCREEN_WIDTH - m_window->TextureSize(PRZYCISK_WYJSCIE).x) / 2, 600);
    AddButton("Wyjscie", PRZYCISK_WYJSCIE, PRZYCISK_WYJSCIE_AKTYWNY, position);
}

void MenuState::DeleteButtons()
{
    for(auto& pair : m_buttons)
    {
        delete pair.second;
    }
    m_buttons.clear();
}

MenuState::~MenuState()
{
    this->DeleteButtons();
}