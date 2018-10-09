//
// Created by Liu Wei on 2018/10/9.
// 问题 A: 【数据结构5-1】串的插入删除

#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include"stdlib.h"

using namespace std;

typedef struct
{
    char *ch;
    int length;
}HString;

int StrAssign(HString &S,char *chars)
{
//    @@1
//    @@1
}

void ShowString(HString S)
{
//    @@2
//    @@2
}

int Delete(HString &S,int pos,int len)
{
//    @@3
//    @@3
}

int Insert(HString &S,int pos,HString T)
{
//    @@4
//    @@4
}

int main( )
{
    HString S,T;
    char a[100];
    int pos,len;

    cin>>a;
    StrAssign(S,a);
    ShowString(S);

    cin>>a;
    StrAssign(T,a);
    ShowString(T);

    cout<<"请输入插入位置" ;
    cin>>pos;

//    @@5        //插入
//    @@5

    cout<<"请输入删除位置和长度" ;
    cin>>pos>>len;

//    @@6       //删除
//    @@6

    return 1;
}

