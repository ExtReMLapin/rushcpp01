#pragma once

#include <Vector>
#include "IMonitorModule.hpp"

class CPUModule : public IMonitorModule
{
	public:
		CPUModule();
		virtual ~CPUModule();	
		void							update(void);
		std::vector<std::string> const	&getStrings(void) const;
		std::deque<float> const			&getNumbers(void) const;
		std::string const				&getModuleName(void) const;
		

	private:
		CPUModule(CPUModule const &src);
		CPUModule	&operator=(CPUModule const &rhs);
		std::deque<float>			_numbers;
	
};
