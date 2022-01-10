#include "load_media.h"

bool loadMedia() {
    //�������� ������������ SURFACES
    {
        MainSurfaces[static_cast<int>(SURFACES::MAIN_PAGE)] = IMG_Load("..\\static\\images\\main\\welcome-page.png");
        if (MainSurfaces[static_cast<int>(SURFACES::MAIN_PAGE)] == NULL) {
            std::cout << "Couldn't initialize MAIN_PAGE image" << SDL_GetError();
            return false;
        }

        MainSurfaces[static_cast<int>(SURFACES::SELECT_SORT)] = IMG_Load("..\\static\\images\\main\\select-sort.png");
        if (MainSurfaces[static_cast<int>(SURFACES::SELECT_SORT)] == NULL) {
            std::cout << "Couldn't initialize MAIN_PAGE image" << SDL_GetError();
            return false;
        }

        MainSurfaces[static_cast<int>(SURFACES::SETTINGS_PAGE)] = IMG_Load("..\\static\\images\\main\\settings-page.png");
        if (MainSurfaces[static_cast<int>(SURFACES::SETTINGS_PAGE)] == NULL) {
            std::cout << "Couldn't initialize MAIN_PAGE image" << SDL_GetError();
            return false;
        }

        MainSurfaces[static_cast<int>(SURFACES::HOW_TO_USE)] = IMG_Load("..\\static\\images\\main\\how-to-use.png");
        if (MainSurfaces[static_cast<int>(SURFACES::HOW_TO_USE)] == NULL) {
            std::cout << "Couldn't initialize MAIN_PAGE image" << SDL_GetError();
            return false;
        }

        MainSurfaces[static_cast<int>(SURFACES::SELECT_LAB)] = IMG_Load("..\\static\\images\\main\\select-lab.png");
        if (MainSurfaces[static_cast<int>(SURFACES::SELECT_LAB)] == NULL) {
            std::cout << "Couldn't initialize MAIN_PAGE image" << SDL_GetError();
            return false;
        }
    }

    //�������� ������������ SETTINGS_PAGE
    {
        SettingsSurfaces[static_cast<int>(SETTINGS_PAGE::SELECTED_SIZE)] = IMG_Load(
                "..\\static\\images\\settings_page\\enter-size.png");
        if (SettingsSurfaces[static_cast<int>(SETTINGS_PAGE::SELECTED_SIZE)] == NULL) {
            std::cout << "Couldn't initialize SETTINGS_PAGE image" << SDL_GetError();
            return false;
        }

        SettingsSurfaces[static_cast<int>(SETTINGS_PAGE::SELECTED_COLOR)] = IMG_Load(
                "..\\static\\images\\settings_page\\selected-2.png");
        if (SettingsSurfaces[static_cast<int>(SETTINGS_PAGE::SELECTED_COLOR)] == NULL) {
            std::cout << "Couldn't initialize SETTINGS_PAGE image" << SDL_GetError();
            return false;
        }

        SettingsSurfaces[static_cast<int>(SETTINGS_PAGE::SELECTED_LAB)] = IMG_Load(
                "..\\static\\images\\settings_page\\selected-3.png");
        if (SettingsSurfaces[static_cast<int>(SETTINGS_PAGE::SELECTED_LAB)] == NULL) {
            std::cout << "Couldn't initialize SETTINGS_PAGE image" << SDL_GetError();
            return false;
        }

        SettingsSurfaces[static_cast<int>(SETTINGS_PAGE::SELECTED_NEXT)] = IMG_Load(
                "..\\static\\images\\settings_page\\selected-next.png");
        if (SettingsSurfaces[static_cast<int>(SETTINGS_PAGE::SELECTED_NEXT)] == NULL) {
            std::cout << "Couldn't initialize SETTINGS_PAGE image" << SDL_GetError();
            return false;
        }
    }

    //�������� ������������ SORTS
    {
        SortSurfaces[static_cast<int>(SORTS::BUBBLE_SORT)] = IMG_Load("..\\static\\images\\sorts\\bubble-sort.png");
        if (SortSurfaces[static_cast<int>(SORTS::BUBBLE_SORT)] == NULL) {
            std::cout << "Couldn't initialize BUBBLE_SORT image" << SDL_GetError();
            return false;
        }

        SortSurfaces[static_cast<int>(SORTS::HEAP_SORT)] = IMG_Load("..\\static\\images\\sorts\\heap-sort.png");
        if (SortSurfaces[static_cast<int>(SORTS::HEAP_SORT)] == NULL) {
            std::cout << "Couldn't initialize HEAP_SORT image" << SDL_GetError();
            return false;
        }

        SortSurfaces[static_cast<int>(SORTS::INSERTION_SORT)] = IMG_Load("..\\static\\images\\sorts\\insertion-sort.png");
        if (SortSurfaces[static_cast<int>(SORTS::INSERTION_SORT)] == NULL) {
            std::cout << "Couldn't initialize INSERTION_SORT image" << SDL_GetError();
            return false;
        }

        SortSurfaces[static_cast<int>(SORTS::MERGE_SORT)] = IMG_Load("..\\static\\images\\sorts\\merge-sort.png");
        if (SortSurfaces[static_cast<int>(SORTS::MERGE_SORT)] == NULL) {
            std::cout << "Couldn't initialize MERGE_SORT image" << SDL_GetError();
            return false;
        }

        SortSurfaces[static_cast<int>(SORTS::QUICK_SORT)] = IMG_Load("..\\static\\images\\sorts\\quick-sort.png");
        if (SortSurfaces[static_cast<int>(SORTS::QUICK_SORT)] == NULL) {
            std::cout << "Couldn't initialize QUICK_SORT image" << SDL_GetError();
            return false;
        }

        SortSurfaces[static_cast<int>(SORTS::SELECTION_SORT)] = IMG_Load("..\\static\\images\\sorts\\selection-sort.png");
        if (SortSurfaces[static_cast<int>(SORTS::SELECTION_SORT)] == NULL) {
            std::cout << "Couldn't initialize SELECTION_SORT image" << SDL_GetError();
            return false;
        }
    }

    //�������� ������������ SELECT_PAGE
    {
        SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_1)] = IMG_Load("..\\static\\images\\select-page\\selected-1.png");
        if (SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_1)] == NULL) {
            std::cout << "Couldn't initialize SELECT_PAGE::SELECTED_1 image" << SDL_GetError();
            return false;
        }
        SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_2)] = IMG_Load("..\\static\\images\\select-page\\selected-2.png");
        if (SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_2)] == NULL) {
            std::cout << "Couldn't initialize SELECT_PAGE::SELECTED_2 image" << SDL_GetError();
            return false;
        }
        SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_3)] = IMG_Load("..\\static\\images\\select-page\\selected-3.png");
        if (SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_3)] == NULL) {
            std::cout << "Couldn't initialize SELECT_PAGE::SELECTED_3 image" << SDL_GetError();
            return false;
        }
        SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_3)] = IMG_Load("..\\static\\images\\select-page\\selected-3.png");
        if (SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_3)] == NULL) {
            std::cout << "Couldn't initialize SELECT_PAGE::SELECTED_3 image" << SDL_GetError();
            return false;
        }
        SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_4)] = IMG_Load("..\\static\\images\\select-page\\selected-4.png");
        if (SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_4)] == NULL) {
            std::cout << "Couldn't initialize SELECT_PAGE::SELECTED_4 image" << SDL_GetError();
            return false;
        }
        SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_5)] = IMG_Load("..\\static\\images\\select-page\\selected-5.png");
        if (SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_5)] == NULL) {
            std::cout << "Couldn't initialize SELECT_PAGE::SELECTED_5 image" << SDL_GetError();
            return false;
        }
        SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_6)] = IMG_Load("..\\static\\images\\select-page\\selected-6.png");
        if (SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_6)] == NULL) {
            std::cout << "Couldn't initialize SELECT_PAGE::SELECTED_6 image" << SDL_GetError();
            return false;
        }
        SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_7)] = IMG_Load("..\\static\\images\\select-page\\selected-7.png");
        if (SelectSurfaces[static_cast<int>(SELECT_PAGE::SELECTED_7)] == NULL) {
            std::cout << "Couldn't initialize SELECT_PAGE::SELECTED_7 image" << SDL_GetError();
            return false;
        }
    }

    //�������� ������������ SELECT_LAB
    {
        LabSurfaces[static_cast<int>(SELECT_LAB::LAB_1)] = IMG_Load("..\\static\\images\\select-lab\\selected-1.png");
        if (LabSurfaces[static_cast<int>(SELECT_LAB::LAB_1)] == NULL) {
            std::cout << "Couldn't initialize SELECT_LAB image" << SDL_GetError();
            return false;
        }

        LabSurfaces[static_cast<int>(SELECT_LAB::LAB_2)] = IMG_Load("..\\static\\images\\select-lab\\selected-2.png");
        if (LabSurfaces[static_cast<int>(SELECT_LAB::LAB_2)] == NULL) {
            std::cout << "Couldn't initialize SELECT_LAB image" << SDL_GetError();
            return false;
        }

        LabSurfaces[static_cast<int>(SELECT_LAB::LAB_3)] = IMG_Load("..\\static\\images\\select-lab\\selected-3.png");
        if (LabSurfaces[static_cast<int>(SELECT_LAB::LAB_3)] == NULL) {
            std::cout << "Couldn't initialize SELECT_LAB image" << SDL_GetError();
            return false;
        }

        LabSurfaces[static_cast<int>(SELECT_LAB::LAB_3)] = IMG_Load("..\\static\\images\\select-lab\\selected-3.png");
        if (LabSurfaces[static_cast<int>(SELECT_LAB::LAB_3)] == NULL) {
            std::cout << "Couldn't initialize SELECT_LAB image" << SDL_GetError();
            return false;
        }

        LabSurfaces[static_cast<int>(SELECT_LAB::LAB_3)] = IMG_Load("..\\static\\images\\select-lab\\selected-3.png");
        if (LabSurfaces[static_cast<int>(SELECT_LAB::LAB_3)] == NULL) {
            std::cout << "Couldn't initialize SELECT_LAB image" << SDL_GetError();
            return false;
        }
    }
    return true;
}