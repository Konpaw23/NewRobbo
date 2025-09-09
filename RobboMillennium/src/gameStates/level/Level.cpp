#include "../../../include/gameStates/level/Level.h"

Level::Level(Window* window, int levelNumber) : m_window(window), height(LEVEL_HEIGHT), width(LEVEL_WIDTH)
{
    screwsToCollect = 0;
    FieldsMemoryAlloc();
    LoadObjects(levelNumber);
    if(screwsToCollect <= 0 && ship != nullptr)
    {
        this->ship->OpenExit();
    }
}

Level::~Level()
{
    DeleteAllObjects();
    FieldsMemoryDealloc();
}

//TODO make buffer for activeObjects to delete and objects that will be added in next turn
//run every object in level in order
void Level::RunSequence()
{
    this->turnNumber++;

    //copy of vector because objects can be added after Object turn
    std::vector<ActiveObject*> initialVector(this->activeObjects);
    for(int i = 0; i < initialVector.size(); i++)
    {
        if(initialVector[i] != nullptr && initialVector[i]->IsActive())
        {
            initialVector[i]->Run();
        }
    }
    if(IsPlayerAlive())
    {
        player->Run();
    }

    this->DeleteDestroyedObjects();
}

int Level::GetTurnNumber()
{
    return this->turnNumber;
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
    return dynamic_cast<MovingObject*>(fields[y][x]);
}

GameObjectName Level::GetObjectNameFromPosition(int x, int y)
{
    if(x < 0 || y < 0 || x >= width || y >= height)
    {
        return WALL;
    }
    else
    {
        if(fields[y][x] == nullptr)
            return NULL_OBJECT;
        else
            return fields[y][x]->GetObjectName();
    }
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

void Level::CreateObject(GameObjectName name, int x, int y)
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
            fields[y][x] = new Wall(Coordinates(x,y), this);
            break;
        case DOOR:
            fields[y][x] = new Door(Coordinates(x,y), this);
            break;
        case CHEST:
            fields[y][x] = new Chest(Coordinates(x,y), this);
            break;
        case BOMB:
            fields[y][x] = new Bomb(Coordinates(x,y), this);
            AddToActiveObjects(dynamic_cast<ActiveObject*>(fields[y][x]));
            break;
        case SURPRISE:
            fields[y][x] = new Surprise(Coordinates(x,y), this);
            break;
        case SCREW:
            fields[y][x] = new Screw(Coordinates(x,y), this);
            break;
        case KEY:
            fields[y][x] = new Key(Coordinates(x,y), this);
            break;
        case AMMO:
            fields[y][x] = new Ammo(Coordinates(x,y), this);
            break;
        case BUSH:
            fields[y][x] = new Bush(Coordinates(x,y), this);
            break;
        case SHIP:
        {
            Ship* newShip = new Ship(Coordinates(x,y), this);
            fields[y][x] = newShip;
            if(this->ship == nullptr)
            {
                this->ship = newShip;
            }
            break;
        }
        case SMOKE:
            fields[y][x] = new Smoke(Coordinates(x,y), this);
            AddToActiveObjects(dynamic_cast<ActiveObject*>(fields[y][x]));
            break;
        case NULL_OBJECT:
        default:
            break;
    }
}

void Level::CreateObject(GameObjectName name, int x, int y, Direction rotation)
{
    switch(name)
    {
        case LASER_SHOOTER:
            fields[y][x] = new LaserShooter(Coordinates(x,y), rotation, this);
            AddToActiveObjects(dynamic_cast<ActiveObject*>(fields[y][x]));
            break;
        case LASER_HEAD:
            fields[y][x] = new LaserHead(Coordinates(x,y), rotation, this);
            AddToActiveObjects(dynamic_cast<ActiveObject*>(fields[y][x]));
            break;
        case CANNON:
            fields[y][x] = new Cannon(Coordinates(x,y), rotation, this);
            AddToActiveObjects(dynamic_cast<ActiveObject*>(fields[y][x]));
            break;
        default:
            this->CreateObject(name, x, y);
            break;
    }
}

