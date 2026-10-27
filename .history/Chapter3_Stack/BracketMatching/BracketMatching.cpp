#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

// 定义栈结构
typedef struct {
    char data[MAXLEN];
    int top;
} Stack;

// 初始化栈
void InitStack(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int IsEmpty(Stack *s) {
    return s->top == -1;
}

// 压栈操作
int Push(Stack *s, char ch) {
    if (s->top >= MAXLEN - 1) {
        printf("栈已满，无法压入元素 '%c'.\n", ch);
        return 0; // 压栈失败
    }
    s->data[++(s->top)] = ch;
    return 1; // 压栈成功
}

// 弹栈操作
int Pop(Stack *s, char *ch) {
    if (IsEmpty(s)) {
        return 0; // 弹栈失败，栈为空
    }
    *ch = s->data[(s->top)--];
    return 1; // 弹栈成功
}

// 读取栈顶元素但不弹出
int ReadTop(Stack *s, char *ch) {
    if (IsEmpty(s)) {
        return 0; // 读取失败，栈为空
    }
    *ch = s->data[s->top];
    return 1; // 读取成功
}

/**
 * 函数名称：matching
 * 功能描述：检查给定表达式中的括号是否匹配。
 * 参数：
 *      - char *exp：需要检查的表达式字符串。
 * 返回值：
 *      - int：1表示括号匹配正确，0表示括号匹配不正确。
 */
int matching(char *exp) {
    Stack s;
    InitStack(&s);
    char ch, topCh;

    for (int i = 0; i < strlen(exp); i++) {
        ch = exp[i];
        // 如果是左括号，压栈
        if (ch == '(' || ch == '{' || ch == '[') {
            if (!Push(&s, ch)) {
                // 如果压栈失败，返回不匹配
                return 0;
            }
        }
        // 如果是右括号，检查栈顶是否有对应的左括号
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (!Pop(&s, &topCh)) {
                // 如果栈为空，无法匹配
                return 0;
            }
            // 检查括号是否匹配
            if ((ch == ')' && topCh != '(') || (ch == '}' && topCh != '{') || (ch == ']' && topCh != '[')) {
                return 0; // 括号不匹配
            }
        }
        // 其他字符忽略
    }

    // 最后检查栈是否为空
    if (IsEmpty(&s)) {
        return 1; // 所有括号都匹配
    } else {
        return 0; // 存在未匹配的左括号
    }
}

int main() {
    char expression[MAXLEN];

    // 输入表达式
    printf("请输入包含括号的表达式：\n");
    fgets(expression, sizeof(expression), stdin);
    // 移除换行符
    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    // 调用匹配函数
    if (matching(expression)) {
        printf("括号匹配正确。\n");
    } else {
        printf("括号匹配不正确。\n");
    }

    getchar();

    return 0;
}
