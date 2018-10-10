//
// Created by Liu Wei on 2018/10/10.
//

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
//    @@1
    return S.length;
//    @@1
}

int HStrCompare(HString S, HString T)  //串比较
{
//    @@2
    int i = 0;
    while (i < S.length && i < T.length) {
        if (S.ch[i] == T.ch[i]) {
            i++;
        } else {
            return (S.ch[i] - T.ch[i]) > 0 ? 1 : -1;
        }
    }
    return S.length - T.length;

//    @@2
}

int HStrAssign(HString &S, char *chars) //串赋值
{
//@@3
    int i = 0;

    while (chars[i] != 0) {
        i++;
    }

    S.length = i;
    S.ch = (char *) malloc(sizeof(S.length));

    for (int i = 0; i < S.length; i++) {
        S.ch[i] = chars[i];
    }
//@@3
}

int ShowHString(HString S)   //串显示
{
//    @@4
    if (S.length == 0) {
        printf("空串\n");
    } else {
        for (int i = 0; i < S.length; i++) {
            printf("%c", S.ch[i]);
        }
        printf("\n");
    }
//    @@4
}

int SubHStr(HString &Sub, HString S, int pos, int len)  //求子串
{
//@@5
    if (pos < 0 || pos > S.length - len) {
        return 0;
    }

    if (len < 0 || len > S.length) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        Sub.ch[i] = S.ch[pos + i];
    }
    Sub.length = len;

    return 1;
//@@5
}

int Index(HString S, HString T, int pos)  //在主串S中从pos位开始模式匹配
{
//    @@6
    if (S.length == 0 || T.length == 0) {
        return -1;
    }

    if (pos + T.length > S.length + 1) {
        return -1;
    }

    int matchStart = -1;

    for (int i = pos; i <= S.length - T.length; i++) {
        if (S.ch[i] == T.ch[0]) {
            matchStart = i;
            break;
        }
    }

    if (matchStart == -1) {
        return -1;
    } else {
        for (int j = 0; j < T.length; j++) {
            if (S.ch[j + matchStart] != T.ch[j]) {
                return -1;
            }
        }
        return matchStart;
    }
//    @@6
}

int DelHStr(HString &S, int pos, int len) //串删除
{
//@@7
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
//@@7
}

int InsHStr(HString &S, int pos, HString T)  //串插入
{
//@@8
// 若插入位置小于 1 或超过字符串长度最大
    if (pos < 1 || pos > S.length + 1) {
        return 0;
    }

    if (T.length != 0) {
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
//@@8
}

int ReplaceHStr(HString &S, HString T, HString V)
//串替换（调用模式匹配，删除，插入来实现）
{
//@@9
    int i = 0;
    int replaceStart = Index(S, T, i);

    while (i < S.length && replaceStart != -1) {
        i = i + (V.length - T.length) + 2;
        DelHStr(S, replaceStart, T.length);
        InsHStr(S, replaceStart, V);
        replaceStart = Index(S, T, i);
    }
//@@9
}

int main() {
    HString S, T, V;
    char a[100];

    cin >> a;
    HStrAssign(S, a);
    ShowHString(S);

    cin >> a;
    HStrAssign(T, a);
    ShowHString(T);

//    HString subString;
//    subString.ch = (char *) malloc(sizeof(char));
//    subString.length = 0;
//
//    int result = SubHStr(subString, S, 3, 4);
//    if (result == 1) {
//        ShowHString(subString);
//    } else {
//        printf("Error");
//    }
    printf("index: %d\n", Index(S, T, 0));

    cin >> a;
    HStrAssign(V, a);

    ReplaceHStr(S, T, V);
    ShowHString(S);

    return 1;
}