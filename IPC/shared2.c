#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/stat.h>

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
    struct shmid_ds shm_ds;
    shmctl(shmid, IPC_STAT, &shm_ds);
    //printf("address %p \n", p);

    struct sembuf msg;
    msg.sem_flg = SEM_UNDO;
    msg.sem_num = 0;
    msg.sem_op = 0;
    if(semop(semid, &msg, 1) == -1)
        perror("Error");
    //write(STDIN_FILENO,p,20);
    msg.sem_flg = SEM_UNDO;
    msg.sem_num = 0;
    msg.sem_op = 1;
    if(semop(semid, &msg, 1) == -1)
        perror("Error");
}
