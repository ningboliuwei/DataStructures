#include <stdio.h>
#include <stdlib.h>

// 定义链表结点结构体
struct node {
    int data;          // 数据域
    struct node *next; // 指向下一个结点的指针
};

// 尾插法创建链表
struct node *creatlink() {
    struct node *head = NULL; // 定义头结点指针并初始化为空
    int c;                    // 定义输入的值
    struct node *p, *q;       // 定义结点指针 p 和 q

    while (1) {
        scanf("%d", &c); // 读取用户输入的整数
        if (c == -1)     // 如果输入的值为 -1，则退出循环
            break;

        // 申请结点空间
        p = (struct node *)malloc(sizeof(struct node));

        // 初始化结点数据域
        p->next = NULL;     // 将结点的下一个指针初始化为空
        p->data = c;        // 将结点的数据域设置为输入的值
        if (head == NULL) { // 如果头结点为空，则将头结点指向当前结点
            head = p;
            q = p;       // 设置尾指针
        } else {         // 如果头结点不为空，则将当前结点挂入链尾
            q->next = p; // 挂入链尾
            q = p;       // 设置尾指针
        }
    }
    return head; // 返回头结点指针
}

// 遍历链表
void traverse(struct node *head) {
    struct node *p = head;      // 定义结点指针 p 并初始化为头结点指针
    while (p != NULL) {         // 循环遍历链表中的结点
        printf("%d ", p->data); // 输出当前结点的数据域
        p = p->next;            // 将指针指向下一个结点
    }
    printf("\n"); // 输出换行符
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

int main() {
    struct node *head = creatlink(); // 创建链表
    traverse(head);                  // 遍历链表
    destroy(head);                   // 销毁链表
    return 0;
}