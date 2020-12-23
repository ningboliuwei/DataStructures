#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 99
typedef int DataType;

typedef struct {
    DataType data[MAXLEN];
    int top;
} SeqStack;

int InitSeqStack(SeqStack &st) {
    st.top = -1;
    return 0;
}

int Push(SeqStack &st, DataType x) {
    st.top++;
    st.data[st.top] = x;
    return 0;
}

int Pop(SeqStack &st, DataType &x) {
    x = st.data[st.top];
    st.top--;
    return 0;
}

int IsSeqEmpty(SeqStack st) {
    if (st.top == -1)
        return 1;
    else
        return 0;
}
int main() {
    SeqStack st;
    int n, m, i, f = 0, t = 0;
    int a[99];
    InitSeqStack(st);

    scanf("%d %d", &m, &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    i = 0;
    while (m > 0 && i < n) {
        if (m >= a[i]) {
            Push(st, i);
            m -= a[i];
        }
        if (m == 0) {
            f = 1;
            break;
        }
        if (st.top == n - 1) {
            f = 0;
            break;
        } else {
            if (i == n - 1) {
                if (st.top == 0) {
                    Pop(st, i);
                    m += a[i];
                }
                if (st.top > 0) {
                    Pop(st, i);
                    m += a[i];
                    if (i == n - 1) {
                        Pop(st, i);
                        m += a[i];
                    }
                }
            }
        }
        i++;
    }
    if (f == 1) {
        for (i = 0; i <= st.top; i++)
            printf("%d\n", a[st.data[i]]);
    } else {
        printf("无解");
    }
    return 1;
}