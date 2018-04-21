
#include "SDL2.framework/Headers/SDL.h"
# include "SDL2_ttf.framework/Headers/SDL_ttf.h"

int				main()
{
	SDL_Event	ev;

	SDL_Init(SDL_INIT_VIDEO);
	if (TTF_Init() == -1)
		printf("Error TTF\n");
	SDL_Window *win = SDL_CreateWindow("SDL TTF", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, 0);
	SDL_Surface *surf = SDL_GetWindowSurface(win);
	TTF_Font *font = TTF_OpenFont("police.ttf", 12);
	SDL_Surface *info_box = TTF_RenderText_Shaded(font, "Raytracer", (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255});
	SDL_BlitSurface(info_box, NULL, surf, NULL);
	SDL_UpdateWindowSurface(win);
	while (1)
	{
		SDL_WaitEvent(&ev);
		if (ev.type == SDL_QUIT)
		{
			TTF_CloseFont(font);
			TTF_Quit();
			SDL_FreeSurface(surf);
			SDL_FreeSurface(info_box);
			SDL_DestroyWindow(win);
			SDL_Quit();
			exit(-1);
		}
	}
	return (0);
}
