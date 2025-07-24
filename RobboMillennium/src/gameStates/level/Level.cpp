#include "../../../include/gameStates/level/Level.h"

Level::Level(Window* window, int levelNumber) : m_window(window), height(LEVEL_HEIGHT), width(LEVEL_WIDTH)
{
    screwsToCollect = 0;
    FieldsMemoryAlloc();
    LoadObjects(levelNumber);
}

Level::~Level()
{
    DeleteAllObjects();
    FieldsMemoryDealloc();
}

//TODO
//run every object in level in order
void Level::RunSequence()
{
    player->Run();
}

bool Level::IsPlayerAlive()
{
    if(player != nullptr && player->IsActive())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Level::SetPlayerAction(RobboAction action)
{
    this->player->SetAction(action);
}

int Level::GetHeight()
{
    return height;
}

int Level::GetWidth()
{
    return width;
}

GameObject* Level::GetObjectFromPosition(int x, int y)
{
    if(x < 0 || y < 0 || x >= width || y >= height)
    {
        return nullptr;
    }
    return fields[y][x];
}
GameObject* Level::GetObjectFromPosition(Coordinates pos)
{
    return GetObjectFromPosition(pos.x, pos.y);
}

MovingObject* Level::GetMovingObjectFromPosition(int x, int y)
{
    if(typeid(fields[y][x]) == typeid(Chest))
    {
        return dynamic_cast<MovingObject*>(fields[y][x]);
    }
    else
    {
        return nullptr;
    }
}

GameObjectName Level::GetObjectNameFromPosition(int x, int y)
{
    if(fields[y][x] == nullptr)
        return NULL_OBJECT;
    else
        return fields[y][x]->GetObjectName();
}

GameObjectName Level::GetObjectNameFromPosition(Coordinates pos)
{
    return GetObjectNameFromPosition(pos.x, pos.y);
}

bool Level::IsObjectCollectible(int x, int y)
{
    GameObject* object = this->GetObjectFromPosition(x,y);
    if(dynamic_cast<Collectible*>(object) == nullptr)
        return false;
    else
        return true;
}
bool Level::IsObjectCollectible(Coordinates dest)
{
    return IsObjectCollectible(dest.x, dest.y);
}

void Level::MoveObject(GameObject *object, Coordinates dest)
{
    Coordinates current_pos = object->GetPosition();
    this->fields[current_pos.y][current_pos.x] = nullptr;
    this->fields[dest.y][dest.x] = object;
}

//TODO I don't like this func I should make it works in other way
//returns nullptr when position out of range
Coordinates* Level::GetNextPosition(Coordinates current, Direction dir)
{
    Coordinates* new_pos = new Coordinates(current.GetNext(dir));
    if(new_pos->x < 0 || new_pos->x >= width || new_pos->y < 0 || new_pos->y >= height)
    {
        return nullptr;
    }
    return new_pos;
}

int Level::GetScrewsNumber()
{
    return screwsToCollect;
}

void Level::UpdateLevelPosition(double deltaTime)
{
    if(moveLevelPositionVertically == 0)
    {
        if(levelRenderingUpperPosition > 0 && player->GetPosition().y - (levelRenderingUpperPosition/FIELD_SIZE) <= 1)
        {
            moveLevelPositionVertically = -1 * FIELD_SIZE * 3;
        }
        if(levelRenderingUpperPosition < (height - 10) * FIELD_SIZE && player->GetPosition().y - (levelRenderingUpperPosition/FIELD_SIZE) >= 8)
        {
            moveLevelPositionVertically = FIELD_SIZE * 3;
        }
    }

    double moveRange = deltaTime / CLOCKS_PER_SEC * (FIELD_SIZE / SEQUENCE_DURATION);
    if(moveLevelPositionVertically < 0)
    {
        if(moveRange > -1 * moveLevelPositionVertically)
        {
            levelRenderingUpperPosition -= moveLevelPositionVertically;
            levelRenderingUpperPosition = std::round(levelRenderingUpperPosition/FIELD_SIZE)*FIELD_SIZE;
            moveLevelPositionVertically = 0;
        }
        else
        {
            levelRenderingUpperPosition -= moveRange;
            moveLevelPositionVertically += moveRange;
        }

        if(levelRenderingUpperPosition < 0)
        {
            levelRenderingUpperPosition = 0;
            moveLevelPositionVertically = 0;
        }
    }
    else if(moveLevelPositionVertically > 0)
    {
        if(moveRange > moveLevelPositionVertically)
        {
            levelRenderingUpperPosition += moveLevelPositionVertically;
            levelRenderingUpperPosition = std::round(levelRenderingUpperPosition/FIELD_SIZE)*FIELD_SIZE;
            moveLevelPositionVertically = 0;
        }
        else
        {
            levelRenderingUpperPosition += moveRange;
            moveLevelPositionVertically -= moveRange;
        }
        if(levelRenderingUpperPosition > (height - 10) * FIELD_SIZE)
        {
            levelRenderingUpperPosition = (height - 10) * FIELD_SIZE;
            moveLevelPositionVertically = 0;
        }
    }
}

void Level::PutLevelPicture()
{
    for(int i = 0 + levelRenderingUpperPosition/FIELD_SIZE; i <= levelRenderingUpperPosition/FIELD_SIZE + 10 ; i++)
    {
        for(int j = 0; j < width; j++)
        {
            PutEmptyField(j,i);
            if(fields[i][j] != nullptr)
            {
                PutObject(fields[i][j]->GetObjectName(), j, i);
            }
        }
    }
}
void Level::PutEmptyField(int x, int y)
{
    Coordinates renderPosition = GetFieldPositionInPixelsOnScreen(x,y);
    m_window->PutTexture(LEVEL_FLOOR, renderPosition.x, renderPosition.y);
}
void Level::PutObject(GameObjectName name, int x, int y)
{
    Coordinates renderPosition = GetFieldPositionInPixelsOnScreen(x,y);

    switch(name)
    {
        case ROBBO:
            m_window->PutTexture(LEVEL_ROBBO, renderPosition.x, renderPosition.y);
            break;
        case WALL:
            m_window->PutTexture(LEVEL_WALL, renderPosition.x, renderPosition.y);
            break;
        case CHEST:
            m_window->PutTexture(LEVEL_CHEST, renderPosition.x, renderPosition.y);
            break;
        case SCREW:
            m_window->PutTexture(LEVEL_SCREW, renderPosition.x, renderPosition.y);
            break;
        case AMMO:
            m_window->PutTexture(LEVEL_AMMO, renderPosition.x, renderPosition.y);
            break;
    }
}

Coordinates Level::GetFieldPositionInPixelsOnScreen(int x, int y)
{
    return Coordinates((SCREEN_WIDTH - (FIELD_SIZE * this->width) )/2 + (x * FIELD_SIZE),
                       y * FIELD_SIZE - levelRenderingUpperPosition);
}

int Level::DecreaseScrewsNumber()
{
    this->screwsToCollect--;
    if(screwsToCollect <= 0)
    {
        screwsToCollect = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

void Level::FieldsMemoryAlloc()
{
    if(player != nullptr)
    {
        delete player;
    }

    if(fields != nullptr)
    {
        std::cout << "!!! Can't to allocate memory for level fields (already allocated) !!!" << std::endl;
        return;
    }

    fields = (GameObject***)malloc(height * sizeof(GameObject**));
    for(int i = 0; i < height; i++)
    {
        fields[i] = (GameObject**)malloc(width * sizeof(GameObject*));
        for(int j = 0; j < width; j++)
        {
            fields[i][j] = nullptr;
        }
    }
}

void Level::DeleteAllObjects()
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(fields[i][j] != nullptr)
                delete fields[i][j];
        }
    }
}

