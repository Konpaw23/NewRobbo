#include "../include/Window.h"

Window::Window(const std::string& title, int width, int height)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    m_window = SDL_CreateWindow(title.c_str(),
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width,
                              height,
                              SDL_WINDOW_SHOWN);

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    AddAllTextures();

    m_font = TTF_OpenFont("assets/textures/fonts/Pixellettersfull-BnJ5.ttf", 128);
    if(!m_font)
    {
        std::cerr << "font opening error: " << TTF_GetError() << std::endl;
    }

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

void Window::Write(const char *text, int size)
{
    this->Write(text, {0,0}, size);
}

void Window::Write(const std::string &text, int size)
{
    this->Write(text.c_str(), {0,0}, size);
}

void Window::Write(const char* text, Coordinates position, int size)
{
    this->Write(text, position, size, SDL_Color(255,255,255));
}

void Window::Write(const std::string& text, Coordinates position, int size)
{
    this->Write(text.c_str(), position, size);
}

void Window::Write(const char *text, Coordinates position, int size, SDL_Color color)
{
    if(text[0] == '\0')
        return;
    SDL_Surface* surface = TTF_RenderText_Solid(this->m_font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    SDL_Rect rect = {position.x, position.y, surface->w * size / surface->h, size};

    SDL_RenderCopy(m_renderer, texture, nullptr, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Window::Write(const std::string &text, Coordinates position, int size, SDL_Color color)
{
    this->Write(text.c_str(), position, size, color);
}

void Window::PutTexture(TextureName name, int x, int y, int width, int height)
{
    SDL_Rect destRect = {x, y, width, height};
    SDL_RenderCopy(m_renderer, this->m_textures[name], nullptr, &destRect);
}

void Window::PutTexture(TextureName name, Coordinates position, Coordinates size)
{
    this->PutTexture(name, position.x, position.y, size.x, size.y);
}

void Window::PutTexture(TextureName name, int x, int y)
{
    Coordinates size = this->TextureSize(name);
    this->PutTexture(name, x, y, size.x, size.y);
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
    if(surface == nullptr)
    {
        std::cerr << "Failed to load texture from \"" << path << "\" path\n";
        return;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->m_renderer, surface);
    free(surface);
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
    std::string t_dir = assets_dir + "textures/";

    struct TexturePaths
    {
        TextureName name;
        std::string path;
    };

    TexturePaths paths[] =
    {
        {MENU_TLO, "menu/menu.bmp"},
        {PRZYCISK_GRA, "menu/przyciskGra.bmp"},
        {PRZYCISK_GRA_AKTYWNY, "menu/przyciskGraAktywny.bmp"},
        {PRZYCISK_WYJSCIE, "menu/przyciskWyjscie.bmp"},
        {PRZYCISK_WYJSCIE_AKTYWNY, "menu/przyciskWyjscieAktywny.bmp"},
        {BLUE_PLANET_BUTTON, "menu/bluePlanetButton.bmp"},
        {BLUE_PLANET_BUTTON_ACTIVE, "menu/bluePlanetButtonActive.bmp"},
        {RED_PLANET_BUTTON, "menu/redPlanetButton.bmp"},
        {RED_PLANET_BUTTON_ACTIVE, "menu/redPlanetButtonActive.bmp"},

        {LEVEL_FLOOR, "level/pole.bmp"},
        {LEVEL_ROBBO, "level/robbo.bmp"},
        {LEVEL_BUSH, "level/bush.bmp"},
        {LEVEL_WALL, "level/sciana.bmp"},
        {LEVEL_SPIKES, "level/spikes.bmp"},
        {LEVEL_DOOR, "level/door.bmp"},
        {LEVEL_MIRROR, "level/mirror.bmp"},
        {LEVEL_CHEST, "level/skrzynia.bmp"},
        {LEVEL_PUSH, "level/push.bmp"},
        {LEVEL_BOMB, "level/bomb.bmp"},
        {LEVEL_SURPRISE, "level/surprise.bmp"},
        {LEVEL_SCREW, "level/screw.bmp"},
        {LEVEL_KEY, "level/key.bmp"},
        {LEVEL_AMMO, "level/ammo.bmp"},
        {LEVEL_BULLET, "level/bullet.bmp"},
        {LEVEL_BLASTER, "level/blaster.bmp"},
        {LEVEL_LIFE, "level/life.bmp"},
        {LEVEL_STOP, "level/stop.bmp"},

        {LEVEL_SMOKE01, "level/smoke/01.bmp"},
        {LEVEL_SMOKE02, "level/smoke/02.bmp"},
        {LEVEL_SMOKE03, "level/smoke/03.bmp"},
        {LEVEL_SMOKE04, "level/smoke/04.bmp"},
        {LEVEL_SMOKE05, "level/smoke/05.bmp"},
        {LEVEL_SMOKE06, "level/smoke/06.bmp"},
        {LEVEL_SMOKE07, "level/smoke/07.bmp"},

        {LEVEL_MAGNET_UP, "level/magnet/up.bmp"},
        {LEVEL_MAGNET_DOWN, "level/magnet/down.bmp"},
        {LEVEL_MAGNET_LEFT, "level/magnet/left.bmp"},
        {LEVEL_MAGNET_RIGHT, "level/magnet/right.bmp"},

        {LEVEL_LASER_SHOOTER_UP, "level/laser/shooterU.bmp"},
        {LEVEL_LASER_SHOOTER_DOWN, "level/laser/shooterD.bmp"},
        {LEVEL_LASER_SHOOTER_LEFT, "level/laser/shooterL.bmp"},
        {LEVEL_LASER_SHOOTER_RIGHT, "level/laser/shooterR.bmp"},

        {LEVEL_LASER_HEAD_UP, "level/laser/laserHeadUp.bmp"},
        {LEVEL_LASER_HEAD_DOWN, "level/laser/laserHeadDown.bmp"},
        {LEVEL_LASER_HEAD_LEFT, "level/laser/laserHeadLeft.bmp"},
        {LEVEL_LASER_HEAD_RIGHT, "level/laser/laserHeadRight.bmp"},

        {LEVEL_LASER_BODY_VERTICAL, "level/laser/laserBodyVertical.bmp"},
        {LEVEL_LASER_BODY_HORIZONTAL, "level/laser/laserBodyHorizontal.bmp"},

        {LEVEL_CANNON_UP, "level/cannon/up.bmp"},
        {LEVEL_CANNON_DOWN, "level/cannon/down.bmp"},
        {LEVEL_CANNON_LEFT, "level/cannon/left.bmp"},
        {LEVEL_CANNON_RIGHT, "level/cannon/right.bmp"},

        {LEVEL_MOVING_CANNON, "level/movingCannon.bmp"},

        {LEVEL_BLASTER_CANNON_UP, "level/blasterCannon/up.bmp"},
        {LEVEL_BLASTER_CANNON_DOWN, "level/blasterCannon/down.bmp"},
        {LEVEL_BLASTER_CANNON_LEFT, "level/blasterCannon/left.bmp"},
        {LEVEL_BLASTER_CANNON_RIGHT, "level/blasterCannon/right.bmp"},

        {LEVEL_SHIP_CLOSED, "level/ship/closed.bmp"},
        {LEVEL_SHIP_OPEN, "level/ship/open.bmp"},

        {LEVEL_GOLDEN_SEAHORSE_UP, "level/goldenSeahorse/goldenSeahorseUp.bmp"},
        {LEVEL_GOLDEN_SEAHORSE_DOWN, "level/goldenSeahorse/goldenSeahorseDown.bmp"},
        {LEVEL_GOLDEN_SEAHORSE_LEFT, "level/goldenSeahorse/goldenSeahorseLeft.bmp"},
        {LEVEL_GOLDEN_SEAHORSE_RIGHT, "level/goldenSeahorse/goldenSeahorseRight.bmp"},

        {LEVEL_PURPLE_SEAHORSE_UP, "level/purpleSeahorse/purpleSeahorseUp.bmp"},
        {LEVEL_PURPLE_SEAHORSE_DOWN, "level/purpleSeahorse/purpleSeahorseDown.bmp"},
        {LEVEL_PURPLE_SEAHORSE_LEFT, "level/purpleSeahorse/purpleSeahorseLeft.bmp"},
        {LEVEL_PURPLE_SEAHORSE_RIGHT, "level/purpleSeahorse/purpleSeahorseRight.bmp"},

        {LEVEL_COOKIE_MONSTER_LEFT, "level/cookieMonster/left.bmp"},
        {LEVEL_COOKIE_MONSTER_RIGHT, "level/cookieMonster/right.bmp"},

        {LEVEL_EYE, "level/eye.bmp"},

        {LEVEL_SNAKE, "level/snake.bmp"},

        {LEVEL_PANEL, "level/panel.bmp"},
    };

    for(const auto& p : paths)
    {
        AddTexture(p.name, t_dir + p.path);
    }
}