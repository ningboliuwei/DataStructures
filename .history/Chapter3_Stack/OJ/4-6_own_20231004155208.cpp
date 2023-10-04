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
    if (stack->top == NULL) {
        return 0;
    }

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

int GetOperatorLevel(char op) {
    if (op == '#') {
        return 0;
    }

    if (op == '(' || op == ')') {
        return 1;
    }

    if (op == '+' || op == '-') {
        return 2;
    }

    if (op == '*' || op == '/') {
        return 3;
    }

    return -1;
}

main() {
    LinkStack *expressionStack = (LinkStack *)malloc(sizeof(LinkStack));
    InitStack(expressionStack);
    DataType currentChar;
    char suffixExpression[100];
    int index = -1;
    // 中缀表达式转换为后缀表达式--BEGIN
    while (scanf("%c", &currentChar) && currentChar != '#') {
        // 如果是数字，直接输出
        if (currentChar == '0' || currentChar == '1' || currentChar == '2' || currentChar == '3' || currentChar == '4'
            || currentChar == '5' || currentChar == '6' || currentChar == '7' || currentChar == '8'
            || currentChar == '9') {
            printf("%c ", currentChar);
            suffixExpression[++index] = currentChar;
        } else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            if (IsEmptyStack(expressionStack)) {
                Push(expressionStack, currentChar);
            } else {
                int currentOperatorLevel = GetOperatorLevel(currentChar);
                char stackTopOperator;
                ReadTop(expressionStack, stackTopOperator);
                int stackTopOperatorLevel = GetOperatorLevel(stackTopOperator);

                // 若当前输入的运算符的优先级 <= 栈顶运算符优先级，则将所有运算符进行出栈，直到栈顶元素优先级 >
                // 当前输入的运算符优先级为止
                // 然后再将当前的入栈
                while (currentOperatorLevel <= stackTopOperatorLevel && !IsEmptyStack(expressionStack)) {
                    Pop(expressionStack, stackTopOperator);
                    printf("%c ", stackTopOperator);
                    suffixExpression[++index] = stackTopOperator;
                    ReadTop(expressionStack, stackTopOperator);
                    stackTopOperatorLevel = GetOperatorLevel(stackTopOperator);
                }

                Push(expressionStack, currentChar);
            }
        }
    }
    // 结束所有输入操作后，将所有剩下的运算符依次出栈
    while (!IsEmptyStack(expressionStack)) {
        char stackTopOperator;
        Pop(expressionStack, stackTopOperator);
        printf("%c ", stackTopOperator);
        suffixExpression[++index] = stackTopOperator;
    }
    // 中缀表达式转换为后缀表达式--END

    printf("\n");
    // 计算后缀表达式结果--BEGIN
    LinkStack *calculationStack = (LinkStack *)malloc(sizeof(LinkStack));
    InitStack(calculationStack);
    int result = 0; // 定义一个变量result，用于存储计算结果

    for (int i = 0; i <= index; i++) {          // 遍历后缀表达式
        char currentChar = suffixExpression[i]; // 获取当前字符

        if (currentChar == '0' || currentChar == '1' || currentChar == '2' || currentChar == '3' || currentChar == '4'
            || currentChar == '5' || currentChar == '6' || currentChar == '7' || currentChar == '8'
            || currentChar == '9') {             // 如果当前字符是数字
            Push(calculationStack, currentChar); // 将数字入栈
        } else if ((currentChar == '+' || currentChar == '-' || currentChar == '*'
                    || currentChar == '/')) { // 如果当前字符是运算符，接连弹出两个栈顶元素进行运算
            char stackTopElement;             // 定义一个变量stackTopElement，用于存储栈顶元素
            Pop(calculationStack, stackTopElement); // 弹出栈顶元素
            int x = (int)stackTopElement - '0';     // 将栈顶元素转换为数字
            Pop(calculationStack, stackTopElement); // 弹出栈顶元素
            int y = (int)stackTopElement - '0';     // 将栈顶元素转换为数字

            if (currentChar == '+') {        // 如果当前运算符是加号
                result = x + y;              // 计算x+y的值
            } else if (currentChar == '-') { // 如果当前运算符是减号
                result = x - y;              // 计算x-y的值
            } else if (currentChar == '*') { // 如果当前运算符是乘号
                result = x * y;              // 计算x*y的值
            } else if (currentChar == '/') { // 如果当前运算符是除号
                result = x / y;              // 计算x/y的值
            }

            Push(calculationStack, result); // 将计算结果入栈
        }
    }
    printf("%d", result);
    // 计算后缀表达式结果--END

    getchar();
    getchar();
}