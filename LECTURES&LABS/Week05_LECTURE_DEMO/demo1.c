//
// Created by 慰 on 2018/10/8.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

int InitLinkList(LinkList list) {
    Node *headNode = (Node *) malloc(sizeof(Node));
    headNode->next = NULL;

    list = headNode;
    return 1;
}

int CreateLinkList(LinkList list) {
    int value;

    while (scanf("%d", &value) && value != -1) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;

        if (list->next == NULL) {
            list->next = newNode;
        } else {
            // 头插
//            newNode->next = list->next;
//            list->next = newNode;


        }
    }
}

void ShowLinkList(LinkList list){
    Node *p = list->next;

    while (p != NULL){
        printf("%d", p->data);
        p=p->next;
    }
}

int main() {
    LinkList list = (LinkList) malloc(sizeof(Node));

    InitLinkList(list);
    CreateLinkList(list);

    ShowLinkList(list);

    getchar();

}