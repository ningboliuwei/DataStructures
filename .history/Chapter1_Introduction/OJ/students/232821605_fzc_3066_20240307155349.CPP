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

void destroy(struct node *head) {
    struct node *p;
    while (head != NULL) {
        p = head;          // p指向要销毁的结点
        head = head->next; // head指向再下一个要销毁的结点
        free(p);           //销毁p指向的结点
    }
}

struct node *insertlinkby_elem(struct node *head, int elem) {
    struct node *p = head, *q;
    //如果p所指向的结点存在，并且数据xiaoyu要找的elem ，指针往后一定
    //直到结束（没有找到数据）或者找到数据为止
    while (p->next != NULL && p->data < elem && p->next->data < elem) {
        p = p->next;
    }

    q = (struct node *)malloc(sizeof(struct node)); //创建新结点

    q->data = elem;
    q->next = p->next;
    p->next = q;

    return head;
}