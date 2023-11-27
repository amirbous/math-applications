#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "help.h"

#define BUFFER_SIZE 1024

typedef struct command{

	char* keyword;
	char* next;

};

int main(){
	char* buffer = malloc(BUFFER_SIZE);
	char* command;
	int i;

	printWelcome();
	do{
		printf(">");
		fgets (buffer, BUFFER_SIZE, stdin);
		command = malloc(strlen(buffer)* sizeof(char));
		strcpy(command, buffer);
		if (strcmp(command, "exit\n") == 0) return 0;
		i = 0;
		while (command[i] != '\0') {
			printf("%c", command[i]);	
    			i++;
		}

	}while(1);
	  
return 0;

}




