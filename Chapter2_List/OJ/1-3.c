//
// Created by 慰 on 2018/9/25.
// 链表练习——创建有序单链表

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;

node* creatlink()
{

    int value = 0;
    struct Node *head = NULL;

    scanf("%d", &value);
    while (value != -1) {
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
        scanf("%d", &value);
    }

    return head;
}
void traverse(node* head)
{
    node *p;
    p=head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
int main()
{
    node *head;
    head=creatlink();
    traverse(head);
}