//
// Created by 慰 on 2018/10/10.
// 问题 C: 【数据结构5-3】串的操作——求子串

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

int SubHStr(HString &Sub, HString S, int pos, int len)  //求子串
{
    if (pos < 1 || pos > S.length - len + 1) {
        return 0;
    }

    if (len < 0 || len > S.length) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        Sub.ch[i] = S.ch[pos + i - 1];
    }
    Sub.length = len;

    return 1;
}

int main() {
    HString S;
    char a[100];
    int pos;
    int len;

    cin >> a;
    HStrAssign(S, a);

    cin >> pos >> len;

    // 此题 pos 为 第 x 个字符（非下标）
    HString subString;
    subString.ch = (char *) malloc(sizeof(char));
    subString.length = 0;

    int result = SubHStr(subString, S, pos, len);
    if (result == 1) {
        ShowHString(subString);
    } else {
        printf("求子串失败");
    }
}