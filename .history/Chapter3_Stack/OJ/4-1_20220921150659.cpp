//
// Created by 慰 on 2018/10/1.
// 问题 A: 【数据结构3-1】顺序栈的基本操作
// OJ PASSED
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10
typedef int DataType;

typedef struct {
    DataType data[MAXLEN];
    int top;
} SeqStack;

int InitSeqStack(SeqStack &st) {
    //@@1
    st.top = -1;
    //@@1
}

int Push(SeqStack &st, DataType x) {
    //@@2
    if (st.top == MAXLEN - 1) {
        return 0;
    }

    st.top++;
    st.data[st.top] = x;
    return 1;
    //@@2
}

int Pop(SeqStack &st, DataType &x) {
    //@@3
    if (st.top == -1) {
        return 0;
    }

    x = st.data[st.top];
    st.top--;

    return 1;
    //@@3
}

int IsSeqEmpty(SeqStack st) {
    //    @@4
    if (st.top == -1) {
        return 1;
    }
    return 0;
    //    @@4
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
