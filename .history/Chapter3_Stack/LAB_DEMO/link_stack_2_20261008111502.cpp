#include <stdio.h>
#include <stdlib.h>

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
    ls.top = NULL;
}

int Push(LinkStack &ls, DataType x) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = x;
    newNode->next = ls.top;
    ls.top = newNode;

    return 1;
}
int IsLinkEmpty(LinkStack ls) {
    if (ls.top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int Pop(LinkStack &ls, DataType &x) {
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
    while (!IsLinkEmpty(ls)) {
        Pop(ls, x);
        printf("%d\n", x);
    }
    return 1;
}