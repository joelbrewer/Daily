#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char ** argv)
{
	int quit;
	quit = 0;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * screen = SDL_CreateWindow("My SDL Empty Window",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

	while (quit != 1)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
			case SDL_QUIT:
				quit = 1;
				break;
		}
	}

	SDL_Quit();

	return 0;
}
