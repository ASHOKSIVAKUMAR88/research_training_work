#include<stdio.h>

union s{
	int a;
	short int b;
	char c;
};

void main(void)
{
	union s g= {.c='a'};
	printf("a b c address %p %p %p %c %c %c \n", &g.a, &g.b, &g.c, (char)g.a, (char)g.b, g.c );
	return;
}
