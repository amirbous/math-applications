
unsigned long long factorial(int n) {
	int i;
	unsigned long long result = 1;
	for (i = n; i > 0; i--) {
		result *= i;
	}
	return result;
}
