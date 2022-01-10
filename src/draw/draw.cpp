#include "draw.h"

// TODO: ������� �������� ������� ������������
void drawArray(SDL_Texture *background, int x, int y, int z) {
    SDL_SetRenderDrawColor(renderer, 255, 192, 203, 0);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    handleKeyboard();

    double j = 0;
    SDL_PumpEvents();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        SDL_Rect rect = {int(SCREEN_WIDTH * 0.1 + j), int(SCREEN_HEIGHT * 0.9), int(RECT_SIZE + 1),
                         int((arr[i] * height_coefficient) * -1)};
        if (complete) {
            SDL_SetRenderDrawColor(renderer, 58, 122, 53, 255);
            SDL_RenderFillRect(renderer, &rect);
        } else if (i == x || i == z) {
            SDL_SetRenderDrawColor(renderer, 80, 180, 80, 200);
            SDL_RenderFillRect(renderer, &rect);
        } else if (i == y) {
            SDL_SetRenderDrawColor(renderer, 123, 36, 36, 130);
            SDL_RenderFillRect(renderer, &rect);
        } else {
            SDL_SetRenderDrawColor(renderer, array_color.r - 25, array_color.g - 25, array_color.b, 100);
            SDL_RenderDrawRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, array_color.r, array_color.g, array_color.b, 40);
            SDL_RenderFillRect(renderer, &rect);
        }
        j += RECT_SIZE;
    }
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(background);
}

void drawSelectedCircle(int x, int y, int radius, int width, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    Circle circle;
    for (int i = radius; i > radius - width; i--) {
        circle.draw_circle(renderer, x, y, i, r, g, b, a);
    }
    SDL_RenderPresent(renderer);
}

void drawText(const char *text, TTF_Font *font, SDL_Color foreground, int x, int y) {
    SDL_Texture *text_texture;
    SDL_Rect dest;
    SDL_Surface *text_surf = TTF_RenderText_Solid(font, text, foreground);
    text_surf = TTF_RenderText_Solid(font, text, foreground);
    text_texture = SDL_CreateTextureFromSurface(renderer, text_surf);

    dest.x = x - text_surf->w / 2;
    dest.y = y - text_surf->h / 2;
    dest.w = text_surf->w;
    dest.h = text_surf->h;
    SDL_RenderCopy(renderer, text_texture, NULL, &dest);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text_surf);
}
