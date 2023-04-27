#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *my_thread_process(void * arg)
{
int i;
char j=*(char*)arg;
for(i=1;i<6;i++){
    printf("thread %c: %d PID_processus %d TID_thread %ld\n ",j,i,getpid(),pthread_self());
    sleep(1);
}
pthread_exit(0);
}
void main(int ac,char **av)
{
    pthread_t th1,th2;
    void *ret;
    printf("processus %d thread principal (main) %ld\n",getpid(),pthread_self());
    if(pthread_create(&th1,NULL,my_thread_process,"1") < 0){
        fprintf(stderr,"pthread_create error for thread 1\n");
        exit(1);
    }
    
    if(pthread_create (&th2,NULL, my_thread_process,"2") < 0){
        fprintf(stderr,"pthread_create error for thread 2\n");
        exit(1);
    }
    (void)pthread_join (th1,&ret);
    (void)pthread_join (th2,&ret);
}
