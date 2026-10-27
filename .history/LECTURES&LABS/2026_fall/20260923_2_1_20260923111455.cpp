#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

typedef int datatype;

typedef struct StackType {
    datatype data[MAXLEN];
    int top;
} SeqStack;

int InitStack(SeqStack *&s) {
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;

    return 1;
}

int main() {
    SeqStack *S;
    InitStack(S);
}