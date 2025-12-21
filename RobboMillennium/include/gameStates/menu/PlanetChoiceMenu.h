#include "gameStates/GameState.h"
#include "Button.h"

//TODO create base class for PlanetChoiceMenu and Menu (As Menu (base) and Menu -> MainMenu (child))
class PlanetChoiceMenu : public GameState
{
public:
    PlanetChoiceMenu(Window* window);
    ~PlanetChoiceMenu();

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