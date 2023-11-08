#include <stdio.h>
#include <stdlib.h>


struct Row {
	unsigned int a;
	unsigned int b;
	int k;
	int alpha;
	int beta;
    struct Row *prev;
	struct Row *next;

};
void initRow(struct Row *row, int a, int b){
    row->a = a;
    row->b = b;
}



void eulerAlphaBeta(struct Row *row) {
    
    if (row->next == NULL){
        row->alpha = 1;
        row->beta = 0;
    } 
    else {
        row->alpha = row->prev->beta - row->prev->alpha * row->k;
    }
    printf("%d | %d || %d || %d || %d\n", row->a, row->b, row->k, row->alpha, row->beta);
    if (row->prev == NULL) return;
    else {
        eulerAlphaBeta(row->prev);
    }
 
}
int euler_extended(struct Row *row) {
	row->k = row->a / row->b;
    printf("%d\n", row->k);
    if (row->b % row->a == 0) {
        eulerAlphaBeta(row);
        return row->a;
    }
    struct Row next = {row->b % row->a, row->a, 0, 0, 0, row, NULL};
    return euler_extended(&next);
}

int to_int(const char *s)
{
    return atoi(s);
}

int main(int argc, char *argv[]) {

    unsigned int a = to_int(argv[1]);
    unsigned int b = to_int(argv[2]);

    struct Row head = {a, b, 0, 0, 0,NULL, NULL};
    printf("\tgcd (%d, %d) = %d\n", a, b, euler_extended(&head));

    return 0;
}
