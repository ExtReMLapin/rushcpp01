#include "IMonitorModule.hpp"


IMonitorModule::IMonitorModule()
{
	return ;
}

IMonitorModule::~IMonitorModule()
{
	return ;
}

IMonitorModule::IMonitorModule(IMonitorModule const &src)
{
	(void)src;
}


IMonitorModule		&IMonitorModule::operator=(IMonitorModule const &rhs)
{
	(void)rhs;
	return (*this);
} 