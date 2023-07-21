#include <AT89S52.h>
#define BUS P0
#define RS P1_2
#define RW P1_1
#define EN P1_0
void lcd_cmd(char);
void lcd_data(char);
void lcd_busy(void);
void lcd_disp(char*);
void main()
{
	EN=0;
	lcd_busy();
	lcd_cmd(0x00);
	lcd_cmd(0x0A);
	lcd_cmd(0x0A);
	lcd_cmd(0x0A);
	lcd_cmd(0x00);
	lcd_cmd(0x11);
	lcd_cmd(0x0D);
	lcd_cmd(0x00);
        lcd_disp("EMBEDDED C");
        while(1)
        {
        lcd_cmd(0x18);
        }
}
void lcd_cmd(char c)
{
	BUS=c;
	RS=0;
	RW=0;
	EN=1;
	EN=0;
	lcd_busy();
}
void lcd_data(char c)
{
	BUS=c;
	RS=1;
	RW=0;
	EN=1;
	EN=0;
	lcd_busy();
}
void lcd_busy(void)
{
  char status;
	BUS=0xFF;
	RS=0;
	RW=1;
	EN=1;
	EN=0;
	status=(BUS&0x40);
	while (status!=0)
	{
		EN=1;
		EN=0;
		status=(BUS&80);
	}
}
void lcd_disp(char *p)
{
	while(*p!='\0')
	{
		lcd_data(*p);
		*p++;
	}
	
