#include<stdio.h>
typedef struct Mine{
	int a;
	short int b;
	char c;
} MINE;

void function(const MINE g)
{
printf("%d %hd %c \n",g.a, g.b, g.c );
}
void main(void)
{
    MINE g= {10,-10,'a'};
    printf("%d %hd %c \n",  g.a, g.b, g.c );
    function(g);
	return;
}
