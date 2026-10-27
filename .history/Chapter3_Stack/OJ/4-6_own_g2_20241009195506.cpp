#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// 定义元素类型：数字或操作符
typedef enum {
    NUM, // 数字
    OP   // 操作符
} ElementType;

// 定义元素结构体，包含类型和数据
typedef struct {
    ElementType type; // 元素类型
    union {
        double num; // 数字值
        char op;    // 操作符
    } data;
} Element;

// 定义栈结构体
typedef struct {
    Element data[MAX_SIZE]; // 存储元素的数组
    int top;                // 栈顶指针
} Stack;

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
void InfixToPostfix(char *infix, Element *postfix, int *postfixLen) {
    Stack opStack;
    opStack.top = -1;
    int i = 0, k = 0;

    while (infix[i] != '#' && infix[i] != '\0') {
        if (isdigit(infix[i])) {
            // 读取多位数字
            char numStr[MAX_SIZE];
            int numIdx = 0;
            while (isdigit(infix[i])) {
                numStr[numIdx++] = infix[i++];
            }
            numStr[numIdx] = '\0';
            // 将数字存入后缀表达式数组
            postfix[k].type = NUM;
            postfix[k].data.num = atof(numStr);
            k++;
        } else if (infix[i] == '(') {
            // 左括号压入操作符栈
            opStack.data[++opStack.top].type = OP;
            opStack.data[opStack.top].data.op = infix[i++];
        } else if (infix[i] == ')') {
            // 弹出操作符栈，直到遇到左括号
            while (opStack.top != -1 && opStack.data[opStack.top].data.op != '(') {
                postfix[k++] = opStack.data[opStack.top--];
            }
            if (opStack.top != -1 && opStack.data[opStack.top].data.op == '(') {
                opStack.top--; // 弹出左括号
            }
            i++;
        } else if (IsOperator(infix[i])) {
            // 处理操作符优先级
            while (opStack.top != -1 && GetPriority(opStack.data[opStack.top].data.op) >= GetPriority(infix[i])) {
                postfix[k++] = opStack.data[opStack.top--];
            }
            // 当前操作符压入栈
            opStack.data[++opStack.top].type = OP;
            opStack.data[opStack.top].data.op = infix[i++];
        } else {
            i++; // 跳过空格或未知字符
        }
    }
    // 弹出操作符栈中剩余的操作符
    while (opStack.top != -1) {
        postfix[k++] = opStack.data[opStack.top--];
    }
    *postfixLen = k;
}

// 计算后缀表达式的结果
double EvaluatePostfix(Element *postfix, int postfixLen) {
    Stack evalStack;
    evalStack.top = -1;

    for (int i = 0; i < postfixLen; i++) {
        if (postfix[i].type == NUM) {
            // 数字直接压入栈
            evalStack.data[++evalStack.top] = postfix[i];
        } else if (postfix[i].type == OP) {
            // 操作符，弹出两个操作数进行计算
            if (evalStack.top < 1) {
                printf("错误：操作数不足！\n");
                exit(1);
            }
            double b = evalStack.data[evalStack.top--].data.num;
            double a = evalStack.data[evalStack.top--].data.num;
            double result;
            switch (postfix[i].data.op) {
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
                default: printf("错误：未知操作符 %c！\n", postfix[i].data.op); exit(1);
            }
            // 将计算结果压入栈
            evalStack.data[++evalStack.top].type = NUM;
            evalStack.data[evalStack.top].data.num = result;
        }
    }
    if (evalStack.top != 0) {
        printf("错误：表达式计算有误！\n");
        exit(1);
    }
    return evalStack.data[evalStack.top].data.num;
}

int main() {
    char infixExp[MAX_SIZE];
    char c;
    int idx = 0;

    while ((c = getchar()) != '#') {
        infixExp[idx++] = c;
    }
    infixExp[idx] = '\0';

    Element postfixExp[MAX_SIZE]; // 存储后缀表达式的数组
    int postfixLen = 0;
    InfixToPostfix(infixExp, postfixExp, &postfixLen);

    for (int i = 0; i < postfixLen; i++) {
        if (postfixExp[i].type == NUM) {
            printf("%.0f ", postfixExp[i].data.num);
        } else if (postfixExp[i].type == OP) {
            printf("%c ", postfixExp[i].data.op);
        }
    }
    printf("\n");

    // 计算结果
    double result = EvaluatePostfix(postfixExp, postfixLen);
    printf("%.1f\n", result);

    return 0;
}
