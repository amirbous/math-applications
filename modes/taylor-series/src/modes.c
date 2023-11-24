#include <math.h> 
#include "utils.h"
#include <stdio.h>
long double exponentiel (float x, int term){
	int i;
	long double result = 1.0;	

	for (i = 1; i <= term; i++) {
		
		result += (double)(pow(x, i) / factorial(i));

	}
	return result;
}


long double nat_logarithm (float x, int term) {

	int i;
	long double result = 0;
	char alter = -1;
	x--;

	for (i = 1; i <= term; i++) {
		alter *= -1;
		result += alter * (double)(pow(x, i) / factorial(i)); 
	}	

	return result;

}
