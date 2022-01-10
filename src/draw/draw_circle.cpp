#include "draw_circle.h"

void Circle::set_pixel(SDL_Renderer *renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderDrawPoint(renderer, x, y);
}

void Circle::draw_circle(SDL_Renderer *renderer, int n_cx, int n_cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    double error = (double) -radius;
    double x = (double) radius - 0.5;
    double y = (double) 0.5;
    double cx = n_cx - 0.5;
    double cy = n_cy - 0.5;

    while (x >= y) {
        set_pixel(renderer, (int) (cx + x), (int) (cy + y), r, g, b, a);
        set_pixel(renderer, (int) (cx + y), (int) (cy + x), r, g, b, a);

        if (x != 0) {
            set_pixel(renderer, (int) (cx - x), (int) (cy + y), r, g, b, a);
            set_pixel(renderer, (int) (cx + y), (int) (cy - x), r, g, b, a);
        }

        if (y != 0) {
            set_pixel(renderer, (int) (cx + x), (int) (cy - y), r, g, b, a);
            set_pixel(renderer, (int) (cx - y), (int) (cy + x), r, g, b, a);
        }

        if (x != 0 && y != 0) {
            set_pixel(renderer, (int) (cx - x), (int) (cy - y), r, g, b, a);
            set_pixel(renderer, (int) (cx - y), (int) (cy - x), r, g, b, a);
        }

        error += y;
        ++y;
        error += y;

        if (error >= 0) {
            --x;
            error -= x;
            error -= x;
        }
    }
}
