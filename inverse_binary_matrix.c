#include <stdio.h>
#include <stdlib.h>



int to_int (const char *s) {
    return atoi(s);
}
void fill_matrix (int height, int width, int result[height][width]) {

    for (int i = 0; i < height; i++) {
        char row[width];
        int a ;
        printf("row n%d: ", i);
        scanf("%s", row);
        for (int j = 0; j < width;j++) result[i][j] = to_int(row[j]);

    }
}
void invert_matrix(int height, int width, int result[height][width]){




}
int main(int argc, char *argv[]) {
    int width = to_int(argv[1]);
    int height = to_int(argv[2]);
    int matrix[height][width];
    fill_matrix(height, width, matrix);

}