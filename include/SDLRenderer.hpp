#pragma once
#include <IMonitorDisplay.hpp>
#include <SDL2/SDL.h>
int		key_press(SDL_Event *e);

class SDLRenderer : public IMonitorDisplay
{
	public:
		void		draw(void);
		SDLRenderer();
		~SDLRenderer();
		SDL_Renderer *getRenderer(void);
		SDL_Window *getWindow(void);
		SDL_Surface *getSurface(void);

	private:
		SDLRenderer(SDLRenderer const &source);
		SDLRenderer & operator=(const SDLRenderer & rhs);
		SDL_Window *window;
		SDL_Surface *surface;
		SDL_Renderer *renderer;
};