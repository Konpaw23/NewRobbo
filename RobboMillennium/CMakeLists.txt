cmake_minimum_required(VERSION 3.27)
project(RobboMillennium)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "SDL2-devel-2.30.10-mingw/SDL2-2.30.10/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(RobboMillennium main.cpp
        src/gameStates/GameState.cpp
        include/gameStates/GameState.h
        src/Window.cpp
        include/Window.h
        src/gameStates/menu/MenuState.cpp
        include/gameStates/menu/MenuState.h
        src/Button.cpp
        include/Button.h
        src/Coordinates.cpp
        include/Coordinates.h
        include/defines.h
        src/gameStates/level/LevelState.cpp
        include/gameStates/level/LevelState.h
        include/enums.h
        main.cpp
        src/gameStates/level/Level.cpp
        include/gameStates/level/Level.h
        include/basicProjectHeaders.h
        src/gameStates/level/gameObjects/GameObject.cpp
        include/gameStates/level/gameObjects/GameObject.h
        src/gameStates/level/gameObjects/StaticObject.cpp
        include/gameStates/level/gameObjects/StaticObject.h
        src/gameStates/level/gameObjects/MovingObject.cpp
        include/gameStates/level/gameObjects/MovingObject.h
        src/gameStates/level/gameObjects/staticObjects/Wall.cpp
        include/gameStates/level/gameObjects/staticObjects/Wall.h
        src/gameStates/level/gameObjects/activeObjects/Robbo.cpp
        include/gameStates/level/gameObjects/activeObjects/Robbo.h
        include/gameStates/level/LevelHeaders.h
        src/gameStates/level/gameObjects/ActiveObject.cpp
        include/gameStates/level/gameObjects/ActiveObject.h
        src/gameStates/level/gameObjects/movingObjects/Chest.cpp
        include/gameStates/level/gameObjects/movingObjects/Chest.h
        src/gameStates/level/gameObjects/Collectible.cpp
        include/gameStates/level/gameObjects/Collectible.h
        src/gameStates/level/gameObjects/collectibles/Screw.cpp
        include/gameStates/level/gameObjects/collectibles/Screw.h
        src/gameStates/level/gameObjects/collectibles/Ammo.cpp
        include/gameStates/level/gameObjects/collectibles/Ammo.h
        src/gameStates/level/gameObjects/activeObjects/Bullet.cpp
        include/gameStates/level/gameObjects/activeObjects/Bullet.h
        src/gameStates/level/gameObjects/staticObjects/Bush.cpp
        include/gameStates/level/gameObjects/staticObjects/Bush.h
        src/gameStates/level/gameObjects/activeObjects/Smoke.cpp
        include/gameStates/level/gameObjects/activeObjects/Smoke.h
        src/gameStates/level/gameObjects/movingObjects/Bomb.cpp
        include/gameStates/level/gameObjects/movingObjects/Bomb.h
        src/gameStates/level/gameObjects/collectibles/Key.cpp
        include/gameStates/level/gameObjects/collectibles/Key.h
        src/gameStates/level/gameObjects/staticObjects/Door.cpp
        include/gameStates/level/gameObjects/staticObjects/Door.h
        src/gameStates/level/gameObjects/staticObjects/Mirror.cpp
        include/gameStates/level/gameObjects/staticObjects/Mirror.h
        src/gameStates/level/gameObjects/staticObjects/MirrorGroup.cpp
        include/gameStates/level/gameObjects/staticObjects/MirrorGroup.h
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/levels)
file(COPY ${CMAKE_SOURCE_DIR}/levels/ DESTINATION ${CMAKE_BINARY_DIR}/levels/)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
