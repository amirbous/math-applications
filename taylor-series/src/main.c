#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"
#include "modes.h"

enum Function{Invalid, Exponentiel, NatLogarithm, Cosinus, Sinus};

int main(int argc, char **argv){
	char read_value = -1, option = 0;	
	int i, depth = 20;
	float value;
	enum Function curr_fn;

	if (argc == 1){printf("too few arguments, -h for help\n"); exit(1);}
	else if (argc == 2) {		
		if ((int)argv[1][0] == '-'){
		if (strlen(argv[1]) == 2 && (int)argv[1][1] == 'h') {printHelp(); exit(0); }
		else printf("invalid command line arguments, -h for help \n");
		exit(0);		
		}
	
			printf("too few arguments, -h for help\n");
			exit(0);
		}
	
		for (i = 1; i < argc; i++){	
		if (i == 1){ 
			if (strcmp(argv[1], "exp") == 0)curr_fn = Exponentiel;
			else if (strcmp(argv[1], "ln") == 0) curr_fn = NatLogarithm;
			else {
			printf("invalid function name, please check the list of valid function names from the help\n");
			exit(1);}
			}
		else if (i == 2) { value = atof(argv[2]);}
		else {
			switch(read_value){	
				case -1:
					if ((int)(argv[i][0] != '-') || strlen(argv[i]) != 2) {
					
					printf("invalid command ilne arguments\n");	
					exit(1);
					}
					else{
				
						switch((int)argv[i][1]){
							case 'd':
							case 'D':
								if (argc <= i + 1) {
									printf("missing value for this option\n");
									exit(1);;
								}
								read_value = 1;
								break;
							default:
								printf("invalud option\n");
								exit(1);	
							}
					}
					break;		
				case 1:
					if (atoi(argv[i]) <= 0){
						printf("invalud option value\n");
						exit(1);
					}		
					else {
						depth = atoi(argv[i]);
					}
					
					break;	
				}

				
			}
			
			}
		switch(curr_fn){
			case Exponentiel:
				printf("T[%f, %d] of exponentiel = ", value, depth);
				printf("%0.10LF\n", exponentiel(value, depth));		
				break;
			case NatLogarithm:
				if (value < 0) { printf("invalid value\n");	exit(1);}	
				printf("T[%f, %d] of natural logarithm = ", value, depth);
				printf("%0.10LF\n", nat_logarithm(value, depth));
			default:
				break;
		}	
		
		
		
	return EXIT_SUCCESS;
}
