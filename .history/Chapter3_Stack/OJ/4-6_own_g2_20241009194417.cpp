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
void InfixToPostfix(char *infix, char *postfix) {
    CharStack opStack;
    InitCharStack(&opStack);
    int i = 0, k = 0;
    while (infix[i] != '#' && infix[i] != '\0') {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' '; // 添加空格分隔
        } else if (infix[i] == '(') {
            PushChar(&opStack, infix[i++]);
        } else if (infix[i] == ')') {
            while (!IsEmptyCharStack(&opStack) && PeekChar(&opStack) != '(') {
                postfix[k++] = PopChar(&opStack);
                postfix[k++] = ' '; // 添加空格分隔
            }
            if (!IsEmptyCharStack(&opStack) && PeekChar(&opStack) == '(') {
                PopChar(&opStack);
            }
            i++;
        } else if (IsOperator(infix[i])) {
            while (!IsEmptyCharStack(&opStack) && GetPriority(PeekChar(&opStack)) >= GetPriority(infix[i])) {
                postfix[k++] = PopChar(&opStack);
                postfix[k++] = ' '; // 添加空格分隔
            }
            PushChar(&opStack, infix[i++]);
        } else {
            i++; // 跳过空格或未知字符
        }
    }
    while (!IsEmptyCharStack(&opStack)) {
        postfix[k++] = PopChar(&opStack);
        postfix[k++] = ' '; // 添加空格分隔
    }
    postfix[k] = '\0'; // 字符串结束符
}

// 计算后缀表达式
double EvaluatePostfix(char *postfix) {
    DoubleStack numStack;
    InitDoubleStack(&numStack);
    char *token = strtok(postfix, " ");
    while (token != NULL) {
        if (IsOperator(token[0]) && token[1] == '\0') {
            double b = PopDouble(&numStack);
            double a = PopDouble(&numStack);
            double result;
            switch (token[0]) {
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
            PushDouble(&numStack, atof(token));
        }
        token = strtok(NULL, " ");
    }
    return PopDouble(&numStack);
}

int main() {
    char infixExp[MAX_SIZE];
    char c;
    int idx = 0;

    // 输入提示信息
    printf("请输入中缀表达式（以#结束）：\n");
    while ((c = getchar()) != '#') {
        infixExp[idx++] = c;
    }
    infixExp[idx] = '\0';

    char postfixExp[MAX_SIZE]; // 一维字符数组
    InfixToPostfix(infixExp, postfixExp);

    // 输出提示信息
    printf("后缀表达式为：\n");
    printf("%s\n", postfixExp);

    // 计算结果
    double result = EvaluatePostfix(postfixExp);
    printf("%.1f\n", result);

    return 0;
}
