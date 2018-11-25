//
// Created by Liu Wei on 2018/11/6.
//

#include<stdio.h>
#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct  //串的堆分配存储
{
    char *ch;
    int length;
} HString;

int HStrLength(HString S)  //串长
{

    int i = 0;
    while(S.ch[i])
        i++;

    return i;

}

int HStrCompare(HString S,HString T)  //串比较
{

    int i;
    for(i = 0;S.ch[i] == T.ch[i] && S.ch[i] && T.ch[i];i++)
        return S.ch[i] - T.ch[i];

}

int HStrAssign(HString &S,char *chars) //串赋值
{

    int i = 0;
    S.ch = new char;
    while(chars[i])
    {
        S.ch[i] = chars[i];
        i++;
    }

    S.length = i;
    S.ch[S.length] = 0;

}

int ShowHString(HString S)   //串显示
{

    int i=0;
    while(i<S.length)
    {
        printf("%c",S.ch[i]);
        i++;
    }
    printf("\n");

}

int SubHStr(HString &Sub,HString S,int pos,int len)  //求子串
{

    int k = 0;
    if(pos+len-1 > S.length)
        return 0;
    else
    {
        for(k = 0;k < len;k++)
            Sub.ch[k] = S.ch[pos+k-1];

        Sub.length = len;
        Sub.ch[Sub.length] = 0;
        return 1;
    }

}

int Index(HString S, HString T,int pos)  //在主串S中从pos位开始模式匹配
{

    int i,j,k;
    for(i = pos;S.ch[i];i++)
    {
        for(j = i,k = 0;S.ch[j] == T.ch[k];j++,k++)
            if(!T.ch[k+1])
                return i;
    }
    return -1;

}

int DelHStr(HString &S,int pos,int len) //串删除
{

    int k = 0;
    if(pos+len-1 >S.length || pos < 0)
        return -1;
    else
    {
        for(k = pos+len;k < S.length;k++,pos++)
            S.ch[pos] = S.ch[k];

        S.length = S.length - len;
        S.ch[S.length] = 0;
        if(S.length == 0)
            return 0;
        else
            return 1;
    }

}

int InsHStr(HString &S,int pos,HString T)  //串插入
{

    int k;
    if(pos > S.length+1 )
        return 0;
    else
    {
        for(k = S.length-1;k>=pos;k--)
            S.ch[T.length + k] = S.ch[k];

        for(k = 0;k < T.length;k++)
            S.ch[pos+k] = T.ch[k];


        S.length = S.length + T.length;
        S.ch[S.length] = 0;
        return 1;
    }


}

int ReplaceHStr(HString &S, HString T,HString V)
//串替换（调用模式匹配，删除，插入来实现）
{

    int lenT,lenV,pos = 0;
    lenT = HStrLength(T);
    lenV = HStrLength(V);
    while(1)
    {
        pos = Index(S,T,pos);
        if(pos == -1)
            break;
        else
        {
            DelHStr(S,pos,lenT);
            InsHStr(S,pos,V);
            pos += lenV;
        }
    }
    return 1;



}

int main( )
{
    HString S,T,V;
    char a[100];

    cin>>a;
    HStrAssign(S,a);

    cin>>a;
    HStrAssign(T,a);

    cin>>a;
    HStrAssign(V,a);

    ReplaceHStr(S,T,V);
    ShowHString(S);

    return 1;
}