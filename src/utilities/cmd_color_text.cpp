#include "cmd_color_text.h"

void cmdColorText(std::string text, COLORS color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    std::cout << text;
    SetConsoleTextAttribute(hConsole, COLORS::WHITE);
}
