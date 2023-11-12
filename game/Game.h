#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

#define FPS 60

#define WIDTH 800
#define HEIGHT 800

#define PLAYER_ASSET "../assets/player/player.png"
#define PROJECTILE_ASSET "../assets/projectile.png"
#define ENGINE_PARTICLE_ASSET_1 "../assets/particles/engine_particle1.png"
#define ENGINE_PARTICLE_ASSET_2 "../assets/particles/engine_particle2.png"
#define ENGINE_PARTICLE_ASSET_3 "../assets/particles/engine_particle3.png"
#define ENGINE_PARTICLE_ASSET_4 "../assets/particles/engine_particle4.png"
#define ENGINE_PARTICLE_ASSET_5 "../assets/particles/engine_particle5.png"
#define FONT_ASSET "../assets/font/game_font.ttf"

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <map>

#include "input/Keyboard.h"
#include "graphics/Particle.h"
#include "object/PlayerObject.h"
#include "object/EnemyObject.h"
#include "time/Time.h"
#include "graphics/Text.h"

#undef main

class GameObject;

class Game
{
public:
    Game();
    ~Game();

    void init(const char* title, bool fullscreen);
    void handleEvents();
    void render();
    void clean();
    void update();
    bool running();

    SDL_Texture* loadTexture(const char* path);
    std::vector<SDL_Texture*> playerAnimation;

    std::vector<Particle*> particles;
    void removeParticle(Particle* particle);
    void spawnParticle(SDL_Texture* particle, int width, int height, int x, int y);

    Keyboard *getKeyboard() {return keyboard;};
    SDL_Renderer* getRenderer() {return renderer;};

    const Time& getTime() {return time;};

    void addGameObject(GameObject* object);
    void removeGameObject(GameObject* object);
    bool containsGameObject(GameObject* object);

    void shootProjectile(GameObject* owner);
    void spawnProjectile(GameObject* owner, int x, int y);

    bool hasPassed(int& currentTime, int& lastFrameTime, int delay);

    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    std::random_device seed;
    std::mt19937 gen{seed()};

    std::vector<SDL_Texture*> possibleEngineParticles = {};

private:

    SDL_Window* window;
    SDL_Renderer* renderer;
    Time time;
    Keyboard* keyboard = new Keyboard;

    bool is_running = false;

    void loadAssets();
    void loadText();

    PlayerObject* playerObject;
    EnemyObject* enemyObject;

    std::vector<GameObject*> gameObjects;
    std::vector<Text*> textObjects;

    SDL_Texture* playerTexture = nullptr;

    SDL_Texture* engineParticleTexture1 = nullptr;
    SDL_Texture* engineParticleTexture2 = nullptr;
    SDL_Texture* engineParticleTexture3 = nullptr;
    SDL_Texture* engineParticleTexture4 = nullptr;
    SDL_Texture* engineParticleTexture5 = nullptr;

    void addParticle(Particle* particle);
};

#endif //UNTITLED_GAME_H
