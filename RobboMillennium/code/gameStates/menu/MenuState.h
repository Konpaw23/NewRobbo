#pragma once
#include "../GameState.h"
#include "../../Button.h"
#include "../../basicProjectHeaders.h"

class MenuState : public GameState
{
public:
    MenuState(Window* window);
    ~MenuState();

private:
    Coordinates mousePosition;
    void ProcessInput() override;
    void Update() override;
    void Render() override;

    void AddButton(std::string buttonName, TextureName textureInactive, TextureName textureActive, Coordinates position);
    void AddAllButtons();
    void DeleteButtons();

    std::unordered_map<std::string, Button*> m_buttons;
};