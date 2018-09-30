//
// Created by Liu Wei on 2018/9/30.
// 问题 C: 【数据结构2-8】单链表按值查找p44六.4

//
// Created by Liu Wei on 2018/9/29.
// 【数据结构2-5】单向循环链表链接（p44六.5）

#include <stdlib.h>
#include <stdio.h>

typedef int dataType;
struct Node {
    dataType data;
    struct Node *next;
};

struct Node *InitLinkList() {
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    head->next = NULL;

    return head;
}

int CreateLinkList(struct Node *list) {
    int value = 0;
    while (scanf("%d", &value) && value != -1) {
        struct Node *node = (struct Node *) malloc(sizeof(struct Node));
        node->data = value;
        node->next = NULL;

        struct Node *p = list;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = node;
    }
    return 1;
}

int ShowLinkList(struct Node *list) {
    struct Node *p = list->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int CountValue(struct Node *list, dataType value) {
    int count = 0;
    struct Node *p = list->next;
    while (p != NULL) {
        if (p->data == value) {
            count++;
        }
        p = p->next;
    }
    return count;
}

int main() {
    struct Node *head = InitLinkList();

    CreateLinkList(head);
    int value = 0;
    scanf("%d", &value);
    int count = CountValue(head, value);
    printf("链表中共有%d个%d", count, value);
}



