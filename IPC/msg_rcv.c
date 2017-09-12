#define _GNU_SOURCE
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/stat.h>

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct members{
  long mtype;
  char mtext[20];
}MEMBER;
void main(int n, char **argv)
{
    printf(" process id %d\n", getpid());
    key_t key = ftok("good.txt", 12);
    int msg_id = msgget(key, S_IRUSR|S_IWUSR);
    printf("message Id %d \n", msg_id);
    MEMBER *m = malloc(sizeof(MEMBER));
    //printf("command line arguments %d %d\n", atoi(argv[1]), atoi(argv[2]));
    if(msgrcv(msg_id, m, sizeof(MEMBER),1,0)== -1)
    {
        printf("Message Not receive\n");
    }
    printf("message %ld %s\n", m->mtype, m->mtext);
   struct msqid_ds msg;
    if(msgctl(msg_id, MSG_STAT, &msg) == 0)
        printf("copied successfully\n");
    printf("Message last send %d receive %d\n", msg.msg_lspid, msg.msg_lrpid);
}
