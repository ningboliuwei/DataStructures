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

int IsOperator(char c);
int GetPrecedence(char op);
void InfixToPostfix(const char *infix, char *postfix, LinkStack *stack);
int EvaluatePostfix(const char *postfix, LinkStack *stack);
void FreeStack(LinkStack *stack);

// 定义是否为运算符的函数
int IsOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
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
    DataType c, elem;
    int i = 0, k = 0;
    while ((c = infix[i]) != '\0' && c != '#') {
        if (isspace(c)) {
            i++; // 忽略空白字符
            continue;
        }
        if (isdigit(c)) {
            // 连续读取数字，直至遇到非数字字符
            do {
                postfix[k++] = c;
                c = infix[++i];
            } while (isdigit(c) || c == '.');
            postfix[k++] = ' '; // 添加空格作为数字分隔符
        }
        else if (c == '(') {
            ++i;
            Push(stack, c); // 左括号入栈
        } else if (c == ')') {
            // 右括号，一直出栈直到遇到左括号
            while (ReadTop(stack, &elem) && elem != '(') {
                Pop(stack, &elem);
                postfix[k++] = elem;
                postfix[k++] = ' '; // 添加空格作为操作符分隔符
            }
            Pop(stack, &elem); // 弹出 '('
            i++;
        } else if (IsOperator(c)) {
            // 操作符，弹出所有优先级大于等于当前操作符的栈顶操作符
            while (!IsEmptyStack(stack) && ReadTop(stack, &elem) && GetPrecedence(elem) >= GetPrecedence(c)) {
                Pop(stack, &elem);
                postfix[k++] = elem;
                postfix[k++] = ' '; // 添加空格作为操作符分隔符
            }
            Push(stack, c); // 当前操作符入栈
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
    DataType i = 0, op1, op2;
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
            Pop(stack, &op2);
            Pop(stack, &op1);
            switch (c) {
            case '+': Push(stack, op1 + op2); break;
            case '-': Push(stack, op1 - op2); break;
            case '*': Push(stack, op1 * op2); break;
            case '/': Push(stack, op1 / op2); break;
            default: printf("Invalid operator %c\n", c); exit(1);
            }
            i++;
        }
    }

    Pop(stack, &op1);
    return op1;
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

    printf("Enter infix expression terminated with #:\n");
    scanf("%[^\n]%*c", infix); // 读取整行直到换行符，不存储换行符

    InfixToPostfix(infix, postfix, &stack);
    printf("Postfix expression: %s\n", postfix);

    int result = EvaluatePostfix(postfix, &stack);
    printf("Expression result: %d\n", result);

    FreeStack(&stack); // 清理动态分配的内存

    getchar();
    getchar();
    getchar();
    return 0;
}