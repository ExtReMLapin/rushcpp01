#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Please use one of these modes: " << std::endl << "	ft_gkrellm -desktop" << std::endl << "	ft_gkrellm -terminal" << std::endl << "	ft_gkrellm -text" << std::endl;
		return (0);
	}

	if (std::strcmp("-desktop", argv[1]) == 0)
	{

	}
	else if (std::strcmp("-terminal", argv[1]) == 0)
	{
		std::cout << "terminal mode" << std::endl;
	}
	else if (std::strcmp("-text", argv[1]) == 0)
	{
		std::cout << "text mode" << std::endl;
	}
	else 
		std::cout << "Please use one of these modes: " << std::endl << "	ft_gkrellm -desktop" << std::endl << "	ft_gkrellm -terminal" << std::endl;


	return 0;
}