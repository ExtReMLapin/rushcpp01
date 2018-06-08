#include "Computer.hpp"

#include <iostream>

Computer::Computer(bool isGUI) : _isGUI(isGUI)
{
	if (_isGUI)
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow(
		"ft_gkrellm",                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		1920,                               // width, in pixels
		1080,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
		);
		if (window == NULL) {
			std::cout << "Could not create window:" << SDL_GetError() << std::endl;
			
		}
	}

	if (!_isGUI) // like failed sdl thing
	{
		//ncurseinit
	}

}
Computer::~Computer()
{

}

Computer::Computer (const Computer& src)
{
	(void)src;
}

Computer &Computer::operator=(const Computer& src)
{
	(void)src;
	return (*this);
}

