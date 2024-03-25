#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_LENGTH 100
#define MAX_STACK_SIZE 100

// 栈的定义及其操作函数
typedef struct {
    int top;
    int elems[MAX_STACK_SIZE];
} Stack;

// 初始化栈
void InitStack(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int IsEmpty(Stack *s) {
    return s->top == -1;
}

// 判断栈是否已满
int IsFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

// 入栈
void Push(Stack *s, int elem) {
    if (IsFull(s)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->elems[++s->top] = elem;
}

// 出栈
int Pop(Stack *s) {
    if (IsEmpty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->elems[s->top--];
}

// 获取栈顶元素（不出栈）
int Peek(Stack *s) {
    if (IsEmpty(s)) {
        printf("Empty stack\n");
        exit(EXIT_FAILURE);
    }
    return s->elems[s->top];
}

// 获取运算符的优先级
int Precedence(char op) {
    switch (op) {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    default: return 0;
    }
}

// 将中缀表达式转换为后缀表达式
void InfixToPostfix(const char *infix, char *postfix) {
    Stack s;
    InitStack(&s);
    int j = 0;
    for (int i = 0; infix[i] != '\0'; ++i) {
        char token = infix[i];
        // 如果字符是操作数，则直接追加到后缀表达式
        if (isdigit(token)) {
            // 支持多位数处理，设数字间有空格分隔
            postfix[j++] = token;
            while (infix[i + 1] != ' ' && isdigit(infix[i + 1])) {
                postfix[j++] = infix[++i];
            }
            postfix[j++] = ' '; // 在操作数后面添加一个空格分隔符
        } else if (token == ' ') {
            // 忽略空格，继续下一轮循环
            continue;
            // 处理左括号 '('
        } else if (token == '(') {
            Push(&s, token);
            // 处理右括号 ')'
        } else if (token == ')') {
            // 弹出并追加直到遇到左括号 '('
            while (!IsEmpty(&s) && Peek(&s) != '(') {
                postfix[j++] = Pop(&s);
                postfix[j++] = ' '; // 在运算符后面添加一个空格分隔符
            }
            Pop(&s); // 移除 '('
            // 处理运算符
        } else {
            // 弹出所有优先级高于或等于当前运算符的栈元素
            while (!IsEmpty(&s) && Precedence(token) <= Precedence(Peek(&s))) {
                postfix[j++] = Pop(&s);
                postfix[j++] = ' '; // 在运算符后面添加一个空格分隔符
            }
            Push(&s, token); // 将当前运算符压入栈
        }
    }
    // 最后，弹出并追加栈中所有剩余的运算符
    while (!IsEmpty(&s)) {
        postfix[j++] = Pop(&s);
        postfix[j++] = ' '; // 在运算符后面添加一个空格分隔符
    }
    if (j > 0 && postfix[j - 1] == ' ') { // 如果表达式结尾为' '，移除它
        postfix[--j] = '\0';
    } else {
        postfix[j] = '\0'; // Null-terminate postfix expression
    }
}

// 计算后缀表达式的值
int EvaluatePostfix(const char *postfix) {
    Stack s;
    InitStack(&s);
    for (int i = 0; postfix[i] != '\0'; ++i) {
        if (postfix[i] == ' ') {
            continue;
        }                          // 忽略空格
        if (isdigit(postfix[i])) { // 如果是操作数，将其转换为整数然后入栈
            int num = 0;
            do {
                num = num * 10 + (postfix[i++] - '0');
            } while (isdigit(postfix[i]));
            Push(&s, num);
        } else { // 如果是运算符
            int val2 = Pop(&s);
            int val1 = Pop(&s);
            int result;
            switch (postfix[i]) {
            case '+': result = val1 + val2; break;
            case '-': result = val1 - val2; break;
            case '*': result = val1 * val2; break;
            case '/': result = val1 / val2; break;
            default: printf("Invalid operator\n"); exit(EXIT_FAILURE);
            }
            Push(&s, result); // 将结果重新压入栈
        }
    }
    return Pop(&s); // 后缀表达式的结果位于栈顶
}

int main() {
    // 假定输入的中缀表达式格式正确，并且数字与运算符之间有空格分割
    char infix[MAX_EXPR_LENGTH], postfix[MAX_EXPR_LENGTH];
    printf("Enter an infix expression with spaces between numbers and operators:\n");
    fgets(infix, MAX_EXPR_LENGTH, stdin); // 输入中缀表达式
    infix[strcspn(infix, "\n")] = 0;      // 去除换行符

    InfixToPostfix(infix, postfix); // 转换为后缀表达式
    printf("Postfix Expression: %s\n", postfix);

    int result = EvaluatePostfix(postfix); // 计算后缀表达式的值
    printf("Result of the expression: %d\n", result);

    getchar();
    getchar();
    getchar();
    return 0;
}