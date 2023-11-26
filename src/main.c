#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(){
	char* buffer = malloc(BUFFER_SIZE);
	char* command;
	int i;
    	do {
        	printf("> "); /* (A) */
        	scanf("%s", buffer); /* (B) */
		i = 0;
		command = malloc(strlen(buffer)* sizeof(char));
		strcpy(command, buffer);
		if (strcmp(command, "exit") == 0) return 0;
		while (command[i] != '\0') {
			printf("%c", buffer[i]);	
    			i++;
		}
		printf("\n");
	} while(1);
    	return 0;
	  
return 0;

}




