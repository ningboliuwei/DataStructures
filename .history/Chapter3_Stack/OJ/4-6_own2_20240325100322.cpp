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

// 出栈操作
int Pop(LinkStack *stack, DataType *data) {
    if (stack->top == NULL) {
        return 0;
    }
    StackNode *node = stack->top;
    *data = node->data;
    stack->top = node->next;
    free(node);
    return 1;
}

// 检查栈是否为空
int IsEmptyStack(LinkStack *stack) {
    return stack->top == NULL;
}

// 检查字符是否为运算符
int IsOperator(char c) {
    switch (c) {
    case '+':
    case '-':
    case '*':
    case '/': return 1;
    default: return 0;
    }
}

// 获取操作符的优先级
int GetPrecedence(char op) {
    switch (op) {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    default: return 0; // 不是运算符则返回0
    }
}

// 中缀表达式转后缀表达式的函数
void InfixToPostfix(const char *infix, char *postfix, LinkStack *stack) {
    int i, j = 0;
    char symbol, topSymbol;
    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];
        if (isdigit(symbol)) {
            // 直接写入数字字符
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            // 左括号直接入栈
            Push(stack, symbol);
        } else if (symbol == ')') {
            // 遇到右括号，出栈直到遇到左括号
            while (ReadTop(stack, &topSymbol) && topSymbol != '(') {
                Pop(stack, &postfix[j++]); // 把运算符添加到后缀表达式
            }
            if (!Pop(stack, &topSymbol)) {
                // 如果不能正确出栈，表示括号不匹配
                fprintf(stderr, "Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            }
        } else if (IsOperator(symbol)) {
            // 对于运算符，需要考虑优先级
            while (!IsEmptyStack(stack) && ReadTop(stack, &topSymbol) && GetPrecedence(topSymbol) >= GetPrecedence(symbol)) {
                Pop(stack, &postfix[j++]); // 把栈内优先级高或相同的运算符弹出
            }
            Push(stack, symbol); // 当前运算符入栈
        }
    }

    // 把栈内剩余的运算符弹出添加到后缀表达式末尾
    while (!IsEmptyStack(stack)) {
        Pop(stack, &postfix[j++]);
    }
    postfix[j] = '\0'; // 结束字符
}

// 后缀表达式求值函数
int EvaluatePostfix(const char *postfix, LinkStack *stack) {
    char symbol;
    DataType operand1, operand2, result;
    int i = 0;
    DataType tempResult;

    while (postfix[i] != '\0') {
        symbol = postfix[i];

        if (isdigit(symbol)) {
            // 字符转换为整数并入栈
            Push(stack, symbol - '0');
        } else if (IsOperator(symbol)) {
            Pop(stack, &operand2);
            Pop(stack, &operand1);
            switch (symbol) {
            case '+': result = operand1 + operand2; break;
            case '-': result = operand1 - operand2; break;
            case '*': result = operand1 * operand2; break;
            case '/': result = operand1 / operand2; break;
            default: // 这个分支实际上可以不需要
                fprintf(stderr, "Unexpected error\n");
                exit(EXIT_FAILURE);
            }
            Push(stack, result); // 将运算结果入栈
        }
        i++;
    }

    Pop(stack, &tempResult);
    return tempResult; // 栈顶元素即为后缀表达式的运算结果
}

int main() {
    char infix[MAX_EXPR_LENGTH];
    char postfix[MAX_EXPR_LENGTH] = {0};
    LinkStack stack;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    InitStack(&stack);

    InfixToPostfix(infix, postfix, &stack);
    printf("Postfix Expression: %s\n", postfix);

    int result = EvaluatePostfix(postfix, &stack);
    printf("The result is: %d\n", result);

    getchar();
    getchar();
    getchar();

    return 0;
}