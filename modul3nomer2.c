#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[2];

void* prima(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter;
    int status=0;
    if(pthread_equal(id,tid[0]))
    {
	printf("Bilangan prima dari 1-50:\n");
        int waw;
        for (waw=1;waw<=50;waw++)
	{
	    int faktor=0;
	    int oke=waw;
	    while (oke)
	    {
		if (waw%oke==0) faktor++;
		oke--;
	    }
	    if (faktor==2) printf("%d ",waw);
	}
	printf("\n");
    }
    else if(pthread_equal(id,tid[1]))
    {

	printf("Bilangan prima dari 51-100:\n");
	int wew;
	for (wew=51;wew<=100;wew++)
	{
	    int factor=0;
	    int ok=wew;
	    while (ok)
	    {
		if (wew%ok==0) factor++;
		ok--;
	    }
	    if (factor==2) printf("%d ",wew);
	}
	printf("\n");
    }
    return NULL;
}
int main(void)
{
    int i=0;
    int err;
    while(i<2)
    {
        err=pthread_create(&(tid[i]),NULL,&prima,NULL);
        if(err!=0)
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
