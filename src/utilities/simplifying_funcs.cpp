#include "simplifying_funcs.h"

void installSurface(SDL_Surface *newSurface) {
    SDL_BlitSurface(newSurface, nullptr, screenSurface, nullptr);
    SDL_UpdateWindowSurface(window);
}

SDL_Texture *createTexture(SDL_Surface *surface) {
    SDL_Texture *texture = NULL;
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) {
        std::cout << "Couldn't initialize texture. SDL_Error:" << SDL_GetError();
    }
    return texture;
}

void handleKeyboard() {
    SDL_Event pause_handle;
    SDL_PollEvent(&e);
    if (e.key.keysym.sym == SDLK_SPACE && e.type == SDL_KEYDOWN) {
        SDL_Delay(70);
        do {
            SDL_PollEvent(&pause_handle);
        } while (pause_handle.key.keysym.sym != SDLK_SPACE && pause_handle.type != SDL_KEYUP);
    } else if (e.key.keysym.sym == SDLK_RIGHT) return;
}

bool init() {
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Couldn't initialize SDL. SDL_Error: " << SDL_GetError();
        success = false;
    } else {
        // ������������� �������� png ��������
        int imgFlag{IMG_INIT_PNG || IMG_INIT_JPG};
        if (!(IMG_Init(imgFlag) & imgFlag)) {
            std::cout << IMG_GetError;
        }

        // �������������� �������
        if (TTF_Init() < 0) {
            std::cout << "Error intializing SDL_ttf: " << TTF_GetError() << std::endl;
            return false;
        }

        font = TTF_OpenFont("..\\static\\fonts\\Montserrat-SemiBold.ttf", 50);
        if (!font) {
            std::cout << "Error loading font: " << TTF_GetError() << std::endl;
            return false;
        }

        // �������� ����
        window = SDL_CreateWindow("Algorithm", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (window == NULL) {
            std::cout << "Couldn't create window. SDL_Error: " << SDL_GetError();
            success = false;
        } else {
            screenSurface = SDL_GetWindowSurface(window);
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

            if (renderer == NULL) {
                std::cout << "Couldn't create renderer. SDL_Error: " << SDL_GetError();
                success = false;
            }
        }

        // �������� ���� ������������
        loadMedia();

        background = createTexture(IMG_Load("..\\static\\images\\main\\bg.png"));
        //���������� ����������� �� ���������
        installSurface(MainSurfaces[static_cast<int>(SURFACES::MAIN_PAGE)]);
    }
    return success;
}

void close() {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
    IMG_Quit();
}