//
// Created by Liu Wei on 2018/11/27.
//

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
typedef int datatype;
typedef struct QNode
{
    datatype      data;
    struct QNode *next;
}QNode;

typedef struct qptr
{
    QNode  *front; //队头指针
    QNode * rear;  //队尾指针
} LinkQueue;

int InitQueue(LinkQueue* &Q)
{
    Q->front = NULL;
    Q->rear = NULL;
}
int QueueEmpty(LinkQueue* Q)
{
    if(NULL == Q->front)
        return 0;
}

int InQueue(LinkQueue* Q,datatype x)
{
    QNode *p = new QNode;
    p->data = x;
    p->next = NULL;
    if(NULL == Q->front)
        Q->front = p;
    else
        Q->rear->next = p;
    Q->rear = p;
}

int OutQueue(LinkQueue* Q,datatype &x)
{
    QNode *p = Q->front;
    if(NULL == Q->front)
        return 0;
    else
    {
        Q->front= p->next;
        if(NULL == Q->front)
            Q->rear = NULL;
        x = p->data;
        delete p;
        return x;
    }
}

int main()
{
    LinkQueue* Q;
    int i,x;

    printf("请选择： 1 创建新队列 2 入队 3 出队 0 结束");
    scanf("%d",&i);
    while(i != 0)
    {
        if(i == 1)
        {
            InitQueue(Q);
            printf("创建成功");
            printf("\n请选择： 1 创建新队列 2 入队 3 出队 0 结束");
        }
        else if(i == 2)
        {
            scanf("%d",&x);
            InQueue(Q,x);
            printf("入队成功");
            printf("\n请选择： 1 创建新队列 2 入队 3 出队 0 结束");
        }
        else if(i == 3)
        {
            if(NULL == Q->front)
                printf("出队失败");
            else
            {
                printf("%d\n",OutQueue(Q,x));

                printf("出队成功");
            }
            printf("\n请选择： 1 创建新队列 2 入队 3 出队 0 结束");
        }
        scanf("%d",&i);
    }
    return 0;
}