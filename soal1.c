#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h> //library thread

void *copy_baca_salin1( void *ptr );
void *copy_salin1_salin2( void *ptr );
int status;
int main()
{
     pthread_t thread1, thread2;//inisialisasi thread

	const char *message1 = "copy ke salin1 sukses";
	const char *message2 = "copy ke salin2 sukses";
	int  iret1, iret2;

     iret1 = pthread_create( &thread1, NULL, copy_baca_salin1, (void*) message1);//membuat thread pertama
     if(iret1)//jika eror
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }

     iret2 = pthread_create( &thread2, NULL, copy_salin1_salin2, (void*) message2);//membuat thread kedua
     if(iret2)//jika gagal
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(EXIT_FAILURE);
     }
     printf("pthread_create() for thread 1 returns: %d\n",iret1);
     printf("pthread_create() for thread 2 returns: %d\n",iret2);

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL);

     exit(EXIT_SUCCESS);
}

FILE *baca, *salin;
void *copy_baca_salin1( void *ptr )
{
	status = 0;

	baca = fopen("baca.txt", "r");

	salin = fopen("salin1.txt", "w");

	char c = fgetc(baca);
	while((c) !=EOF) {
		fputc(c,salin);
		c = fgetc(baca);
	}

	fclose(baca);
	fclose(salin);

	status = 1;

return 0;
}

FILE *salin2, *salin3;
void *copy_salin1_salin2 ( void *ptr) {
	while (!status) {}
		salin2 = fopen ("salin1.txt", "r");
        	salin3 = fopen ("salin2.txt", "w");

		char d = fgetc(salin2);
        	while((d) !=EOF) {
         	fputc(d,salin3);
	 	d=fgetc(salin2);
		}

	fclose(salin2);
	fclose(salin3);
}
