#include<AT89S52.h>
#define COL P0
#define ROW P1

const char col_pixel[9]={0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81};
const char row_pixel[9]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};

void main()
{
COL=0x00;
ROW=0x00;
while(1)
{
char i;
for(i=0;i<8;i++)
{
COL=col_pixel[i];
ROW=row_pixel[i];
ROW=0x00;
}
}
}