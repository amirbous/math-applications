#include <stdio.h>
#include <stdlib.h>



int to_int (const char *s) {
    return atoi(s);
}
void fill_matrix (int dimension, int result[dimension][dimension]) {

    for (int i = 0; i < dimension; i++) {
        char row[dimension];
        int a;
        printf("row n%d: ", i);
        scanf("%s", row);
        for (int j = 0; j < dimension;j++) result[i][j] = (row[j] - '0');

    }
}
void invert_matrix(int height, int width, int result[height][width]){




}
int main(int argc, char *argv[]) {
    int dimension = to_int(argv[1]);
    int matrix[dimension][dimension];
    fill_matrix(dimension, matrix);

}