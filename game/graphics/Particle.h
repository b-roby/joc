#ifndef UNTITLED_PARTICLE_H
#define UNTITLED_PARTICLE_H

#include "../time/Time.h"
#include <random>

#include <SDL.h>

class Game;

class Particle {

public:

    Particle(Game* game, const char* texture, int width, int height, int x, int y);
    Particle(Game* game, SDL_Texture* texture, int width, int height, int x, int y);

    Game* game;
    SDL_Texture* texture;
    SDL_Rect rect;

    void update();
    void scaleUp(int scale);
    void scaleDown(int scale);

private:

    int velocity = 6;

    int animationTime = 0;
    std::uniform_int_distribution<> possibleLifetime{750, 1000};

    int lifeVar = 0;
    int lifetime;

};


#endif //UNTITLED_PARTICLE_H
