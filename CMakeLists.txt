cmake_minimum_required(VERSION 3.26)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "C:/Users/rober/Documents/Work/Code/SDL")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SDL2_IMAGE_PATH "C:/Users/rober/Documents/Work/Code/SDL_image")
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

set(SDL2_TTF_PATH "C:/Users/rober/Documents/Work/Code/SDL_ttf")
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIR})

add_executable(untitled main.cpp
        game/Game.cpp
        game/Game.h
        game/input/Keyboard.cpp
        game/input/Keyboard.h
        game/object/GameObject.cpp
        game/object/GameObject.h
        game/object/PlayerObject.cpp
        game/object/PlayerObject.h
        game/graphics/Particle.cpp
        game/graphics/Particle.h
        game/object/ProjectileObject.cpp
        game/object/ProjectileObject.h
        game/object/EnemyObject.cpp
        game/object/EnemyObject.h
        game/time/Time.h
        game/graphics/Text.cpp
        game/graphics/Text.h
)

target_link_libraries(untitled ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})