//
// Created by 慰 on 2018/10/1.
// 问题 E: 【数据结构3-8】两个栈共用一个数组

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
typedef int DataType;

typedef struct {
    DataType *data;
    int top;
} SeqStack;

SeqStack s, t;
int a[5];

int InitStack(int sno) {
    //    @@1
    if (sno == 1) {
        s.data = a;
        s.top = -1;
    } else if (sno == 2) {
        t.data = a;
        t.top = 5;
    };
    //    @@1
}

int IsFull() {
    //    @@2
    if (s.top + 1 == t.top) {
        return 1;
    }
    return 0;
    //    @@2
}

int IsEmpty(int sno) {
    //    @@3
    if (sno == 1 && s.top == -1) {
        return 1;
    }

    if (sno == 2 && t.top == 5) {
        return 1;
    }

    return 0;
    //    @@3
}

int Push(int sno, DataType x) {
    //    @@4
    if (IsFull()) {
        return 0;
    }

    if (sno == 1) {
        s.top++;
        s.data[s.top] = x;
    } else if (sno == 2) {
        t.top--;
        t.data[t.top] = x;
    }

    return 1;
    //    @@4
}

int Pop(int sno, DataType &x) {
    //    @@5
    if (IsEmpty(sno)) {
        return 0;
    }

    if (sno == 1) {
        x = s.data[s.top];
        s.top--;
    } else if (sno == 2) {
        x = t.data[t.top];
        t.top++;
    }

    return 1;
    //    @@5
}

int main() {
    int code, x; //操作code:  1代表入栈 2代表出栈
    char sno;    //栈编号sno: 1代表s栈 2代表t栈

    InitStack(1);
    InitStack(2);
    while (1) {
        cin >> sno;
        if (sno == 'O')
            break;
        cin >> code;
        //        @@6

        if (code == 1) {
            cin >> x;
        }

        int stackNo = 0;

        if (sno == 's') {
            stackNo = 1;
        } else if (sno == 't') {
            stackNo = 2;
        }

        printf("%c栈", sno);
        int result;
        if (code == 1) {
            result = Push(stackNo, x);
            printf("push");
        } else if (code == 2) {
            result = Pop(stackNo, x);
            printf("pop");
        }
        if (result == 1) {
            printf("成功");
        } else {
            printf("失败");
        }

        if (code == 2) {
            printf(" %d", x);
        }
        printf("\n");

        //        @@6
    }
}
