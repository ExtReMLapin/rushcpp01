#include <IMonitorDisplay.hpp>


IMonitorDisplay::IMonitorDisplay()
{
	return ;
}

IMonitorDisplay::~IMonitorDisplay()
{
	return ;
}


IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const &src)
{
	(void)src;
}


IMonitorDisplay		&IMonitorDisplay::operator=(IMonitorDisplay const &rhs)
{
	(void)rhs;
	return (*this);
} 