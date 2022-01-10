#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_TTF.h>
#include<iostream>
#include"algorithms/binary_tree.h"

// ������������� ���� (������������ ��� �������� ������������)
enum SURFACES {
    MAIN_PAGE,
    SELECT_SORT,
    SETTINGS_PAGE,
    HOW_TO_USE,
    SELECT_LAB,
    TOTAL_AMOUNT_SURFACES
};

enum SORTS {
    BUBBLE_SORT,
    HEAP_SORT,
    INSERTION_SORT,
    MERGE_SORT,
    QUICK_SORT,
    SELECTION_SORT,
    TOTAL_AMOUNT_SORTS
};

enum SELECT_PAGE {
    SELECTED_1,
    SELECTED_2,
    SELECTED_3,
    SELECTED_4,
    SELECTED_5,
    SELECTED_6,
    SELECTED_7,
    TOTAL_AMOUNT_SELECTED
};

enum SETTINGS_PAGE {
    SELECTED_SIZE,
    SELECTED_COLOR,
    SELECTED_LAB,
    SELECTED_NEXT,
    TOTAL_AMOUNT_SETTINGS
};

enum SELECT_LAB {
    LAB_1,
    LAB_2,
    LAB_3,
    LAB_4,
    TOTAL_AMOUNT_LAB
};

// SDL ���������e
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Surface *screenSurface;
extern SDL_Surface *MainSurfaces[static_cast<int>(SURFACES::TOTAL_AMOUNT_SURFACES)];
extern SDL_Surface *SettingsSurfaces[static_cast<int>(SETTINGS_PAGE::TOTAL_AMOUNT_SETTINGS)];
extern SDL_Surface *SortSurfaces[static_cast<int>(SORTS::TOTAL_AMOUNT_SORTS)];
extern SDL_Surface *SelectSurfaces[static_cast<int>(SELECT_PAGE::TOTAL_AMOUNT_SELECTED)];
extern SDL_Surface *LabSurfaces[static_cast<int>(SELECT_LAB::TOTAL_AMOUNT_LAB)];
extern SDL_Texture *background;
extern SDL_Event e;
extern SDL_Color array_color;
extern TTF_Font *font;

// ������ ������������ ��� ����� ������� �������
extern std::string input;

// ������������� �������� ����
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

// ������ �������� ������� �� ������ (�������) � ������ �������
extern const int ARRAY_WIDTH;
extern const int ARRAY_HEIGHT;

// ������ ������� �� ��������� � ������ ������� ��������
extern int ARRAY_SIZE;
extern double RECT_SIZE;

// ������� ��� ����������
extern int *arr;
extern int *fill_arr;

// ����������� , �� ������� ����� �������� ������� �������, ����� �������� ��� ������ ������������ ���� ���������
extern double height_coefficient;

extern unsigned long long int comparisons;
extern unsigned long long int swaps;

extern bool complete;

