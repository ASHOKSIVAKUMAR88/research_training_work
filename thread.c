#include <stdio.h>
#include<errno.h>
#include<pthread.h>
pthread_t thread;
void * function(void* a)
{
    int  count = 0;
    printf("Thread Id by self %ld\n", pthread_self());
    pthread_detach(pthread_self());
    pthread_cancel(pthread_self());
    pthread_join(pthread_self(), NULL);
    printf("After Join by self\n");
    getchar();
    //pthread_cancel(pthread_self());
    printf("In %s %d\n", __func__, count++);

}
typedef void*(*function_pointer)(void*);
function_pointer f = function;
int main(int argc, char *argv[])
{
    //function_argument = function;
    printf("Hello World!\n");
    f = &function;
    int s;
    s= pthread_create(&thread, NULL, f, (void*)NULL);
    if(s != 0)
        perror("Pthread_create");
    printf("thread Id %ld\n", thread);
    pthread_join(thread, NULL);
    //getchar();
    return 0;
}
