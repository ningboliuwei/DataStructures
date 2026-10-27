#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
        printf("操作符栈溢出！\n");
        exit(1);
    }
}

// 操作符栈出栈
char PopChar(CharStack *s) {
    if (!IsEmptyCharStack(s)) {
        return s->data[(s->top)--]; // 返回栈顶元素，栈顶指针减 1
    } else {
        printf("操作符栈为空！\n");
        exit(1);
    }
}

// 获取操作符栈顶元素（不出栈）
char PeekChar(CharStack *s) {
    if (!IsEmptyCharStack(s)) {
        return s->data[s->top]; // 返回栈顶元素
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
        printf("数字栈溢出！\n");
        exit(1);
    }
}

// 数字栈出栈
double PopDouble(DoubleStack *s) {
    if (!IsEmptyDoubleStack(s)) {
        return s->data[(s->top)--]; // 返回栈顶元素，栈顶指针减 1
    } else {
        printf("数字栈为空！\n");
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
    CharStack opStack;       // 定义操作符栈
    InitCharStack(&opStack); // 初始化操作符栈
    int i = 0, k = 0;        // `i` 用于遍历中缀表达式，`k` 用于构建后缀表达式

    while (infix[i] != '#' && infix[i] != '\0') {
        if (isdigit(infix[i])) {
            // 处理多位数字
            while (isdigit(infix[i])) {
                postfix[k++] = infix[i++]; // 将数字字符添加到后缀表达式
            }
            postfix[k++] = ' '; // 数字结束后添加空格作为分隔符
        } else if (infix[i] == '(') {
            // 遇到左括号，压入操作符栈
            PushChar(&opStack, infix[i++]);
        } else if (infix[i] == ')') {
            // 遇到右括号，弹出操作符栈顶元素，直到遇到左括号
            while (!IsEmptyCharStack(&opStack) && PeekChar(&opStack) != '(') {
                postfix[k++] = PopChar(&opStack); // 将操作符添加到后缀表达式
                postfix[k++] = ' ';               // 添加空格分隔
            }
            if (!IsEmptyCharStack(&opStack) && PeekChar(&opStack) == '(') {
                PopChar(&opStack); // 弹出左括号
            }
            i++; // 移动到下一个字符
        } else if (IsOperator(infix[i])) {
            // 遇到运算符，处理操作符优先级
            while (!IsEmptyCharStack(&opStack) && GetPriority(PeekChar(&opStack)) >= GetPriority(infix[i])) {
                postfix[k++] = PopChar(&opStack); // 将栈顶操作符添加到后缀表达式
                postfix[k++] = ' ';               // 添加空格分隔
            }
            PushChar(&opStack, infix[i++]); // 将当前操作符压入栈
        } else {
            i++; // 跳过空格或未知字符
        }
    }

    // 处理剩余的操作符
    while (!IsEmptyCharStack(&opStack)) {
        postfix[k++] = PopChar(&opStack); // 将栈中剩余的操作符添加到后缀表达式
        postfix[k++] = ' ';               // 添加空格分隔
    }
    postfix[k] = '\0'; // 添加字符串结束符
}

// 计算后缀表达式的结果
double EvaluatePostfix(char *postfix) {
    DoubleStack numStack;               // 定义数字栈
    InitDoubleStack(&numStack);         // 初始化数字栈
    char *token = strtok(postfix, " "); // 使用空格分割后缀表达式

    while (token != NULL) {
        if (IsOperator(token[0]) && token[1] == '\0') {
            // 如果是操作符，弹出两个操作数进行计算
            double b = PopDouble(&numStack); // 注意先弹出的为第二个操作数
            double a = PopDouble(&numStack); // 再弹出第一个操作数
            double result;

            // 根据操作符进行相应的计算
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
                default: printf("未知的操作符：%c\n", token[0]); exit(1);
            }
            PushDouble(&numStack, result); // 将计算结果压入栈
        } else {
            // 如果是数字，转换为双精度浮点数并压入栈
            PushDouble(&numStack, atof(token));
        }
        token = strtok(NULL, " "); // 获取下一个 token
    }

    // 弹出最终结果
    return PopDouble(&numStack);
}

// -----------------------------
// 主函数
// -----------------------------
int main() {
    char infixExp[MAX_SIZE]; // 存储中缀表达式的数组
    char c;
    int idx = 0; // 用于记录输入字符的索引

    // 输入提示信息
    printf("请输入中缀表达式（以#结束）：\n");

    // 读取中缀表达式，直到遇到 '#' 结束符
    while ((c = getchar()) != '#') {
        infixExp[idx++] = c;
    }
    infixExp[idx] = '\0'; // 添加字符串结束符

    char postfixExp[MAX_SIZE];            // 定义后缀表达式数组（一维字符数组）
    InfixToPostfix(infixExp, postfixExp); // 调用函数将中缀表达式转换为后缀表达式

    // 输出提示信息
    printf("后缀表达式为：\n");
    printf("%s\n", postfixExp); // 输出后缀表达式

    // 计算后缀表达式的结果
    double result = EvaluatePostfix(postfixExp);

    // 输出计算结果，保留一位小数
    printf("%.1f\n", result);

    return 0;
}
