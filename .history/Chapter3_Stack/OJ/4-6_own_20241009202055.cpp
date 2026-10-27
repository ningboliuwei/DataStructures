#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// 定义字符栈
typedef struct {
    char data[MAX_SIZE]; // 存储字符的数组
    int top;             // 栈顶指针
} CharStack;

// 初始化栈
void InitCharStack(CharStack *s) {
    s->top = -1;
}

// 判断栈是否为空
int IsEmptyCharStack(CharStack *s) {
    return s->top == -1;
}

// 栈入栈
void PushChar(CharStack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = c;
    } else {
        printf("栈溢出！\n");
        exit(1);
    }
}

// 栈出栈
char PopChar(CharStack *s) {
    if (!IsEmptyCharStack(s)) {
        return s->data[(s->top)--];
    } else {
        printf("栈为空！\n");
        exit(1);
    }
}

// 获取栈顶元素
char PeekChar(CharStack *s) {
    if (!IsEmptyCharStack(s)) {
        return s->data[s->top];
    } else {
        return '#'; // 特殊符号，表示栈为空
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
            // 将数字字符复制到后缀表达式中
            while (isdigit(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' '; // 数字结束，添加空格分隔
        } else if (infix[i] == '(') {
            PushChar(&opStack, infix[i++]);
        } else if (infix[i] == ')') {
            while (!IsEmptyCharStack(&opStack) && PeekChar(&opStack) != '(') {
                postfix[k++] = PopChar(&opStack);
                postfix[k++] = ' '; // 操作符后添加空格分隔
            }
            if (!IsEmptyCharStack(&opStack) && PeekChar(&opStack) == '(') {
                PopChar(&opStack); // 弹出左括号
            }
            i++;
        } else if (IsOperator(infix[i])) {
            while (!IsEmptyCharStack(&opStack) && GetPriority(PeekChar(&opStack)) >= GetPriority(infix[i])) {
                postfix[k++] = PopChar(&opStack);
                postfix[k++] = ' '; // 操作符后添加空格分隔
            }
            PushChar(&opStack, infix[i++]);
        } else {
            i++; // 跳过空格或未知字符
        }
    }
    // 弹出栈中剩余的操作符
    while (!IsEmptyCharStack(&opStack)) {
        postfix[k++] = PopChar(&opStack);
        postfix[k++] = ' '; // 操作符后添加空格分隔
    }
    postfix[k] = '\0'; // 添加字符串结束符
}

// 计算后缀表达式
double EvaluatePostfix(char *postfix) {
    CharStack stack;
    InitCharStack(&stack);
    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            // 将数字字符压入栈中
            while (isdigit(postfix[i])) {
                PushChar(&stack, postfix[i++]);
            }
            PushChar(&stack, ' '); // 数字结束，添加空格作为标识
        } else if (IsOperator(postfix[i])) {
            // 操作符，弹出两个操作数进行计算
            double num2 = 0, num1 = 0;
            char numStr[MAX_SIZE];
            int idx = 0;

            // 获取第二个操作数
            while (!IsEmptyCharStack(&stack) && PeekChar(&stack) != ' ') {
                numStr[idx++] = PopChar(&stack);
            }
            if (!IsEmptyCharStack(&stack) && PeekChar(&stack) == ' ') {
                PopChar(&stack); // 弹出空格
            }
            numStr[idx] = '\0';
            // 反转字符串
            for (int j = 0; j < idx / 2; j++) {
                char temp = numStr[j];
                numStr[j] = numStr[idx - j - 1];
                numStr[idx - j - 1] = temp;
            }
            num2 = atof(numStr);

            // 重置 idx，获取第一个操作数
            idx = 0;
            while (!IsEmptyCharStack(&stack) && PeekChar(&stack) != ' ') {
                numStr[idx++] = PopChar(&stack);
            }
            if (!IsEmptyCharStack(&stack) && PeekChar(&stack) == ' ') {
                PopChar(&stack); // 弹出空格
            }
            numStr[idx] = '\0';
            // 反转字符串
            for (int j = 0; j < idx / 2; j++) {
                char temp = numStr[j];
                numStr[j] = numStr[idx - j - 1];
                numStr[idx - j - 1] = temp;
            }
            num1 = atof(numStr);

            // 计算结果
            double result = 0;
            switch (postfix[i]) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/':
                    if (num2 == 0) {
                        printf("错误：除数不能为零！\n");
                        exit(1);
                    }
                    result = num1 / num2;
                    break;
                default: printf("错误：未知操作符 %c！\n", postfix[i]); exit(1);
            }

            // 将计算结果以字符形式压入栈中
            char resultStr[MAX_SIZE];
            sprintf(resultStr, "%.0f", result);
            int len = strlen(resultStr);
            for (int j = 0; j < len; j++) {
                PushChar(&stack, resultStr[j]);
            }
            PushChar(&stack, ' '); // 结果结束，添加空格作为标识
            i++;                   // 跳过操作符
        } else {
            i++; // 跳过空格或未知字符
        }
    }

    // 获取最终结果
    char finalNumStr[MAX_SIZE];
    int idx = 0;
    while (!IsEmptyCharStack(&stack) && PeekChar(&stack) != ' ') {
        finalNumStr[idx++] = PopChar(&stack);
    }
    finalNumStr[idx] = '\0';
    // 反转字符串
    for (int j = 0; j < idx / 2; j++) {
        char temp = finalNumStr[j];
        finalNumStr[j] = finalNumStr[idx - j - 1];
        finalNumStr[idx - j - 1] = temp;
    }
    double finalResult = atof(finalNumStr);
    return finalResult;
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

    char postfixExp[MAX_SIZE]; // 存储后缀表达式的数组
    InfixToPostfix(infixExp, postfixExp);

    // 输出后缀表达式
    printf("后缀表达式为：\n");
    printf("%s\n", postfixExp);

    // 计算结果
    double result = EvaluatePostfix(postfixExp);
    printf("%.1f\n", result);

    return 0;
}
