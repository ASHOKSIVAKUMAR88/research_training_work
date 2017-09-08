#include<stdio.h>
int even_odd(int number)
{
    return number&1?1:0;
}
void main(void)
{
     printf("return value %d\n", even_odd(10));

}
