#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 10
typedef int DataType;

typedef struct {
    DataType data[MAXLEN];
    int top;
} SeqStack;

int InitSeqStack(SeqStack &st) {

    st.top = -1;
    return 1;

}

int Push(SeqStack &st, DataType x) {

    st.top++;
    st.data[st.top] = x;
    return 1;

}

int Pop(SeqStack &st, DataType &x) {

    x = st.data[st.top];
    st.top--;

    return 1;

}

int IsSeqEmpty(SeqStack st) {

    if (st.top != -1)
        return 0;
    else
        return 1;

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