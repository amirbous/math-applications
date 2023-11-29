#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "utils/help.h"
#include "utils/list_command.h"

#define BUFFER_SIZE 1024

typedef struct Linked_command Linked_command;

int main(){
	char* buffer = malloc(BUFFER_SIZE);
	int i;

	printWelcome();
	do{
		printf(">");
		fgets (buffer, BUFFER_SIZE, stdin);

		Linked_command *command;
		command->single_word = malloc(strlen(buffer)* sizeof(char));
		strcpy(command->single_word, buffer);
		if (strcmp(command->single_word, "exit\n") == 0) return 0;
		i = 0;

		while (command->single_word[i] != '\0') {
			printf("%c", command->single_word[i]);	
    			i++;
		}

	}while(1);
	  
return 0;

}




