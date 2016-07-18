
#define MCUID 2

#include "command.h"

int main()
{
	lcd.init();
	lcd.drawText(0, 0, "Ready");
	usart0.init(0x33, true);
	usart0.setTrigger(';');
	usart1.init(0x33, true);
	usart1.setTrigger(';');
	while (1)
	{
		checkCmd(usart0);
		checkCmd(usart1);
		_delay_ms(500);
	}
}