#include <iostream>
#include <SDL2/SDL.h>

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
    SDL_Window* window = nullptr;
    SDL_Surface* surface = nullptr;

    if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
        std::cout << "SDL could not be initialised. SDL_Error: \n" << SDL_GetError() << '\n';
    } else {
        // create window
        std::cout << "creating window\n";
        window = SDL_CreateWindow("My First Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (!window) {
            std::cout << "Window could not be created. SDL_Error: \n" << SDL_GetError() << '\n';
        } else {
            // get window surface
            surface = SDL_GetWindowSurface(window);

            //  fill the surface white
            SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

            // update the surface
            SDL_UpdateWindowSurface(window);

            // Hack to get window to stay up - create an event loop
            SDL_Event e; bool quit = false; while(quit == false){ while(SDL_PollEvent(&e)) {if (e.type == SDL_QUIT) quit = true;}}
        }
    }

    // destroy window
    SDL_DestroyWindow(window);

    // quit SDL subsystems
    SDL_Quit();

    return 0;
}