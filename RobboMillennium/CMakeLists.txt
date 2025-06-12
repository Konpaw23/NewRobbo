cmake_minimum_required(VERSION 3.27)
project(RobboMillennium)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "SDL2-devel-2.30.10-mingw/SDL2-2.30.10/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(RobboMillennium main.cpp
        code/gameStates/GameState.cpp
        code/gameStates/GameState.h
        code/Window.cpp
        code/Window.h
        code/gameStates/menu/MenuState.cpp
        code/gameStates/menu/MenuState.h
        code/Button.cpp
        code/Button.h
        code/Coordinates.cpp
        code/Coordinates.h
        code/defines.h
        code/gameStates/level/LevelState.cpp
        code/gameStates/level/LevelState.h
        code/enums.h
        main.cpp
        code/gameStates/level/Level.cpp
        code/gameStates/level/Level.h
        code/basicProjectHeaders.h
        code/gameStates/level/GameObject.cpp
        code/gameStates/level/GameObject.h
        code/gameStates/level/GameObjects/StaticObject.cpp
        code/gameStates/level/GameObjects/StaticObject.h
        code/gameStates/level/GameObjects/MovingObject.cpp
        code/gameStates/level/GameObjects/MovingObject.h
        code/gameStates/level/GameObjects/StaticObjects/Wall.cpp
        code/gameStates/level/GameObjects/StaticObjects/Wall.h
        code/gameStates/level/GameObjects/MovingObjects/LivingObjects/Robbo.cpp
        code/gameStates/level/GameObjects/MovingObjects/LivingObjects/Robbo.h
        code/gameStates/level/LevelHeaders.h
        code/gameStates/level/GameObjects/MovingObjects/LivingObject.cpp
        code/gameStates/level/GameObjects/MovingObjects/LivingObject.h
        code/gameStates/level/GameObjects/MovingObjects/Chest.cpp
        code/gameStates/level/GameObjects/MovingObjects/Chest.h
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/levels)
file(COPY ${CMAKE_SOURCE_DIR}/levels/ DESTINATION ${CMAKE_BINARY_DIR}/levels/)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
