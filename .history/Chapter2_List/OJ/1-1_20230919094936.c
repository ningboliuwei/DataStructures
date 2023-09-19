//
// Created by 慰 on 2018/9/24.
//
// 【1-1】头插法创建带头结点的链表

// 本程序用头插法创建带头结点的链表

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义链表结构体
struct node {
    int data;          //链表节点的数据域
    struct node *next; //链表节点的指针域
};

//函数声明
void destroy(struct node *head);   //销毁链表
void creatlink(struct node *head); //创建链表
void traverse(struct node *head);  //遍历链表

//主函数
main() {
    int c;
    struct node *head;                                 //定义头结点指针
    head = (struct node *)malloc(sizeof(struct node)); //动态分配头结点内存空间
    head->next = NULL;                                 //初始化头结点的指针域为空
    creatlink(head);                                   //用头插法创建带头结点的链表
    traverse(head);                                    //遍历链表
    destroy(head);                                     //销毁链表
}

//销毁链表
void destroy(struct node *head) {
    struct node *p, *q;
    p = head;           // p指向头结点
    while (p != NULL) { //循环遍历链表
        q = p->next;    // q指向p的下一个节点
        free(p);        //释放p所指向的节点的内存空间
        p = q;          // p指向q，即指向下一个节点
    }
}

//创建链表
void creatlink(struct node *head) {
    struct node *p;
    int x;
    scanf("%d", &x);                                    //输入第一个节点的数据
    while (x != -1) {                                   //当输入-1时结束循环
        p = (struct node *)malloc(sizeof(struct node)); //动态分配节点内存空间
        p->data = x;                                    //将输入的数据存储到节点的数据域中
        p->next = head->next;                           //将p的指针域指向头结点的下一个节点
        head->next = p;                                 //将头结点的指针域指向p
        scanf("%d", &x);                                //输入下一个节点的数据
    }
}

//遍历链表
void traverse(struct node *head) {
    struct node *p;
    p = head->next;             // p指向头结点的下一个节点
    while (p != NULL) {         //循环遍历链表
        printf("%d ", p->data); //输出节点的数据域
        p = p->next;            // p指向下一个节点
    }
}