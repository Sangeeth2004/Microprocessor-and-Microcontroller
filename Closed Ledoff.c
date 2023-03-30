#include <AT89S52.h> /*include header for AT89S52*/
#define LED P2_4 /*LED connected at port pin P2.4*/
#define ON 0 /*logic 0 active*/
#define OFF 1 /*logic 1 inactive*/
#define SW P3_3 /*switch coonected at port pin P3.3*/
#define INPUT 1 /*To configure port pin as input '1' logic must be writtern on port pin*/
void main()
{
__bit status; /*initializ a bit variable*/
LED=OFF; /*Turn OFF the LED*/
SW=INPUT ;/*Configure port pin connection to switch as input*/
while(1) /*Execute below lines in super Loop*/
{
status=SW; /*Read the switch and store the logic to a Variable*/
LED=status ;/*write the logic to the LED*/
}
}
