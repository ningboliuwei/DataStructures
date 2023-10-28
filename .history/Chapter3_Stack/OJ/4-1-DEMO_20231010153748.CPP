#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10
typedef int DataType;

typedef struct {
    DataType data[MAXLEN];
    int top;
} SeqStack;

int InitSeqStack(SeqStack &st) {
    // @@1

    // @@1
}

int Push(SeqStack &st, DataType x) {
    // @@2

    // @@2
}

int Pop(SeqStack &st, DataType &x) {
    // @@3

    // @@3
}

int IsSeqEmpty(SeqStack st) {
    // @@4

    // @@4
}

int main() {
    SeqStack st;
    DataType x;

    InitSeqStack(st);

    scanf("%d", &x);
    while (x >= 0) {
        Push(st, x);
        scanf("%d", &x);
    }
    while (!IsSeqEmpty(st)) {
        Pop(st, x);
        printf("%d\n", x);
    }

    int a;
    scanf("%d", a);
    return 1;
}