#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "utils/help.h"
#include "utils/list_command.h"

#define BUFFER_SIZE 1024

typedef struct LinkedCommand LinkedCommand;

enum Mode {DEFAULT = 0, ALGEBRA = 1, DISCRETE = 2, ANALYSIS = 3};



int main(){
	char* buffer = malloc(BUFFER_SIZE);
	int i;
	enum Mode activeMode = DEFAULT;

	printWelcome();
	do{
		switch (activeMode)
		{
		case ALGEBRA:
			printf("LinearAlgebra");
			break;
		case DISCRETE:
			printf("Discete structures");
			break;
		case ANALYSIS:
			printf("Analysis");
			break;

		default:

			break;
		}
		printf(">");
		fgets (buffer, BUFFER_SIZE, stdin);

		LinkedCommand *command = (LinkedCommand*)malloc(sizeof(LinkedCommand));
		
		strcpy(command->single_word, buffer);
		if (strcmp(command->single_word, "exit\n") == 0) return 0;
		LinkedCommand *commandlist = BuildLinkedCommand(buffer);

		if (strcmp(first(commandlist), "mode") == 0) {

			if (SizeCommand(commandlist) < 2) {
				continue;
			}
			else {
				activeMode = getWord(commandlist, 1)[0] - '0';
			}

		}


	}while(1);
	  
return 0;

}




