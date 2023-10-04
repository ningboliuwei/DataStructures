#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *insertlinkby_elem(struct node *head, int elem);
void destroy(struct node *head);
struct node *creatlink();
void traverse(struct node *head);

int main() {
    int c;
    struct node *head;
    head = creatlink(); //用尾插法创建链表
    scanf("%d", &c);
    head = insertlinkby_elem(head, c);
    traverse(head);
    destroy(head);
    return 0;
}

struct node *creatlink() //尾插法创建链表
{
    struct node *head = NULL;
    int c;
    struct node *p, *q;

    while (1) {
        scanf("%d ", &c);
        if (c == -1)
            break;

        //申请结点空间
        p = (struct node *)malloc(sizeof(struct node));

        //初始化结点数据域
        p->next = NULL;
        p->data = c;
        if (head == NULL) {
            head = p;
            q = p; //设置尾指针
        } else {
            q->next = p; //挂入链尾
            q = p;       //设置尾指针
        }
    }
    return head;
}

void traverse(struct node *head) {
    struct node *p = head;
    //如果p指向的结点不是空结点
    while (p != NULL) {
        printf("%d ", p->data); //则输出所指向的结点的数据域
        p = p->next;            //让p指向下一个结点
    }
}

// 销毁链表
void destroy(struct node *head) {
    struct node *p = head; // 定义结点指针 p 并初始化为头结点指针
    struct node *q = NULL; // 定义结点指针 q 并初始化为空指针
    while (p != NULL) {    // 循环遍历链表中的结点
        q = p->next;       // 将 q 指向下一个结点
        free(p);           // 释放当前结点的内存空间
        p = q;             // 将 p 指向下一个结点
    }
}

struct node *insertlinkby_elem(struct node *head, int elem) {
    struct node *p = head, *q = NULL; // 创建两个指向结构体的指针p和q，p指向链表头结点，q指向p的前一个结点
    struct node *newnode = (struct node *)malloc(sizeof(struct node)); // 创建一个新结点newnode
    newnode->data = elem;                                              // 将新结点的数据域赋值为elem
    newnode->next = NULL;                                              // 将新结点的指针域赋值为NULL
    if (head == NULL) {                                                // 如果链表为空
        head = newnode;                                                // 将链表头指针指向新结点
        return head;                                                   // 返回链表头指针
    }

    while (p != NULL && p->data < elem) { // 在链表中找到第一个大于等于elem的结点p
        q = p;                            // 将q指向p的前一个结点
        p = p->next;                      // 将p指向下一个结点
    }

    if (p == head) {          // 如果新结点应该插入到链表头部
        newnode->next = head; // 将新结点的指针域指向原链表头结点
        head = newnode;       // 将链表头指针指向新结点
    } else {                  // 如果新结点应该插入到链表中间或尾部
        q->next = newnode;    // 将q的指针域指向新结点
        newnode->next = p;    // 将新结点的指针域指向p
    }
    return head; // 返回链表头指针
}