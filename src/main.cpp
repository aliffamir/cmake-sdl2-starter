#include <iostream>
#include <SDL2/SDL.h>

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = nullptr;
SDL_Surface* gScreenSurface = nullptr;
SDL_Surface* gImage = nullptr;

bool init() {
    bool isSuccess = true;

    if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
        std::cout << "SDL could not be initialised. SDL_Error: \n" << SDL_GetError() << '\n';
        isSuccess = false;
    } else {
        // create window
        gWindow = SDL_CreateWindow("My First Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (!gWindow) {
            std::cout << "Window could not be created. SDL_Error: \n" << SDL_GetError() << '\n';
            isSuccess = false;
        } else {
            // get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return isSuccess;
}

bool loadMedia() {
    bool isSuccess = true;

    // load bmp image, use relative path for now
    gImage = SDL_LoadBMP("../block.bmp");
    if(!gImage) {
        std::cout << "Unable to load image. SDL Error: \n" << SDL_GetError() << '\n';
        isSuccess = false;
    }
    
    return isSuccess;
}

void close() {
    // deallocate surface
    SDL_FreeSurface(gImage);
    gImage = nullptr;

    // destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;

    // quit SDL subsystems
    SDL_Quit();
}

int main(int argc, char* args[]) {
    if(!init()) {
        std::cout << "Failed to initialise\n";
    } else {
        // load media
        if(!loadMedia()) {
            std::cout << "Failed to load media\n";
        } else {
            // apply the image
            SDL_BlitSurface(gImage, NULL, gScreenSurface, NULL);

            // update the surface
            SDL_UpdateWindowSurface(gWindow);

            // event loop to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    close();

    return 0;
}