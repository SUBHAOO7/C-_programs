#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd[2],n;
	char buf[50];
	pid_t p;
	pipe(fd);
	p=fork();
	if(p>0)
	{
		close(fd[0]);
		printf("Passing data to child\n");
		write(fd[1],"Hello",5);
		wait();
	}
	else
	{
		close(fd[1]);
		n=read(fd[0],buf,100);
		write(1,buf,n);
	}
	exit(0);
}
