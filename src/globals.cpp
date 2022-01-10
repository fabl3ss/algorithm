#include "globals.h"

// ������������� SDL ����������
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Surface *screenSurface = NULL;
SDL_Surface *MainSurfaces[static_cast<int>(SURFACES::TOTAL_AMOUNT_SURFACES)];
SDL_Surface *SettingsSurfaces[static_cast<int>(SETTINGS_PAGE::TOTAL_AMOUNT_SETTINGS)];
SDL_Surface *SortSurfaces[static_cast<int>(SORTS::TOTAL_AMOUNT_SORTS)];
SDL_Surface *SelectSurfaces[static_cast<int>(SELECT_PAGE::TOTAL_AMOUNT_SELECTED)];
SDL_Surface *LabSurfaces[static_cast<int>(SELECT_LAB::TOTAL_AMOUNT_LAB)];
SDL_Texture *background = NULL;
SDL_Event e;
TTF_Font *font;
SDL_Color array_color = {0, 0, 0};

// ������ ������������ ��� ����� ������� �������
std::string input;

// ������������� �������� ����
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 640;

// ������ �������� ������� �� ������ (�������) � ������ �������
const int ARRAY_WIDTH = SCREEN_WIDTH * 0.8;
const int ARRAY_HEIGHT = SCREEN_HEIGHT * 0.6;

// ������ ������� �� ��������� � ������ ������� ��������
int ARRAY_SIZE = 100;
double RECT_SIZE = (double) ARRAY_WIDTH / ARRAY_SIZE;

// ������� ��� ����������
int *arr = new int[ARRAY_SIZE];
int *fill_arr = new int[ARRAY_SIZE]; // <---- ����� ����� ����� ���������� ������� ��������� ������� ��������� ��������, ��� ��������� ����� ��������� �����

// ����������� , �� ������� ����� �������� ������� �������, ����� �������� ��� ������ ������������ ���� ���������
double height_coefficient = 0;

unsigned long long int comparisons = 0;
unsigned long long int swaps = 0;

bool complete = false;
