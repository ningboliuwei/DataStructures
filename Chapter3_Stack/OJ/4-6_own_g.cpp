#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// 操作符栈
typedef struct {
    char data[MAX_SIZE];
    int top;
} CharStack;

// 数字栈
typedef struct {
    double data[MAX_SIZE];
    int top;
} DoubleStack;

// 初始化操作符栈
void InitCharStack(CharStack *s) {
    s->top = -1;
}

// 判断操作符栈是否为空
int IsEmptyCharStack(CharStack *s) {
    return s->top == -1;
}

// 操作符栈入栈
void PushChar(CharStack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = c;
    } else {
        printf("操作符栈溢出！\n");
        exit(1);
    }
}

// 操作符栈出栈
char PopChar(CharStack *s) {
    if (!IsEmptyCharStack(s)) {
        return s->data[(s->top)--];
    } else {
        printf("操作符栈为空！\n");
        exit(1);
    }
}

// 获取操作符栈顶元素
char PeekChar(CharStack *s) {
    if (!IsEmptyCharStack(s)) {
        return s->data[s->top];
    } else {
        return '#'; // 特殊符号，表示栈为空
    }
}

// 初始化数字栈
void InitDoubleStack(DoubleStack *s) {
    s->top = -1;
}

// 判断数字栈是否为空
int IsEmptyDoubleStack(DoubleStack *s) {
    return s->top == -1;
}

// 数字栈入栈
void PushDouble(DoubleStack *s, double num) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = num;
    } else {
        printf("数字栈溢出！\n");
        exit(1);
    }
}

// 数字栈出栈
double PopDouble(DoubleStack *s) {
    if (!IsEmptyDoubleStack(s)) {
        return s->data[(s->top)--];
    } else {
        printf("数字栈为空！\n");
        exit(1);
    }
}

// 判断是否为运算符
int IsOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// 获取操作符优先级
int GetPriority(char c) {
    if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

// 中缀表达式转换为后缀表达式
void InfixToPostfix(char *infix, char postfix[][MAX_SIZE], int *postfixLen) {
    CharStack opStack;
    InitCharStack(&opStack);
    int i = 0, k = 0;
    while (infix[i] != '#' && infix[i] != '\0') {
        if (isdigit(infix[i])) {
            char numStr[MAX_SIZE];
            int numIdx = 0;
            while (isdigit(infix[i])) {
                numStr[numIdx++] = infix[i++];
            }
            numStr[numIdx] = '\0';
            strcpy(postfix[k++], numStr);
        } else if (infix[i] == '(') {
            PushChar(&opStack, infix[i++]);
        } else if (infix[i] == ')') {
            while (!IsEmptyCharStack(&opStack) && PeekChar(&opStack) != '(') {
                char op[2] = {PopChar(&opStack), '\0'};
                strcpy(postfix[k++], op);
            }
            if (!IsEmptyCharStack(&opStack) && PeekChar(&opStack) == '(') {
                PopChar(&opStack);
            }
            i++;
        } else if (IsOperator(infix[i])) {
            while (!IsEmptyCharStack(&opStack) && GetPriority(PeekChar(&opStack)) >= GetPriority(infix[i])) {
                char op[2] = {PopChar(&opStack), '\0'};
                strcpy(postfix[k++], op);
            }
            PushChar(&opStack, infix[i++]);
        } else {
            i++; // 跳过空格或未知字符
        }
    }
    while (!IsEmptyCharStack(&opStack)) {
        char op[2] = {PopChar(&opStack), '\0'};
        strcpy(postfix[k++], op);
    }
    *postfixLen = k;
}

// 计算后缀表达式
double EvaluatePostfix(char postfix[][MAX_SIZE], int postfixLen) {
    DoubleStack numStack;
    InitDoubleStack(&numStack);
    for (int i = 0; i < postfixLen; i++) {
        if (IsOperator(postfix[i][0]) && postfix[i][1] == '\0') {
            double b = PopDouble(&numStack);
            double a = PopDouble(&numStack);
            double result;
            switch (postfix[i][0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("除数不能为零！\n");
                        exit(1);
                    }
                    result = a / b;
                    break;
            }
            PushDouble(&numStack, result);
        } else {
            PushDouble(&numStack, atof(postfix[i]));
        }
    }
    return PopDouble(&numStack);
}

int main() {
    char infixExp[MAX_SIZE];
    char c;
    int idx = 0;

    while ((c = getchar()) != '#') {
        infixExp[idx++] = c;
    }
    infixExp[idx] = '\0';

    char postfixExp[MAX_SIZE][MAX_SIZE]; // 存储后缀表达式
    int postfixLen = 0;
    InfixToPostfix(infixExp, postfixExp, &postfixLen);

    // 输出后缀表达式
    for (int i = 0; i < postfixLen; i++) {
        printf("%s ", postfixExp[i]);
    }
    printf("\n");

    // 计算结果
    double result = EvaluatePostfix(postfixExp, postfixLen);
    printf("%.1f\n", result);

    return 0;
}
