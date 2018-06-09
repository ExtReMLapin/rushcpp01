#include <iostream>
#include <cstring>
#include <Computer.hpp>
#include <CPUModule.hpp>
#include <SDL2/SDL.h>

Computer g_computer;


int main(int argc, char const *argv[])
{
	


	if (argc != 2)
	{
		std::cout << "Please use one of these modes: " << std::endl << "	ft_gkrellm -desktop" << std::endl << "	ft_gkrellm -terminal" << std::endl << "	ft_gkrellm -text" << std::endl;
		return (0);
	}

	if (std::strcmp("-desktop", argv[1]) == 0)
	{
		g_computer.setGUI(true);

		while (1)
		{
			g_computer.renderer->draw();
			g_computer.cpu.update();

		}
		

	}
	else if (std::strcmp("-terminal", argv[1]) == 0)
	{
		std::cout << "terminal mode" << std::endl;
		 g_computer.setGUI(false);
	}
	else 
		std::cout << "Please use one of these modes: " << std::endl << "	ft_gkrellm -desktop" << std::endl << "	ft_gkrellm -terminal" << std::endl;


	return 0;
}
