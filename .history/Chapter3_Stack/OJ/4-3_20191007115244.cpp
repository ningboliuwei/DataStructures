//
// Created by 慰 on 2018/10/1.
// 问题 C: 【数据结构3-3】栈的应用——进制转换
#include<stdio.h>
#include<stdlib.h>

//@@1
//栈的类型申明
typedef int DataType;

typedef struct stacknode {
    DataType data;
    struct stacknode *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;
//@@1

//@@2
//用到的栈的基本运算函数的定义（push，pop等）
int InitLinkStack(LinkStack &ls) {
    ls.top = NULL;
}

int Push(LinkStack &ls, DataType x) {
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
}

int IsEmpty(LinkStack ls) {
    if (ls.top == NULL) {
        return 1;
    }
    return 0;
}

int Pop(LinkStack &ls, DataType &x) {
    x = ls.top->data;
    StackNode *q = ls.top;
    ls.top = ls.top->next;
    free(q);

    return 1;
}
//@@2

int main() {
    int n;   //n为输入的正整数

//    @@3
    //读入n，调用栈的操作，输出转换后的八进制数
    LinkStack stack;
    InitLinkStack(stack);
    scanf("%d", &n);
    while (n != 0) {
        Push(stack, n % 8);
        n = n / 8;
    }

    DataType x = 0;
    while (!IsEmpty(stack)) {
        Pop(stack, x);
        printf("%d", x);
    }

//    @@3

    return 1;
}
