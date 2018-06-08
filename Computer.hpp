#pragma once
#include <SDL2/SDL.h>


class Computer
{
	public:
		Computer(bool isGUI);
		~Computer();

	private:
		Computer();
		Computer (const Computer&);
		Computer &operator=(const Computer&);
		bool _isGUI;
		SDL_Window *window;
	
};