//
// Created by Liu Wei on 2018/9/4.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    Node *next;
} Node, *LinkList;

// 头插法创建链表
LinkList CreateList_L(LinkList linkList) {
    Node *newNode;
    int data = 0;

    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    linkList = head;

    while (1) {
        printf("Input a number, 0 to exit.");
        scanf("%d", &data);

        if (data != 0) {
            newNode = (Node *)malloc(sizeof(Node));
            newNode->data = data;
            newNode->next = head->next;
            head->next = newNode;
        } else {
            break;
        }
    }

    return linkList;
}

//显示带头结点的链表元素
void ShowList_L(LinkList linklist) {
    Node *p = linklist;

    while (p->next) {
        // 以下两行代码顺序不要颠倒
        p = p->next;
        printf("%d ", p->data);
    }
}

int main() {
    LinkNode node;

    getchar();
}
