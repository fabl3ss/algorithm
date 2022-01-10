#pragma once

#include"../algorithms/sorts.h"
#include"../draw/draw.h"
#include"../algorithms/array/array_processing.h"
#include"../utilities/cmd_color_text.h"
//#include"../../xlnt-master/include/xlnt.hpp"
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<algorithm>
#include"../algorithms/binary_tree.h"
#include"../draw/draw_circle.h"

enum FIRST_LAB_CASES {
    BEST_CASE,
    AVERAGE_CASE,
    WORST_CASE,
    TOTAL_CASES
};

// ������� ������������ ������ #1
void firstLab();

//void firstLabIter(xlnt::worksheet ws, double(*sort_algorithm)(bool), std::string sort_name);

void sortIter(unsigned int size, FIRST_LAB_CASES case_, double(*sort_algorithm)(bool), int max_rand);

// ������� ������������ ������ #2
void secondLab();