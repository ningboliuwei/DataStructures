//
// Created by Liu Wei on 2018/9/13.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXP_MAX_LENGTH 20

typedef struct StackNodeStruct {
    char data;
    struct StackNodeStruct *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;

void InitStack(LinkStack *stack) {
    stack->top = NULL;
}

int ReadTop(LinkStack *stack, char *topElement) {
    if (stack->top == NULL) {
        return 0;
    }

    *topElement = stack->top->data;

    return 1;
}


int Push(LinkStack *stack, char x) {
    StackNode *node = (StackNode *) malloc(sizeof(StackNode));
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

int ShowStack(LinkStack *stack) {
    StackNode *node = stack->top;

    while (node != NULL) {
        printf("%c\n", node->data);
        node = node->next;
    }

    printf("--------\n");
}

int Infix2Suffix(char *infix, char *suffix) {
    LinkStack *stack = (LinkStack *) malloc(sizeof(LinkStack));
    char index = 0;
    char *topElement = (char *) malloc(sizeof(char));

    InitStack(stack);

    for (int i = 0; i < strlen(infix); i++) {
        char current = infix[i];

        // 非运算符，直接输出
        if (GetOperatorLevel(current) == -1) {
            suffix[index] = current;
            index++;
        }// 运算符
        else {
            printf("current: %c\n", current);
            ShowStack(stack);

            //如果op=='('，则直接入栈
            if (current == '(') {
                Push(stack, current);
            }// 如果 op==')'，则依次弹出栈顶直到弹出'('，但'('不输出到后缀表达式
            else if (current == ')') {
                do {
                    Pop(stack, topElement);

                    if (*topElement != '(') {
                        suffix[index] = *topElement;
                        index++;
                    }
                } while (*topElement != '(');
            }// 如果栈为空，则直接入栈
            else if (IsEmptyStack(stack)) {
                Push(stack, current);
            } else {
                ReadTop(stack, topElement);

                // 如果op的优先级高于栈顶操作符的优先级，则入栈
                if (GetOperatorLevel(current) > GetOperatorLevel(*topElement)) {
                    Push(stack, current);
                }// 如果op的优先级低于或等于栈顶操作符的优先级，则依次弹出栈顶直到op的优先级高于栈顶操作符的优先级（或栈为空），再将op入栈
                else {
                    while (ReadTop(stack, topElement) && GetOperatorLevel(current) <= GetOperatorLevel(*topElement)) {
                        Pop(stack, topElement);
                        suffix[index] = *topElement;
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

int Caculate(int x, int y, char op) {
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

int GetValue(char *suffix) {
    LinkStack *numberStack = (LinkStack *) malloc(sizeof(LinkStack));
    InitStack(numberStack);

    char *topNumber = (char *) malloc(sizeof(char));

    int i = 0;

    for (int i = 0; i < strlen(suffix); i++) {
        char current = suffix[i];

        if (current == '\n') {
            break;
        }

        if (GetOperatorLevel(current) == -1) {
            Push(numberStack, current);
        } else {
            Pop(numberStack, topNumber);
            int y = (*topNumber - 48);
            Pop(numberStack, topNumber);
            int x = (*topNumber - 48);
            int temp = Caculate(x, y, current);
            Push(numberStack, (temp + 48));
        }

        ShowStack(numberStack);
    }
    ReadTop(numberStack, topNumber);
    return *topNumber - 48;
}

int Suffix2Infix(char* suffix, char* infix){

}

int main() {
    char *expression = (char *) malloc(sizeof(char) * EXP_MAX_LENGTH);
    char result[EXP_MAX_LENGTH];
    int caculationResult;

    printf("%d", '1');
    printf("Input a infix expression.\n");
    gets(expression);
    Infix2Suffix(expression, result);
    puts(result);
    caculationResult = GetValue(result);
    printf("result is : %d", caculationResult);

    getchar();
}