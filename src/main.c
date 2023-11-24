#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(){
	char *buffer = malloc(BUFFER_SIZE);
	int i;
	while(fgets(buffer, sizeof buffer, stdin) != NULL) {  // reads newline too
        	i = 0;
        	while (buffer[i] != '\0') {                     // shortcut to testing newline and nul
            	printf("%d ", buffer[i]);                  // print char value
            	i++;
        	}
        printf ("\n");
        free(buffer);     	
	}

	  
return 0;

}




