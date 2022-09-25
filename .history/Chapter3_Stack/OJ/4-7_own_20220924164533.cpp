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

int ReadTop(LinkStack *stack, DataType &topElement) {
    if (stack->top == NULL) {
        return 0;
    }

    topElement = stack->top->data;

    return 1;
}

int Push(LinkStack *stack, DataType x) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = x;
    node->next = stack->top;
    stack->top = node;
}

int Pop(LinkStack *stack, DataType &x) {
    // 栈为空
    if (stack->top == NULL) {
        return 0;
    }

    StackNode *node = stack->top;
    x = node->data;
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

void ShowStack(LinkStack *stack) {
    while (!IsEmptyStack(stack)) {
        DataType element;
        Pop(stack, element);
        printf("%d ", element);
    }
}

int Packaging(int maxCapacity, int itemCount, int itemWeights[MAX_ITEM_COUNT], LinkStack *&selectedItemWeightsStack) {
    int totalWeight = 0;
    int itemToTryIndex = 0;
    bool solutionFound = false;

    while (1) {
        // 要尝试装入背包的重量
        int weightToTry = itemWeights[itemToTryIndex];
        int latestSelectedItemIndex = -1;

        if (itemToTryIndex == itemCount) {
            int stackTopWeight;
            Pop(selectedItemWeightsStack, stackTopWeight);
        }

        if (totalWeight + weightToTry < maxCapacity) {
            Push(selectedItemWeightsStack, weightToTry);
            latestSelectedItemIndex = itemToTryIndex;
            totalWeight += weightToTry;
            itemToTryIndex++;
        } else if (totalWeight + weightToTry > maxCapacity) {
            int stackTopWeight;
            itemToTryIndex++;
            continue;
        } else {
            totalWeight += weightToTry;
            Push(selectedItemWeightsStack, weightToTry);
            break;
        }
    }
}

int main() {
    int maxCapacity = 0;
    int itemCount = 0;
    int itemWeights[MAX_ITEM_COUNT];
    LinkStack *selectedItemWeightsStack;
    selectedItemWeightsStack = (LinkStack *)malloc(sizeof(LinkStack));
    InitStack(selectedItemWeightsStack);

    scanf("%d", &maxCapacity);
    scanf("%d", &itemCount);

    for (int i = 0; i < itemCount; i++) {
        scanf("%d", &itemWeights[i]);
    }

    Packaging(maxCapacity, itemCount, itemWeights, selectedItemWeightsStack);

    getchar();
}