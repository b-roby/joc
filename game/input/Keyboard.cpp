#include "Keyboard.h"

bool Keyboard::isKeyDown(SDL_KeyCode keyCode) {
    auto it = keyMap.find(keyCode);

    if (it == keyMap.end())
        return false;
    return it->second;
}

bool Keyboard::isKeyPressed(SDL_KeyCode keyCode) {
    auto it = keyMap.find(keyCode);
    auto prevIt = previousKeyState.find(keyCode);

    if (it == keyMap.end() || prevIt == previousKeyState.end())
        return false;

    return it->second && !prevIt->second;
}

void Keyboard::updatePreviousState() {
    previousKeyState = keyMap;
}

void Keyboard::handleKeyDown(SDL_KeyboardEvent event) {
    keyMap[event.keysym.sym] = true;
}

void Keyboard::handleKeyUp(SDL_KeyboardEvent event) {
    keyMap[event.keysym.sym] = false;
}

