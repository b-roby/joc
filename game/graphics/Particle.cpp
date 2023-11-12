#include <iostream>
#include "Particle.h"
#include "../Game.h"

Particle::Particle(Game *game, const char* texture, int width, int height, int x, int y) {
    this->game = game;
    rect.w = width;
    rect.h = height;
    rect.x = x;
    rect.y = y;

    this->texture = game->loadTexture(texture);
    this->lifetime = possibleLifetime(game->gen);
}

Particle::Particle(Game *game, SDL_Texture *texture, int width, int height, int x, int y) {
    this->game = game;
    rect.w = width;
    rect.h = height;
    rect.x = x;
    rect.y = y;

    this->texture = texture;
}

void Particle::scaleUp(int scale) {
    rect.w *= scale;
    rect.h *= scale;
}

void Particle::scaleDown(int scale) {
    rect.w /= scale;
    rect.h /= scale;
}

void Particle::update() {
    SDL_RenderCopy(game->getRenderer(), texture, nullptr, &rect);
    rect.y += velocity;

    if(game->getTime().hasPassed(animationTime, 150, true))
        scaleDown(2);

    if(game->getTime().hasPassed(lifeVar, lifetime))
        game->removeParticle(this);
}
