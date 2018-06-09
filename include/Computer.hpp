#pragma once
#include <SDL2/SDL.h>
int		key_press(SDL_Event *e);

class Computer
{
	public:
		Computer(bool isGUI);
		~Computer();
		SDL_Window *window;
		SDL_Surface *surface;
		SDL_Renderer *renderer;
		bool isGUI(void) const;
		Computer (const Computer&);
		Computer &operator=(const Computer&);
		Computer();
		void setGUI(bool gui);
	private:
		

		bool _isGUI;

	
};

extern Computer g_computer;