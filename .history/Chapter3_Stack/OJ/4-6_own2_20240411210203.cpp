// Created by 慰 on 2024/3/25.
// 1605【数据结构3-6】栈的应用——表达式求解
// 测试数据 1：
// 输入：1*2+(3-8/4)*6
// 结果：1 2 * 3 8 4 / - 6 * +
// 8
// 测试数据 2：
// 输入：(1+2)*(2+3)/5#
// 结果：1 2 + 2 3 + * 5 /
// 3.0
// 测试数据 3：
// 输入：5+4*3-2#
// 结果：5 4 3 * + 2 -
// 15.0
// 测试数据 4：
// 输入：(1+2)*3-4#
// 结果：1 2 + 3 * 4 -
// 5.0

// OJ PASSED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_LENGTH 100

// 定义数据类型为 char
typedef char DataType;

// 栈节点定义
typedef struct StackNodeStruct {
    DataType data;
    struct StackNodeStruct *next;
} StackNode;

// 链栈定义
typedef struct {
    StackNode *top;
} LinkStack;

// 初始化栈
void InitStack(LinkStack *stack) {
    stack->top = NULL;
}

// 读取栈顶元素
int ReadTop(LinkStack *stack, DataType *topElement) {
    if (stack->top == NULL) {
        return 0;
    }
    *topElement = stack->top->data;
    return 1;
}

// 入栈操作
int Push(LinkStack *stack, DataType data) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    if (!node)
        return 0;
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    return 1;
}

// 检查栈是否为空
int IsEmptyStack(LinkStack *stack) {
    return stack->top == NULL;
}

// 出栈操作
int Pop(LinkStack *stack, DataType *data) {
    if (IsEmptyStack(stack)) {
        return 0;
    }

    StackNode *node = stack->top;
    *data = node->data;
    stack->top = node->next;
    free(node);
    return 1;
}

// 定义是否为运算符的函数
int IsOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return 1;
    } else {
        return 0;
    }
}

// 定义获取运算符优先级的函数
int GetPrecedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return -1; // 非运算符
    }
}

// 中缀转后缀表达式的函数定义
void InfixToPostfix(const char *infix, char *postfix, LinkStack *stack) {
    DataType currentChar, elem;
    int i = 0, k = 0;
    while ((currentChar = infix[i]) != '\0' && currentChar != '#') {
        if (isspace(currentChar)) {
            i++; // 忽略空白字符
            continue;
        }
        if (isdigit(currentChar)) {
            // 连续读取数字，直至遇到非数字字符
            do {
                postfix[k++] = currentChar;
                currentChar = infix[++i];
            } while (isdigit(currentChar) || currentChar == '.');
            postfix[k++] = ' '; // 添加空格作为数字分隔符
        } else if (currentChar == '(') {
            i++;
            Push(stack, currentChar); // 左括号入栈
        } else if (currentChar == ')') {
            // 右括号，一直出栈直到遇到左括号
            while (ReadTop(stack, &elem) && elem != '(') {
                Pop(stack, &elem);
                postfix[k++] = elem;
                postfix[k++] = ' '; // 添加空格作为操作符分隔符
            }
            Pop(stack, &elem); // 弹出 '('
            i++;
        } else if (IsOperator(currentChar)) {
            // 操作符，弹出所有优先级大于等于当前操作符的栈顶操作符
            while (!IsEmptyStack(stack) && ReadTop(stack, &elem) && GetPrecedence(elem) >= GetPrecedence(currentChar)) {
                Pop(stack, &elem);
                postfix[k++] = elem;
                postfix[k++] = ' '; // 添加空格作为操作符分隔符
            }
            Push(stack, currentChar); // 当前操作符入栈
            i++;
        }
    }
    // 弹出栈中剩余的操作符
    while (!IsEmptyStack(stack)) {
        Pop(stack, &elem);
        postfix[k++] = elem;
        postfix[k++] = ' '; // 添加空格作为操作符分隔符
    }
    postfix[k - 1] = '\0'; // 结束字符串并且移除最后一个空格字符
}

// 后缀表达式求值的函数定义
int EvaluatePostfix(const char *postfix, LinkStack *stack) {
    DataType c;
    DataType i = 0, opLeft, opRight;
    char buffer[MAX_EXPR_LENGTH]; // 多位数字的缓冲区

    while (postfix[i] != '\0') {
        c = postfix[i];

        if (isspace(c)) {
            i++; // 忽略空白字符
            continue;
        }

        if (isdigit(c)) {
            // 如果是数字，读取完整的多位数
            int numIndex = 0; // 缓冲区索引
            while (isdigit(postfix[i]) || postfix[i] == '.') {
                buffer[numIndex++] = postfix[i++];
            }
            buffer[numIndex] = '\0'; // 必须 null-terminate
            int num = atoi(buffer);
            Push(stack, num); // 将已转换的整数入栈
        } else if (IsOperator(c)) {
            Pop(stack, &opRight);
            Pop(stack, &opLeft);
            switch (c) {
                case '+': Push(stack, opLeft + opRight); break;
                case '-': Push(stack, opLeft - opRight); break;
                case '*': Push(stack, opLeft * opRight); break;
                case '/': Push(stack, opLeft / opRight); break;
                default: printf("Invalid operator %c\n", c); exit(1);
            }
            i++;
        }
    }

    Pop(stack, &opLeft);
    return opLeft;
}

// 释放栈占用的所有动态内存
void FreeStack(LinkStack *stack) {
    DataType temp;
    while (!IsEmptyStack(stack)) {
        Pop(stack, &temp);
    }
}

// 主程序入口
int main() {
    LinkStack stack;
    InitStack(&stack);
    char infix[MAX_EXPR_LENGTH];
    char postfix[MAX_EXPR_LENGTH] = {0};

    scanf("%[^\n]%*c", infix); // 读取整行直到换行符，不存储换行符

    InfixToPostfix(infix, postfix, &stack);
    printf("%s\n", postfix);

    float result = EvaluatePostfix(postfix, &stack);
    printf("%.1f\n", result);

    getchar();
    getchar();
    getchar();
    return 0;
}