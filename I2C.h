#include <AT89S52.h>
#define SCL P0_3
#define SDA P1_5
void i2c_init(void)
{
	SCL=0;/*serial clock is low*/
	SDA=0;/*serial data is low*/
}
void i2c_start(void)
{
	SDA=1;/*serial data is high*/
	SCL=1;/*serial clock is high*/
	SDA=0;/*serial data is low*/
	SCL=0;/*serial clock is low*/
}
void i2c_stop(void)
{
	SCL=1;/*serial clock is high*/
	SDA=1;/*serial data is high*/
	SCL=0;/*serial clock is low*/
	SDA=0;/*serial data is low*/
}
void i2c_ack(void)
{
	SDA=0;/*serial data is low*/
	SCL=1;/*serial clock is high*/
	SCL=0;/*serial clock is low*/
	SDA=1;/*serial data is high*/
}
void i2c_nack(void)
{
	SDA=1;/*serial data is high*/
	SCL=1;/*serial clock is high*/
	SCL=0;/*serial clock is low*/
	SDA=0;/*serial data is low*/
}
void i2c_write(char b)
{
	char i;
	__bit v;/*to define the read input*/
	for(i=0;i<8;i++)
	{
		if((b)&(0x80>>i)!=0)
		{
			SDA=1;/*serial data is high*/
		}
		else
		{
			SDA=0;/*serial data is low*/
		}
			SCL=1;/*serial clock is high*/
			SCL=0;/*serial clock is low*/
	}
		SDA=1;/*serial data is high*/
		SCL=1;/*serial clock is high*/
		v=SDA;/*to define read pin as high*/
		SCL=0;/*serial clock is low*/
}

	char i2c_read(void)
	{
		char s=0x00;
		char j;
		SDA=1;/*serial data is high*/
		for(j=0;j<8;j++)
		{
			SCL=1;/*serial clock is high*/
			if(SDA==1)
			{
			 s=s|(0x80>>j);
			}
			else
			{
			}
			SCL=0;/*serial clock is low*/
		}
		SDA=0;/*serial data is low*/
		return s;
	}
	void main(){
	  i2c_init();
	  i2c_start();
	  i2c_write(0xD0);
	  i2c_write(0x00);
	  i2c_write(0x00);
	  i2c_stop();
	  	while(1){
	  		 i2c_start();
	  		 i2c_write(0xD0);
	  		 i2c_write(0x00);
	  		 i2c_start();
	  		 i2c_write(0xD1);
	  		 P2=~i2c_read();
	  		 i2c_nack();
	  		 i2c_stop();
	  }
	}
