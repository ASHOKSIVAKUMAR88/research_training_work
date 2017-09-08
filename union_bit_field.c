#include<stdio.h>
union test
{
unsigned int x: 3;
unsigned int y: 3;
int z:4;
}__attribute__((packed));

int main()
{ 
union test t;
t.z = 1;
t.x = 5;
t.y = 4;

printf("t.x = %d, t.y = %d, t.z = %d\n %ld",
		t.x, t.y, t.z, sizeof(t));
return 0;
}

