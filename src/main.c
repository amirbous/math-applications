#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "utils/help.h"
#include "utils/list_command.h"

#define BUFFER_SIZE 1024

typedef struct LinkedCommand LinkedCommand;

int main(){
	char* buffer = malloc(BUFFER_SIZE);
	int i;

	printWelcome();
	do{
		printf(">");
		fgets (buffer, BUFFER_SIZE, stdin);

		LinkedCommand *command = (LinkedCommand*)malloc(sizeof(LinkedCommand));
		
		strcpy(command->single_word, buffer);
		if (strcmp(command->single_word, "exit\n") == 0) return 0;
		LinkedCommand *commandlist = BuildLinkedCommand(buffer);
	
		if (strcmp(first(commandlist), "mode") == 0) printf("current mode: DEFAULT\n");


		
	}while(1);
	  
return 0;

}




