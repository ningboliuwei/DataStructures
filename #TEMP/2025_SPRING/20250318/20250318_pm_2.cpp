#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct stacknode {
    datatype data;
    struct stacknode *next;
} StackNode;

typedef struct {
    StackNode* top;
} LinkStack;

int InitStack(LinkStack& ls) {
    ls.top = NULL;
}

int Push(LinkStack& ls, datatype x) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = x;
    newNode->next = ls.top;
    ls.top = newNode;

}

int Pop(LinkStack& ls, datatype& x) {
    StackNode* p = ls.top;
    x = ls.top->data;
    ls.top = p->next;
    free(p);
}

int IsEmpty(LinkStack ls) {
    if (ls.top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    LinkStack stack1;
    int x;

    InitStack(stack1);

    Push(stack1, 3);
    Push(stack1, 4);
    Push(stack1, 5);

    Pop(stack1, x);
    Pop(stack1, x);
}
