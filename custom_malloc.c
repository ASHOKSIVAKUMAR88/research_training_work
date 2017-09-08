#include<stdio.h>
#include<unistd.h>
#include<malloc.h>
int a;
int *ptr = &a;
typedef struct list{
   int size;
   void * ptr;
   struct list *next;
}LL;

void main(void)
{
   printf("%p\n", sbrk(0));
   printf("%p\n", sbrk(1));
   int *ptr= sbrk(4);
   *ptr = 10;
   printf("%p\n", ptr);
   printf("%d\n", *ptr);
   struct mallinfo  j = mallinfo();
   printf("%d\n",j.arena);

}
