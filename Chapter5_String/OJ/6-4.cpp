//
// Created by 慰 on 2018/10/10.
// 问题 D: 【数据结构5-4】串的操作——模式匹配

#include<stdio.h>
#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct  //串的堆分配存储
{
    char *ch;
    int length = 0;
} HString;

int HStrLength(HString S)  //串长
{
    return S.length;
}

int HStrAssign(HString &S, char *chars) //串赋值
{
    int i = 0;

    while (chars[i] != 0) {
        i++;
    }

    S.length = i;
    S.ch = (char *) malloc(sizeof(S.length));

    for (int i = 0; i < S.length; i++) {
        S.ch[i] = chars[i];
    }
}

int ShowHString(HString S)   //串显示
{
    if (S.length == 0) {
        printf("空串\n");
    } else {
        for (int i = 0; i < S.length; i++) {
            printf("%c", S.ch[i]);
        }
        printf("\n");
    }
}


int Index(HString S, HString T, int pos)  //在主串S中从pos位开始模式匹配
{
    if (S.length == 0 || T.length == 0) {
        return -1;
    }

    if (pos + T.length > S.length + 1) {
        return -1;
    }

    int flagMatch;
    int matchStart;

    for (int i = pos; i <= S.length - T.length; i++) {
        matchStart = -1;
        flagMatch = 0;

        if (S.ch[i] == T.ch[0]) {
            matchStart = i;
            flagMatch = 1;
        }

        if (matchStart != -1) {
            for (int j = 0; j < T.length; j++) {
                if (S.ch[j + matchStart] != T.ch[j]) {
                    flagMatch = 0;
                }
            }
        }

        if (flagMatch == 1) {
            return matchStart;
        }
    }

    return -1;
}

int main() {
    HString S, T;
    char a[100];

    gets(a);
    HStrAssign(S, a);

    gets(a);
    HStrAssign(T, a);

    int result = Index(S, T, 0);
    if (result == -1) {
        printf("失败");
    } else {
        printf("%d\n", result);
    }

    return 1;
}