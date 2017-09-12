#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/stat.h>
struct shmesg{
    char m[20];
};
void main(int n, char **argv)
{
    int semid = semget(atoi(argv[1]), 1, IPC_CREAT|IPC_EXCL|S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH);
    if(semid == -1)
    {
        perror("ERROR");
        semid = semget(atoi(argv[1]),1, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH);
    }
    printf("semaphore id %d\n", semid);
    int shmid = shmget(atoi(argv[1]), 20, IPC_CREAT|IPC_EXCL|S_IRUSR|S_IWUSR);
    if(shmid == -1)
    {
        perror("ERROR");
        shmid = shmget(atoi(argv[1]), 20, S_IRUSR|S_IWUSR);
    }
    printf("shmid %d\n", shmid);
    char *p;
    p = (char*)shmat(shmid, NULL, 0 );
//    struct sembuf msg;
//    msg.sem_flg = SEM_UNDO;
//    msg.sem_num = 0;
//    msg.sem_op = -1;
//    if(semop(semid, &msg, 1) == -1)
//        perror("Error");
    printf("address %p\n",p);
    strcpy(p, "ashok");
    p[strlen("ashok")+1] = '\0';
    printf("string %s\n", *p);
//    msg.sem_flg = SEM_UNDO;
//    msg.sem_num = 0;
//    msg.sem_op = 0;
//    if(semop(semid, &msg, 1) == -1)
//        perror("Error");

}
