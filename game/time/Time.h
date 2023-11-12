#ifndef UNTITLED_TIME_H
#define UNTITLED_TIME_H

#include "SDL.h"

class Time {

public:

    static bool hasPassed(int& placeholder, int ms, bool reset = false){
        if (placeholder == 0)
            placeholder = SDL_GetTicks() + ms;

        if(placeholder <= SDL_GetTicks()) {
            if(reset)
                placeholder = 0;
            return true;
        }
        return false;
    }



};


#endif //UNTITLED_TIME_H
