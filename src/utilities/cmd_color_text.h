#pragma once

#include"windows.h"
#include<iostream>

enum COLORS {
    BLACK,
    BLUE,
    GREEN,
    AQUA,
    RED,
    PURPLE,
    YELLOW,
    WHITE,
    GRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
};

void cmdColorText(std::string text, COLORS color_key);
