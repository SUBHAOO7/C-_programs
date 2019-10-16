#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
void *fun1();
void *fun2();
int shared=1;
sem_t s;
//pthread_mutex_t l;	//Dec of lock
int main()
{
	
	sem_init(&s,0,1);	
	pthread_t th1,th2;
	//pthread_mutex_init(&l,NULL);
	pthread_create(&th1,NULL,fun1,NULL);
	pthread_create(&th2,NULL,fun2,NULL);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	printf("\nValue of shared2 is %d",shared);
}

void *fun1()
{
	int x;
	sem_wait(&s);
	//pthread_mutex_lock(&l);
	x=shared;
	x++;
	sleep(1);
	shared=x;
	sem_post(&s);
	//pthread_mutex_unlock(&l);	
}

void *fun2()
{
	int y;
	sem_wait(&s);
	//pthread_mutex_lock(&l);
	y=shared;
	y--;
	sleep(1);
	shared=y;
	sem_post(&s);
	//pthread_mutex_unlock(&l);
}


