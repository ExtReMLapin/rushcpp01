#include <iostream>
#include <cstring>
#include <Computer.hpp>



static int		event(SDL_Event *e)
{

	if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
	{
		SDL_DestroyRenderer(g_computer.renderer);
		SDL_DestroyWindow(g_computer.window);
		SDL_Quit();
		exit(0);
	}

	return (0);
}



int main(int argc, char const *argv[])
{
	 SDL_Event		e;

	if (argc != 2)
	{
		std::cout << "Please use one of these modes: " << std::endl << "	ft_gkrellm -desktop" << std::endl << "	ft_gkrellm -terminal" << std::endl << "	ft_gkrellm -text" << std::endl;
		return (0);
	}

	if (std::strcmp("-desktop", argv[1]) == 0)
	{
		Computer g_computer(true);
		while (g_computer.isGUI()) // can be false is failed
		{
			while (SDL_PollEvent(&e))
				event(&e);
		}
	}
	else if (std::strcmp("-terminal", argv[1]) == 0)
	{
		std::cout << "terminal mode" << std::endl;
		Computer g_computer(false);
	}
	else if (std::strcmp("-text", argv[1]) == 0)
	{
		std::cout << "text mode" << std::endl;
	}
	else 
		std::cout << "Please use one of these modes: " << std::endl << "	ft_gkrellm -desktop" << std::endl << "	ft_gkrellm -terminal" << std::endl;


	return 0;
}