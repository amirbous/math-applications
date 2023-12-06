struct Fraction {

    int numerator;
    int denominator;

    struct Fraction * rows;
    struct Fraction * columns;
};


struct Matrix {

    unsigned int width;
    unsigned int height;

    struct Fraction *elements;

};



struct Fraction * ScalarProduct(struct Matrix *v1, struct Matrix *v2);