void Level::FieldsMemoryDealloc()
{
    if(fields == nullptr)
    {
        return;
    }

    for(int i = 0; i < height; i++)
    {
        free(fields[i]);
    }
    free(fields);
}

//here number of screws to collect is calculated
void Level::LoadObjects(int levelNumber)
{
    std::string fileName = "levels/level" + std::to_string(levelNumber) + ".txt";
    std::ifstream levelData(fileName);
    if(!levelData.is_open())
    {
        std::cout << "!!! Failed to open file: " << fileName << " !!!" << std::endl;
    }

    int x = 0, y = 0;
    char objectChar;
    while(levelData.get(objectChar))
    {
        switch(objectChar)
        {
            case 'W':
                AddObject(WALL, x, y);
                break;
            case '*':
                AddObject(ROBBO, x, y);
                break;
            case '#':
                AddObject(CHEST, x, y);
                break;
            case '$':
                AddObject(SCREW, x, y);
                screwsToCollect++;
                break;
            case '!':
                AddObject(AMMO, x, y);
                break;
            case '\n':
                x = 0;
                y++;
                break;
        }
        if(objectChar != '\n')
        {
            x++;
        }
    }
}

void Level::AddObject(GameObjectName name, int x, int y)
{
    switch(name)
    {
        case ROBBO:
            if(player == nullptr)
            {
                player = new Robbo(Coordinates(x,y), this);
                fields[y][x] = player;
            }
            break;
        case WALL:
            fields[y][x] = new Wall(Coordinates(x,y));
            break;
        case CHEST:
            fields[y][x] = new Chest(Coordinates(x,y), this);
            break;
        case SCREW:
            fields[y][x] = new Screw(Coordinates(x,y), this);
            break;
        case AMMO:
            fields[y][x] = new Ammo(Coordinates(x,y), this);
    }
}