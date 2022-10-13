//
// Created by 慰 on 2018/10/18.
//

//
// Created by Liu Wei on 2018/10/19.
// 1631 问题 A: 【数据结构7-1】根据先序创建二叉树
// 测试数据：ab**c**
// 结果：
// abc
// bac
// bca
// OJ PASSED

// 测试数据：ABE**FH***C*G**

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front; //队头指针
    QueueNode *rear;  //队尾指针
} LinkQueue;

int InitQueue(LinkQueue *&Q) {
    Q = new LinkQueue;
    Q->front = NULL;
    Q->rear = NULL;

    return 1;
}

int QueueEmpty(LinkQueue *queue) {
    if (queue->front == NULL && queue->rear == NULL) {
        return 1;
    }

    return 0;
}

int InQueue(LinkQueue *queue, int value) {
    QueueNode *newNode = new QueueNode;
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    return 1;
    //    @@3
}

int OutQueue(LinkQueue *Q, dataType &x) {
    //@@4
    if (QueueEmpty(Q)) {
        return 0;
    }

    QueueNode *p = Q->front;
    x = Q->front->data;
    Q->front = Q->front->next;
    // 表示队列中只有一个元素
    if (Q->rear == p) {
        Q->rear = NULL;
    }

    free(p);

    return 1;
    //@@4
}

typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

int CreateBiTree(BiTree &T, char *elements, int &index) {
    if (elements[index] == '\0') {
        return 1;
    }

    if (elements[index] == '*') {
        T = NULL;
    } else {
        T = (BiNode *)malloc(sizeof(BiNode));
        T->data = elements[index];
        CreateBiTree(T->lchild, elements, ++index);
        CreateBiTree(T->rchild, elements, ++index);
    }
}

void LevelOrder(BiTree &tree) {
    BiNode *p;
    BiNode *q[MAX_SIZE];

    int front;
    int rear;

    p = tree;

    if (p != NULL) {
        front = 0;
        q[front] = tree;
        rear = 1;
    }

    while (front != rear) {
        p = q[front];
        front++;
        printf("%c ", p->data);
        if (p->lchild != NULL) {
            q[rear] = p->lchild;
            rear++;
        }
        if (p->rchild != NULL) {
            q[rear] = p->rchild;
            rear++;
        }
    }
}

int main() {
    char elements[20];
    int index = 0;
    BiTree tree;

    gets(elements);
    CreateBiTree(tree, elements, index);
    LevelOrder(tree);
    getchar();
    getchar();
}
