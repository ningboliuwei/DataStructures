#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

typedef int datatype;

typedef struct stacknode {
    datatype data[MAXLEN];
    int top;
} SeqStack;

int InitStack(SeqStack *&s) {
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;

    return 1;
}

int IsEmpty(SeqStack *s) {
    if (s->top == -1) {
        return 1;
    }

    return 0;
}

int ReadTop(SeqStack *s, datatype &x) {
    if (IsEmpty(s) == 1) {
        return 0;
    } else {
        x = s->data[s->top];
        return 1;
    }
}

int Push(SeqStack *s, datatype x) {
    if (s->top == MAXLEN - 1) {
        return 0;
    }

    s->top++;
    s->data[s->top] = x;

    // s->data[++s->top] = x; // 以上两行合二为一
}

int Pop(SeqStack *s, datatype x) {
    if (IsEmpty(s) == 1) {
        return 0;
    }

    x = s->data[s->top];
    s->top--;
}

int main() {
    SeqStack* stack1;
    datatype x;

    InitStack(stack1);
    Push(stack1, 3);
    Push(stack1, 4);
    Push(stack1, 5);

    Pop(stack1, x);
    printf("%d", x);

}