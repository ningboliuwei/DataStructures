//
// Created by 慰 on 2018/10/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXP_MAX_LENGTH 100

typedef int DataType;

typedef struct StackNodeStruct {
    DataType data;
    struct StackNodeStruct *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;

void InitStack(LinkStack *stack) { stack->top = NULL; }

int ReadTop(LinkStack *stack, DataType *x) {
    if (stack->top == NULL) {
        return 0;
    }

    *x = stack->top->data;

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

int IsEmpty(LinkStack *stack) {
    if (stack->top == NULL) {
        return 1;
    }

    return 0;
}

int MatchBracket(char *expression) {
    // state 1--目前匹配; state 0--不匹配
    int state = 1;
    int i = 0;
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));

    InitStack(stack);

    while (i < strlen(expression) && state) {
        DataType current = exp[i];

        if (current == '(' || current == '[') {
            Push(stack, exp[i]);
            i++;
        } else {
            DataType *top = (DataType *)malloc(sizeof(DataType));
            ReadTop(stack, top);
            if (!IsEmpty(stack) && ((*top == '(' && current == ')') ||
                                    (*top == '[' && current == ']'))) {
                Pop(stack, top);
                i++;
            } else {
                state = 0;
            }
        }
    }

    // 遍历了栈中所有的括号
    if (state && IsEmpty(stack)) {
        return 1;
    }

    return 0;
}

int main() {
    char *expression = (char *)malloc(sizeof(char) * EXP_MAX_LENGTH);
    gets(expression);

    if (MatchBracket(expression)) {
        printf("OK");
    } else {
        printf("Error");
    }

    getchar();
}