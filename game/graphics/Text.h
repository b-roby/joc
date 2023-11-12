#ifndef UNTITLED_TEXT_H
#define UNTITLED_TEXT_H

#define FONT_ASSET "../../assets/game_font.ttf"

#include <SDL.h>
#include <SDL_ttf.h>

class Game;


class Text {
public:

    Text(Game* game, const char* text, int x, int y, int w, int h, SDL_Color color);

    void render();

private:

    Game* game;
    TTF_Font* font;
    SDL_Texture* texture;
    SDL_Rect rect;

};


#endif //UNTITLED_TEXT_H
