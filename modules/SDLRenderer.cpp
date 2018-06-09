#include "SDLRenderer.hpp"
#include <iostream>


SDL_Event		e;


void SDLRenderer::draw()
{
	Uint32		startclock;
	double		current;

	startclock = SDL_GetTicks();
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
		{
			SDL_DestroyRenderer(this->renderer);
			SDL_DestroyWindow(this->window);
			SDL_Quit();
			exit(0);
		}
	}
	current =  static_cast<double>(SDL_GetTicks() - startclock) / static_cast<double>(1000); // 60fps limit
	if (current < static_cast<double>(1 / 60))
		SDL_Delay(static_cast<uint32_t>((1 / 60 - current) * 1000));
}

SDLRenderer::SDLRenderer()
{
		SDL_Init(SDL_INIT_EVERYTHING);
		this->window = SDL_CreateWindow(
		"ft_gkrellm",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1920,
		1080,
		SDL_WINDOW_OPENGL
		);
		if (window == NULL) {
			std::cout << "Could not create window:" << SDL_GetError() << std::endl;
		}
		this->surface = SDL_GetWindowSurface(this->window);
		this->renderer = SDL_CreateSoftwareRenderer(this->surface);
		SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
}


SDLRenderer::~SDLRenderer()
{

}

SDLRenderer & SDLRenderer::operator=(const SDLRenderer & rhs)
{
	this->window = rhs.window;
	this->surface = rhs.surface;
	this->renderer = rhs.renderer;
	return (*this);
}

SDLRenderer::SDLRenderer(SDLRenderer const &source)
{
	*this = source;
}

