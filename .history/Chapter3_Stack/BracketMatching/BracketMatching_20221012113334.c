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
    StackNode *node = (StackNode *) malloc(sizeof(StackNode));
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

int MatchBracket(datatype *exp) {
    int flag = 1;
    int i = 0;
    LinkStack *stack = (LinkStack *) malloc(sizeof(LinkStack));

    InitStack(stack);

    while (i < strlen(exp) && flag) {
        datatype current = exp[i];

        if (current == '(') {
            Push(stack, current);
            i++;
        } else if (current == ')') {
            datatype *top = (datatype *) malloc(sizeof(datatype));
            ReadTop(stack, top);

            if (!IsEmptyStack(stack) && *top == '(') {
                Pop(stack, top);
                i++;
            } else {
                flag = 0;
            }
        }
    }

// 遍历了栈中所有的括号
    if (flag && IsEmptyStack(stack)) {
        return 1;
    }

    return 0;
}

int MatchBracket2(datatype *exp) {
    int flag = 1;
    int i = 0;
    LinkStack *stack = (LinkStack *) malloc(sizeof(LinkStack));

    InitStack(stack);

    while (i < strlen(exp) && flag) {
        datatype current = exp[i];

        if (current == '(' || current == '[' || current == '{') {
            Push(stack, exp[i]);
            i++;
        } else {
            datatype *top = (datatype *) malloc(sizeof(datatype));
            ReadTop(stack, top);

            if (!IsEmptyStack(stack) && ((*top == '(' && current == ')')
                                         || (*top == '[' && current == ']')
                                         || (*top == '{' && current == '}'))) {
                Pop(stack, top);
                i++;
            } else {
                flag = 0;
            }
        }
    }

    // 遍历了栈中所有的括号
    if (flag && IsEmptyStack(stack)) {
        return 1;
    }

    return 0;
}

int main() {
    datatype *exp = (datatype *) malloc(sizeof(datatype) * EXP_MAX_LENGTH);
    printf("Input brackets\n");
    gets(exp);

    if (MatchBracket2(exp)) {
        printf("Matching");
    } else {
        printf("Not matching");
    }

    getchar();
}


