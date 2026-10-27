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

void traverse(struct node *head) {
    struct node *p = head;
    int i;
    for (i = 0; i < 4; i++) {
        printf("%c ", p->data);
        p = p->next;
    }
}
void destroy(struct node *head) {
    struct node *p;
    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }
}
struct node *tailinsert() {
    struct node *head = NULL, *tail = NULL, *p = NULL;
    int i, l;
    for (i = 0; i < 4; i++) {
        p = (node *)malloc(sizeof(node));
        scanf("%c", &l);
        p->data = l;
        p->next = NULL;
        if (head == NULL) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }
    return head;
}