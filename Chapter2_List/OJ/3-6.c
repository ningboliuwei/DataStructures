//
// Created by 慰 on 2018/9/30.
// 问题 F: 【数据结构2-7】多项式求和——链表实现（p39自主设计实验2）

#include<stdio.h>
#include<malloc.h>

typedef struct Node {
    int m;       // 系数
    int n;       // 指数
    struct Node *next;
} LinkNode, *LinkList;

LinkList InitList() {
    LinkList list = (LinkList) malloc(sizeof(LinkNode));
    return list;
}

int InsertNode(LinkList list, LinkNode *newNode) {
    if (list == NULL) {
        return 0;
    }

    newNode->next = list->next;
    list->next = newNode;

    return 1;
}

int CreateList(LinkList list) {
    // 系数
    int m = -1;
    // 指数
    int n = -1;

    while (scanf("%d%d", &m, &n) && !(m == 0 && n == 0)) {
        LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
        newNode->m = m;
        newNode->n = n;
        newNode->next = NULL;
        InsertNode(list, newNode);
    }

    return 1;
}

int AddList(LinkList list1, LinkList list2, LinkList list3) {
    int maxN = 0;
    // 找出最高指数
    LinkNode *current = list1->next;
    while (current) {
        if (current->n > maxN) {
            maxN = current->n;
        }
        current = current->next;
    }

    current = list2->next;
    while (current) {
        if (current->n > maxN) {
            maxN = current->n;
        }
        current = current->next;
    }

    // 方便头插法
    for (int i = 0; i <= maxN; i++) {
        int sumM = 0;
        current = list1;
        while (current) {
            if (current->n == i) {
                sumM = sumM + current->m;
            }
            current = current->next;
        }

        current = list2;
        while (current) {
            if (current->n == i) {
                sumM = sumM + current->m;
            }
            current = current->next;
        }

        LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
        newNode->m = sumM;
        newNode->n = i;
        newNode->next = list3->next;
        list3->next = newNode;
    }
}

int ShowList(LinkList list) {
    LinkNode *current = list->next;

    while (current) {
        if (current->m != 0) {
            printf("%d %d\n", current->m, current->n);
        }
        current = current->next;
    }
}

int main() {
    LinkList list1 = InitList();
    LinkList list2 = InitList();
    LinkList list3 = InitList();

    CreateList(list1);
    CreateList(list2);

    AddList(list1, list2, list3);

    ShowList(list3);

    return 1;
}

