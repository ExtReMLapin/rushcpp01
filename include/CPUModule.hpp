#pragma once

#include <vector>
#include "IMonitorModule.hpp"

class CPUModule : public IMonitorModule
{
	public:
		CPUModule();
		~CPUModule();	
		void							update(void);
		std::vector<float> const		&getNumbers(void) const;
		std::string getFreq(void) const;
		size_t getCoreCount(void) const;

	private:
		CPUModule(CPUModule const &src);
		CPUModule	&operator=(CPUModule const &rhs);
		std::vector<float>			_numbers; // history of total cpu usage
		size_t		_ncores;
		std::vector<float>			_coresnumbers; // now perentage usage of each core
		uint64_t _ncycles;
		double _frequency;
		double _maxfreq;
};
