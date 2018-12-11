/*************************************************
 * Interprete de comandos en C by Alevsk	 *
 *************************************************/

#include<sys/types.h>   // fork
#include<unistd.h>      // getpid, getppid
#include<stdio.h>       // printf
#include<sys/wait.h>	// wait
#include<string.h>	// strcat

int main(int argc, char *argv[])
{
    	int n,m, i = 1;
	char comando[256];
	char *puntero;

    	if(argc < 2)
    	{
        	printf("Debes teclear almenos 1 comando, ej. ls\n");
        	exit(1);
    	}

   	strcpy(comando,argv[i]);
   
   	do
   	{
		if(argv[i] && argv[i+1])
		{
			//strcat(argv[1]," ");
			//strcat(argv[1],argv[i+1]);
			strcat(comando," ");
			puntero = strcat(comando,argv[i+1]);		
			i++;
		}
		else
		{
			puntero = comando;
			break;
		}	
   	}while(1);


	if(n = !fork())
	{
	
		//execlp("bash","bash","-c",argv[1],0);
		execlp("bash","bash","-c",puntero,0);
		printf("\n");
		exit(1);
	}
	wait(&n); //Esperar a que el proceso hijo termine
	return -1;
}
