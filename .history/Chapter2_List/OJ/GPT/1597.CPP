#include <stdio.h>
#include <stdlib.h>
    typedef struct Node {
    int data;
    struct Node *next;
} node;

node *creatlink() {
    // 创建一个头节点
    node *head = (node *)malloc(sizeof(node));
    if (head == NULL) {
        exit(EXIT_FAILURE); // 内存分配失败，退出程序
    }
    head->next = NULL; // 初始化头节点的next指针为NULL

    int input;
    // 逐个输入元素并存入链表，直到输入-1
    while (scanf("%d", &input) == 1 && input != -1) {
        // 创建一个新节点
        node *newNode = (node *)malloc(sizeof(node));
        if (newNode == NULL) {
            free(head);         // 释放已分配的头节点内存
            exit(EXIT_FAILURE); // 内存分配失败，退出程序
        }
        newNode->data = input;
        newNode->next = NULL;

        // 找到插入位置，使链表保持递增排序
        node *p = head;
        while (p->next != NULL && p->next->data < input) {
            p = p->next;
        }

        // 插入新节点
        newNode->next = p->next;
        p->next = newNode;
    }
    //
    return head;
}
void traverse(node *head) {
    node *p;
    if (head == NULL)
        return;
    p = head->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main() {
    node *head;
    head = creatlink();
    traverse(head);
}