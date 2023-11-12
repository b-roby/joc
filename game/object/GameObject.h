#ifndef UNTITLED_GAMEOBJECT_H
#define UNTITLED_GAMEOBJECT_H

#include <SDL.h>
#include <vector>

class Game;

class GameObject {
public:

    bool hasAnimation = false;
    int frameIndex = 0;

    GameObject(Game* game, const char* texture, int x, int y, int width, int height);
    GameObject(Game* game, std::vector<SDL_Texture*> animation, int x, int y, int width, int height);
    GameObject(Game* game, SDL_Texture* texture, int x, int y, int width, int height);

    virtual void update() = 0;

    void render();
    void positionUpdate(int x, int y);
    void animate();

    bool isOutOfBoundsX(int x, int threshold);
    bool isOutOfBoundsY(int y, int threshold);

    bool isCollidingWith(GameObject* gameObject);

    SDL_Texture* texture;
    std::vector<SDL_Texture*> animation;

    SDL_Rect position;
    Game* game;

private:

    void initializePosition(int x, int y, int width, int height);

    int frame_delay = 500;
    int currentTime = 0;
    int lastFrameTime = 0;

};


#endif //UNTITLED_GAMEOBJECT_H
