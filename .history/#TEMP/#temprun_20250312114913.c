#include <stdio.h>
#include "stdlib.h"
#include <iostream>
using namespace std;

typedef int datatype;

typedef struct linknode {
    datatype data;
    struct linknode *next;
} LinkNode, *LinkList;

LinkList Gethead(LinkList L);             //获取链式存储的线性表（带头结点）的头指针
LinkList NextPos(LinkList L, LinkList h); //获取后继结点的地址
datatype GetCurElem(LinkList p);          //获取当前结点的数据值
void DelFirst(LinkList L, LinkList &q);   //删除线性表中的第一个数据结点并把删除结点放入q中
void Append(LinkList L, LinkList q);      //追加一个结点到线性表中（尾部加入q结点）
void FreeNode(LinkList L);                //释放整个线性表L
int MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);
int InitList(LinkList &L); //线性表L初始化

LinkList Gethead(LinkList L) {
    return L;
}
LinkList NextPos(LinkList L, LinkList h) {
    if (h == NULL)
        return NULL;
    return h->next;
}
datatype GetCurElem(LinkList p) {
    if (p == NULL)
        return -1;
    return p->data;
}
void DelFirst(LinkList L, LinkList &q) {
    if (L == NULL || L->next == NULL)
        return;
    q = L->next;
    L->next = q->next;
    q->next = NULL;
}
void Append(LinkList L, LinkList q) {
    if (L == NULL || q == NULL)
        return;
    LinkList p = L;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = q;
}
void FreeNode(LinkList L) {
    LinkList p = L;
    while (p != NULL) {
        LinkList temp = p;
        p = p->next;
        free(temp);
    }
}
int InitList(LinkList &L) {
    L = new LinkNode;
    if (L == NULL)
        return 0;
    (L)->next = NULL;
    return 1;
}
int MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {
    InitList(Lc);
    LinkList ha = Gethead(La);
    LinkList hb = Gethead(Lb);
    LinkList pa = NextPos(La, ha);
    LinkList pb = NextPos(Lb, hb);
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

    if (pa)
        Append(Lc, pa);
    if (pb)
        Append(Lc, pb);

    return 1;
}
LinkList CreatLinkList() {
    LinkList head, tail, newNode;
    InitList(head);
    tail = head;
    datatype num;
    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;
        newNode = new LinkNode;
        newNode->data = num;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}
void ShowLinkList(LinkList L) {
    LinkList p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    LinkList La, Lb, Lc;
    La = CreatLinkList();
    Lb = CreatLinkList();
    MergeList_L(La, Lb, Lc);
    ShowLinkList(Lc);
    FreeNode(La);
    FreeNode(Lb);
    FreeNode(Lc);
    return 0;
}