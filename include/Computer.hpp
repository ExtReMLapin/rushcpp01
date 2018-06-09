#pragma once
#include <CPUModule.hpp>
#include <IMonitorDisplay.hpp>

class Computer
{
	public:
		~Computer();
		bool isGUI(void) const;
		void setGUI(bool gui);
		Computer (const Computer&);
		Computer &operator=(const Computer&);
		Computer();
		IMonitorDisplay *renderer;
		CPUModule cpu;	
	private:
		bool _isGUI;
		

	
};

extern Computer g_computer;