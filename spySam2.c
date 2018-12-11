//Proyecto #1
/* Universidad Nacional de Costa Rica
 * Sistemas Operativos
 * Created by Roger Amador Villagra
 * Código fuente
 * 2017
 * 
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <time.h>
#define max_history 10
#define max_command 500
#define max_args 3


typedef struct
{																		
	char *cmd_path;	
	int argc;	
	char *argv[max_args];
	char cmd_suffix;
}commandForm;
typedef char cadenaCaracteres [50]; 
cadenaCaracteres *cadenas[max_history];
//char *cadenas[max_history]; // this array contain the last 10 commands 
int contador=0;
//-----------------------------------------------------running the command line-----------------------------------------
int runCommand(commandForm * command1, char * comLine,int aux){	
	execv(command1->cmd_path, command1->argv);
	cadenas[aux] = malloc(sizeof(commandForm*));
	char * cd[max_history];
	if(strcmp(comLine, "catejemplo.c" ) == 0){
		printf("Hello crazy cat  \n");
		strcpy(comLine,"catejemplo.c");
		cadenas[aux]=comLine;
		//cd[aux] = cadenas[aux];
		
		}
		if(strcmp(comLine, "date") == 0){
			time_t tiempo = time(0);
			struct tm *tlocal = localtime(&tiempo);
			char output[128];
			strftime(output, 128, "%d/%m/%y %H:%M:%S", tlocal);
			printf("Fecha y Hora: %s  \n",output);
			strcpy(comLine,"date");
			cadenas[aux]=comLine;
			//cd[aux] = cadenas[aux];
			
		}
		if(strcmp(comLine, "who") == 0){	
		printf("be serious !  \n");
		strcpy(comLine,"who");
		cadenas[aux]=comLine;
		//cd[aux] = cadenas[aux];
		}
		if(strcmp(comLine, "call") == 0){
		printf("you call me, Im here...  \n");
		strcpy(comLine,"call");
		cadenas[aux]=comLine;
		//cd[aux] = cadenas[aux];
		}	
		if(strcmp(comLine, "ls") == 0){
		printf("maybe I can show you something usefull but I won't  \n");
		strcpy(comLine,"ls");
		cadenas[aux]=comLine;
		//cd[aux] = cadenas[aux];
		}	
		if(strcmp(comLine, "top") == 0){
		printf("let's foward  \n");	
		strcpy(comLine,"top");
		cadenas[aux]=comLine;
		//cd[aux] = cadenas[aux];
		}
		if(strcmp(comLine, "ps") == 0){
		printf("what are you mean???  \n");
		strcpy(comLine,"ps");
		cadenas[aux]=comLine;
		//cd[aux] = cadenas[aux];
		}
		if(strcmp(comLine, "less") == 0){
		printf("less free time, more hard work  \n");
		strcpy(comLine,"less");
		cadenas[aux]=comLine;
		//cd[aux] = cadenas[aux];
		}	
		if(strcmp(comLine, " ") == 0){
		printf("invalid command  \n");
		}
		if(strcmp(comLine, "history") == 0){
		strcpy(comLine,"history");
		cadenas[aux]=comLine;
		toString(cadenas);
		//cd[aux] = cadenas[aux];
		}
		return 1;
		
	}
//-----------------------------------------------------------------------------------------------------------------------		
	
//----------------------------------------------------- create the command history to be access--------------------------
	void addHistory(char *cd[], char *comand){
		
		}
//-----------------------------------------------------------------------------------------------------------------------
	void toString(char** cad[]){
		for(int i = 0; i < max_history; i++){
		printf(" \n");
		printf("%d ",i+1);
		printf("%s",cad[i]);
		printf(" \n");	
		}	
	}
//-----------------------------------------------------------------------------------------------------------------------
int runCommand(commandForm * command1, char * comLine,int aux);
void toString(char** cad[]);
void addHistory(char *cd[], char *comand);

int main(){
	
	char *linea;
	char buffer[max_command];
	char *arg;
	char *command;
	int flag;
	
	int childstatus;
	int status;
	int cmdlen;
	int flagsecond;
	
	commandForm *command1 = (commandForm*) malloc(sizeof(commandForm));	
	
	int aux=-1;
	
	flag = 1;
	
	printf("Welcome to my first litle shell spySam\n");
	printf("To exit write and press enter (exit)\n");
	
	do{
		
		flagsecond=0;
		command1->argc = 1;
		printf("spySam >");
		fflush(stdout);
		linea=fgets(buffer, 50, stdin);									
		cmdlen = strlen(linea);
		if (linea[cmdlen-1] == '\n'){
			linea[cmdlen-1] = '\0';
		}
			
		arg = strtok(linea, " ");
		command = arg;
		
		if (strcmp(linea, "exit") == 0)											
			flag = 0;
		
		command1->cmd_path = command;
		command1->argv[0] = command1->cmd_path;
		aux++;
		
		while (1){
			if (command1->argc > 4) {
				printf("\nError! Too many command arguements!\n");
				break;
			}
            arg = strtok(NULL, " ");									
            if (arg == NULL){
				break;
			}
			
		command1->argv[command1->argc] = arg;							
		command1->argc = command1->argc+1;								
		}
		
		if(aux == 10){
			aux = -1;
			}
		
		
		if (linea[cmdlen-2] == '&')										
		{
			linea[cmdlen-2] = '\0'; 									
			flagsecond = 1;
		}
	
		
		childstatus = fork();
		if (childstatus != 0){
			if (!flagsecond)										
				wait(&status);
		} 
		else {
			
			return runCommand(command1,linea,aux);
		}
		
	}
	while (flag==1);
	return 0;
}
