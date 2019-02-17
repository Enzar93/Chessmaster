#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
        SDL_Window* window;
        SDL_Renderer* renderer;

        // Initialize SDL.
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
                return 1;

        // Create the window where we will draw.
        window = SDL_CreateWindow("SDL_RenderClear",
                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                        512, 512,
                        0);

        // We must call SDL_CreateRenderer in order for draw calls to affect this window.
        renderer = SDL_CreateRenderer(window, -1, 0);

        // Select the color for drawing. It is set to red here.
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        // Clear the entire screen to our selected color.
        SDL_RenderClear(renderer);

        // Up until now everything was drawn behind the scenes.
        // This will show the new, red contents of the window.
        SDL_RenderPresent(renderer);

        // Give us time to see the window.
        SDL_Delay(5000);

        // Always be sure to clean up
        SDL_Quit();
        return 0;
}
