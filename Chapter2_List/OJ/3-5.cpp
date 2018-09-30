//
// Created by Liu Wei on 2018/9/30.
// 问题 E: 【数据结构2-11】链式表的合并问题

#include<stdio.h>
#include"stdlib.h"
#include<iostream>

using namespace std;

typedef int datatype;

typedef struct linknode {
    datatype data;
    struct linknode *next;
} LinkNode, *LinkList;

LinkList GetHead(LinkList L);   //获取链式存储的线性表（带头结点）的头指针
LinkList NextPos(LinkList L, LinkList h);  //获取后继结点的地址
datatype GetCurElem(LinkList p);          //获取当前结点的数据值
void DelFirst(LinkList L, LinkList &q);    //删除线性表中的第一个数据结点并把删除结点放入q中
void Append(LinkList L, LinkList q);   //追加一个结点到线性表中（尾部加入q结点）
void FreeNode(LinkList L);             //释放整个线性表L
int MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);

void Show(LinkList L);

int InitList(LinkList &L);     //线性表L初始化

//@@2
//自己设计主函数及其他需要的函数定义

LinkList GetHead(LinkList L) {
    return L;
};   //获取链式存储的线性表（带头结点）的头指针

void Show(LinkList L) {
    LinkNode *h = GetHead(L);
    LinkNode *p = NextPos(L, h);

    while (p) {
        datatype element = GetCurElem(p);
        printf("%d ", element);
        p = NextPos(L, p);
    }
    printf("\n");
}


LinkList NextPos(LinkList L, LinkList h) {
    return h->next;
};  //获取后继结点的地址
datatype GetCurElem(LinkList p) {
    return p->data;
};          //获取当前结点的数据值
void DelFirst(LinkList L, LinkList &q) {
    q = L->next;
    if (L->next->next != NULL) {
        L->next = L->next->next;
    } else {
        L->next = NULL;
    }
    // 下一行重要
    q->next = NULL;
};    //删除线性表中的第一个数据结点并把删除结点放入q中
void Append(LinkList L, LinkList q) {
    LinkNode *p = GetHead(L);

    while (p->next != NULL) {
        p = NextPos(L, p);
    }

    p->next = q;
};   //追加一个结点到线性表中（尾部加入q结点）
void FreeNode(LinkList L) {
    LinkNode *p = L;
    LinkNode *q = NULL;

    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
};             //释放整个线性表L

//合并算法的伪代码参考如下
int MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {
    InitList(Lc);
    LinkNode *ha = GetHead(La);
    LinkNode *hb = GetHead(Lb);
    LinkNode *pa = NextPos(La, ha);
    LinkNode *pb = NextPos(Lb, hb);
    while (pa && pb) {
        datatype a = GetCurElem(pa);
        datatype b = GetCurElem(pb);
        LinkList q;
        if (a <= b) {
            DelFirst(ha, q);
            Append(Lc, q);
            pa = NextPos(La, ha);
        } else {
            DelFirst(hb, q);
            Append(Lc, q);
            pb = NextPos(Lb, hb);
        }
    }
    if (pa) {
        Append(Lc, pa);
    } else {
        Append(Lc, pb);
    };
    return 1;
} // MergeList_L

int InitList(LinkList &L) {
    L = (LinkList) malloc(sizeof(LinkList));
    L->next = NULL;

    return 1;
};     //线性表L初始化
int main() {
    LinkList list1;
    LinkList list2;
    LinkList list3;

    InitList(list1);
    InitList(list2);

    datatype value = 0;
    while (scanf("%d", &value) && value != -1) {
        LinkNode *node = (LinkNode *) malloc(sizeof(LinkNode));
        node->data = value;
        node->next = NULL;
        Append(list1, node);
    }

    while (scanf("%d", &value) && value != -1) {
        LinkNode *node = (LinkNode *) malloc(sizeof(LinkNode));
        node->data = value;
        node->next = NULL;
        Append(list2, node);
    }

    MergeList_L(list1, list2, list3);
    Show(list3);
    FreeNode(list1);
    FreeNode(list2);
}
//@@2