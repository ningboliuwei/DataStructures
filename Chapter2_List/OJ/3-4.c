//
// Created by Liu Wei on 2018/9/30.
// 问题 D: 【数据结构2-11】单链表按位删除p44六.3

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

int DeleteFromLinkList(struct Node *list, int start, int length) {
    struct Node *current = list->next;
    int pos = 1;
    while (current != NULL && pos < start - 1) {
        pos++;
        current = current->next;
    }
    struct Node *gapStart = current;
    int count = 0;
    while (current != NULL && count <= length) {
        count++;
        current = current->next;
    }
    gapStart->next = current;
}

int ShowLinkList(struct Node *list) {
    struct Node *p = list->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct Node *list = InitLinkList();

    CreateLinkList(list);
    int start = 0;
    int length = 0;
    scanf("%d%d", &start, &length);
    DeleteFromLinkList(list, start, length);
    ShowLinkList(list);

}

