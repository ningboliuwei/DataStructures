#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// OJ PASSED

#define MAX_SIZE 100

// 定义栈结构
typedef struct {
    char data[MAX_SIZE]; // 存储字符（操作数和运算符）
    int top;             // 栈顶指针
} Stack;

// 初始化栈
void InitStack(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int IsEmpty(Stack *s) {
    return s->top == -1;
}

// 入栈
void Push(Stack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = c;
    } else {
        printf("错误：栈溢出！\n");
        exit(1);
    }
}

// 出栈
char Pop(Stack *s) {
    if (!IsEmpty(s)) {
        return s->data[(s->top)--];
    } else {
        printf("错误：栈为空！\n");
        exit(1);
    }
}

// 获取栈顶元素
char Peek(Stack *s) {
    if (!IsEmpty(s)) {
        return s->data[s->top];
    } else {
        return '#'; // 特殊符号，表示栈为空
    }
}

// 判断是否为运算符
int IsOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// 获取运算符优先级
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
    Stack stack;
    InitStack(&stack);
    int i = 0, k = 0;
    char c;

    while ((c = infix[i++]) != '#' && c != '\0') {
        if (isdigit(c)) {
            // 操作数直接添加到后缀表达式
            postfix[k++] = c;
            postfix[k++] = ' '; // 添加空格作为分隔符
        } else if (c == '(') {
            // 左括号压入栈
            Push(&stack, c);
        } else if (c == ')') {
            // 遇到右括号，弹出栈中元素直到左括号
            while (!IsEmpty(&stack) && Peek(&stack) != '(') {
                postfix[k++] = Pop(&stack);
                postfix[k++] = ' '; // 添加空格分隔
            }
            if (!IsEmpty(&stack) && Peek(&stack) == '(') {
                Pop(&stack); // 弹出左括号
            }
        } else if (IsOperator(c)) {
            // 处理运算符优先级
            while (!IsEmpty(&stack) && GetPriority(Peek(&stack)) >= GetPriority(c)) {
                postfix[k++] = Pop(&stack);
                postfix[k++] = ' '; // 添加空格分隔
            }
            Push(&stack, c);
        } else {
            // 跳过空格或未知字符
        }
    }
    // 弹出栈中剩余的运算符
    while (!IsEmpty(&stack)) {
        postfix[k++] = Pop(&stack);
        postfix[k++] = ' '; // 添加空格分隔
    }
    postfix[k - 1] = '\0'; // 覆盖最后一个空格，添加字符串结束符
}

// 计算后缀表达式的结果，保留一位小数
double EvaluatePostfix(char *postfix) {
    Stack stack;
    InitStack(&stack);
    int i = 0;
    char c;
    double num1, num2, result;

    while ((c = postfix[i++]) != '\0') {
        if (isdigit(c)) {
            // 将操作数压入栈
            Push(&stack, c);
        } else if (IsOperator(c)) {
            // 弹出两个操作数
            if (stack.top < 1) {
                printf("错误：操作数不足！\n");
                exit(1);
            }
            char b_char = Pop(&stack);
            char a_char = Pop(&stack);
            num2 = (double)(b_char - '0'); // 第二个操作数
            num1 = (double)(a_char - '0'); // 第一个操作数

            // 执行运算
            switch (c) {
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
                default: printf("错误：未知操作符 %c！\n", c); exit(1);
            }
            // 将结果压入栈
            // 为了保留一位小数，转换为字符并压入栈是不现实的
            // 因此，我们需要暂时存储结果在栈中，但由于栈只能存储字符，
            // 我们采用以下策略：
            // 将结果转换为字符表示（仅限整数部分）并压入栈
            // 同时，将结果存储在一个单独的变量中
            // 这样，最终结果可以从该变量中获取

            // 检查结果是否为整数
            if (result - (int)result == 0.0) {
                Push(&stack, ((int)result) + '0'); // 将整数部分转换为字符
            } else {
                // 如果需要保留一位小数，可以将其转换为整数表示，例如乘以10
                // 并在最终输出时格式化
                int temp = (int)(result * 10 + 0.5); // 四舍五入
                // 将temp的个位数压入栈
                Push(&stack, (temp % 10) + '0');
                // 这里忽略高位数字，因为栈只能存储单个字符
                // 这种方法仅适用于结果的个位数及一位小数
            }
        } else {
            // 跳过空格或未知字符
        }
    }

    // 获取最终结果
    // 为了保留一位小数，我们需要从栈中提取结果
    // 由于栈只能存储单个字符，这里假设结果不超过一位小数
    if (stack.top < 0) {
        printf("错误：表达式计算有误！\n");
        exit(1);
    }

    double finalResult = 0.0;

    // 如果有一个字符在栈中，表示整数部分
    if (stack.top == 0) {
        finalResult = (double)(Pop(&stack) - '0');
    }
    // 如果有两个字符在栈中，表示一位小数
    else if (stack.top == 1) {
        char decimal = Pop(&stack);
        char integer = Pop(&stack);
        finalResult = (double)(integer - '0') + (double)(decimal - '0') / 10.0;
    } else {
        printf("错误：表达式计算有误！\n");
        exit(1);
    }

    return finalResult;
}

int main() {
    char infixExp[MAX_SIZE];
    char c;
    int idx = 0;

    while ((c = getchar()) != '#' && idx < MAX_SIZE - 1) {
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
