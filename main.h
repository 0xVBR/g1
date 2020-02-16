#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "player.h"

struct Game {
        int running;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;
};

int init_game(struct Game* game);
int exit_game(struct Game* game);
