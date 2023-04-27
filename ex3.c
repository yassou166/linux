#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/wait.h>
#include <sched.h>

void main(void* args){

	struct sched_param schedparam;
	schedparam.sched_priority = 1;
	sched_setscheduler(0,SCHED_FIFO,&schedparam);

		

	pid_t p1,p2;
	p1=fork();
	if (p1!=0){//partie parent 

		p2=fork();

		if (p2==0){//partie fis 2
			struct sched_param schedparam;
			schedparam.sched_priority = 6;
			sched_setscheduler(0,SCHED_FIFO,&schedparam);
			int j;
			for (j=0;j<10;j++)
				printf("B \n");
				//usleep(100000);
			exit(0);
		}
			waitpid(p2,NULL,0);
			waitpid(p1,NULL,0);
	}

	else{//partie fils 1
		struct sched_param schedparam;
		schedparam.sched_priority = 3;
		sched_setscheduler(0,SCHED_FIFO,&schedparam);
		int i;
		nice(-6);
		for (i=0;i<10;i++)
			printf("A \n");
			//usleep(100000);
		exit(0);
	}
}
