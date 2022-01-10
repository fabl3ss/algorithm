#define SDL_MAIN_HANDLED

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_TTF.h>
#include<iostream>
#include<time.h>
#include<string>
#include"draw/draw.h"
#include"globals.h"
#include"utilities/simplifying_funcs.h"
#include"algorithms/array/array_processing.h"
#include"algorithms/sorts.h"
#include"labs/labs.h"

bool sizeEntering() {
    SDL_StartTextInput();
    static const unsigned char *keys = SDL_GetKeyboardState(NULL);

    SDL_Event e;


    while (SDL_PollEvent(&e) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                close();
            case SDL_TEXTINPUT:
                if (*e.text.text >= '0' && *e.text.text <= '9') {
                    input += e.text.text;
                }
                break;
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_RETURN) {
                    return false;
                }
                if (e.key.keysym.sym == SDLK_BACKSPACE && input.size()) {
                    input.pop_back();
                }
                break;
        }
    }
    SDL_RenderCopy(renderer, background, NULL, NULL);

    if (input.size()) {
        font = TTF_OpenFont("..\\static\\fonts\\Montserrat-SemiBold.ttf", 42);
        drawText(input.c_str(), font, {252, 247, 235, 200}, SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.52);

        font = TTF_OpenFont("..\\static\\fonts\\Montserrat-Regular.ttf", 25);
        drawText("press enter to continue", font, {238, 232, 219, 35}, SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.58);
    }

    SDL_RenderPresent(renderer);
    return true;
}

