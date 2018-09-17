//
// Created by Liu Wei on 2018/9/15.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10

typedef struct SequenceQueueType {
    int data[MAX_LENGTH];
    int front;
    int rear;
} *SequenceQueue;

int IsEmptyQueue(SequenceQueue queue) {
    if (queue->front == -1 && queue->rear == -1) {
        return 1;
    }
    return 0;
}

int LengthOfQueue(SequenceQueue queue) {
    if (IsEmptyQueue(queue)) {
        return 0;
    } else {
        return queue->rear - queue->front + 1;
    }
}

int InQueue(SequenceQueue *queue, int item) {
    if ((*queue)->rear == MAX_LENGTH - 1) {
        return 0;
    }

    if (IsEmptyQueue(queue)) {
        (*queue)->front = 0;
    }

    (*queue)->rear++;
    (*queue)->data[(*queue)->rear] = item;

    return 1;
}

int OutQueue(SequenceQueue *queue, int *item) {
    if (IsEmptyQueue(queue)) {
        return 0;
    }

    *item = (*queue)->data[(*queue)->front];
    return 1;
}

int InitQueue(SequenceQueue *queue) {
    (*queue)->front = -1;
    (*queue)->rear = -1;
}

void ShowQueue(SequenceQueue queue) {
    printf("items: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    SequenceQueue *queue = (SequenceQueue *) malloc(sizeof(SequenceQueue));
    InitQueue(queue);

    InQueue(queue, 1);
    InQueue(queue, 2);
    InQueue(queue, 3);
    InQueue(queue, 4);

    ShowQueue(queue);

    int *item = (int *) malloc(sizeof(int));

    OutQueue(queue, item);
    printf("out: %d", *item);
    OutQueue(queue, item);
    printf("out: %d", *item);

    ShowQueue(queue);

}