//
// Created by 慰 on 2018/10/7.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_COUNT 1000

typedef char DataType;

typedef struct StackNodeStruct {
    DataType data;
    struct StackNodeStruct *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;

void InitStack(LinkStack *stack) { stack->top = NULL; }

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

int ClearStack(LinkStack *stack) {
    DataType topElement;

    while (!IsEmptyStack(stack)) {
        Pop(stack, topElement);
    }
}

void ShowLine(LinkStack *stack) {
    while (!IsEmptyStack(stack)) {
        DataType topElement;
        Pop(stack, topElement);
        printf("%c", topElement);
    }
    printf("\n");
}

void EditLines() {
    DataType currentChar;
    DataType topElement;
    DataType lines[MAX_CHAR_COUNT];
    int index = 0;

    LinkStack *lineStack = (LinkStack *)malloc(sizeof(LinkStack));
    InitStack(lineStack);

    while (scanf("%c", &currentChar)) {
        if (currentChar == '\n' || currentChar == '$') {
            ShowLine(lineStack);
        } else if (currentChar == '#') {
            Pop(lineStack, topElement);
        } else if (currentChar == '@') {
            ClearStack(lineStack);
        } else {
            Push(lineStack, currentChar);
        }

        if (currentChar == '$') {
            break;
        }
    }
}

int main() { EditLines(); }