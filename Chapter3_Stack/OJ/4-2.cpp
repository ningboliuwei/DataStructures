//
// Created by 慰 on 2018/10/1.
// 问题 B: 【数据结构3-2】链栈的基本操作

#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 10
typedef int DataType;

typedef struct stacknode {
    DataType data;
    struct stacknode *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;

int InitLinkStack(LinkStack &ls) {
//    @@1
    ls.top = NULL;
//    @@1
}

int Push(LinkStack &ls, DataType x) {
//    @@2
    StackNode *newNode = (StackNode *) malloc(sizeof(StackNode));
    newNode->data = x;
    newNode->next = NULL;

    if (ls.top == NULL) {
        ls.top = newNode;
    } else {
        newNode->next = ls.top;
        ls.top = newNode;
    }
    return 1;
//    @@2
}

int LinkStackEmpty(LinkStack ls) {
//    @@3
    if (ls.top == NULL) {
        return 1;
    }
    return 0;
//    @@3
}

int Pop(LinkStack &ls, DataType &x) {
//    @@4
    x = ls.top->data;
    StackNode *q = ls.top;
    ls.top = ls.top->next;
    free(q);

    return 1;
//    @@4
}

int main() {
    LinkStack ls;
    DataType x;

    InitLinkStack(ls);

    scanf("%d", &x);
    while (x >= 0) {
        Push(ls, x);
        scanf("%d", &x);
    }
    while (!LinkStackEmpty(ls)) {
        Pop(ls, x);
        printf("%d\n", x);
    }
    return 1;

}

