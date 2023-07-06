#include<AT89S52.h>

const char code[11]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void wait(int);

void main(){
while(1)
{
char i;
for(i=0;i<10;i++)
{
P0=code[i];
wait(500);
}
}
}

void wait(int c)
{
int i;
for(i=0;i<c;i++)
{}
}
_______________________________________________________________________________________________________________________________________
_______________________________________________________________________________________________________________________________________
#include<AT89S52.h>

const char code[11]={0x80,0xA4,0xA4,0xC0,0x90,0xB0,0x82,0xF9,0x80,0xF8};
void wait(int);

void main(){
while(1)
{
char i;
for(i=0;i<10;i++)
{
P0=code[i];
wait(100);
}
}
}

void wait(int c)
{
int i;
for(i=0;i<c;i++)
{}
}
