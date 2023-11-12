#include <iostream>
#include "../Game.h"
#include "ProjectileObject.h"
#include "PlayerObject.h"

void PlayerObject::spawnEngineParticles() {
    int eng1SpawnPositionX = position.x + 34 + spawnDistance(game->gen);
    int eng1SpawnPositionY = position.y + 105 + spawnDistance(game->gen);

    int eng2SpawnPositionX = position.x + 95 + spawnDistance(game->gen);
    int eng2SpawnPositionY = position.y + 105 + spawnDistance(game->gen);

    SDL_Texture* eng1Particle = game->possibleEngineParticles.at(engineParticle(game->gen));
    SDL_Texture* eng2Particle = game->possibleEngineParticles.at(engineParticle(game->gen));

    game->spawnParticle(eng1Particle, particleSize, particleSize, eng1SpawnPositionX, eng1SpawnPositionY);
    game->spawnParticle(eng2Particle, particleSize, particleSize, eng2SpawnPositionX, eng2SpawnPositionY);
}

void PlayerObject::update() {
    if(game->getKeyboard()->isKeyDown(SDLK_w))
        positionUpdate(0, -speed);
    if(game->getKeyboard()->isKeyDown(SDLK_s))
        positionUpdate(0, +speed);
    if(game->getKeyboard()->isKeyDown(SDLK_a))
        positionUpdate(-speed, 0);
    if(game->getKeyboard()->isKeyDown(SDLK_d))
        positionUpdate(speed, 0);

    if(game->getKeyboard()->isKeyDown(SDLK_SPACE) && game->getTime().hasPassed(shootingPlaceholder, 1000, true))
        game->shootProjectile(this);

    if(game->getTime().hasPassed(particleSpawningPlaceholder, particleDelay, true))
        spawnEngineParticles();

}
