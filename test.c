#include<stdio.h>
void main(void)
{
unsigned int pinNum = 47;
unsigned long offset=pinNum/32;
unsigned long mask=(1<<(pinNum%32));
printf("Pin number %lu\n", mask);
for(int i = 32; i > 0; i-- )
    printf("%lu ", (mask>>i)&1);
printf("\n");

}