void Level::CreateObject(GameObjectName name, int x, int y, Axis axis)
{
    switch(name)
    {
        case LASER_BODY:
            fields[y][x] = new LaserBody(Coordinates(x,y), axis, this);
            break;
        default:
            this->CreateObject(name, x, y);
            break;
    }
}

void Level::CreateGoldenSeahorse(Coordinates position, Direction movementSide, Direction initialDirection)
{
    GoldenSeahorse* newSeahorse = new GoldenSeahorse(position, movementSide, initialDirection, this);
    fields[position.y][position.x] = newSeahorse;
    this->AddToActiveObjects(newSeahorse);
}

void Level::CreateOpenShip(Coordinates position)
{
    Ship* newShip = new Ship(position, this);
    fields[position.y][position.x] = newShip;
    newShip->OpenExit();
}

void Level::SpawnBullet(Coordinates pos, Direction trajectory)
{
    if(pos.x < 0 || pos.y < 0 || pos.x >= width || pos.y >= height)
    {
        return;
    }
    if(GetObjectNameFromPosition(pos) == NULL_OBJECT)
    {
        fields[pos.y][pos.x] = new Bullet(pos, trajectory, this);
        AddToActiveObjects(dynamic_cast<ActiveObject*>(fields[pos.y][pos.x]));
    }
    else if(!fields[pos.y][pos.x]->IsProjectileResistant())
    {
        fields[pos.y][pos.x]->Destroy();
    }
}

void Level::SpawnSmoke(Coordinates pos)
{
    if(GetObjectNameFromPosition(pos) == NULL_OBJECT)
    {
        fields[pos.y][pos.x] = new Smoke(pos, this);
        AddToActiveObjects(dynamic_cast<ActiveObject*>(fields[pos.y][pos.x]));
    }
}

void Level::RemoveObject(GameObject *object)
{
    Coordinates pos = object->GetPosition();
    this->fields[pos.y][pos.x] = nullptr;

    //TODO optimize finding activeObject
    ActiveObject* active = dynamic_cast<ActiveObject*>(object);
    if(active != nullptr)
    {
        for(int i = 0; i < activeObjects.size(); i++)
        {
            if(activeObjects[i] == active)
            {
                activeObjects.erase(activeObjects.begin() + i);
                break;
            }
        }
    }
    //TODO it is unnecessary for every object (it works only for Robbo when checking if is active)
    //TODO other objects are deleted anyway in DeleteDestroyedObjects
    object->SetToDelete();
    objectsToDelete.push_back(object);
}

void Level::DeselectRobbo(Robbo *robbo)
{
    if(robbo == this->player)
    {
        this->player = nullptr;
    }
}

void Level::HideRobbo()
{
    Coordinates pos = this->player->GetPosition();
    if(this->player == this->fields[pos.y][pos.x])
    {
        this->fields[pos.y][pos.x] = nullptr;
        this->isRobboVisible = false;
    }
}

void Level::ShowRobbo()
{
    Coordinates pos = this->player->GetPosition();
    if(this->fields[pos.y][pos.x] == nullptr)
    {
        this->fields[pos.y][pos.x] = this->player;
        this->isRobboVisible = true;
    }
}

bool Level::IsRobboVisible()
{
    return this->isRobboVisible;
}

void Level::FinishLevel()
{
    this->HideRobbo();
    this->isLevelFinished = true;
}

bool Level::IsLevelFinished()
{
    return this->isLevelFinished;
}

//TODO I don't like this func I should make it works in other way
//returns nullptr when position out of range
Coordinates* Level::GetNextPosition(Coordinates current, Direction dir)
{
    Coordinates* new_pos = new Coordinates(current.GetNext(dir));
    if(new_pos->x < 0 || new_pos->x >= width || new_pos->y < 0 || new_pos->y >= height)
    {
        delete new_pos;
        return nullptr;
    }
    return new_pos;
}

