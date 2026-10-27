#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

// 链栈中的结点类型
typedef struct stacknode {
    datatype data;
    struct stacknode *next;
} StackNode;

// 链栈（本身）类型
typedef struct {
    StackNode *top;
} LinkStack;

int InitStack(LinkStack ls) {
    ls.top = NULL;
}

int IsEmpty(LinkStack ls) {
    if (ls.top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int ReadTop(LinkStack ls, datatype &x) {
    if (IsEmpty(ls)) {
        return 0;
    }

    x = ls.top->data;
    return 1;
}

int Push(LinkStack &ls, datatype x) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = x;
    newNode->next = ls.top;
    ls.top = newNode;
}

int Pop(LinkStack &ls, datatype &x) {
    if (IsEmpty(ls)) {
        return 0;
    }

    StackNode *p = ls.top;
    x = p->data;
    ls.top = p->next;
    free(p);

    return 1;
}

int main() {
    LinkStack stack1;

    InitStack(stack1);
    Push(stack1, 3);
    Push(stack1, 4);
    Push(stack1, 5);

    int x;

    Pop(stack1, x);
    Pop(stack1, x);
}