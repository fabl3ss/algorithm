#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_TTF.h>
#include"../globals.h"
#include"draw_circle.h"
#include"../utilities/simplifying_funcs.h"
#include"windows.h"

void drawArray(SDL_Texture *background, int x = -1, int y = -1, int z = -1);

void drawText(const char *text, TTF_Font *font, SDL_Color foreground, int x, int y);

void drawSelectedCircle(int x, int y, int radius, int width, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
