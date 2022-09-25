//
// Created by 慰 on 2018/10/1.
// 1605【数据结构3-6】栈的应用——表达式求解

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXP_MAX_LENGTH 20

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

int Push(LinkStack *stack, char x) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = x;
    node->next = stack->top;
    stack->top = node;
}

int Pop(LinkStack *stack, char *x) {
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

int Infix2Suffix(char *infix, char *suffix) {
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
    char index = 0;
    char *topElement = (char *)malloc(sizeof(char));

    InitStack(stack);

    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '#') {
            break;
        }

        char current = infix[i];

        // 非运算符，直接输出
        if (GetOperatorLevel(current) == -1) {
            suffix[index] = current;
            index++;

            if (GetOperatorLevel(infix[i + 1]) != -1) {
                suffix[index] = ' ';
                index++;
            }
        } // 运算符
        else {
            //如果op=='('，则直接入栈
            if (current == '(') {
                Push(stack, current);
            } // 如果
              // op==')'，则依次弹出栈顶直到弹出'('，但'('不输出到后缀表达式
            else if (current == ')') {
                do {
                    Pop(stack, topElement);

                    if (*topElement != '(') {
                        suffix[index] = *topElement;
                        index++;

                        suffix[index] = ' ';
                        index++;
                    }
                } while (*topElement != '(');
            } // 如果栈为空，则直接入栈
            else if (IsEmptyStack(stack)) {
                Push(stack, current);
            } else {
                ReadTop(stack, topElement);
                // 如果op的优先级高于栈顶操作符的优先级，则入栈
                if (GetOperatorLevel(current) > GetOperatorLevel(*topElement)) {
                    Push(stack, current);
                } // 如果op的优先级低于或等于栈顶操作符的优先级，则依次弹出栈顶直到op的优先级高于栈顶操作符的优先级（或栈为空），再将op入栈
                else {
                    while (ReadTop(stack, topElement) && GetOperatorLevel(current) <= GetOperatorLevel(*topElement)) {
                        Pop(stack, topElement);
                        suffix[index] = *topElement;
                        index++;

                        suffix[index] = ' ';
                        index++;
                    }
                    Push(stack, current);
                }
            }
        }
    }

    while (!IsEmptyStack(stack)) {
        Pop(stack, topElement);

        if (*topElement != ')') {
            suffix[index] = *topElement;
            index++;
        }
    }
    suffix[index] = '\n';

    return 1;
}

float Calculate(int x, int y, char op) {
    if (op == '+') {
        return x + y;
    }

    if (op == '-') {
        return x - y;
    }

    if (op == '*') {
        return x * y;
    }

    if (op == '/') {
        return x / y;
    }
}

int ConvertToInt(char *str, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum = sum * 10 + (str[i] - 48);
    }
    return sum;
}

float GetValue(char *suffix) {
    NumberLinkStack *numberStack =
        (NumberLinkStack *)malloc(sizeof(NumberLinkStack));
    InitNumberStack(numberStack);

    DataType *topNumber =
        (DataType *)malloc(sizeof(DataType));

    for (int i = 0; i < strlen(suffix); i++) {
        if (suffix[i] == '\n') {
            break;
        }

        if (suffix[i] >= 48 && suffix[i] <= 57) {
            char *startPos = suffix + i;
            int length = 0;
            while (suffix[i] != ' ') {
                length++;
                i++;
            }
            // 将字符转换为数值
            int number = ConvertToInt(startPos, length);
            PushNumber(numberStack, number);
        } else if (suffix[i] != ' ') {
            PopNumber(numberStack, topNumber);
            int y = *topNumber;
            PopNumber(numberStack, topNumber);
            int x = *topNumber;
            int temp = Calculate(x, y, suffix[i]);
            PushNumber(numberStack, temp);
        }
    }
    ReadTopNumber(numberStack, topNumber);
    return *topNumber;
}

int main() {
    char *expression = (char *)malloc(sizeof(char) * EXP_MAX_LENGTH);
    char result[EXP_MAX_LENGTH];
    float calculationResult = 0;

    gets(expression);
    Infix2Suffix(expression, result);
    puts(result);
    calculationResult = GetValue(result);
    // 注意保留一位小数的写法
    printf("result is : %.1f", calculationResult);
}