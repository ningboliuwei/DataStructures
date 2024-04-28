#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
typedef int DataType;

typedef struct {
    DataType *data;
    int top;
} SeqStack;

SeqStack s, t;
int a[5];
int InitStack(char sno) {
    switch (sno) {
        case 's':
            s = *new SeqStack;
            s.data = new DataType[5];
            s.top = -1;
            break;
        case 't':
            t = *new SeqStack;
            t.data = new DataType[5];
            t.top = -1;
            break;
    }
    return 1;
}

int IsFull(char sno) {
    switch (sno) {
        case 's':
            if (s.top == 4)
                return 1;
            break;
        case 't':
            if (t.top == 4)
                return 1;
            break;
    }
    return 0;
}

int IsEmpty(char sno) {
    switch (sno) {
        case 's':
            if (s.top == -1)
                return 1;
            break;
        case 't':
            if (t.top == -1)
                return 1;
            break;
    }
    return 0;
}

int Push(char sno, DataType x) {
    switch (sno) {
        case 's':
            if (s.top == 4)
                return 0;
            else {
                s.top++;
                s.data[s.top] = x;
            }
            break;
        case 't':
            if (t.top == 4)
                return 0;
            else {
                t.top++;
                t.data[t.top] = x;
            }
            break;
    }
    return 1;
}

int Pop(char sno, DataType &x) {
    switch (sno) {
        case 's':
            if (s.top == -1)
                return 0;
            x = s.data[s.top];
            s.top--;
            break;
        case 't':
            if (t.top == -1)
                return 0;
            x = t.data[t.top];
            t.top--;
            break;
    }
    return 1;
}

int main() {
    int code, x; //操作code:  1代表入栈 2代表出栈
    char sno;    //栈编号sno: s栈 t栈

    InitStack('s');
    InitStack('t');
    while (1) {
        cin >> sno;
        if (sno == 'O')
            break;
        cin >> code;

        switch (code) {
            case 1:
                if (IsFull(sno) == 0) {
                    scanf("%d", &x);
                    Push(sno, x);
                    printf("%c栈push成功\n", sno);
                }
                break;
            case 2:
                if (IsEmpty(sno) == 0) {
                    Pop(sno, x);
                    printf("%c栈pop成功 %d\n", sno, x);
                }
                break;
        }
    }
}