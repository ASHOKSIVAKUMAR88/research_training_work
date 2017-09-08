#include<stdio.h>
int sum(int n)
{
    if(n == 0)
        return 0;
    else
        return n + sum(n-1);

}
void main_a(void)
{
    printf("sum of natural number %d\n",sum(2));
    _exit(0);

}