std::vector<Coordinates> Level::GetFieldsAround(Coordinates position)
{
    std::vector<Coordinates> vector = {};
    //TODO this will be fixed when I fix GetNextPosition
    //TODO MAKARON
    Direction pattern[4] = {LEFT, RIGHT, UP, DOWN};
    Coordinates* buffer = nullptr;
    for(int i = 0; i < 4; i++)
    {
        buffer = this->GetNextPosition(position, pattern[i]);
        if(buffer != nullptr)
        {
            vector.push_back(*buffer);

            //if left or right from starting position is available, we check also up and down from this
            //so all 4 corners also will be included
            if(pattern[i] == LEFT || pattern[i] == RIGHT)
            {
                Coordinates cords = *buffer;
                delete buffer;
                buffer = this->GetNextPosition(cords, UP);
                if(buffer != nullptr)
                {
                    vector.push_back(*buffer);
                    delete buffer;
                }

                buffer = this->GetNextPosition(cords, DOWN);
                if(buffer != nullptr)
                {
                    vector.push_back(*buffer);
                    delete buffer;
                }
            }
            else
            {
                delete buffer;
            }
        }
    }
    return vector;
}

std::vector<Coordinates> Level::GetFieldsNextTo(Coordinates position)
{
    std::vector<Coordinates> fieldsFound = {};
    Direction directions[4] = {UP, DOWN, LEFT, RIGHT};
    Coordinates* buffer = nullptr;
    for(int i = 0; i < 4; i++)
    {
        buffer = this->GetNextPosition(position, directions[i]);
        if(buffer != nullptr)
        {
            fieldsFound.push_back(*buffer);
            delete buffer;
        }
    }
    return fieldsFound;
}

int Level::GetScrewsNumber()
{
    return screwsToCollect;
}

