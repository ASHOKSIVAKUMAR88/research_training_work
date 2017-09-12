#define _GNU_SOURCE
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/stat.h>

#include<stdio.h>
#include<stdlib.h>//malloc()
#include<unistd.h>//fork()
#include<string.h>//strcpy()
typedef struct members{
  long mtype;
  char mtext[20];
}MEMBER;
void main(int n, char ** argv)
{
    //
    printf(" process id %d\n", getpid());
    FILE *fp = fopen("good.txt", "w");
    fclose(fp);
    int key = ftok("good.txt", 12);
    int msg_id = msgget(key, S_IRUSR|S_IWUSR);
    printf("message Id %d \n", msg_id);
    MEMBER *m = malloc(sizeof(MEMBER));
    m->mtype = 1;
    strcpy(m->mtext, "ashok");
    if(1)//fork() == 0)
    {
        for(int i=0; i<10; i++)
        if(msgsnd(msg_id, (void*)m, sizeof(MEMBER), IPC_NOWAIT)!=0)
        {
            printf("Message Not Sent\n");
        }
    }
    else
    {
        if(msgrcv(msg_id, (void*)m, sizeof(MEMBER), 1, 0)== -1)//IPC_NOWAIT
        {
            printf("Message Not receive\n");
        }
        printf("message %ld %s\n", m->mtype, m->mtext);

    }
    getchar();
//    if(msgctl(msg_id, IPC_RMID, NULL) == 0)
//        printf("removed successfully\n");
}
