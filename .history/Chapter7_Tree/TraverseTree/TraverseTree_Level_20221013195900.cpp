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

typedef QueueNode datatype;

typedef struct QueueNode {
    datatype data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front; //队头指针
    QueueNode *rear;  //队尾指针
} LinkQueue;

int InitQueue(LinkQueue *&queue) {
    queue = new LinkQueue;
    queue->front = NULL;
    queue->rear = NULL;

    return 1;
}

int QueueEmpty(LinkQueue *queue) {
    if (queue->front == NULL && queue->rear == NULL) {
        return 1;
    }

    return 0;
}

int InQueue(LinkQueue *queue, datatype element) {
    QueueNode *newNode = new QueueNode;
    newNode->data = element;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    return 1;
}

int OutQueue(LinkQueue *queue, datatype &element) {
    if (QueueEmpty(queue)) {
        return 0;
    }

    QueueNode *p = queue->front;
    element = queue->front->data;
    queue->front = queue->front->next;
    // 表示队列中只有一个元素
    if (queue->rear == p) {
        queue->rear = NULL;
    }

    free(p);

    return 1;
}

typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

int CreateBiTree(BiTree &tree, char *elements, int &index) {
    if (elements[index] == '\0') {
        return 1;
    }

    if (elements[index] == '*') {
        tree = NULL;
    } else {
        tree = (BiNode *)malloc(sizeof(BiNode));
        tree->data = elements[index];
        CreateBiTree(tree->lchild, elements, ++index);
        CreateBiTree(tree->rchild, elements, ++index);
    }
}

void LevelOrder(BiTree &tree) {
    // 初始化队列
    LinkQueue *queue;
    InitQueue(queue);

    // 将根节点入队
    if (tree != NULL) {
        InQueue(queue, tree);
    }

    while (!QueueEmpty(queue)) {
        int value = 0;
        OutQueue(queue, value);
        printf("%d", value);
        if ()
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
