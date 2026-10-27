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

int main() {
    LinkStack stack1;
    InitStack(stack1);

    
}
