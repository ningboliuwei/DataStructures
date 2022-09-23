//
// Created by 慰 on 2018/10/7.
//

#include <stdio.h>
#include <stdlib.h>

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
    DataType *topElement = (DataType *)malloc(sizeof(DataType));

    while (!IsEmptyStack(stack)) {
        Pop(stack, topElement);
    }
}

void LineEdit() {}

int main() {
    char ch;
    char *topElement = (char *)malloc(sizeof(char));
    char lines[10000];
    int index = 0;

    LinkStack *lineStack = (LinkStack *)malloc(sizeof(LinkStack));

    InitStack(lineStack);

    while (scanf("%c", &ch)) {
        if (ch == '\n' || ch == '$') {
            while (!IsEmptyStack(lineStack)) {
                Pop(lineStack, topElement);
                lines[index] = *topElement;
                index++;
            }
            lines[index] = '\n';
            index++;
        } else if (ch == '#') {
            Pop(lineStack, topElement);
        } else if (ch == '@') {
            ClearStack(lineStack);
        } else {
            Push(lineStack, ch);
        }

        if (ch == '$') {
            break;
        }
    }

    index = 0;
    int lineLength = 0;
    while (1) {
        if (lines[index] == '\n' || lines[index] == '$') {
            for (int i = 0; i <= lineLength - 1; i++) {
                printf("%c", lines[index - 1 - i]);
            }
            lineLength = 0;
            if (lines[index] == '\n') {
                printf("\n");
            }
        }

        index++;
        lineLength++;

        if (lines[index] == '$') {
            break;
        }
    }
}