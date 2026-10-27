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


int main() {
    LinkStack stack1;
    InitStack(stack1);

    Push(stack1, 3);
    Push(stack1, 4);
    Push(stack1, 5);
}
