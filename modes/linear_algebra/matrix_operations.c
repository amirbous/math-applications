#include <stdlib.h>
#include <stddef.h>

struct Fraction {

    int numerator;
    int denominator;
};

struct Matrix {

    int width;
    int height;

    struct Fraction *elements;

};

typedef struct Fraction Fraction;
typedef struct Matrix Matrix;



struct Fraction * ScalarProduct(struct Matrix *v1, struct Matrix *v2){
    Fraction *result = 0;
    if (v1->width + v2->width != 2 || v1->height != v2->height) {
        printf("invalid dimensions, both vectors should be of width 1, and have the same height");
        
    }
    return result;
}





