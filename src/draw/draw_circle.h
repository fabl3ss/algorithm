#pragma once

#include<SDL2/SDL.h>
#include<iostream>

class Circle {
public:
    void set_pixel(SDL_Renderer *renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    void draw_circle(SDL_Renderer *renderer, int n_cx, int n_cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};

