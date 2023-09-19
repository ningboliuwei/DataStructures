#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} node;

node *creatlink() {
    node *head = (node *)malloc(sizeof(node)); // 创建头节点
    head->next = NULL;                         // 头节点的 next 指针指向 NULL
    node *tail = head;                         // 定义尾指针，初始指向头节点

    int x;
    while (scanf("%d", &x) != EOF) {            // 输入链表元素，以 EOF 结束
        node *p = (node *)malloc(sizeof(node)); // 创建新节点
        p->data = x;                            // 将新节点的数据域设置为 x
        p->next = NULL;                         // 将新节点的 next 指针设置为 NULL
        tail->next = p;                         // 将尾节点的 next 指针指向新节点
        tail = p;                               // 将尾指针指向新节点
    }

    return head; // 返回头节点
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