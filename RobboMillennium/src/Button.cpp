#include "../include/Button.h"

Button::Button(Window* window,Coordinates position, Coordinates size)
        : m_window(window), m_position(position), m_size(size),
        m_textureInactive(NULL_TEXTURE), m_textureActive(NULL_TEXTURE), m_isHovered(false)
{
    ;
}

Button::Button(Window* window, Coordinates position, Coordinates size, TextureName textureInactive, TextureName textureActive)
    : m_window(window), m_position(position), m_size(size),
    m_textureInactive(textureInactive), m_textureActive(textureActive), m_isHovered(false)
{
    ;
}

void Button::HandleMouseMovement(Coordinates mousePosition)
{
    int mouseX = mousePosition.x;
    int mouseY = mousePosition.y;
    if(mouseX >= m_position.x && mouseX <= m_position.x + m_size.x &&
        mouseY >= m_position.y && mouseY <= m_position.y + m_size.y)
    {
        this->m_isHovered = true;
    }
    else
        this->m_isHovered = false;
}

bool Button::IsHovered()
{
    return this->m_isHovered;
}

int Button::PutTexture()
{
    if(m_textureInactive == NULL_TEXTURE || m_textureActive == NULL_TEXTURE)
    {
        return 1;
    }
    if(m_isHovered)
    {
        m_window->PutTexture(m_textureActive, m_position.x, m_position.y);
    }
    else
    {
        m_window->PutTexture(m_textureInactive, m_position.x, m_position.y);
    }
    return 0;
}

Coordinates Button::GetPosition()
{
    return m_position;
}