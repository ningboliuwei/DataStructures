//
// Created by Liu Wei on 2018/9/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXP_MAX_LENGTH 100

typedef char datatype;

typedef struct StackNodeStruct {
    datatype data;
    struct StackNodeStruct *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;

void InitStack(LinkStack *stack) {
    stack->top = NULL;
}

int ReadTop(LinkStack *stack, datatype *x) {
    if (stack->top == NULL) {
        return 0;
    }

    *x = stack->top->data;

    return 1;
}

int Push(LinkStack *stack, datatype x) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = x;
    node->next = stack->top;
    stack->top = node;
}

int Pop(LinkStack *stack, datatype *x) {
    // 栈为空
    if (stack->top == NULL) {
        return 0;
    }

    StackNode *node = stack->top;
    *x = node->data;
    stack->top = node->next;
    free(node);

    return 1;
}

int IsEmptyStack(LinkStack *stack) {
    if (stack->top == NULL) {
        return 1;
    }

    return 0;
}

// MatchBracket2
// 函数是一个用于匹配括号的函数，它接受一个字符串作为参数，返回一个整数值。函数中使用了链栈来实现括号匹配的功能。
// 函数中的 flag 变量用于标记括号匹配的状态，初始值为 1。i 变量用于遍历字符串中的字符。stack
// 变量是一个链栈，用于存储左括号。 在 while 循环中，如果当前字符是左括号，则将其入栈，并将 i 加
// 1。如果当前字符是右括号，则从栈中取出栈顶元素，判断栈是否为空
// 以及当前右括号是否与栈顶元素匹配。如果匹配，则将栈顶元素出栈，并将 i 加 1。如果不匹配，则将 flag 置为
// 0，表示括号匹配失败。 最后，如果遍历完字符串后，栈为空且 flag 为 1，则表示括号匹配成功，返回 1；否则返回 0。
// 在代码中，IsEmptyStack、Push、Pop 和 ReadTop 都是链栈的操作函数。
int MatchBracket2(datatype *exp) {
    int flag = 1;                                              // 标记括号匹配状态，初始值为 1
    int i = 0;                                                 // 遍历字符串的下标
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack)); // 创建链栈

    InitStack(stack); // 初始化链栈

    while (i < strlen(exp) && flag) { // 遍历字符串中的字符
        datatype current = exp[i];    // 当前字符

        if (current == '(' || current == '[' || current == '{') { // 如果当前字符是左括号
            Push(stack, exp[i]);                                  // 将其入栈
            i++;                                                  // 下标加 1
        } else {                                                  // 如果当前字符是右括号
            datatype *top = (datatype *)malloc(sizeof(datatype)); // 创建指向栈顶元素的指针
            ReadTop(stack, top);                                  // 读取栈顶元素

            if (!IsEmptyStack(stack)
                && ((*top == '(' && current == ')') // 如果栈不为空且当前右括号与栈顶元素匹配
                    || (*top == '[' && current == ']') || (*top == '{' && current == '}'))) {
                Pop(stack, top); // 将栈顶元素出栈
                i++;             // 下标加 1
            } else {             // 如果不匹配
                flag = 0;        // 标记括号匹配失败
            }
        }
    }

    // 遍历了栈中所有的括号
    if (flag && IsEmptyStack(stack)) { // 如果遍历完字符串后，栈为空且括号匹配状态为 1
        return 1;                      // 表示括号匹配成功，返回 1
    }

    return 0; // 否则返回 0，表示括号匹配失败
}

int main() {
    datatype *exp = (datatype *)malloc(sizeof(datatype) * EXP_MAX_LENGTH);
    printf("Input brackets\n");
    gets(exp);

    if (MatchBracket2(exp)) {
        printf("Matching");
    } else {
        printf("Not matching");
    }

    getchar();
}
