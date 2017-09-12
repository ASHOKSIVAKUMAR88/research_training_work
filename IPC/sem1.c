#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/stat.h>//S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IXUSR|S_IXGRP|S_IXOTH

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

struct semid_ds g;
struct sembuf s;

void main(int n , char **argv)
{
    int semid = semget(atoi(argv[1]), atoi(argv[2]), IPC_CREAT|IPC_EXCL|S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH);
    if(semid == -1)
    {
        perror("ERROR");
        semid = semget(atoi(argv[1]), atoi(argv[2]), S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH);
    }
    printf("semaphore id %d\n", semid);
    if(semctl(semid, 1 , IPC_STAT, &g) != -1)
        printf("successfully copied\n");
    //getchar();
    printf("structure details %s %ld %s", ctime(&g.sem_ctime),g.sem_nsems,ctime(&g.sem_otime));
    s.sem_num = 0;
    s.sem_flg = SEM_UNDO;
    s.sem_op = 1;
    if(semop( semid, &s, 1) == 0)
    {
        printf("sembuf values %d %d %d\n", s.sem_flg,s.sem_num,s.sem_op);

    }
    s.sem_num = 0;
    s.sem_flg = SEM_UNDO;
    s.sem_op = -1;
    if(semop( semid, &s, 1) == 0)
    {
        printf("sembuf values %d %d %d\n", s.sem_flg,s.sem_num,s.sem_op);

    }

}
