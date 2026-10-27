#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10
typedef char DataType;

typedef struct stacknode {
    DataType data;
    struct stacknode *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;

int InitLinkStack(LinkStack &ls) {
    ls.top = NULL;
    return 0;
}

int Push(LinkStack &ls, DataType x) {
    StackNode *node;
    node = (StackNode *)malloc(sizeof(StackNode));
    node->data = x;
    node->next = ls.top;
    ls.top = node;
    return 0;
}
int IsLinkEmpty(LinkStack ls) {
    if (ls.top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int Pop(LinkStack &ls, DataType &x) {
    StackNode *node;
    if (IsLinkEmpty(ls) == 1) {
        return 0;
    }
    node = ls.top;
    ls.top = node->next;
    x = node->data;
    free(node);
    return 1;
}
int readTop(LinkStack &ls, DataType &x) {
    StackNode *node;
    node = ls.top;
    if (ls.top == NULL) {
        return 0;
    }
    x = node->data;
    return 1;
}
int main() {
    char n;
    LinkStack ls;
    DataType x;
    int _flag = 0, i = 0, j = 0;
    char exp[MAXLEN];
    InitLinkStack(ls);

    while (1) {
        scanf("%c", &n);
        if (n == '#') {
            break;
        }
        exp[i] = n;
        i++;
    }
    while (j < i && _flag == 0) {
        switch (exp[j]) {
            case '(': {
                Push(ls, exp[j]);
                j++;
                break;
            }

            case '[': {
                Push(ls, exp[j]);
                j++;
                break;
            }

            case ')': {
                if (readTop(ls, x) == 0) {
                    break;
                }
                if (x == '(') {
                    Pop(ls, x);
                    j++;
                } else {
                    _flag = 1;
                }
                break;
            }

            case ']': {
                if (readTop(ls, x) == 0) {
                    break;
                }
                readTop(ls, x);
                if (x == '[') {
                    Pop(ls, x);
                    j++;
                } else {
                    _flag = 1;
                }
                break;
            }
        }
    }
    if (IsLinkEmpty(ls) == 1) {
        printf("%s", "OK");
    } else {
        printf("%s", "Error ");
    }

    int x;
    scanf("%d", &x);
    return 1;
}