#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *creatlink() {                            // 创建链表
    node *head = (node *)malloc(sizeof(node)); // 创建头节点
    head->next = NULL;                         // 头节点的 next 指针指向 NULL
    node *tail = head;                         // 定义尾指针，初始指向头节点

    int x;
    while (scanf("%d", &x) && x != -1) {        // 输入链表元素，以 -1 结束
        node *p = (node *)malloc(sizeof(node)); // 创建新节点
        p->data = x;                            // 将新节点的数据域设置为 x
        p->next = NULL;                         // 将新节点的 next 指针设置为 NULL
        tail->next = p;                         // 将尾节点的 next 指针指向新节点
        tail = p;                               // 将尾指针指向新节点
    }

    return head; // 返回头节点
}

void traverse(node *head) { // 遍历链表
    node *p;
    if (head == NULL) // 如果头节点为 NULL，表示链表为空
        return;
    p = head->next;             // 将 p 指向链表的第一个节点
    while (p) {                 // 遍历链表
        printf("%d ", p->data); // 输出当前节点的数据域
        p = p->next;            // 将 p 指向下一个节点
    }
}

int main() {                  // 主函数
    node *head = creatlink(); // 创建链表
    traverse(head);           // 遍历链表
    return 0;                 // 返回 0，表示程序正常结束
}