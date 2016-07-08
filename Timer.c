//Программа часы

#include <avr/io.h>
#include "LCD_HD44780.h"
#include <string.h>
#include <stdlib.h>

int main()
{
	int8_t hour, minuts, second;
	int8_t HOUR[2], MINUTS[2], SECOND[2];
	LCD_init();


	for(;;)
	{
		for(hour = 0; hour<24; hour++)
		{
			if(hour<10)
			{	
				itoa(hour, HOUR, 10);
				LCD_write_adress(0x30, FIRST);
				LCD_write_str(HOUR);
				LCD_write(0x3A,RS_DATA);
			}
			else
			{
				itoa(hour, HOUR, 10);
				kursor_adress(FIRST);
				LCD_write_str(HOUR);
				LCD_write(0x3A,RS_DATA);
			}
			for(minuts = 0; minuts<60; minuts++)
			{
				if(minuts<10)
				{
					itoa(minuts, MINUTS, 10);
					LCD_write_adress(0x30, FOURTH);
					LCD_write_str(MINUTS);
					LCD_write(0x3A,RS_DATA);
				}
				else
				{
					itoa(minuts, MINUTS, 10);
					kursor_adress(FOURTH);
					LCD_write_str(MINUTS);
					LCD_write(0x3A,RS_DATA);
				}				
				for(second = 0; second<60; second++)
				{
					if(second<10)
					{
						itoa(second, SECOND, 10);
						LCD_write_adress(0x30, SEVENTH);
						LCD_write_str(SECOND);
					}
					else 
					{
						kursor_adress(SEVENTH);
						itoa(second, SECOND, 10);
						LCD_write_str(SECOND);
					}
					_delay_ms(870);

/*					itoa(hour, BUF_H, 10);
					itoa(minuts, BUF_M, 10);
					itoa(second, BUF_S, 10);
					strcat(BUF_H,':');
					strcat(BUF_M,':');
					strcat(BUF_H,BUF_M);
					strcat(BUF_H,BUF_S);
					clean_display();
					line_wrapping(1);
					LCD_write_str(BUF_H);
*/				}
			}
		}
	}
	return 1;
}
