#include <CPUModule.hpp>
#include <unistd.h>



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
}

CPUModule::~CPUModule()
{


}

void		CPUModule::update(void)
{


}


std::vector<float> const			&CPUModule::getNumbers(void) const
{
	return (_numbers);
}


	