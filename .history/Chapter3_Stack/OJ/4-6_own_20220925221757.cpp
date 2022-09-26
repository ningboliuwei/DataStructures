//
// Created by 慰 on 2018/10/1.
// 1605【数据结构3-6】栈的应用——表达式求解

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXP_MAX_LENGTH 20

typedef char DataType;

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
    if (stack->top == NULL) { return 0; }

    topElement = stack->top->data;

    return 1;
}

int Push(LinkStack *stack, char x) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = x;
    node->next = stack->top;
    stack->top = node;
}

int Pop(LinkStack *stack, char &x) {
    // 栈为空
    if (stack->top == NULL) { return 0; }

    StackNode *node = stack->top;
    x = node->data;
    stack->top = node->next;
    free(node);

    return 1;
}

int IsEmptyStack(LinkStack *stack) {
    if (stack->top == NULL) { return 1; }
    return 0;
}

int GetOperatorLevel(char op) {
    if (op == '#') { return 0; }

    if (op == '(' || op == ')') { return 1; }

    if (op == '+' || op == '-') { return 2; }

    if (op == '*' || op == '/') { return 3; }

    return -1;
}

main() {
    LinkStack *expressionStack = (LinkStack *)malloc(sizeof(LinkStack));
    InitStack(expressionStack);
    DataType currentChar;
    while (scanf("%c", &currentChar) && currentChar != '#') {
        // 如果是数字，直接输出
        if (currentChar == '0' || currentChar == '1' || currentChar == '2' || currentChar == '3' || currentChar == '4'
            || currentChar == '5' || currentChar == '6' || currentChar == '7' || currentChar == '8'
            || currentChar == '9') {
            printf("%c ", currentChar);
        } else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            if (IsEmptyStack(expressionStack)) {
                Push(expressionStack, currentChar);
            } else {
                int currentOperatorLevel = GetOperatorLevel(currentChar);
                char stackTopOperator;
                ReadTop(expressionStack, stackTopOperator);
                int stackTopOperatorLevel = GetOperatorLevel(stackTopOperator);

                // 若当前输入的运算符的优先级 <= 栈顶运算符优先级，则将所有运算符进行出栈，直到栈顶元素优先级
                while (currentOperatorLevel <= stackTopOperatorLevel && !IsEmptyStack(expressionStack)) {
                    Pop(expressionStack, stackTopOperator);
                    printf("%c ", stackTopOperator);
                    ReadTop(expressionStack, stackTopOperator);
                    int stackTopOperatorLevel = GetOperatorLevel(stackTopOperator);
                }

                Push(expressionStack, currentChar);
            }
        }
    }

    while (!IsEmptyStack(expressionStack)) {
        char stackTopOperator;
        Pop(expressionStack, stackTopOperator);
        printf("%c ", stackTopOperator);
    }

    getchar();
    getchar();
}