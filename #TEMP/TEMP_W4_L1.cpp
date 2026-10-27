//
// Created by Liu Wei on 2019-10-29.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10

typedef int datatype;

typedef struct LinkQueueNodeStruct {
    datatype data;
    struct LinkQueueNodeStruct *next;
} LinkQueueNode;

typedef struct {
    LinkQueueNode *front;
    LinkQueueNode *rear;
} LinkQueue;

LinkQueue *Init_Queue(){
    LinkQueue *queue =(LinkQueue *) malloc(sizeof(LinkQueue));

    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

int InQueue(LinkQueue *queue, datatype x){
    LinkQueueNode *node = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    node->next = NULL;
    node->data = x;

    if(queue->front == NULL && queue->rear == NULL){
        queue->front = node;
        queue->rear = node;
    }else{
        queue->rear->next = node;
        queue->rear = node;
    }
}

int LengthOfQueue(LinkQueue *queue){
    if(queue->front == NULL && queue->rear == NULL){
        return 0;
    }

    int count = 0;
    LinkQueueNode *p = queue->front;

    while (p!= NULL){
        count++;
        p = p->next;
    }

    return count;
}

void ShowQueue(LinkQueue *queue){
    if(queue->front == NULL && queue->rear == NULL){
        printf("empty queue\n");
    }

    LinkQueueNode *p = queue->front;

    while (p!= NULL){
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n---------------\n");

}

int OutQueue(LinkQueue *queue, datatype *x){
    if(queue->front == NULL && queue->rear == NULL){
        return 0;
    }

    *x = queue->front->data;

    LinkQueueNode *p = queue->front;
    queue->front = queue->front->next;
    free(p);

    if(queue->front == NULL){
        queue->rear = NULL;
    }
}


int main(){
    LinkQueue *queue = Init_Queue();
    printf("%d\n",LengthOfQueue(queue) );
    ShowQueue(queue);

    InQueue(queue, 1);
    printf("%d\n",LengthOfQueue(queue) );
    ShowQueue(queue);

    InQueue(queue, 2);
    printf("%d\n",LengthOfQueue(queue) );
    ShowQueue(queue);

    InQueue(queue, 3);
    printf("%d\n",LengthOfQueue(queue) );
    ShowQueue(queue);

    datatype *x = (datatype *)malloc(sizeof(datatype));

    OutQueue(queue, x);
    printf("\n out: %d\n", *x);
    ShowQueue(queue);

    OutQueue(queue, x);
    printf("\n out: %d\n", *x);
    ShowQueue(queue);

    OutQueue(queue, x);
    printf("\n out: %d\n", *x);
    ShowQueue(queue);

    getchar();
}
