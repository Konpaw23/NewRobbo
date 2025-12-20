#include "structs.h"
#include "Coordinates.h"
#include "defines.h"
#include "Window.h"

class InfoPanel
{
public:
    InfoPanel(Window* window, InfoPanelData data);

    void Update(InfoPanelData newData);
    void Refresh();
private:
    Window* window;

    InfoPanelData data;
    Coordinates position;
    Coordinates size;
};