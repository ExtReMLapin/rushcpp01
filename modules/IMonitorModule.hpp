#pragma once

# include <iostream>
# include <Vector>

class IMonitorModule
{
public:
	IMonitorModule();
	virtual ~IMonitorModule();

	virtual void							update(void) = 0;
	virtual std::string const				&getModuleName(void) const = 0;
	virtual std::vector<std::string> const	&getStrings(void) const = 0;
	virtual std::vector<float> const		&getNumbers(void) const = 0;
	
private:
	IMonitorModule(IMonitorModule const &src);
	IMonitorModule				&operator=(IMonitorModule const &rhs);
};