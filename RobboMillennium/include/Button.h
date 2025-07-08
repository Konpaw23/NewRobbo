#pragma once
#include "basicProjectHeaders.h"

class Button
{
public:
    Button(Window* window, Coordinates position, Coordinates size);
    Button(Window* window, Coordinates position, Coordinates size, TextureName textureInactive, TextureName textureActive);
    void HandleMouseMovement(Coordinates mousePosition);
    bool IsHovered();

    //put texture without presenting it
    //returns 1 if button has no textures in m_texture... variables
    int PutTexture();
    Coordinates GetPosition();
private:
    Coordinates m_position, m_size;
    bool m_isHovered;
    TextureName m_textureInactive;
    TextureName m_textureActive;
    Window* m_window;
};