void Level::UpdateLevelPosition(double deltaTime)
{
    //TODO camera freezes when Robbo dies!!!
    if(this->player == nullptr)
    {
        return;
    }
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
    for(int i = 0 + levelRenderingUpperPosition/FIELD_SIZE; i <= levelRenderingUpperPosition/FIELD_SIZE + 10 && i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            PutEmptyField(j,i);
            GameObject* obj = fields[i][j];
            if(obj != nullptr)
            {
                GameObjectName objName = obj->GetObjectName();
                if(objName == SMOKE)
                {
                    Smoke* smoke = dynamic_cast<Smoke*>(obj);
                    PutObject(objName, j, i, smoke->GetDensity());
                    continue;
                }
                if(objName == SHIP)
                {
                    Ship* ship = dynamic_cast<Ship*>(obj);
                    PutObject(objName, j, i, ship->IsOpen());
                }

                RotatingObject* rotatingObject = dynamic_cast<RotatingObject*>(obj);
                if(rotatingObject != nullptr)
                {
                    PutObject(objName, j, i, rotatingObject->GetRotation());
                    continue;
                }

                if(objName == LASER_BODY)
                {
                    LaserBody* laser = dynamic_cast<LaserBody*>(obj);
                    PutObject(objName, j, i, laser->axis);
                    continue;
                }

                PutObject(objName, j, i);
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
        case DOOR:
            m_window->PutTexture(LEVEL_DOOR, renderPosition.x, renderPosition.y);
            break;
        case MIRROR:
            m_window->PutTexture(LEVEL_MIRROR, renderPosition.x, renderPosition.y);
            break;
        case CHEST:
            m_window->PutTexture(LEVEL_CHEST, renderPosition.x, renderPosition.y);
            break;
        case BOMB:
            m_window->PutTexture(LEVEL_BOMB, renderPosition.x, renderPosition.y);
            break;
        case SURPRISE:
            m_window->PutTexture(LEVEL_SURPRISE, renderPosition.x, renderPosition.y);
            break;
        case SCREW:
            m_window->PutTexture(LEVEL_SCREW, renderPosition.x, renderPosition.y);
            break;
        case KEY:
            m_window->PutTexture(LEVEL_KEY, renderPosition.x, renderPosition.y);
            break;
        case AMMO:
            m_window->PutTexture(LEVEL_AMMO, renderPosition.x, renderPosition.y);
            break;
        case BULLET:
            m_window->PutTexture(LEVEL_BULLET, renderPosition.x, renderPosition.y);
            break;
        case BUSH:
            m_window->PutTexture(LEVEL_BUSH, renderPosition.x, renderPosition.y);
            break;
    }
}

void Level::PutObject(GameObjectName name, int x, int y, int frame)
{
    Coordinates renderPosition = GetFieldPositionInPixelsOnScreen(x,y);

    switch(name)
    {
        //first textures with multiple frames
        case SMOKE:
            m_window->PutTexture( (TextureName)((int)LEVEL_SMOKE01 + frame) , renderPosition.x, renderPosition.y);
            break;
        case SHIP:
            if(frame == 0)
            {
                m_window->PutTexture(LEVEL_SHIP_CLOSED, renderPosition.x, renderPosition.y);
            }
            else
            {
                m_window->PutTexture(LEVEL_SHIP_OPEN, renderPosition.x, renderPosition.y);
            }
            break;
        default:
            this->PutObject(name, x, y);
            break;
    }
}

void Level::PutObject(GameObjectName name, int x, int y, Direction rotation)
{
    Coordinates renderPosition = GetFieldPositionInPixelsOnScreen(x,y);

    switch(name)
    {
        //first textures with multiple frames
        case LASER_SHOOTER:
            switch(rotation)
            {
                case UP:
                    m_window->PutTexture( LEVEL_LASER_SHOOTER_UP , renderPosition.x, renderPosition.y);
                    break;
                case DOWN:
                    m_window->PutTexture( LEVEL_LASER_SHOOTER_DOWN , renderPosition.x, renderPosition.y);
                    break;
                case LEFT:
                    m_window->PutTexture( LEVEL_LASER_SHOOTER_LEFT , renderPosition.x, renderPosition.y);
                    break;
                case RIGHT:
                    m_window->PutTexture( LEVEL_LASER_SHOOTER_RIGHT , renderPosition.x, renderPosition.y);
                    break;
            }
            break;
        case LASER_HEAD:
            switch(rotation)
            {
                case UP:
                    m_window->PutTexture( LEVEL_LASER_HEAD_UP , renderPosition.x, renderPosition.y);
                    break;
                case DOWN:
                    m_window->PutTexture( LEVEL_LASER_HEAD_DOWN , renderPosition.x, renderPosition.y);
                    break;
                case LEFT:
                    m_window->PutTexture( LEVEL_LASER_HEAD_LEFT , renderPosition.x, renderPosition.y);
                    break;
                case RIGHT:
                    m_window->PutTexture( LEVEL_LASER_HEAD_RIGHT , renderPosition.x, renderPosition.y);
                    break;
            }
            break;
        case LASER_BODY:
            switch(rotation)
            {
                case UP:
                case DOWN:
                    m_window->PutTexture( LEVEL_LASER_HEAD_DOWN , renderPosition.x, renderPosition.y);
                    break;
                case LEFT:
                case RIGHT:
                    m_window->PutTexture( LEVEL_LASER_HEAD_RIGHT , renderPosition.x, renderPosition.y);
                    break;
            }
            break;
        case CANNON:
            switch(rotation)
            {
                case UP:
                    m_window->PutTexture( LEVEL_CANNON_UP, renderPosition.x, renderPosition.y);
                    break;
                case DOWN:
                    m_window->PutTexture( LEVEL_CANNON_DOWN, renderPosition.x, renderPosition.y);
                    break;
                case LEFT:
                    m_window->PutTexture( LEVEL_CANNON_LEFT, renderPosition.x, renderPosition.y);
                    break;
                case RIGHT:
                    m_window->PutTexture( LEVEL_CANNON_RIGHT, renderPosition.x, renderPosition.y);
                    break;
            }
            break;
        case GOLDEN_SEAHORSE:
            switch(rotation)
            {
                case UP:
                    m_window->PutTexture(LEVEL_GOLDEN_SEAHORSE_UP, renderPosition.x, renderPosition.y);
                    break;
                case DOWN:
                    m_window->PutTexture(LEVEL_GOLDEN_SEAHORSE_DOWN, renderPosition.x, renderPosition.y);
                    break;
                case LEFT:
                    m_window->PutTexture(LEVEL_GOLDEN_SEAHORSE_LEFT, renderPosition.x, renderPosition.y);
                    break;
                case RIGHT:
                    m_window->PutTexture(LEVEL_GOLDEN_SEAHORSE_RIGHT, renderPosition.x, renderPosition.y);
                    break;
            }
            break;
        default:
            this->PutObject(name, x, y);
            break;
    }
}

void Level::PutObject(GameObjectName name, int x, int y, Axis axis)
{
    Coordinates renderPosition = GetFieldPositionInPixelsOnScreen(x,y);
    switch(name)
    {
        case LASER_BODY:
            switch(axis)
            {
                case VERTICAL:
                    m_window->PutTexture( LEVEL_LASER_BODY_VERTICAL , renderPosition.x, renderPosition.y);
                    break;
                case HORIZONTAL:
                    m_window->PutTexture( LEVEL_LASER_BODY_HORIZONTAL , renderPosition.x, renderPosition.y);
                    break;
            }
            break;
        default:
            this->PutObject(name, x, y);
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
        if(this->ship != nullptr)
        {
            this->ship->OpenExit();
        }
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

    this->activeObjects.clear();
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

    this->activeObjects.clear();
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

    std::unordered_map<int, MirrorGroup*> mirrorGroups = {};

    int x = 0, y = 0;
    char objectChar;
    while(levelData.get(objectChar))
    {
        switch(objectChar)
        {
            case 'W':
                CreateObject(WALL, x, y);
                break;
            case '|':
                CreateObject(DOOR, x, y);
                break;
            case '*':
                CreateObject(ROBBO, x, y);
                break;
            case '#':
                CreateObject(CHEST, x, y);
                break;
            case '@':
                CreateObject(BOMB, x, y);
                break;
            case '?':
                CreateObject(SURPRISE, x, y);
                break;
            case '$':
                CreateObject(SCREW, x, y);
                screwsToCollect++;
                break;
            case '=':
                CreateObject(KEY, x, y);
                break;
            case '!':
                CreateObject(AMMO, x, y);
                break;
            case '%':
                CreateObject(BUSH, x, y);
                break;
            case 'v':
                CreateObject(LASER_SHOOTER, x, y, DOWN);
                break;
            case '^':
                CreateObject(LASER_SHOOTER, x, y, UP);
                break;
            case '<':
                CreateObject(LASER_SHOOTER, x, y, LEFT);
                break;
            case '>':
                CreateObject(LASER_SHOOTER, x, y, RIGHT);
                break;
            case 'U':
                CreateObject(CANNON, x, y, UP);
                break;
            case 'D':
                CreateObject(CANNON, x, y, DOWN);
                break;
            case 'L':
                CreateObject(CANNON, x, y, LEFT);
                break;
            case 'R':
                CreateObject(CANNON, x, y, RIGHT);
                break;
            case '&':
                CreateObject(SHIP, x, y);
                break;
            //GOLDEN SEAHORSE
            case 'a':
                CreateGoldenSeahorse(Coordinates(x, y), LEFT, UP);
                break;
            case '\n':
                x = 0;
                y++;
                break;
            default:
                //Mirrors
                if(objectChar >= '0' && objectChar <= '9')
                {
                    int groupId = objectChar - '0';
                    if(!mirrorGroups.contains(groupId))
                    {
                        mirrorGroups.insert( {groupId, new MirrorGroup()} );
                    }
                    CreateMirror(x, y, mirrorGroups.at(groupId));
                    break;
                }
                else
                {
                    CreateObject(NULL_OBJECT, x, y);
                    break;
                }
        }
        if(objectChar != '\n')
        {
            x++;
        }
    }
}

void Level::AddToActiveObjects(ActiveObject *object)
{
    this->activeObjects.push_back(object);
}

void Level::RemoveFromActiveObjects(int index)
{
    if(index < this->activeObjects.size())
    {
        activeObjects.erase(activeObjects.begin() + index);
    }
}

void Level::DeleteDestroyedObjects()
{
    for(int i = 0; i < objectsToDelete.size(); i++)
    {
        if(!objectsToDelete[i]->IsActive())
            delete objectsToDelete[i];
    }
    objectsToDelete.clear();
}

void Level::CreateMirror(int x, int y, MirrorGroup* group)
{
    fields[y][x] = new Mirror(Coordinates(x,y), this, group);
}