bool selectColor() {
    SDL_Event e;
    SDL_Rect dest;
    SDL_Color foreground = {238, 232, 219, 35};
    SDL_Surface *text_surf;
    SDL_Texture *text;

    while (SDL_PollEvent(&e) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                close();

                // ќбработка клика
            case SDL_KEYDOWN:
                // ¬ыйти с текущего окна, если нажат ENTER
                if (e.key.keysym.sym == SDLK_RETURN) {
                    return false;
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, background, NULL, NULL);

                font = TTF_OpenFont("..\\static\\fonts\\Montserrat-Regular.ttf", 25);
                text_surf = TTF_RenderText_Solid(font, "press enter to confirm", foreground);

                if (e.motion.x >= 135 && e.motion.x <= 200 && e.motion.y >= 280 && e.motion.y <= 345) {
                    drawSelectedCircle(168, 315, 40, 3, 255, 255, 255, 200);

                    array_color = {218, 9, 30, 255};

                    font = TTF_OpenFont("..\\static\\fonts\\Montserrat-Regular.ttf", 25);
                    text_surf = TTF_RenderText_Solid(font, "press enter to confirm", foreground);
                    text = SDL_CreateTextureFromSurface(renderer, text_surf);

                    dest.x = SCREEN_WIDTH / 2 - text_surf->w / 2;
                    dest.y = SCREEN_HEIGHT * 0.58;
                    dest.w = text_surf->w;
                    dest.h = text_surf->h;
                    SDL_RenderCopy(renderer, text, NULL, &dest);
                } else if (e.motion.x >= 235 && e.motion.x <= 300 && e.motion.y >= 280 && e.motion.y <= 345) {
                    drawSelectedCircle(266, 315, 40, 3, 255, 255, 255, 200);

                    array_color = {207, 101, 43, 255};

                    font = TTF_OpenFont("..\\static\\fonts\\Montserrat-Regular.ttf", 25);
                    text_surf = TTF_RenderText_Solid(font, "press enter to confirm", foreground);
                    text = SDL_CreateTextureFromSurface(renderer, text_surf);

                    dest.x = SCREEN_WIDTH / 2 - text_surf->w / 2;
                    dest.y = SCREEN_HEIGHT * 0.58;
                    dest.w = text_surf->w;
                    dest.h = text_surf->h;
                    SDL_RenderCopy(renderer, text, NULL, &dest);
                } else if (e.motion.x >= 335 && e.motion.x <= 400 && e.motion.y >= 280 && e.motion.y <= 345) {
                    drawSelectedCircle(364, 315, 40, 3, 255, 255, 255, 200);

                    array_color = {255, 243, 67, 255};

                    font = TTF_OpenFont("..\\static\\fonts\\Montserrat-Regular.ttf", 25);
                    text_surf = TTF_RenderText_Solid(font, "press enter to confirm", foreground);
                    text = SDL_CreateTextureFromSurface(renderer, text_surf);

                    dest.x = SCREEN_WIDTH / 2 - text_surf->w / 2;
                    dest.y = SCREEN_HEIGHT * 0.58;
                    dest.w = text_surf->w;
                    dest.h = text_surf->h;
                    SDL_RenderCopy(renderer, text, NULL, &dest);
                } else if (e.motion.x >= 435 && e.motion.x <= 500 && e.motion.y >= 280 && e.motion.y <= 345) {
                    drawSelectedCircle(462, 315, 40, 3, 255, 255, 255, 200);

                    array_color = {82, 172, 98, 255};

                    font = TTF_OpenFont("..\\static\\fonts\\Montserrat-Regular.ttf", 25);
                    text_surf = TTF_RenderText_Solid(font, "press enter to confirm", foreground);
                    text = SDL_CreateTextureFromSurface(renderer, text_surf);

                    dest.x = SCREEN_WIDTH / 2 - text_surf->w / 2;
                    dest.y = SCREEN_HEIGHT * 0.58;
                    dest.w = text_surf->w;
                    dest.h = text_surf->h;
                    SDL_RenderCopy(renderer, text, NULL, &dest);
                } else if (e.motion.x >= 535 && e.motion.x <= 600 && e.motion.y >= 280 && e.motion.y <= 345) {
                    drawSelectedCircle(560, 315, 40, 3, 255, 255, 255, 200);

                    array_color = {106, 192, 243, 255};

                    font = TTF_OpenFont("..\\static\\fonts\\Montserrat-Regular.ttf", 25);
                    text_surf = TTF_RenderText_Solid(font, "press enter to confirm", foreground);
                    text = SDL_CreateTextureFromSurface(renderer, text_surf);

                    dest.x = SCREEN_WIDTH / 2 - text_surf->w / 2;
                    dest.y = SCREEN_HEIGHT * 0.58;
                    dest.w = text_surf->w;
                    dest.h = text_surf->h;
                    SDL_RenderCopy(renderer, text, NULL, &dest);
                } else if (e.motion.x >= 635 && e.motion.x <= 700 && e.motion.y >= 280 && e.motion.y <= 345) {
                    drawSelectedCircle(658, 315, 40, 3, 255, 255, 255, 200);

                    array_color = {77, 103, 172, 255};

                    font = TTF_OpenFont("..\\static\\fonts\\Montserrat-Regular.ttf", 25);
                    text_surf = TTF_RenderText_Solid(font, "press enter to confirm", foreground);
                    text = SDL_CreateTextureFromSurface(renderer, text_surf);

                    dest.x = SCREEN_WIDTH / 2 - text_surf->w / 2;
                    dest.y = SCREEN_HEIGHT * 0.58;
                    dest.w = text_surf->w;
                    dest.h = text_surf->h;
                    SDL_RenderCopy(renderer, text, NULL, &dest);
                } else if (e.motion.x >= 735 && e.motion.x <= 800 && e.motion.y >= 280 && e.motion.y <= 345) {
                    drawSelectedCircle(756, 315, 40, 3, 255, 255, 255, 200);

                    array_color = {220, 120, 173, 255};

                    font = TTF_OpenFont("..\\static\\fonts\\Montserrat-Regular.ttf", 25);
                    text_surf = TTF_RenderText_Solid(font, "press enter to confirm", foreground);
                    text = SDL_CreateTextureFromSurface(renderer, text_surf);

                    dest.x = SCREEN_WIDTH / 2 - text_surf->w / 2;
                    dest.y = SCREEN_HEIGHT * 0.58;
                    dest.w = text_surf->w;
                    dest.h = text_surf->h;
                    SDL_RenderCopy(renderer, text, NULL, &dest);
                } else if (e.motion.x >= 835 && e.motion.x <= 900 && e.motion.y >= 280 && e.motion.y <= 345) {
                    drawSelectedCircle(854, 315, 40, 3, 255, 255, 255, 200);

                    array_color = {208, 208, 208, 255};

                    font = TTF_OpenFont("..\\static\\fonts\\Montserrat-Regular.ttf", 25);
                    text_surf = TTF_RenderText_Solid(font, "press enter to confirm", foreground);
                    text = SDL_CreateTextureFromSurface(renderer, text_surf);

                    dest.x = SCREEN_WIDTH / 2 - text_surf->w / 2;
                    dest.y = SCREEN_HEIGHT * 0.58;
                    dest.w = text_surf->w;
                    dest.h = text_surf->h;
                    SDL_RenderCopy(renderer, text, NULL, &dest);
                }
                SDL_RenderPresent(renderer);
        }
    }
    return true;
}

