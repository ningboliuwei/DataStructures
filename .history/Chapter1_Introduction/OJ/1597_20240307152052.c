#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *creatlink() { // 创建链表
    node *head = NULL, *p, *q, *t;
    int ch;
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
    while (1) {
        scanf("%d", &ch);
        if (ch == -1)
            break;
        p = (node *)malloc(sizeof(node));
        p->data = ch;
        p->next = NULL;
        if (head->next == NULL) {
            head->next = p;
            q = p;
        } else {
            if (p->data < head->next->data) {
                p->next = head->next;
                head->next = p;
            } else {
                t = head->next;
                while (t->next != NULL && t->next->data < p->data) {
                    t = t->next;
                }
                p->next = t->next;
                t->next = p;
            }
            if (q->next == NULL) {
                q = p;
            }
        }
    }

    return head;
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