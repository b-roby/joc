#include <iostream>
#include <SDL.h>
#include "game/Game.h"

#undef main

int main() {
    auto game = new Game();
    game->init("Hourg", false);

    while (game->running()) {
        game->frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        game->frameTime = SDL_GetTicks() - game->frameStart;

        if (game->frameDelay > game->frameTime)
            SDL_Delay(game->frameDelay - game->frameTime);
    }

    game->clean();

    return 0;
}
