#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;          // 多项式的系数
    int exp;           // 多项式的指数
    struct Node *next; // 指向下一个节点的指针
} node;

node *creatlink() {
    // @@1 开始
    // 创建一个头节点，用于简化插入操作
    node *head = (node *)malloc(sizeof(node));
    if (head == NULL) {
        exit(EXIT_FAILURE); // 内存分配失败，退出程序
    }
    head->next = NULL; // 初始化头节点的 next 指针为 NULL

    int coef, exp;

    // 读取所有输入，直到输入结束（EOF）
    while (scanf("%d %d", &coef, &exp) == 2) {
        if (coef == 0 && exp == 0) {
            continue; // 多项式结束，继续读取下一个多项式
        }

        // 创建一个新节点
        node *newNode = (node *)malloc(sizeof(node));
        if (newNode == NULL) {
            // 释放链表内存并退出
            node *temp = head;
            while (temp != NULL) {
                node *next = temp->next;
                free(temp);
                temp = next;
            }
            exit(EXIT_FAILURE);
        }
        newNode->coef = coef;
        newNode->exp = exp;
        newNode->next = NULL;

        // 插入新节点到链表中，保持递减排序
        node *p = head;
        while (p->next != NULL && p->next->exp > newNode->exp) {
            p = p->next;
        }

        if (p->next != NULL && p->next->exp == newNode->exp) {
            // 如果指数相同，合并系数
            p->next->coef += newNode->coef;
            if (p->next->coef == 0) {
                // 如果合并后的系数为 0，删除该节点
                node *temp = p->next;
                p->next = temp->next;
                free(temp);
            }
            free(newNode); // 合并后不需要新节点
        } else {
            // 插入新节点
            newNode->next = p->next;
            p->next = newNode;
        }
    }
    // @@1 结束
    return head;
}

void traverse(node *head) {
    // @@2 开始
    node *p = head->next; // 跳过头节点
    while (p) {
        if (p->coef != 0) { // 只输出非零系数的项
            printf("%d %d ", p->coef, p->exp);
        }
        p = p->next;
    }
    printf("\n"); // 输出换行符
    // @@2 结束
}

int main() {
    node *head = creatlink();
    traverse(head);

    // 释放链表内存
    node *current = head;
    while (current != NULL) {
        node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
