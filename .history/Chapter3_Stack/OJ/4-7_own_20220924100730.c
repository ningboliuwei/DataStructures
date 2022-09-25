//
// Created by 慰 on 2018/10/5.
// 问题 G: 【数据结构3-5】栈的应用——背包问题

#include <stdio.h>
#include <stdlib.h>

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

int IndexOf(DataType *array, int length, DataType value) {
    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int maxCapacity = 0;
    int n = 0;
    int weight[10];
    //    printf("Input capacity:\n");
    scanf("%d", &maxCapacity);
    //    printf("Input count:\n");
    scanf("%d", &n);
    //    printf("Input item weight:\n");
    for (int i = n - 1; i >= 0; i--) {
        scanf("%d", weight + i);
    }

    LinkStack *stack = (LinkStack *)malloc(sizeof(StackNode));
    InitStack(stack);

    int totalWeight = 0;
    int nextStart = 0;

    while (totalWeight < maxCapacity) {
        for (int i = nextStart; i < n; i++) {
            int currentWeight = weight[i];

            if (totalWeight + currentWeight <= maxCapacity) {
                Push(stack, currentWeight);
                nextStart = i + 1;
                totalWeight = totalWeight + currentWeight;

                if (totalWeight == maxCapacity) {
                    break;
                }
            }
        }

        if (totalWeight < maxCapacity) {
            DataType *element = (DataType *)malloc(sizeof(DataType));
            Pop(stack, element);
            totalWeight = totalWeight - *element;
            nextStart = IndexOf(weight, n, *element) + 1;
        }
    }
    ShowStack(stack);
}