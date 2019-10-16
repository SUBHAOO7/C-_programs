#include<stdio.h>
#include<sys/types.h>
int main()
{
	pid_t p1,p3;
	p1=fork();
	//printf("Parent P1 id is %d\n",getppid());
	if(p1==0)
	{
		printf("Child P2 process is created, id is- %d, Parent P1 is %d\n",getpid(),getppid());
		/*if(fork()==0)
		printf("Process P3 is created, ID is %d and Parent id is %d\n",getpid(),getppid());*/
	}
	if(p1>0)
	{
		wait(); //It will help to execute child process first
		printf("I am parent with ID %d\n",getpid());
	}
	//wait(NULL);

	return 0;
}
