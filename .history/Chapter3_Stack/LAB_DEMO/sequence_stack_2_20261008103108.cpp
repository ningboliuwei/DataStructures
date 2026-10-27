#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100
typedef int DataType;

typedef struct {
    DataType data[MAXLEN];
    int top;
} SeqStack;

void InitSeqStack(SeqStack &st) {
    st.top = -1;
}

int IsSeqEmpty(SeqStack st) {
    if (st.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int Push(SeqStack &st, DataType x) {
    if (st.top == MAXLEN - 1) {
        return 0;
    } else {
        // st.top++;
        // st.data[st.top] = x;
        st.data[++st.top] = x;
    }
}

int Pop(SeqStack &st, DataType &x) {
    if (IsSeqEmpty(st)) {
        return 0;
    } else {
        // x = st.data[st.top];
        // st.top--;
        x = st.data[st.top--];
        return 1;
    }
}

int main() {
    SeqStack st;
    DataType x;

    InitSeqStack(st);

    scanf("%d", &x);
    while (x >= 0) {
        Push(st, x);
        scanf("%d", &x);
    }
    while (!IsSeqEmpty(st)) {
        Pop(st, x);
        printf("%d\n", x);
    }
    return 1;
}