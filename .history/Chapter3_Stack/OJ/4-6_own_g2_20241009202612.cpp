#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// OJ PASSED 2024-10-09

#define MAX_SIZE 100 // 定义栈和数组的最大容量

// -----------------------------
// 定义操作符栈（字符栈）
// -----------------------------
typedef struct {
    char data[MAX_SIZE]; // 存储操作符的数组
    int top;             // 栈顶指针，初始值为 -1
} CharStack;

// 初始化操作符栈
void InitCharStack(CharStack *s) {
    s->top = -1; // 栈顶指针设为 -1，表示栈为空
}

// 判断操作符栈是否为空
int IsEmptyCharStack(CharStack *s) {
    return s->top == -1;
}

// 操作符栈入栈
void PushChar(CharStack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = c; // 栈顶指针先加 1，然后在新位置存入元素
    } else {
        printf("错误：操作符栈溢出！\n");
        exit(1);
    }
}

// 操作符栈出栈
char PopChar(CharStack *s) {
    if (!IsEmptyCharStack(s)) {
        return s->data[(s->top)--]; // 返回栈顶元素，栈顶指针减 1
    } else {
        printf("错误：操作符栈为空！\n");
        exit(1);
    }
}

// 获取操作符栈顶元素（不出栈）
char PeekChar(CharStack *s) {
    if (!IsEmptyCharStack(s)) {
        return s->data[s->top];
    } else {
        return '#'; // 返回特殊字符，表示栈为空
    }
}

// -----------------------------
// 定义数字栈（双精度浮点数栈）
// -----------------------------
typedef struct {
    double data[MAX_SIZE]; // 存储数字的数组
    int top;               // 栈顶指针，初始值为 -1
} DoubleStack;

// 初始化数字栈
void InitDoubleStack(DoubleStack *s) {
    s->top = -1; // 栈顶指针设为 -1，表示栈为空
}

// 判断数字栈是否为空
int IsEmptyDoubleStack(DoubleStack *s) {
    return s->top == -1;
}

// 数字栈入栈
void PushDouble(DoubleStack *s, double num) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = num; // 栈顶指针先加 1，然后在新位置存入元素
    } else {
        printf("错误：数字栈溢出！\n");
        exit(1);
    }
}

// 数字栈出栈
double PopDouble(DoubleStack *s) {
    if (!IsEmptyDoubleStack(s)) {
        return s->data[(s->top)--]; // 返回栈顶元素，栈顶指针减 1
    } else {
        printf("错误：数字栈为空！\n");
        exit(1);
    }
}

// -----------------------------
// 工具函数和核心算法
// -----------------------------

// 判断字符是否为运算符
int IsOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// 获取操作符的优先级
int GetPriority(char c) {
    if (c == '*' || c == '/') {
        return 2; // 乘除法优先级为 2
    } else if (c == '+' || c == '-') {
        return 1; // 加减法优先级为 1
    } else {
        return 0; // 其他字符优先级为 0
    }
}

// 中缀表达式转换为后缀表达式
void InfixToPostfix(char *infix, char *postfix) {
    CharStack opStack;
    InitCharStack(&opStack); // 初始化操作符栈
    int i = 0, k = 0;        // i 用于遍历中缀表达式，k 用于构建后缀表达式

    while (infix[i] != '#' && infix[i] != '\0') {
        if (isdigit(infix[i])) {
            // 处理操作数（单个位数字）
            postfix[k++] = infix[i++]; // 直接将数字添加到后缀表达式
            postfix[k++] = ' ';        // 添加空格作为分隔符
        } else if (infix[i] == '(') {
            PushChar(&opStack, infix[i++]); // 遇到左括号，压入操作符栈
        } else if (infix[i] == ')') {
            // 遇到右括号，弹出栈中操作符直到遇到左括号
            while (!IsEmptyCharStack(&opStack) && PeekChar(&opStack) != '(') {
                postfix[k++] = PopChar(&opStack); // 弹出操作符并添加到后缀表达式
                postfix[k++] = ' ';               // 添加空格分隔
            }
            if (!IsEmptyCharStack(&opStack) && PeekChar(&opStack) == '(') {
                PopChar(&opStack); // 弹出左括号
            }
            i++; // 移动到下一个字符
        } else if (IsOperator(infix[i])) {
            // 处理运算符，根据优先级弹出栈中高优先级运算符
            while (!IsEmptyCharStack(&opStack) && GetPriority(PeekChar(&opStack)) >= GetPriority(infix[i])) {
                postfix[k++] = PopChar(&opStack); // 弹出操作符并添加到后缀表达式
                postfix[k++] = ' ';               // 添加空格分隔
            }
            PushChar(&opStack, infix[i++]); // 当前运算符压入栈中
        } else {
            // 跳过空格或其他未知字符
            i++;
        }
    }

    // 弹出操作符栈中剩余的操作符
    while (!IsEmptyCharStack(&opStack)) {
        postfix[k++] = PopChar(&opStack);
        postfix[k++] = ' '; // 添加空格分隔
    }

    postfix[k] = '\0'; // 添加字符串结束符
}

// 计算后缀表达式的结果
double EvaluatePostfix(char *postfix) {
    DoubleStack numStack;
    InitDoubleStack(&numStack); // 初始化数字栈
    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            // 处理数字，直接将其转换为 double 并压入数字栈
            double num = (double)(postfix[i] - '0'); // 将字符数字转换为数值
            PushDouble(&numStack, num);
            i += 2; // 跳过数字和空格
        } else if (IsOperator(postfix[i])) {
            // 处理运算符，从数字栈中弹出两个操作数进行计算
            if (numStack.top < 1) {
                printf("错误：操作数不足！\n");
                exit(1);
            }
            double b = PopDouble(&numStack); // 弹出第二个操作数
            double a = PopDouble(&numStack); // 弹出第一个操作数
            double result = 0;

            // 根据运算符进行相应的计算
            switch (postfix[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("错误：除数不能为零！\n");
                        exit(1);
                    }
                    result = a / b;
                    break;
                default: printf("错误：未知操作符 %c！\n", postfix[i]); exit(1);
            }

            PushDouble(&numStack, result); // 将计算结果压入数字栈
            i += 2;                        // 跳过操作符和空格
        } else {
            // 跳过空格或其他未知字符
            i++;
        }
    }

    // 获取最终结果
    if (numStack.top != 0) {
        printf("错误：表达式计算有误！\n");
        exit(1);
    }
    return PopDouble(&numStack); // 返回栈顶元素，即最终结果
}

// -----------------------------
// 主函数
// -----------------------------
int main() {
    char infixExp[MAX_SIZE];
    char c;
    int idx = 0;

    while ((c = getchar()) != '#') {
        infixExp[idx++] = c;
    }
    infixExp[idx] = '\0'; // 添加字符串结束符

    char postfixExp[MAX_SIZE];            // 存储后缀表达式的数组
    InfixToPostfix(infixExp, postfixExp); // 调用函数将中缀表达式转换为后缀表达式

    printf("%s\n", postfixExp);

    // 计算结果
    double result = EvaluatePostfix(postfixExp);
    printf("%.1f\n", result); // 输出计算结果，保留一位小数

    return 0;
}
