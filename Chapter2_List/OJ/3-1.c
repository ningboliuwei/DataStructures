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
    head->next = head;

    return head;
}

int CreateLoopLinkList(struct Node *list) {
    int value = 0;
    while (scanf("%d", &value) && value != -1) {
        struct Node *node = (struct Node *) malloc(sizeof(struct Node));
        node->data = value;
        node->next = list;

        struct Node *p = list;
        while (p->next != list) {
            p = p->next;
        }
        p->next = node;
    }
    return 1;
}

int ShowLinkList(struct Node *list) {
    struct Node *p = list->next;
    while (p != list) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int ConcatLinkList(struct Node *list1, struct Node *list2) {
    struct Node *p = list1->next;
    while (p->next != list1) {
        p = p->next;
    }
    p->next = list2->next;
    while (p->next != list2) {
        p = p->next;
    }
    p->next = list1;

    return 1;
}

int main() {
    struct Node *head1 = InitLinkList();
    struct Node *head2 = InitLinkList();
    struct Node *head3 = InitLinkList();

    CreateLoopLinkList(head1);
    CreateLoopLinkList(head2);

    ConcatLinkList(head1, head2);
    ShowLinkList(head1);

}

