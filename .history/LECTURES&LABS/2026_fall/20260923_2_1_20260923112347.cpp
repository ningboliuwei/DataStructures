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

int IsStackEmpty(SeqStack *s) {
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int Push(SeqStack *s, datatype x) {
    if (s->top == MAXLEN - 1) {
        return 0;
    } else {
        // s->top++;
        // s->data[s->top] = x;

        s->data[++s->top] = x;
    }
}

int main() {
    SeqStack *S;
    InitStack(S);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
}