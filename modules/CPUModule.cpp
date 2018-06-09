#include <CPUModule.hpp>
#include <unistd.h>
#include <sstream>


static inline uint64_t get_cycles()
{
  uint64_t t;
  asm volatile ("rdtsc" : "=A"(t));
  return t;
}


CPUModule::CPUModule()
{
	this->_ncores = sysconf(_SC_NPROCESSORS_ONLN);
	this->_ncycles = get_cycles();
	this->_frequency =   static_cast<double>((static_cast<unsigned int>(this->_ncycles/1000000)))/1000;
	this->_maxfreq = 4.2; // hardcoded
	this->_numbers.reserve(100);
}

CPUModule::~CPUModule()
{


}

void		CPUModule::update(void)
{
	this->_ncycles = get_cycles();
	this->_frequency =   static_cast<double>((static_cast<unsigned int>(this->_ncycles/1000000)))/1000;
	std::cout << "CPU At " << this->_frequency << "Ghz" << std::endl;
	std::cout << "ncoute = " << this->getCoreCount() << std::endl;
	std::cout << this->_numbers.size() << std::endl;

	if (this->_numbers.size() == 100)
		this->_numbers.erase(this->_numbers.begin());
	_numbers.push_back(this->_frequency);
}


std::vector<float> const			&CPUModule::getNumbers(void) const
{
	return (_numbers);
}


std::string CPUModule::getFreq(void)const
{
	std::ostringstream ss;
	ss << this->_frequency << "Ghz";

	return (ss.str());
}
size_t CPUModule::getCoreCount(void)const
{
	return (this->_ncores);
}

	