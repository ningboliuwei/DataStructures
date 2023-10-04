#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *insertlinkby_elem(struct node *head, int elem);
void destroy(struct node *head);
struct node *creatlink();
void traverse(struct node *head);

int main() {
    int c;
    struct node *head;
    head = creatlink(); //用尾插法创建链表
    scanf("%d", &c);
    head = insertlinkby_elem(head, c);
    traverse(head);
    destroy(head);
    return 0;
}

struct node *creatlink() //尾插法创建链表
{
    struct node *head = NULL;
    int c;
    struct node *p, *q;

    while (1) {
        scanf("%d", &c);
        if (c == -1)
            break;

        //申请结点空间
        p = (struct node *)malloc(sizeof(struct node));

        //初始化结点数据域
        p->next = NULL;
        p->data = c;
        if (head == NULL) {
            head = p;
            q = p; //设置尾指针
        } else {
            q->next = p; //挂入链尾
            q = p;       //设置尾指针
        }
    }
    return head;
}

void traverse(struct node *head) {
    struct node *p = head;
    while (p != NULL) //如果p指向的结点不是空结点
    {
        printf("%d ", p->data); //则输出所指向的结点的数据域
        p = p->next;            //让p指向下一个结点
    }
}

struct node *insertlinkby_elem(struct node *head, int elem) {
    struct node *newnode;
    struct node *p, *tail;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = elem;
    newnode->next = NULL;

    // p=head->next;  本行代码会导致 1 3 5 7 插入 2 出错
    p = head;
    while (p->data < elem) {
        tail = p;
        p = p->next;
    }
    if (head->data > elem) {
        newnode->next = head;
        head = newnode;
        return head;
    } else {
        tail->next = newnode;
        newnode->next = p;
        return head;
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