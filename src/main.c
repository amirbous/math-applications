#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "utils/help.h"
#include "utils/list_command.h"

#include <readline/readline.h>
#include <readline/history.h>
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
    buffer = readline("");
    
    LinkedCommand *commandlist = BuildLinkedCommand(buffer);
	//PrintCommand(commandlist);
	printf("%d\n", SizeCommand(commandlist));
		if (strcmp(first(commandlist), "exit") == 0 && SizeCommand(commandlist) == 1) return 0;
		if (strcmp(first(commandlist), "mode") == 0) {

			if (SizeCommand(commandlist) < 2) {
				continue;
			}
			else {
				activeMode = getWord(commandlist, 1)[0] - '0';
			}

		}
    free(buffer);

	}while(1);
	  
return 0;

}




