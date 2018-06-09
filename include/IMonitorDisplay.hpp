#pragma once

class IMonitorDisplay
{
	public:
		IMonitorDisplay();
		virtual ~IMonitorDisplay();

		virtual void	draw(void) = 0;
		
	protected:
	private:
		IMonitorDisplay(IMonitorDisplay const &src);
		IMonitorDisplay				&operator=(IMonitorDisplay const &rhs);
};