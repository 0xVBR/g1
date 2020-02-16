#include "main.h"

#define WINDOW_TITLE "Game 1"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main (int argc, char* argv[]){
        int exit_flag = EXIT_SUCCESS;
        struct Game game;

        if(init_game(&game) != EXIT_SUCCESS){
                exit_flag = EXIT_FAILURE;
                goto cleanup;  
        };

        SDL_Texture* texture = NULL;
        texture = load_texture("res/0001.png", game.renderer);

        game.running = 1;
        while(game.running == 1){

                while(SDL_PollEvent(&game.event) != 0){
                        if(game.event.type == SDL_QUIT){
                                game.running = 0;
                        };
                };

                SDL_SetRenderDrawColor(game.renderer, 160, 160, 160, 0);
                SDL_RenderClear(game.renderer);
                SDL_RenderCopy(game.renderer, texture, NULL, NULL);
                SDL_RenderPresent(game.renderer);
        };

cleanup:        
        exit_game(&game);
        return exit_flag;
}

int init_game(struct Game* game)
{
        int exit_flag = EXIT_SUCCESS;

        printf("Initializing SDL... \n");
        if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
                printf("SDL_Init error: %s\n", SDL_GetError());
                exit_flag = EXIT_FAILURE;
        };

        printf("Creating game window... \n");        
        game->window = SDL_CreateWindow(WINDOW_TITLE, 
                                        SDL_WINDOWPOS_CENTERED, 
                                        SDL_WINDOWPOS_CENTERED, 
                                        WINDOW_WIDTH, 
                                        WINDOW_HEIGHT, 
                                        0);
        if(game->window == NULL){
                printf("SDL_CreateWindow error: %s\n", SDL_GetError());
                exit_flag = EXIT_FAILURE;
        };

        printf("Creating game renderer... \n");  
        game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
        if(game->renderer == NULL){
                printf("SDL_CreateRenderer error: %s\n", SDL_GetError());
                exit_flag = EXIT_FAILURE;
        };

        return exit_flag;
};

int exit_game(struct Game* game)
{
        int exit_flag = EXIT_SUCCESS;

        if(game->renderer != NULL){
                printf("Destroying game renderer... \n"); 
                SDL_DestroyRenderer(game->renderer);
        };

        if(game->window != NULL){
                printf("Destroying game window... \n"); 
                SDL_DestroyWindow(game->window);
        };

        printf("Quitting SDL... \n");        
        SDL_Quit();

        return exit_flag;
};


