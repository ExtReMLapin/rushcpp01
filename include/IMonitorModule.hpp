#pragma once

# include <iostream>
# include <vector>

class IMonitorModule
{
public:
	IMonitorModule();
	virtual ~IMonitorModule();

	virtual void							update(void) = 0;
	
private:
	IMonitorModule(IMonitorModule const &src);
	IMonitorModule				&operator=(IMonitorModule const &rhs);
};