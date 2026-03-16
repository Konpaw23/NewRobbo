#pragma once
#include "basicProjectHeaders.h"

class Window
{
public:
    Window(const std::string& title);
    ~Window();

    //returns size of texture named by string that is saved in memory
    Coordinates TextureSize(TextureName name);

    void Write(const char* text, int size);
    void Write(const std::string& text, int size);
    void Write(const char* text, Coordinates position, int size);
    void Write(const std::string& text, Coordinates position, int size);
    void Write(const char* text, Coordinates position, int size, SDL_Color color);
    void Write(const std::string& text, Coordinates position, int size, SDL_Color color);
    //puts texture on screen coords x, y
    void PutTexture(TextureName name, int x, int y, int width, int height);
    void PutTexture(TextureName name, Coordinates position, Coordinates size);
    void PutTexture(TextureName name, int x, int y);
    void Clear() const; //clears entire screen
    void Present() const; //updates screen (show all put textures ...)

    //adds texture to memory
    //name - unique name that will identify texture
    //path - path to file containing texture
    void AddTexture(TextureName name, const std::string path);
    void ClearTextures(); //deletes all textures from memory

    Coordinates GetScreenSize();
    double GetXScaling();
    double GetYScaling();

private:
    void AddAllTextures();
    const std::string assets_dir = "assets/";
    int screen_width;
    int screen_height;
    double x_scaling;
    double y_scaling;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    TTF_Font* m_font;
    std::unordered_map<TextureName, SDL_Texture*> m_textures;
};
