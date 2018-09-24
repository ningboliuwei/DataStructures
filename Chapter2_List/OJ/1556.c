//
// Created by 慰 on 2018/9/24.
//
// 链表练习——【链表操作】头插法创建带头结点的链表

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    head = (struct node *) malloc(sizeof(struct node)); //head指向头结点
    head->next = NULL;
    creatlink(head);   //用头插法创建带头结点的链表
    traverse(head);
    destroy(head);
}


void creatlink(struct node *head) {
    struct node *p;
    int c;
    //采用相同的方式创建若干个结点
    while (1) {

//  @@1
//  读取整数到c，如果c为-1，则结束循环，否则
//  创建新结点，把c放入新结点的数据域
//  把原链表的第1个结点，挂到新结点的后面，让新结点成为新的第1个结点。
//  @@1

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
//  @@2
//  这里的访问与输出，与不带头结点的链表的不同点在于
//  head所指向的，并不是第1个结点，而是头结点，所以输出应该从头结点后的结点开始
//  @@2
//  注意此处不是 head->next
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

