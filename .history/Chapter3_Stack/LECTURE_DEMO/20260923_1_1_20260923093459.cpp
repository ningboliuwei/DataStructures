#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10
typedef int datatype;

typedef struct stack {
    datatype data[MAX_LENGTH];
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