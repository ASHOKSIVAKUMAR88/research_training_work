#include<stdio.h>

int divisible(int n , int d)
{
   n = n & (d-1);
   if(n == 1)
       return 1;
   else if(n == 0)
       return 0;
   else
   divisible(n, d-1);

}
void main(void)
{
    //(divisible(100,3)==1)?printf("not divisible\n"):printf("divisble\n");
    for(unsigned int i =0 ; i<= 100;i++)
    {
    printf("value %u-->%u\n",i, i&(5));
    }
}
