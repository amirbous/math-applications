#include <stdio.h>
#include <stdlib.h>

void outputResult (int p, int result[0][5]) {
    printf("-------------------------------\n");
    printf("\tEULER EXTENDED ALGORITHM\n");
    printf("-------------------------------\n");
    printf("\ta : b | k | ap : bt\n");
    printf("-------------------------------\n");
    for (int i = 0; i < p + 1; i++) printf("\t%d : %d | %d | %d : %d\n", result[i][0], result[i][1], result[i][2], result[i][3], result[i][4]);
    printf("-------------------------------\n");


}
void eulerAlphaBeta(int n, int result[0][5]) {
    int p = n;
    result[n][3] = 1;
    result[n][4] = 0;

    while ( n > 0) {
        result[n-1][3] = result[n][4] - result[n][3] * result[n-1][2];
        result[n-1][4] = result[n][3];
        --n;
    }
    outputResult(p, result);
}
int euler_extended(int n, int result[0][5], int a, int b) {
    result[n][0] = a;
    result[n][1] = b;
    result[n][2] = b / a;
    if (b % a == 0) {
        eulerAlphaBeta(n, result);
        return a;
    }
    return euler_extended(++n, result, b % a, a);
}
int to_int(const char *s)
{
    return atoi(s);
}
int main(int argc, char *argv[]) {

    int a = to_int(argv[1]);
    int b = to_int(argv[2]);
    int eulerExtended[1][5];
   
    printf("input both numbers: ");
    printf("\t gcd (%d, %d) = %d\n", a, b, euler_extended(0, eulerExtended, b, a));
    printf("-------------------------------\n");
    return 0;
}
