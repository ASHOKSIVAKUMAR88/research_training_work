#include<stdio.h>
union typecast{
  unsigned int a;
  int b;
};
void main(void)
{
  union typecast t = {.a = 1};
  printf("%d %u \n",t.b,t.a);

}
