//
// Created by Liu Wei on 2018/9/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int datatype;

typedef struct StackNodeStruct {
    datatype data;
    struct StackNodeStruct *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;

void InitStack(LinkStack *stack) {
    stack->top = NULL;
}

int ReadTop(LinkStack *stack, int *x) {
    if (stack->top == NULL) {
        return 0;
    }

    *x = stack->top->data;

    return 1;
}


int Push(LinkStack *stack, datatype x) {
    StackNode *node = (StackNode *) malloc(sizeof(StackNode));
    node->data = x;
    node->next = stack->top;
    stack->top = node;
}

int Pop(LinkStack *stack, datatype *x) {
// 栈为空
    if (stack->top == NULL) {
        return 0;
    }

    StackNode *node = stack->top;
    *x = node->data;
    stack->top = node->next;
    free(node);

    return 1;
}

int IsEmptyStack(LinkStack *stack) {
    if (stack->top == NULL) {
        return 1;
    }
    return 0;
}

int ShowStack(LinkStack *stack) {
    printf("\n--------\n");
    StackNode *node;
    node = stack->top;

    while (node != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }

    printf("\n--------\n");
}

int main() {
    LinkStack *stack = (LinkStack *) malloc(sizeof(LinkStack));

    InitStack(stack);
    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);

    datatype *x = (datatype *) malloc(sizeof(int));
    ReadTop(stack, x);
    printf("top: %d\n", *x);

    ShowStack(stack);

    Pop(stack, x);
    printf("Popped: %d\n", *x);
    Pop(stack, x);
    printf("Popped: %d\n", *x);
    Pop(stack, x);
    printf("Popped: %d\n", *x);

    if (ReadTop(stack, x)) {
        printf("top: %d\n", *x);
    } else {
        printf("empty stack");
    }

    ShowStack(stack);

    getchar();
}


