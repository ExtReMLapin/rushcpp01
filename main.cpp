#include <iostream>
#include <cstring>
#include <Computer.hpp>
#include <CPUModule.hpp>


static inline uint64_t get_cycles()
{
  uint64_t t;
  asm volatile ("rdtsc" : "=A"(t));
  return t;
}


Computer g_computer;

int		event(SDL_Event *e)
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


	 std::cout << get_cycles() << std::endl;

	if (argc != 2)
	{
		std::cout << "Please use one of these modes: " << std::endl << "	ft_gkrellm -desktop" << std::endl << "	ft_gkrellm -terminal" << std::endl << "	ft_gkrellm -text" << std::endl;
		return (0);
	}

	if (std::strcmp("-desktop", argv[1]) == 0)
	{
		Uint32		startclock;
		g_computer = Computer(true);
		double		current;
		while (g_computer.isGUI()) // can be false is failed
		{

			startclock = SDL_GetTicks();
			while (SDL_PollEvent(&e))
				event(&e);


			current =  static_cast<double>(SDL_GetTicks() - startclock) / static_cast<double>(1000); // 60fps limit
			if (current < static_cast<double>(1 / 60))
				SDL_Delay(static_cast<uint32_t>((1 / 60 - current) * 1000));
		}
	}
	else if (std::strcmp("-terminal", argv[1]) == 0)
	{
		std::cout << "terminal mode" << std::endl;
		 g_computer = Computer(false);
	}
	else if (std::strcmp("-text", argv[1]) == 0)
	{
		std::cout << "text mode" << std::endl;
	}
	else 
		std::cout << "Please use one of these modes: " << std::endl << "	ft_gkrellm -desktop" << std::endl << "	ft_gkrellm -terminal" << std::endl;


	return 0;
}
