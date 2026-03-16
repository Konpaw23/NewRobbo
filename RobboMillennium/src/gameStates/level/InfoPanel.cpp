#include "../../../include/gameStates/level/InfoPanel.h"

InfoPanel::InfoPanel(Window* window, InfoPanelData data) :
    position({GAME_WIDTH/2-LEVEL_WIDTH*FIELD_SIZE/2, 10*FIELD_SIZE}),
    size({LEVEL_WIDTH*FIELD_SIZE, GAME_HEIGHT - 10*FIELD_SIZE}),
    window(window),
    data(data)
{
    ;
}

void InfoPanel::Update(InfoPanelData newData)
{
    this->data = newData;
}

void InfoPanel::Refresh()
{
    double x_scaling = window->GetXScaling();
    double y_scaling = window->GetYScaling();
    int xPos = this->position.x;
    int xMargin = 40;
    int xField = 90;
    int xTextSize = 65;
    int yPos = this->position.y + (this->size.y - xField) / 2;
    int textSize = 96;
    int yPosText = this->position.y + (this->size.y - textSize) / 2;

    this->window->PutTexture(LEVEL_PANEL, this->position, this->size);

    //TODO LEVEL_SMOKE to change to planet icon and delete keys and robbo as number representation
    TextureName textures[5] = {LEVEL_SCREW, LEVEL_AMMO, LEVEL_SMOKE05, LEVEL_KEY, LEVEL_ROBBO};
    int numbers[5] = {this->data.screwsRemaining, this->data.ammo, this->data.planet, this->data.keys, this->data.health};
    for(int i = 0; i < 5; i++)
    {
        xPos += xMargin;
        this->window->Write(std::to_string(numbers[i]), {xPos, yPosText}, textSize);
        xPos += xTextSize;
        this->window->PutTexture(textures[i], {xPos, yPos}, {xField, xField});
        xPos += xField + xMargin;
    }
}
