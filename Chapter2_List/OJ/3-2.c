//
// Created by Liu Wei on 2018/9/30.
// 问题 B: 【数据结构2-6】创建有序单链表

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *creatlink() {
//    @@1
    struct Node *head = NULL;
    int value = 0;

    while (scanf("%d", &value) && value != -1) {
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            struct Node *current = head;
            struct Node *previous = NULL;

            while (current != NULL && current->data < value) {
                previous = current;
                current = current->next;
            }

            if (previous == NULL) {
                newNode->next = head;
                head = newNode;
            } else {
                newNode->next = previous->next;
                previous->next = newNode;
            }
        }
    }


//    @@1
    return head;
}

void traverse(node *head) {
    node *p;
    p = head;
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
