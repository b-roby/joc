#include "Game.h"
#include "object/GameObject.h"
#include "object/PlayerObject.h"
#include "object/ProjectileObject.h"
#include "object/EnemyObject.h"

#include <iostream>
#include <algorithm>

Game::Game(){}
Game::~Game(){}

void Game::init(const char* title, bool fullscreen) {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    is_running = true;
    if (!window || !renderer) {
        is_running = false;
        clean();
    }

    loadAssets();
    loadText();

    playerObject = new PlayerObject(this, playerTexture, WIDTH / 2, 500, 128, 128);
    addGameObject(playerObject);

    enemyObject = new EnemyObject(this, PLAYER_ASSET, WIDTH / 2, 200, 128, 128);
    addGameObject(enemyObject);
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        case SDL_KEYDOWN:
            keyboard->handleKeyDown(event.key);
            break;
        case SDL_KEYUP:
            keyboard->handleKeyUp(event.key);
            break;
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);
    SDL_RenderClear(renderer);

    for(auto particle : particles){
        particle->update();

        if(particle->rect.y >= HEIGHT)
            removeParticle(particle);
    }

    for(auto object : gameObjects)
        if (!object->hasAnimation)
            object->render();
        else
            object->animate();

    for(auto text : textObjects)
        text->render();

    keyboard->updatePreviousState();
    SDL_RenderPresent(renderer);
}

void Game::update() {
    for(auto object : gameObjects) {
        if(!object) continue;
        object->update();

        if(auto* projectileObject = dynamic_cast<ProjectileObject*>(object)){
            if(projectileObject->isCollidingWith(enemyObject) && !projectileObject->isCollidingWithShooter(enemyObject)) {
                removeGameObject(enemyObject);
                removeGameObject(projectileObject);
            }
        }
    }
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::running() {
    return is_running;
}

SDL_Texture *Game::loadTexture(const char *path) {
    SDL_Surface* tempSurface = IMG_Load(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}

void Game::addGameObject(GameObject *object) {
    gameObjects.push_back(object);
}

void Game::removeGameObject(GameObject *object) {
    gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(),
                     [object](GameObject* obj) { return obj == object; }),
                      gameObjects.end());
}

bool Game::containsGameObject(GameObject *object) {
    if(gameObjects.empty()) return false;

    if(std::find(gameObjects.begin(), gameObjects.end(), object) != gameObjects.end()) return true;
    return false;
}

bool Game::hasPassed(int &currentTime, int &lastFrameTime, int delay) {
    if(currentTime - lastFrameTime >= delay){
        lastFrameTime = currentTime;
        return true;
    }
    return false;
}

void Game::addParticle(Particle *particle) {
    particles.push_back(particle);
}

void Game::removeParticle(Particle *particle) {
    particles.erase(std::remove_if(particles.begin(), particles.end(),
                                     [particle](Particle* obj) { return obj == particle; }),
                      particles.end());
}

void Game::spawnProjectile(GameObject* owner, int x, int y){
    auto* projectile = new ProjectileObject(this, PROJECTILE_ASSET, x, y, 64, 64);
    projectile->shooter = owner;
    addGameObject(projectile);
}

void Game::shootProjectile(GameObject* owner) {
    int spawnPositionX = playerObject->position.x + 32;
    int spawnPositionY = playerObject->position.y;
    auto* projectile = new ProjectileObject(this, PROJECTILE_ASSET, spawnPositionX, spawnPositionY, 64, 64);
    projectile->shooter = owner;

    addGameObject(projectile);
}

void Game::loadAssets() {
    this->playerTexture = loadTexture(PLAYER_ASSET);

    this->engineParticleTexture1 = loadTexture(ENGINE_PARTICLE_ASSET_1);
    possibleEngineParticles.push_back(engineParticleTexture1);

    this->engineParticleTexture2 = loadTexture(ENGINE_PARTICLE_ASSET_2);
    possibleEngineParticles.push_back(engineParticleTexture2);

    this->engineParticleTexture3 = loadTexture(ENGINE_PARTICLE_ASSET_3);
    possibleEngineParticles.push_back(engineParticleTexture3);

    this->engineParticleTexture4 = loadTexture(ENGINE_PARTICLE_ASSET_4);
    possibleEngineParticles.push_back(engineParticleTexture4);

    this->engineParticleTexture5 = loadTexture(ENGINE_PARTICLE_ASSET_5);
    possibleEngineParticles.push_back(engineParticleTexture5);
}

void Game::loadText() {
    SDL_Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 100;

    Text* text = new Text(this, "Hello world", 0, 0, 200, 50, color);
    textObjects.push_back(text);
}

void Game::spawnParticle(SDL_Texture* particle, int width, int height, int x, int y) {
    auto* particleObject = new Particle(this, particle, width, height, x, y);
    addParticle(particleObject);
}