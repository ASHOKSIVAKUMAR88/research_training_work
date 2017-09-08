#include<stdio.h>
union typecast{
  unsigned int a;
  int b;
};
void main(void)
{
  union typecast t = {.a = -10};
  printf("%d %d \n",t.b,t.a);

}
