#include <stdio.h>
#include <stdlib.h>

#include "SDL2/SDL.h"

/* This function may run in a separate event thread */
int FilterEvents(const SDL_Event *event) {
    static int boycott = 1;

    /* This quit event signals the closing of the window */
    if ( (event->type == SDL_QUIT) && boycott ) {
        printf("Quit event filtered out -- try again.\n");
        boycott = 0;
        return(0);
    }
    if ( event->type == SDL_MOUSEMOTION ) {
        printf("Mouse moved to (%d,%d)\n",
                event->motion.x, event->motion.y);
        return(0);    /* Drop it, we've handled it */
    }
    return(1);
}

int main(int argc, char *argv[])
{
    SDL_Event event;

    /* Initialize the SDL library (starts the event loop) */
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        fprintf(stderr,
                "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    /* Clean up on exit, exit on window close and interrupt */
    atexit(SDL_Quit);

    /* Ignore key events */
    SDL_EventState(SDL_KEYDOWN, SDL_IGNORE);
    SDL_EventState(SDL_KEYUP, SDL_IGNORE);

    /* Filter quit and mouse motion events */
    SDL_SetEventFilter(FilterEvents);

    /* The mouse isn't much use unless we have a display for reference */
    if ( SDL_SetVideoMode(640, 480, 8, 0) == NULL ) {
        fprintf(stderr, "Couldn't set 640x480x8 video mode: %s\n",
                        SDL_GetError());
        exit(1);
    }

    /* Loop waiting for ESC+Mouse_Button */
    while ( SDL_WaitEvent(&event) >= 0 ) {
        switch (event.type) {
            case SDL_ACTIVEEVENT: {
                if ( event.active.state & SDL_APPACTIVE ) {
                    if ( event.active.gain ) {
                        printf("App activated\n");
                    } else {
                        printf("App iconified\n");
                    }
                }
            }
            break;
                    
            case SDL_MOUSEBUTTONDOWN: {
                Uint8 *keys;

                keys = SDL_GetKeyState(NULL);
                if ( keys[SDLK_ESCAPE] == SDL_PRESSED ) {
                    printf("Bye bye...\n");
                    exit(0);
                }
                printf("Mouse button pressed\n");
            }
            break;

            case SDL_QUIT: {
                printf("Quit requested, quitting.\n");
                exit(0);
            }
            break;
        }
    }
    /* This should never happen */
    printf("SDL_WaitEvent error: %s\n", SDL_GetError());
    exit(1);
}