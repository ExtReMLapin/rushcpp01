#include <Computer.hpp>

#include <iostream>



Computer::Computer(bool isGUI) : _isGUI(isGUI)
{
	if (_isGUI)
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		this->window = SDL_CreateWindow(
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
		this->surface = SDL_GetWindowSurface(this->window);
		this->renderer = SDL_CreateSoftwareRenderer(this->surface);
		SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
	}

	if (!_isGUI) // like failed sdl, so don't use else
	{

	}
}


bool Computer::isGUI(void) const
{
	return (_isGUI);
}

void Computer::setGUI(bool gui)
{
	this->_isGUI = gui;
}
  
Computer::Computer()
{

}



Computer::~Computer()
{

}

Computer::Computer (const Computer& src)
{
	*this = src;
	(void)src;
}

Computer &Computer::operator=(const Computer& src)
{
	this->_isGUI = src._isGUI; 
	return (*this);
}

