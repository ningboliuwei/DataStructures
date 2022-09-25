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

void ShowSelectedWeights(LinkStack *stack, int itemWeights[MAX_ITEM_COUNT]) {
    int selectedWeightIndexes[MAX_ITEM_COUNT];
    int index = 0;

    while (!IsEmptyStack(stack)) {
        DataType element;
        Pop(stack, element);
        selectedWeightIndexes[index] = element;
        index++;
    }

    for (int i = index - 1; i >= 0; i--) {
        if (i != 0) {
            printf("%d\n", itemWeights[selectedWeightIndexes[i]]);
        } else {
            printf("%d", itemWeights[selectedWeightIndexes[i]]);
        }
    }
}

int Packaging(int maxCapacity, int itemCount, int itemWeights[MAX_ITEM_COUNT], LinkStack *&selectedItemWeightsStack) {
    int totalWeight = 0;
    int itemToTryIndex = 0;

    while (itemToTryIndex != itemCount) {
        int weightToTry = itemWeights[itemToTryIndex];
        // 若 当前总重量 + 接下来要尝试的重量 = 背包总容量，则算找到了解，将要尝试的重量对应的下标入栈，并 return 退出函数
        if (totalWeight + weightToTry == maxCapacity) {
            Push(selectedItemWeightsStack, itemToTryIndex);
            totalWeight += weightToTry;
            return 1;
        } else if (totalWeight + weightToTry > maxCapacity) {
            // 若 当前总重量 + 接下来要尝试的重量 > 背包总容量，则不进行任何操作，直接尝试下一个
            itemToTryIndex++;
            // 若已经尝试完了最后一个重量，则弹出现有栈顶，并从要弹出的栈顶的下一个开始尝试
            if (itemToTryIndex == itemCount) {
                int stackTopIndex;
                Pop(selectedItemWeightsStack, stackTopIndex);
                itemToTryIndex = stackTopIndex + 1;
                totalWeight -= itemWeights[stackTopIndex];
            }
        } else {
            // 若 当前总重量 + 接下来要尝试的重量 > 背包总容量，且要尝试的不是最后一个，则将要尝试的重量对应的下标入栈；如果已经尝试过了最后一个，则弹栈，说明上一个放入的无解，试试上一个放入的下一个。
            if (itemToTryIndex != itemCount - 1) {
                Push(selectedItemWeightsStack, itemToTryIndex);
                totalWeight += weightToTry;
                itemToTryIndex++;
            } else {
                int stackTopIndex;
                if (!IsEmptyStack(selectedItemWeightsStack)) {
                    Pop(selectedItemWeightsStack, stackTopIndex);
                    itemToTryIndex = stackTopIndex + 1;
                    totalWeight -= itemWeights[stackTopIndex];
                }
            }
        }
    }

    return -1;
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

    int result = Packaging(maxCapacity, itemCount, itemWeights, selectedItemWeightsStack);

    if (result == -1) {
        printf("无解；");
    } else {
        ShowSelectedWeights(selectedItemWeightsStack, itemWeights);
    }

    getchar();
    getchar();
}