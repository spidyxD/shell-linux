//Proyecto #1
/* Universidad Nacional de Costa Rica
 * Sistemas Operativos
 * Created by Roger Amador Villagra
 * Código fuente
 * 2017
 * 
 * */
#include <errno.h>
#include <stdio.h>
#include <string.h> //string class
#include <stdlib.h> //printf
#include <signal.h> //
#include <sys/wait.h> //wait
#include <sys/types.h> // call to fork
#include <unistd.h> //getPid
#include <time.h>
#define MAX_PTR 1000   /* numero de filas con info sobre el comando */                  /* coincide con la longitud de ptr */
#define COL   100      /* numero de columnas con info sobre el comando */
#define ok 50          /* si estado vale ok,se da valida la linea del comando */
#define error 60   /* si estado vale error,no se da valida la linea del comando */  
#define max_args 15  
#define max_command 500

typedef struct{			//nickname of the structure															//command structure
	char *cmd_path;	//path of command
	int argc;	//number of args for the cmd
	char *argv[max_args]; //array of arguments
	char cmd_suffix;
	char comnd[max_command];
}commandForm;


int main(){																//main function{
	char *comLine;
	char storage[500];   // temporal storage
	char *arg;
	char com;
	char *command;
	int keep = 1;        // flag
	static char cadenas[MAX_PTR][COL];  
	int cmdlen;
	int flagsecond;
	FILE * pFile;
	commandForm *comm1 = (commandForm*) malloc(sizeof(commandForm));	//create a structur instance and the malloc func request for a memory block
	
	printf("Welcome to my first litle shell spySam\n");
	printf("To exit write and press enter (exit)\n");
	
	do {
		flagsecond=0;
		comm1->argc = 1;
		printf("spySam >");
		fflush(stdout);						// send the text line from the standart exit and clean the temporal storage
		comLine=fgets(storage, max_command, stdin);		//Catch the command from the keyboard
		cmdlen = strlen(comLine);
		strcpy(coms,storage);
			
		if (comLine[cmdlen-1] == '\n'){ 		//analize if the command line have a jump line
			comLine[cmdlen-1] = '\0';
		}
			
		arg = strtok(comLine, " ");
		command = arg;
		//----------------------------------------------------- analyzing command for pipes ------------------------------------
	/*	
	 int i =0; // variable para recorrer el comando, que en esta funcion es l 
	  int k;    // variable de apoyo para hacer bucles 
	  int nulo; // variable que dice la posicion del ultimo NULL en ptr  
	  int estado =0; // variable que dice en que estado del automata estamos 
	  int f=0;  // variable para acceder a las filas de cadenas 
	  int c=0;  // variable para acceder a las columnas de cadenas 

	  
		  storage[0]=NULL; nulo=0; /* suponemos inicialmente el comando vacio 
		for (k=1;k<=(max_command)-1;k++) storage[k]=&cadenas[k][0];
		while ( estado != ok && estado != error ) {


		switch (estado) {
		case 1:
			if (l[i]=='|'){
                                    estado=14;
				    storage[f][c]=0;
				    nulo=f+1; ptr[nulo]=NULL;
                             // inicializamos la informacion de las redirecciones 
                             // y de los tipos de separadores 
				    for (k=0;k<=5;k++) cadenas[nulo+1][k]=0;
                                  //informamos que hay separador || 
				    cadenas[nulo+1][3]=1;
				    f=f+5; c=0;
		default: break;  */
		
		//----------------------------------------------------------------------------------------------------------------------
		
		
		
		//-----------------------------------------------------reading the command line-----------------------------------------
		if (strcmp(comLine, "exit") == 0){								//write exit to quit			
			keep = 0;}
			
		if(strcmp(comLine, "catejemplo.c" ) == 0){
		printf("Hello crazy cat  \n");}
		if(strcmp(comLine, "date") == 0){
			time_t tiempo = time(0);
			struct tm *tlocal = localtime(&tiempo);
			char output[128];
			strftime(output, 128, "%d/%m/%y %H:%M:%S", tlocal);
			printf("Fecha y Hora: %s  \n",output);
		}
		if(strcmp(comLine, "who") == 0){	
		printf("be serious !  \n");}
		if(strcmp(comLine, "call") == 0){
		printf("you call me, Im here...  \n");}	
		if(strcmp(comLine, "ls") == 0){
		printf("maybe I can show you something usefull but I won't  \n");}	
		if(strcmp(comLine, "top") == 0){
		printf("let's foward  \n");	}
		if(strcmp(comLine, "ps") == 0){
		printf("what are you mean???  \n");	}
		if(strcmp(comLine, "less") == 0){
		printf("less free time, more hard work  \n");}	
		if(strcmp(comLine, " ") == 0){
		printf("invalid command  \n");}
		//-----------------------------------------------------------------------------------------------------------------------
		
		
		//----------------------------------------------------- create the command history to be access--------------------------
 		
		pFile = fopen ( "history.txt", "r+" ); 
			
			fputs( storage, pFile );
			fclose ( pFile );
 	
		
		
		/*for(int i = 0; i < 10; i++){*/
		//if(strcmp(comLine, "history") == 0){}
		//}
		//-----------------------------------------------------------------------------------------------------------------------
		
		
		
		
		
		comm1->cmd_path = command;
		comm1->argv[0] = comm1->cmd_path;
		
		
		if (comLine[cmdlen-2] == '&'){										//Anlize if it's executing in second roll
		
			comLine[cmdlen-2] = '\0'; 									
			flagsecond = 1;
			}
		
		
	
	}
	while (keep==1);
	
	
	
	return 0;
}
