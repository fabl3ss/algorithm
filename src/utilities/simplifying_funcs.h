#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"../globals.h"
#include"load_media.h"

void installSurface(SDL_Surface *newSurface);

SDL_Texture *createTexture(SDL_Surface *surface);

void handleKeyboard();

bool init();

void close();

