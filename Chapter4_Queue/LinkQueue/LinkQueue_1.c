//
// Created by Liu Wei on 2018/9/17.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10

typedef struct LinkQueueNodeStruct {
    int data;
    struct LinkQueueNodeStruct *next;
} LineQueueNode;

typedef struct {
    struct LinkQueueNodeStruct *front;
    struct LinkQueueNodeStruct *rear;
} LinkQueue;

int IsEmptyQueue(LinkQueue *queue) {
    if (queue->front == NULL && queue->rear == NULL) {
        return 1;
    }

    return 0;
}

int LengthOfQueue(LinkQueue *queue) {
    int count = 0;

    if (IsEmptyQueue(queue)) {
        return 0;
    }

    LineQueueNode *node = queue->front;

    while (node != NULL) {
        node = node->next;
        count++;
    }

    return count;
}

int InQueue(LinkQueue *queue, int item) {
    struct LinkQueueNodeStruct *newNode = (struct LinkQueueNodeStruct *) malloc(sizeof(struct LinkQueueNodeStruct));

    newNode->data = item;
    newNode->next = NULL;

    if (IsEmptyQueue(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;

    return 1;
}

int OutQueue(LinkQueue *queue, int *item) {
    if (IsEmptyQueue(queue)) {
        return 0;
    }

    *item = queue->front->data;
    queue->front = queue->front->next;

    return 1;

}

int InitQueue(LinkQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void ShowQueue(LinkQueue *queue) {

    if (IsEmptyQueue(queue)) {
        printf("empty queue");
    }

    printf("queue: ");

    LineQueueNode *node = queue->front;

    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }

    printf("\n");

}

int main() {
    LinkQueue *queue = (LinkQueue *) malloc(sizeof(struct LinkQueueNodeStruct));
    InitQueue(queue);

    InQueue(queue, 1);
    InQueue(queue, 2);
    InQueue(queue, 3);
    InQueue(queue, 4);

    int *item = (int *) malloc(sizeof(int));

    ShowQueue(queue);
    printf("length of queue: %d\n", LengthOfQueue(queue));
    OutQueue(queue, item);
    printf("out: %d\n", *item);

    ShowQueue(queue);
    printf("length of queue: %d\n", LengthOfQueue(queue));
    OutQueue(queue, item);
    printf("out: %d\n", *item);


    ShowQueue(queue);
    printf("length of queue: %d\n", LengthOfQueue(queue));
    OutQueue(queue, item);
    printf("out: %d\n", *item);


    ShowQueue(queue);
    printf("length of queue: %d\n", LengthOfQueue(queue));
    OutQueue(queue, item);
    printf("out: %d\n", *item);

    printf("length of queue: %d\n", LengthOfQueue(queue));

    getchar();

}