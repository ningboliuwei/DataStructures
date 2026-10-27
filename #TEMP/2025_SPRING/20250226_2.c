#include <stdio.h>
#include <stdlib.h>

struct node //结点数据类型
{
    char data;
    struct node *next;
};

void traverse(struct node *head);
void destroy(struct node *head);
struct node *tailinsert();

int main() {
    struct node *head = NULL;
    head = tailinsert(); //用尾插法创建链表
    traverse(head);      //遍历链表
    destroy(head);       //释放资源，销毁链表中所有结点

    return 0;
}
// @@1
void traverse(struct node *head) {
    struct node *p = head;

    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }
}

void destroy(struct node *head) {
    struct node *p = head;

    while (p != NULL) {
        struct node *q = p;
        p = p->next;
        free(q);
    }
}

struct node *tailinsert() {
    struct node *head = NULL;

    for (int i = 0; i < 4; i++) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        char c;
        scanf("%c", &c);
        newNode->data = c;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            struct node *p = head;

            while (p->next != NULL) {
                p = p->next;
            }

            p->next = newNode;
        }
    }
    return head;
}
// @@1