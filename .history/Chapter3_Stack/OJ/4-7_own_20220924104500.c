//
// Created by 慰 on 2018/10/5.
// 1604 问题 G: 【数据结构3-5】栈的应用——背包问题

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEM_COUNT 10
typedef int DataType;

typedef struct StackNodeStruct {
    DataType data;
    struct StackNodeStruct *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;

void InitStack(LinkStack *stack) {
    stack->top = NULL;
}

int ReadTop(LinkStack *stack, DataType *topElement) {
    if (stack->top == NULL) {
        return 0;
    }

    *topElement = stack->top->data;

    return 1;
}

int Push(LinkStack *stack, DataType x) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = x;
    node->next = stack->top;
    stack->top = node;
}

int Pop(LinkStack *stack, DataType *x) {
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
    while (!IsEmptyStack(stack)) {
        DataType *element = (DataType *)malloc(sizeof(DataType));
        Pop(stack, element);
        printf("%d ", *element);
    }
}

int main() {
    int maxCapacity = 0;
    int n = 0;
    int weight[MAX_ITEM_COUNT];

    scanf("%d", &maxCapacity);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    getchar();
}