#include <Computer.hpp>
#include <SDLRenderer.hpp>
#include <iostream>





bool Computer::isGUI(void) const
{
	return (_isGUI);
}

void Computer::setGUI(bool gui)
{
	this->_isGUI = gui;
	if (this->_isGUI)
		this->renderer = new SDLRenderer();

	if (!this->_isGUI) // like failed sdl, so don't use else
	{

	}
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