void selectLab() {
    bool selected = false;
    SDL_Event e;

    while (!selected) {
        while (SDL_PollEvent(&e) != 0) {
            installSurface(MainSurfaces[static_cast<int>(SURFACES::SELECT_LAB)]);
            if (e.type == SDL_QUIT) {
                close();
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.motion.x >= 485 && e.motion.x <= 536 && e.motion.y >= 150 && e.motion.y <= 193) {
                    installSurface(LabSurfaces[static_cast<int>(SELECT_LAB::LAB_1)]);
                    SDL_Delay(100);
                    selected = true;
                    //firstLab();
                }

                if (e.motion.x >= 485 && e.motion.x <= 536 && e.motion.y >= 250 && e.motion.y <= 293) {
                    installSurface(LabSurfaces[static_cast<int>(SELECT_LAB::LAB_2)]);
                    SDL_Delay(100);
                    selected = true;
                    secondLab();
                }

                if (e.motion.x >= 485 && e.motion.x <= 536 && e.motion.y >= 348 && e.motion.y <= 392) {
                    installSurface(LabSurfaces[static_cast<int>(SELECT_LAB::LAB_3)]);
                    SDL_Delay(100);
                    selected = true;
                }

                if (e.motion.x >= 485 && e.motion.x <= 536 && e.motion.y >= 445 && e.motion.y <= 487) {
                    installSurface(LabSurfaces[static_cast<int>(SELECT_LAB::LAB_4)]);
                    SDL_Delay(100);
                    selected = true;
                }
            }
        }
    }
}

void settingsPage() {
    SDL_Event e;
    bool next = false;

    while (!next) {
        while (SDL_PollEvent(&e) != 0) {
            installSurface(MainSurfaces[static_cast<int>(SURFACES::SETTINGS_PAGE)]);
            if (e.type == SDL_QUIT) {
                close();
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.motion.x >= 325 && e.motion.x <= 700 && e.motion.y >= 202 && e.motion.y <= 250) {
                    background = createTexture(SettingsSurfaces[static_cast<int>(SETTINGS_PAGE::SELECTED_SIZE)]);
                    SDL_Delay(100);

                    while (sizeEntering()) {
                        SDL_Delay(40);
                    }

                    if (!input.empty() && stoi(input) != 0) {
                        ARRAY_SIZE = ((stoi(input) > 100000) ? 100000 : stoi(input));
                        RECT_SIZE = (double) ARRAY_WIDTH / ARRAY_SIZE;
                        delete[] arr, fill_arr;
                        arr = new int[ARRAY_SIZE];
                        fill_arr = new int[ARRAY_SIZE];
                        randomizeArray();
                    }
                }

                if (e.motion.x >= 380 && e.motion.x <= 650 && e.motion.y >= 294 && e.motion.y <= 340) {
                    installSurface(SettingsSurfaces[static_cast<int>(SETTINGS_PAGE::SELECTED_COLOR)]);
                    SDL_Delay(100);
                    installSurface(IMG_Load("..\\static\\images\\settings_page\\select-color.png"));;
                    background = createTexture(IMG_Load("..\\static\\images\\settings_page\\select-color.png"));
                    while (selectColor());

                }

                if (e.motion.x >= 358 && e.motion.x <= 661 && e.motion.y >= 387 && e.motion.y <= 567) {
                    installSurface(SettingsSurfaces[static_cast<int>(SETTINGS_PAGE::SELECTED_LAB)]);
                    SDL_Delay(100);

                    selectLab();
                }

                if (e.motion.x >= 865 && e.motion.x <= 970 && e.motion.y >= 560 && e.motion.y <= 600) {
                    installSurface(MainSurfaces[static_cast<int>(SURFACES::SELECT_SORT)]);
                    next = true;
                }
            }
        }
    }
}


