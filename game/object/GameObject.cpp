#include <iostream>
#include "GameObject.h"
#include "../Game.h"
#include "ProjectileObject.h"

GameObject::GameObject(Game* game, const char* texture, int x, int y, int width, int height) {
    this->game = game;
    this->texture = game->loadTexture(texture);
    initializePosition(x, y, width, height);
}

GameObject::GameObject(Game *game, std::vector<SDL_Texture*> animation, int x, int y, int width, int height) {
    this->game = game;
    this->texture = animation.at(0);
    this->animation = animation;
    initializePosition(x, y, width, height);

    hasAnimation = true;
}

GameObject::GameObject(Game *game, SDL_Texture *texture, int x, int y, int width, int height) {
    this->game = game;
    this->texture = texture;

    initializePosition(x, y, width, height);
}

void GameObject::initializePosition(int x, int y, int width, int height) {
    position.w = width;
    position.h = height;

    position.x = x;
    position.y = y;
}

void GameObject::positionUpdate(int x, int y) {
    int newPositionX = position.x + x;
    int newPositionY = position.y + y;

    if(x != 0 && isOutOfBoundsX(newPositionX, 110)) return;
    if(y != 0 && isOutOfBoundsY(newPositionY, 110)) return;

    this->position.x = newPositionX;
    this->position.y = newPositionY;
}

void GameObject::render() {
    SDL_RenderCopy(game->getRenderer(), texture, nullptr, &position);
}

void GameObject::animate() {
    if(frameIndex > animation.size() - 1)
        frameIndex = 0;
    SDL_RenderCopy(game->getRenderer(), animation.at(frameIndex), nullptr, &position);

    if(game->hasPassed(currentTime, lastFrameTime, frame_delay)){
        frameIndex++;
    }
}

bool GameObject::isOutOfBoundsX(int x, int threshold) {
    return x > WIDTH - threshold || x < 0;
}

bool GameObject::isOutOfBoundsY(int y, int threshold) {
    return y > HEIGHT - threshold || y < 0;
}

bool GameObject::isCollidingWith(GameObject *gameObject) {
    if(!(game->containsGameObject(gameObject))) return false;

    int x = position.x;
    int y = position.y;
    int width = position.w;
    int height = position.h;

    int otherX = gameObject->position.x;
    int otherY = gameObject->position.y;
    int otherWidth = gameObject->position.w;
    int otherHeight = gameObject->position.h;

    return x < otherX + otherWidth &&
           x + width > otherX &&
           y < otherY + otherHeight &&
           y + height > otherY;
}
