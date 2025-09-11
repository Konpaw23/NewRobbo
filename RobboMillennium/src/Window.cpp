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
    AddTexture(LEVEL_DOOR, "../assets/textures/level/door.bmp");
    AddTexture(LEVEL_MIRROR, "../assets/textures/level/mirror.bmp");
    AddTexture(LEVEL_CHEST, "../assets/textures/level/skrzynia.bmp");
    AddTexture(LEVEL_BOMB, "../assets/textures/level/bomb.bmp");
    AddTexture(LEVEL_SURPRISE, "../assets/textures/level/surprise.bmp");
    AddTexture(LEVEL_SCREW, "../assets/textures/level/screw.bmp");
    AddTexture(LEVEL_KEY, "../assets/textures/level/key.bmp");
    AddTexture(LEVEL_AMMO, "../assets/textures/level/ammo.bmp");
    AddTexture(LEVEL_LIFE, "../assets/textures/level/life.bmp");
    AddTexture(LEVEL_PANEL, "../assets/textures/level/panel.bmp");
    AddTexture(LEVEL_BULLET, "../assets/textures/level/bullet.bmp");
    AddTexture(LEVEL_BUSH, "../assets/textures/level/bush.bmp");
    AddTexture(LEVEL_SMOKE01, "../assets/textures/level/smoke/01.bmp");
    AddTexture(LEVEL_SMOKE02, "../assets/textures/level/smoke/02.bmp");
    AddTexture(LEVEL_SMOKE03, "../assets/textures/level/smoke/03.bmp");
    AddTexture(LEVEL_SMOKE04, "../assets/textures/level/smoke/04.bmp");
    AddTexture(LEVEL_SMOKE05, "../assets/textures/level/smoke/05.bmp");
    AddTexture(LEVEL_SMOKE06, "../assets/textures/level/smoke/06.bmp");
    AddTexture(LEVEL_SMOKE07, "../assets/textures/level/smoke/07.bmp");
    AddTexture(LEVEL_LASER_SHOOTER_DOWN, "../assets/textures/level/laser/shooterD.bmp");
    AddTexture(LEVEL_LASER_SHOOTER_UP, "../assets/textures/level/laser/shooterU.bmp");
    AddTexture(LEVEL_LASER_SHOOTER_LEFT, "../assets/textures/level/laser/shooterL.bmp");
    AddTexture(LEVEL_LASER_SHOOTER_RIGHT, "../assets/textures/level/laser/shooterR.bmp");
    AddTexture(LEVEL_LASER_HEAD_DOWN, "../assets/textures/level/laser/laserHeadDown.bmp");
    AddTexture(LEVEL_LASER_HEAD_UP, "../assets/textures/level/laser/laserHeadUp.bmp");
    AddTexture(LEVEL_LASER_HEAD_LEFT, "../assets/textures/level/laser/laserHeadLeft.bmp");
    AddTexture(LEVEL_LASER_HEAD_RIGHT, "../assets/textures/level/laser/laserHeadRight.bmp");
    AddTexture(LEVEL_LASER_BODY_VERTICAL, "../assets/textures/level/laser/laserBodyVertical.bmp");
    AddTexture(LEVEL_LASER_BODY_HORIZONTAL, "../assets/textures/level/laser/laserBodyHorizontal.bmp");
    AddTexture(LEVEL_CANNON_UP, "../assets/textures/level/cannon/up.bmp");
    AddTexture(LEVEL_CANNON_DOWN, "../assets/textures/level/cannon/down.bmp");
    AddTexture(LEVEL_CANNON_LEFT, "../assets/textures/level/cannon/left.bmp");
    AddTexture(LEVEL_CANNON_RIGHT, "../assets/textures/level/cannon/right.bmp");
    AddTexture(LEVEL_SHIP_CLOSED, "../assets/textures/level/ship/closed.bmp");
    AddTexture(LEVEL_SHIP_OPEN, "../assets/textures/level/ship/open.bmp");
    AddTexture(LEVEL_MAGNET_LEFT, "../assets/textures/level/magnet/left.bmp");
    AddTexture(LEVEL_MAGNET_RIGHT, "../assets/textures/level/magnet/right.bmp");
    AddTexture(LEVEL_MAGNET_UP, "../assets/textures/level/magnet/up.bmp");
    AddTexture(LEVEL_MAGNET_DOWN, "../assets/textures/level/magnet/down.bmp");
    AddTexture(LEVEL_GOLDEN_SEAHORSE_UP, "../assets/textures/level/goldenSeahorse/goldenSeahorseUp.bmp");
    AddTexture(LEVEL_GOLDEN_SEAHORSE_DOWN, "../assets/textures/level/goldenSeahorse/goldenSeahorseDown.bmp");
    AddTexture(LEVEL_GOLDEN_SEAHORSE_LEFT, "../assets/textures/level/goldenSeahorse/goldenSeahorseLeft.bmp");
    AddTexture(LEVEL_GOLDEN_SEAHORSE_RIGHT, "../assets/textures/level/goldenSeahorse/goldenSeahorseRight.bmp");
    AddTexture(LEVEL_PURPLE_SEAHORSE_UP, "../assets/textures/level/purpleSeahorse/purpleSeahorseUp.bmp");
    AddTexture(LEVEL_PURPLE_SEAHORSE_DOWN, "../assets/textures/level/purpleSeahorse/purpleSeahorseDown.bmp");
    AddTexture(LEVEL_PURPLE_SEAHORSE_LEFT, "../assets/textures/level/purpleSeahorse/purpleSeahorseLeft.bmp");
    AddTexture(LEVEL_PURPLE_SEAHORSE_RIGHT, "../assets/textures/level/purpleSeahorse/purpleSeahorseRight.bmp");
    AddTexture(LEVEL_COOKIE_MONSTER_LEFT, "../assets/textures/level/cookieMonster/left.bmp");
    AddTexture(LEVEL_COOKIE_MONSTER_RIGHT, "../assets/textures/level/cookieMonster/right.bmp");
    AddTexture(LEVEL_EYE, "../assets/textures/level/eye.bmp");
}