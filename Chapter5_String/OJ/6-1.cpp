//
// Created by Liu Wei on 2018/10/9.
// 问题 A: 【数据结构5-1】串的插入删除

#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include"stdlib.h"

using namespace std;

typedef struct {
    char *ch;
    int length;
} HString;

int StrAssign(HString &S, char *chars) {
//    @@1
    int i = 0;

    while (chars[i] != 0) {
        i++;
    }

    S.length = i;
    S.ch = (char *) malloc(sizeof(S.length));

    for (int i = 0; i < S.length; i++) {
        S.ch[i] = chars[i];
    }
//    @@1
}

void ShowString(HString S) {
//    @@2
    if (S.length == 0) {
        printf("空串\n");
    } else {
        for (int i = 0; i < S.length; i++) {
            printf("%c", S.ch[i]);
        }
        printf("\n");
    }
//    @@2
}

int Delete(HString &S, int pos, int len) {
//    @@3
    if (pos < 0 || pos > S.length - 1) {
        return 0;
    }

    if (len < 0 || len > S.length) {
        return 0;
    }

    if (S.length == 0) {
        return 0;
    }

    for (int i = 0; i < S.length - (pos + len); i++) {
        S.ch[pos + i] = S.ch[pos + i + len];
    }

    S.length = S.length - len;

    return 1;
//    @@3
}

int Insert(HString &S, int pos, HString T) {
//    @@4
    // 若插入位置小于 1 或超过字符串长度最大
    if (pos < 1 || pos > S.length + 1) {
        return 0;
    }

    if (T.length != 0) {
        ShowString(S);
        S.ch = (char *) realloc(S.ch, (S.length + T.length) * sizeof(char));

        for (int i = S.length - pos - 1; i >= 0; i--) {
            S.ch[pos + i + T.length] = S.ch[pos + i];
        }

        for (int i = 0; i < T.length; i++) {
            S.ch[pos + i] = T.ch[i];
        }

        S.length = S.length + T.length;

        return 1;
    }
//    @@4
}

int main() {
    HString S, T;
    char a[100];
    int pos, len;

    cin >> a;
    StrAssign(S, a);
    ShowString(S);

    cin >> a;
    StrAssign(T, a);
    ShowString(T);

    cout << "请输入插入位置";
    cin >> pos;

//    @@5        //插入
    int result = Insert(S, pos, T);
    if (result == 0) {
        printf("插入失败");
    } else {
        ShowString(S);
    }

//    @@5

    cout << "请输入删除位置和长度";
    cin >> pos >> len;

//    @@6       //删除
    result = Delete(S, pos, len);
    if (result == 0) {
        printf("删除失败");
    } else {
        ShowString(S);
    }
//    @@6

    return 1;
}

