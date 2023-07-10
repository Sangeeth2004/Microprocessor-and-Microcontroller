#include<AT89S52.h>
#define DATA P0
#define DIGIT P1
const char code[11]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
void wait(int);
void main()
{
DATA=0xFF;
DIGIT=0x0F;
while(1)
{
DATA=code[2];
DIGIT=0x07;
wait(10);
DIGIT=0x0F;
DATA=code[0];
DIGIT=0x0B;
wait(10);
DIGIT=0x0F;
DATA=code[2];
DIGIT=0x0D;
wait(10);
DIGIT=0x0F;
DATA=code[3];
DIGIT=0x0E;
wait(10);
DIGIT=0x0F;
}
}

void wait(int c){
int i;
for(i=0;i<c;i++){}
}
