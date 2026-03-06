cmake_minimum_required(VERSION 3.27)
project(RobboMillennium)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "${CMAKE_SOURCE_DIR}/SDL2-devel-2.30.10-mingw/SDL2-2.30.10/x86_64-w64-mingw32")
set(SDL2TTF_PATH "${CMAKE_SOURCE_DIR}/SDL2_ttf-devel-2.24.0-mingw/SDL2_ttf-2.24.0/x86_64-w64-mingw32")

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
        src/gameStates/level/gameObjects/activeObjects/laser/LaserShooter.cpp
        include/gameStates/level/gameObjects/activeObjects/laser/LaserShooter.h
        src/gameStates/level/gameObjects/activeObjects/laser/LaserHead.cpp
        include/gameStates/level/gameObjects/activeObjects/laser/LaserHead.h
        src/helpers.cpp
        include/helpers.h
        src/gameStates/level/gameObjects/activeObjects/laser/LaserBody.cpp
        include/gameStates/level/gameObjects/activeObjects/laser/LaserBody.h
        src/gameStates/level/gameObjects/movingObjects/Surprise.cpp
        include/gameStates/level/gameObjects/movingObjects/Surprise.h
        src/gameStates/level/gameObjects/movingObjects/Ship.cpp
        include/gameStates/level/gameObjects/movingObjects/Ship.h
        src/gameStates/level/gameObjects/activeObjects/Cannon.cpp
        include/gameStates/level/gameObjects/activeObjects/Cannon.h
        src/gameStates/level/gameObjects/RotatingObject.cpp
        include/gameStates/level/gameObjects/RotatingObject.h
        src/gameStates/level/gameObjects/activeObjects/GoldenSeahorse.cpp
        include/gameStates/level/gameObjects/activeObjects/GoldenSeahorse.h
        src/gameStates/level/gameObjects/KillingObject.cpp
        include/gameStates/level/gameObjects/KillingObject.h
        src/gameStates/level/gameObjects/activeObjects/PurpleSeahorse.cpp
        include/gameStates/level/gameObjects/activeObjects/PurpleSeahorse.h
        src/gameStates/level/gameObjects/activeObjects/RotatingCannon.cpp
        include/gameStates/level/gameObjects/activeObjects/RotatingCannon.h
        src/gameStates/level/gameObjects/collectibles/Life.cpp
        include/gameStates/level/gameObjects/collectibles/Life.h
        src/gameStates/level/gameObjects/staticObjects/BushWall.cpp
        include/gameStates/level/gameObjects/staticObjects/BushWall.h
        src/gameStates/level/gameObjects/activeObjects/CookieMonster.cpp
        include/gameStates/level/gameObjects/activeObjects/CookieMonster.h
        src/gameStates/level/gameObjects/activeObjects/Eye.cpp
        include/gameStates/level/gameObjects/activeObjects/Eye.h
        src/gameStates/level/gameObjects/activeObjects/Magnet.cpp
        include/gameStates/level/gameObjects/activeObjects/Magnet.h
        src/gameStates/level/gameObjects/activeObjects/Blaster.cpp
        include/gameStates/level/gameObjects/activeObjects/Blaster.h
        src/gameStates/level/gameObjects/activeObjects/BlasterCannon.cpp
        include/gameStates/level/gameObjects/activeObjects/BlasterCannon.h
        src/gameStates/level/gameObjects/activeObjects/Push.cpp
        include/gameStates/level/gameObjects/activeObjects/Push.h
        src/gameStates/level/gameObjects/activeObjects/MovingCannon.cpp
        include/gameStates/level/gameObjects/activeObjects/MovingCannon.h
        src/gameStates/level/gameObjects/activeObjects/Snake.cpp
        include/gameStates/level/gameObjects/activeObjects/Snake.h
        src/gameStates/level/InfoPanel.cpp
        include/gameStates/level/InfoPanel.h
        include/structs.h
        src/gameStates/menu/PlanetChoiceMenu.cpp
        include/gameStates/menu/PlanetChoiceMenu.h
        src/gameStates/level/gameObjects/staticObjects/Spikes.cpp
        include/gameStates/level/gameObjects/staticObjects/Spikes.h
        src/gameStates/level/gameObjects/collectibles/Stop.cpp
        include/gameStates/level/gameObjects/collectibles/Stop.h
)

include_directories(
        "${SDL2_PATH}/include/SDL2"
        "${SDL2TTF_PATH}/include/SDL2"
        "${CMAKE_SOURCE_DIR}/include"
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/levels)

target_link_libraries(${PROJECT_NAME} PRIVATE
        mingw32
        "${SDL2_PATH}/lib/libSDL2main.a"
        "${SDL2_PATH}/lib/libSDL2.a"
        "${SDL2TTF_PATH}/lib/libSDL2_ttf.a"

        setupapi
        imm32
        winmm
        version
        rpcrt4
        cfgmgr32
)

target_link_options(${PROJECT_NAME} PRIVATE
        -static
        -static-libgcc
        -static-libstdc++
)

#set(SDL2_DLL "${CMAKE_SOURCE_DIR}/SDL2-devel-2.30.10-mingw/SDL2-2.30.10/x86_64-w64-mingw32/bin/SDL2.dll")
#set(SDL2TTF_DLL "${CMAKE_SOURCE_DIR}/SDL2_ttf-devel-2.24.0-mingw/SDL2_ttf-devel-2.24.0-mingw/x86_64-w64-mingw32/bin/SDL2_ttf.dll")
#
#if(WIN32)
#    add_custom_command(
#            TARGET ${PROJECT_NAME} POST_BUILD
#            COMMAND "${CMAKE_COMMAND}" -E copy_if_different
#                "${SDL2_DLL}"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
#            VERBATIM
#    )
#endif()
#
#if(WIN32)
#    add_custom_command(
#            TARGET ${PROJECT_NAME} POST_BUILD
#            COMMAND "${CMAKE_COMMAND}" -E copy_if_different
#                "${SDL2TTF_DLL}"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
#            VERBATIM
#    )
#endif()

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_directory
            "${CMAKE_SOURCE_DIR}/levels"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/levels"
)