void run() {
    if (!init()) {
        std::cout << "SDL Initialization Failed.\n";
    } else {
        SDL_Event e;
        bool quit = false;
        bool title = true;
        // ќжидание пока пользователь перейдет к окну выбора сортировок

        while (title) {
            SDL_PollEvent(&e);
            if (e.type == SDL_QUIT) {
                close();
            } else if (e.type == SDL_KEYUP) {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        close();
                        break;
                    default:
                        installSurface(MainSurfaces[static_cast<int>(SURFACES::HOW_TO_USE)]);
                        SDL_Event ev;
                        SDL_Delay(50);
                        SDL_PollEvent(&ev);
                        if (ev.type == SDL_QUIT) {
                            close();
                        }
                        if (ev.key.keysym.sym) {
                            settingsPage();
                            title = false;
                        }
                        break;
                }
            }
        }
        randomizeArray();

        while (!quit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                    complete = false;
                } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                    prepareArray();
                    complete = false;
                    if (e.motion.x >= 370 && e.motion.x <= 652 && e.motion.y >= 177 && e.motion.y <= 214) {
                        installSurface(SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_1)]);
                        SDL_Delay(100);
                        bubbleSort(true);
                        SDL_Delay(1500);
                        installSurface(MainSurfaces[static_cast<int>(SURFACES::SELECT_SORT)]);
                    } else if (e.motion.x >= 350 && e.motion.x <= 676 && e.motion.y >= 230 && e.motion.y <= 270) {
                        installSurface(SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_2)]);
                        SDL_Delay(100);
                        insertionSort();
                        SDL_Delay(1500);
                        installSurface(MainSurfaces[static_cast<int>(SURFACES::SELECT_SORT)]);
                    } else if (e.motion.x >= 348 && e.motion.x <= 676 && e.motion.y >= 285 && e.motion.y <= 323) {
                        installSurface(SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_3)]);
                        SDL_Delay(100);
                        selectionSort();
                        SDL_Delay(1500);
                        installSurface(MainSurfaces[static_cast<int>(SURFACES::SELECT_SORT)]);
                    } else if (e.motion.x >= 368 && e.motion.x <= 675 && e.motion.y >= 343 && e.motion.y <= 378) {
                        installSurface(SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_4)]);
                        SDL_Delay(100);
                        mergeSort(arr, 0, ARRAY_SIZE - 1);
                        SDL_Delay(1500);
                        installSurface(MainSurfaces[static_cast<int>(SURFACES::SELECT_SORT)]);
                    } else if (e.motion.x >= 388 && e.motion.x <= 657 && e.motion.y >= 398 && e.motion.y <= 435) {
                        installSurface(SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_5)]);
                        SDL_Delay(100);
                        inplaceHeapSort(arr, ARRAY_SIZE, true);
                        SDL_Delay(1500);
                        installSurface(MainSurfaces[static_cast<int>(SURFACES::SELECT_SORT)]);
                    } else if (e.motion.x >= 383 && e.motion.x <= 642 && e.motion.y >= 451 && e.motion.y <= 498) {
                        installSurface(SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_6)]);
                        SDL_Delay(100);
                        quickSort(&arr[0], &arr[ARRAY_SIZE], true);
                        complete = true;
                        drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::QUICK_SORT)]));
                        SDL_Delay(1500);
                        installSurface(MainSurfaces[static_cast<int>(SURFACES::SELECT_SORT)]);
                    } else if (e.motion.x >= 425 && e.motion.x <= 600 && e.motion.y >= 514 && e.motion.y <= 546) {
                        installSurface(SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_7)]);
                        SDL_Delay(100);
                        close();
                    }
                }
            }
        }
        close();
    }
}

int main(int argc, char *argv[]) {
    run();
    return 0;
}
