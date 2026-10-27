#include<stdio.h>
#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct  //串的堆分配存储
{
    char *ch;
    int length;
} HString;

int HStrAssign(HString &S) //串赋值
{
    int i, j, n = 0;
    char ch;
    S.ch = new char[100];
    S.length = 0;
    ch = getchar();
    while (ch != '\n') {
        S.ch[S.length] = ch;
        S.length++;
        ch = getchar();
    }
    return 1;
}


int Index(HString S, HString T) {
    int i, j, n = 0, x = 0;
    for (i = 0; i < S.length; i++) {
        if (S.ch[i] == T.ch[n]) {
            n++;
            for (j = i + 1; j < S.length; j++) {
                if (n >= T.length)
                    break;
                if (S.ch[j] == T.ch[n])
                    n++;
                else
                    return 0;
            }
        }
        if (n == T.length)
            return i + 1;
    }
}

int main() {
    HString S, T, V;
    int n;
    HStrAssign(S);
    HStrAssign(T);

    cout << S.ch << endl;
    cout << T.ch << endl;

    n = Index(S, T);
    if (n == 0)
        cout << "失败" << endl;
    else
        cout << n << endl;
    return 1;
}