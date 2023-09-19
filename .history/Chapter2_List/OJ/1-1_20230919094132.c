//
// Created by 慰 on 2018/9/24.
//
// 【1-1】头插法创建带头结点的链表

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};
void destroy(struct node *head);
void creatlink(struct node *head);
void traverse(struct node *head);

main() {
    int c;
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node)); // head指向头结点
    head->next = NULL;
    creatlink(head); //用头插法创建带头结点的链表
    traverse(head);
    destroy(head);
}

void creatlink(struct node *head) {
    struct node *p;
    int c;
    //采用相同的方式创建若干个结点
    while (1) {
        int c;

        scanf("%d", &c);

        if (c == -1) {
            break;
        } else {
            p = malloc(sizeof(struct node));
            p->data = c;
            p->next = head->next;
            head->next = p;
        }
    }
}

void traverse(struct node *head) {
    struct node *p = head;
    while (p->next != NULL) {
        p = p->next;
        printf("%d ", p->data);
    }
}

//销毁链表函数设计

void destroy(struct node *head) {
    struct node *p;
    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }
}
