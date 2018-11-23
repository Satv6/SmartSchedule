#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

//Dimensiones constantes de la ventana
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[])
{
    SDL_Window *ventana = NULL;
    SDL_Surface *pantalla = NULL;
    SDL_Event evento;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr, "No se ha podido inicializar SDL de forma correcta: %s\n", SDL_GetError());
        exit(1);
    }
    else{
        ventana = SDL_CreateWindow("SmartSchedule", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(ventana == NULL){
            printf("La ventana no ha podido ser creada. Error: %s\n", SDL_GetError());
        }
        else{
            pantalla = SDL_GetWindowSurface(ventana);

            //Rellenar la pantalla de color banco
            SDL_FillRect(pantalla, NULL, SDL_MapRGB(pantalla->format, 0xFF, 0xFF, 0xFF));
            //Actualizar la ventana
            SDL_UpdateWindowSurface(ventana);
            SDL_Delay(3000);
        }
    }

    SDL_DestroyWindow(ventana);
    SDL_Quit();
    return 0;
}
