//
// Created by Liu Wei on 2019-10-11.
//
#include "stdio.h"
#include "stdlib.h"

#define MAXLEN 3

typedef int datatype;

typedef struct {
    datatype data[MAXLEN];
    int top;
} SeqStack;

SeqStack *CreateStack_Seq() {
    SeqStack *stack = (SeqStack *) malloc(sizeof(SeqStack));
    stack->top = -1;

    return stack;
}

void PushStack_Seq(SeqStack *stack, datatype x) {
    if (stack->top == MAXLEN - 1) {
        printf("already full, no push");
        return;
    }

    stack->top++;
    stack->data[stack->top] = x;
}

datatype ReadTopStack_Seq(SeqStack *stack) {
    return stack->data[stack->top];
}

datatype PopStack_Seq(SeqStack *stack) {
    if (stack->top == -1) {
        printf("already empty, no pop");
        return -1000000;
    }

    datatype result = stack->data[stack->top];
    stack->top--;
    return result;
}

void ShowStack_Seq(SeqStack *stack) {
    printf("\n");

    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }

    printf("\n");
}

int main() {
    SeqStack *stack = CreateStack_Seq();
    PushStack_Seq(stack, 1);
    PushStack_Seq(stack, 2);
    PushStack_Seq(stack, 3);
    PushStack_Seq(stack, 4);
    ShowStack_Seq(stack);

    int x = ReadTopStack_Seq(stack);
    printf("%d", x);
    ShowStack_Seq(stack);

    getchar();
}
