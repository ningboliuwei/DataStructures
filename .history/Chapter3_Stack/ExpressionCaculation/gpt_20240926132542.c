#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100 // 栈的最大容量

// 定义栈结构
typedef struct {
    int top;
    char items[MAX];
} Stack;

// 初始化栈
void initialize(Stack *s) {
    s->top = -1;
}

// 检查栈是否为空
int isEmpty(Stack *s) {
    return s->top == -1;
}

// 检查栈是否已满
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// 入栈操作
void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = item;
}

// 出栈操作
char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0'; // 返回空字符表示栈为空
    }
    return s->items[(s->top)--];
}

// 获取栈顶元素但不弹出
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

// 判断字符是否为运算符
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// 获取运算符优先级
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// 判断运算符是否为右结合
int isRightAssociative(char op) {
    return op == '^';
}

// 中缀表达式转换为后缀表达式
void infixToPostfix(const char *infix, char *postfix) {
    Stack s;
    initialize(&s);
    int i = 0, k = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isdigit(c)) {
            // 直接将操作数添加到后缀表达式
            postfix[k++] = c;
            postfix[k++] = ' '; // 添加空格分隔
        } else if (c == '(') {
            // 左括号入栈
            push(&s, c);
        } else if (c == ')') {
            // 右括号，弹出并输出直到遇到左括号
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
                postfix[k++] = ' ';
            }
            if (!isEmpty(&s) && peek(&s) == '(') {
                pop(&s); // 弹出左括号但不输出
            } else {
                printf("Error: Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            }
        } else if (isOperator(c)) {
            // 运算符处理
            while (!isEmpty(&s) && isOperator(peek(&s))) {
                char topOp = peek(&s);
                if ((precedence(topOp) > precedence(c)) || (precedence(topOp) == precedence(c) && !isRightAssociative(c))) {
                    postfix[k++] = pop(&s);
                    postfix[k++] = ' ';
                } else {
                    break;
                }
            }
            push(&s, c);
        } else if (c == ' ' || c == '\t') {
            // 忽略空格和制表符
            continue;
        } else {
            printf("Error: Invalid character '%c' in expression\n", c);
            exit(EXIT_FAILURE);
        }
    }

    // 弹出栈中剩余的运算符
    while (!isEmpty(&s)) {
        char topOp = pop(&s);
        if (topOp == '(' || topOp == ')') {
            printf("Error: Mismatched parentheses\n");
            exit(EXIT_FAILURE);
        }
        postfix[k++] = topOp;
        postfix[k++] = ' ';
    }

    postfix[k] = '\0'; // 结束符
}

// 计算后缀表达式
int evaluatePostfix(const char *postfix) {
    Stack s;
    initialize(&s);
    int i = 0;
    char c;

    while ((c = postfix[i++]) != '\0') {
        if (isdigit(c)) {
            // 将数字推入栈中
            push(&s, c - '0'); // 转换为整数
        } else if (isOperator(c)) {
            // 弹出两个操作数
            if (s.top < 1) {
                printf("Error: Insufficient operands for operator '%c'\n", c);
                exit(EXIT_FAILURE);
            }
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            int result;

            // 执行运算
            switch (c) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = 1;
                    for (int j = 0; j < operand2; j++) {
                        result *= operand1;
                    }
                    break;
                default: printf("Error: Unknown operator '%c'\n", c); exit(EXIT_FAILURE);
            }
            push(&s, result);
        } else if (c == ' ' || c == '\t') {
            // 忽略空格和制表符
            continue;
        } else {
            printf("Error: Invalid character '%c' in postfix expression\n", c);
            exit(EXIT_FAILURE);
        }
    }

    if (s.top != 0) {
        printf("Error: The postfix expression is invalid\n");
        exit(EXIT_FAILURE);
    }

    return pop(&s);
}

// 主函数
int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression (use single-digit operands and operators +, -, *, /, ^, and parentheses):\n");
    fgets(infix, MAX, stdin);

    // 去除换行符
    size_t len = strlen(infix);
    if (infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    // 转换为后缀表达式
    infixToPostfix(infix, postfix);

    printf("Postfix Expression:\n%s\n", postfix);

    // 计算后缀表达式的结果
    int result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);
    getchar();
    getchar();

    return 0;
}
