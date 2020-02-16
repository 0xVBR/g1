#include "player.h"

SDL_Texture* load_texture(char* path, SDL_Renderer* r)
{
        SDL_Texture* texture = NULL;
        SDL_Surface* surface = IMG_Load(path);
        if (surface == NULL){
                printf("Unable to load image %s! Error: %s\n", path, IMG_GetError()); 
        } 
        else {
                texture = SDL_CreateTextureFromSurface(r, surface);
                if (texture == NULL){
                       printf("Unable to create texture %s! Error: %s\n", path, SDL_GetError());  
                };
        };

        SDL_FreeSurface(surface);
        return texture;
};
