#ifndef UNTITLED_KEYBOARD_H
#define UNTITLED_KEYBOARD_H

#include <map>
#include <SDL.h>

class Keyboard {
public:
    bool isKeyDown(SDL_KeyCode keyCode);
    bool isKeyPressed(SDL_KeyCode keyCode);

    void handleKeyDown(SDL_KeyboardEvent event);
    void handleKeyUp(SDL_KeyboardEvent event);

    void updatePreviousState();

private:

    std::map<SDL_Keycode, bool> keyMap;
    std::map<SDL_Keycode, bool> previousKeyState;

};


#endif //UNTITLED_KEYBOARD_H
