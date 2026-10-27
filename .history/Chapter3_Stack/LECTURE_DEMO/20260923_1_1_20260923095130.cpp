#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10
typedef int datatype;

typedef struct stack {
    datatype data[MAX_LENGTH];
    int top;
} SeqStack;

int InitStack(SeqStack *&S) {
    S = (SeqStack *)malloc(sizeof(SeqStack));
    S->top = -1;

    return 1;
}

int IsStackEmpty(SeqStack *S) {
    if (S->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int ReadTop(SeqStack *S, datatype &x) {
    if (IsStackEmpty(S)) {
        return 0;
    } else {
        x = S->data[S->top];
        return 1;
    }
}

int Pop(SeqStack *S, datatype &x) {
    if (IsStackEmpty(S)) {
        return 0;
    } else {
        x = S->data[S->top];
        S->top--;
        return 1;
    }
}

int Push(SeqStack *&S, datatype x) {
    if (S->top == MAX_LENGTH - 1) {
        return 0;
    } else {
        S->top++;
        S->data[S->top] = x;

        // S->data[++S->top] = x;
        return 1;
    }
}

int main() {
    SeqStack *S;
    InitStack(S);

    Push(S, 4);
    Push(S, 5);
    Push(S, 6);

    datatype x;
    Pop(S, x);
}