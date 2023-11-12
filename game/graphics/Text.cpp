#include "Text.h"
#include "../Game.h"

Text::Text(Game* game, const char* text, int x, int y, int w, int h, SDL_Color color) {
    TTF_Init();
    this->game = game;
    this->font = TTF_OpenFont(FONT_ASSET, 24);

    SDL_Surface* textSurface = TTF_RenderText_Solid(this->font, text, color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(game->getRenderer(), textSurface);
    SDL_FreeSurface(textSurface);

    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    this->texture = textTexture;
}

void Text::render() {
    SDL_RenderCopy(game->getRenderer(), texture, NULL, &rect);
}
