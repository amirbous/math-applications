#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fillSubMatrix(int curr_Dimension, int target[curr_Dimension-1][curr_Dimension-1],
                   int source[curr_Dimension][curr_Dimension], int i, int j) {
    int k, l;
    int a = 0, b = 0;
    for (k = 0; k < curr_Dimension; k++) {
        if (k != i) {
            for (l = 0; l < curr_Dimension; l++) {
                if (l != j) {
                    target[a][b] = source[k][l];
                    b++;
                }
            }
            a++;
            b = 0;
        }
    }

}
int to_int (const char *s) {
    return atoi(s);
}
int determinant (int dimension, int matrix[dimension][dimension]) {
    int det = 0;
    if (dimension == 1) {
        return matrix[0][0];
    }
    if (dimension == 2) {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else {

        int temp[dimension - 1][dimension - 1];
        for (int i = 0; i < dimension; i++) {
            fillSubMatrix(dimension, temp, matrix, 0, i);
            det += matrix[0][i] * pow(-1, i)  * determinant(dimension - 1, temp);

        }


    }
    return det;

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
void invert_matrix(int dimension, int result[dimension][dimension]){

    if (determinant(dimension, result) == 0) {
        printf("impossible, there is no inverse matrix");
    }


}
int main(int argc, char *argv[]) {
    int dimension = to_int(argv[1]);
    int matrix[dimension][dimension];
    fill_matrix(dimension, matrix);
    printf("%d\t", determinant(dimension, matrix));
}