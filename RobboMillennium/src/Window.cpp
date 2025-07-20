#include "../include/Window.h"

Window::Window(const std::string& title, int width, int height)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    m_window = SDL_CreateWindow(title.c_str(),
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width,
                              height,
                              SDL_WINDOW_SHOWN);

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    AddAllTextures();

    //main color - black
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

    //TODO FULLSCREEN (not needed yet)
    //SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN);
}

Window::~Window()
{
    //delete all textures in memory
    this->ClearTextures();
    SDL_SetWindowFullscreen(m_window, 0);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

Coordinates Window::TextureSize(TextureName name)
{
    int w, h;
    SDL_QueryTexture(this->m_textures[name], nullptr, nullptr, &w, &h);
    return Coordinates(w, h);
}

void Window::PutTexture(TextureName name, int x, int y)
{
    Coordinates size = this->TextureSize(name);
    SDL_Rect destRect = {x, y, size.x, size.y};
    SDL_RenderCopy(m_renderer, this->m_textures[name], nullptr, &destRect);
}

void Window::Clear() const
{
    SDL_RenderClear(m_renderer);
}

void Window::Present() const
{
    SDL_RenderPresent(m_renderer);
}

void Window::AddTexture(TextureName name, const std::string path)
{
    SDL_Surface* surface = SDL_LoadBMP(path.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->m_renderer, surface);
    m_textures[name] = texture;
}

void Window::ClearTextures()
{
    for(auto& pair : m_textures)
    {
        SDL_DestroyTexture(pair.second);
    }
    m_textures.clear();
}

void Window::AddAllTextures()
{
    AddTexture(MENU_TLO, "../assets/textures/menu/menu.bmp");
    AddTexture(PRZYCISK_GRA, "../assets/textures/menu/przyciskGra.bmp");
    AddTexture(PRZYCISK_GRA_AKTYWNY, "../assets/textures/menu/przyciskGraAktywny.bmp");
    AddTexture(PRZYCISK_WYJSCIE, "../assets/textures/menu/przyciskWyjscie.bmp");
    AddTexture(PRZYCISK_WYJSCIE_AKTYWNY, "../assets/textures/menu/przyciskWyjscieAktywny.bmp");
    AddTexture(LEVEL_FLOOR, "../assets/textures/level/pole.bmp");
    AddTexture(LEVEL_ROBBO, "../assets/textures/level/robbo.bmp");
    AddTexture(LEVEL_WALL, "../assets/textures/level/sciana.bmp");
    AddTexture(LEVEL_CHEST, "../assets/textures/level/skrzynia.bmp");
    AddTexture(LEVEL_SCREW, "../assets/textures/level/screw.bmp");
    AddTexture(LEVEL_PANEL, "../assets/textures/level/panel.bmp");
}