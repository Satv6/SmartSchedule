#include<stdio.h>
#include<SDL2/SDL.h>
#include <stdbool.h>
void botonX();
SDL_Window * window = NULL; //ventana que se va a mostrar
SDL_Surface * screenSurface = NULL; //superficie donde se va a mostrar
void botonX(){//hacer que el programa cierre hasta que le den al boton X
			bool quit = false;
			SDL_Event e;
			while( !quit )
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}
            }
}

int main (int argc, char * args []) {

     if(SDL_Init(SDL_INIT_VIDEO)<0){
        printf("Error no se pudo iniciar SDL SDL_ERROR: %c",SDL_GetError());
     }
       else {
        window = SDL_CreateWindow ("Agenda", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
       if (window == NULL) {
            printf ("No se pudo crear la ventana SDL_Error:% s \ n", SDL_GetError ());
       }

       else {
            screenSurface = SDL_GetWindowSurface (window); //obtener superficie
            SDL_FillRect (screenSurface, NULL, SDL_MapRGB (screenSurface-> format, 0x33,0x66,0xFF)); //rellena la superficie
            SDL_UpdateWindowSurface(window);
            botonX();

            }
        }
    SDL_DestroyWindow (window);
    SDL_Quit ();
    return 0;
     }



