//
// Created by 慰 on 2018/10/1.
// OJ PASSED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXP_MAX_LENGTH 100

typedef struct StackNodeStruct {
    char data;
    struct StackNodeStruct *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;

void InitStack(LinkStack *stack) { stack->top = NULL; }

int ReadTop(LinkStack *stack, char &x) {
    if (stack->top == NULL) {
        return 0;
    }

    x = stack->top->data;

    return 1;
}

int Push(LinkStack *stack, char x) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = x;
    node->next = stack->top;
    stack->top = node;
}

int Pop(LinkStack *stack, char &x) {
    // 栈为空
    if (stack->top == NULL) {
        return 0;
    }

    StackNode *node = stack->top;
    x = node->data;
    stack->top = node->next;
    free(node);

    return 1;
}

int IsEmpty(LinkStack *stack) {
    if (stack->top == NULL) {
        return 1;
    }

    return 0;
}

int MatchBracket(char *expression) {
    // state 1--目前匹配; state 0--不匹配
    // int state = 1;
    int i = 0;
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));

    InitStack(stack);

    // 遍历所有括号
    char current = expression[0];
    while (current != '#') {
        if (current == '(' || current == '[') {
            // 若遍历到的是左括号，则将其放入栈
            Push(stack, expression[i]);
            i++;
        } else if (current == ')' || current == ']') {
            // 若遍历到的是右括号，则将其与栈顶左括号进行比较
            char top;
            ReadTop(stack, top);
            // 若栈当前不为空（说明左括号数量没有少于右括号数量）
            if (!IsEmpty(stack) && ((top == '(' && current == ')') ||
                                    (top == '[' && current == ']'))) {
                // 将已经可以匹配的栈顶括号出栈
                Pop(stack, top);
                // 遍历下一个括号
                i++;
            } else {
                // 若不满足以上条件，则说明不匹配
                return 0;
            }
        } else {
            //也许是非括号字符，直接遍历下一个字符
            i++;
        }
        current = expression[i];
    }

    // 遍历了栈中所有的括号
    // 遍历完所有的右括号后栈空了，说明左右括号数量正好
    if (IsEmpty(stack)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char *expression = (char *)malloc(sizeof(char) * EXP_MAX_LENGTH);
    gets(expression);

    if (MatchBracket(expression)) {
        printf("OK");
    } else {
        printf("Error");
    }

    getchar();
}