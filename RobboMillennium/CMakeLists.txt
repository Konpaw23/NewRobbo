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
        src/gameStates/level/GameObject.cpp
        include/gameStates/level/GameObject.h
        src/gameStates/level/GameObjects/StaticObject.cpp
        include/gameStates/level/GameObjects/StaticObject.h
        src/gameStates/level/GameObjects/MovingObject.cpp
        include/gameStates/level/GameObjects/MovingObject.h
        src/gameStates/level/GameObjects/StaticObjects/Wall.cpp
        include/gameStates/level/GameObjects/StaticObjects/Wall.h
        src/gameStates/level/GameObjects/MovingObjects/LivingObjects/Robbo.cpp
        include/gameStates/level/GameObjects/MovingObjects/LivingObjects/Robbo.h
        include/gameStates/level/LevelHeaders.h
        src/gameStates/level/GameObjects/MovingObjects/LivingObject.cpp
        include/gameStates/level/GameObjects/MovingObjects/LivingObject.h
        src/gameStates/level/GameObjects/MovingObjects/Chest.cpp
        include/gameStates/level/GameObjects/MovingObjects/Chest.h
        src/gameStates/level/GameObjects/Collectible.cpp
        include/gameStates/level/GameObjects/Collectible.h
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/levels)
file(COPY ${CMAKE_SOURCE_DIR}/levels/ DESTINATION ${CMAKE_BINARY_DIR}/levels/)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
