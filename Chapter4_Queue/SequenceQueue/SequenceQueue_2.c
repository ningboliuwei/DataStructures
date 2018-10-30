//
// Created by Liu Wei on 2018/9/19.
// 此版本，front 不再指向队列中第一个元素，而是第一个元素的前一个
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
    if (queue->front == queue->rear) {
        return 1;
    }
    return 0;
}

int LengthOfQueue(SequenceQueue queue) {
    return queue->rear - queue->front;
}

int InQueue(SequenceQueue *queue, int item) {
    if ((*queue)->rear == MAX_LENGTH - 1) {
        return 0;
    }

    (*queue)->rear++;
    (*queue)->data[(*queue)->rear] = item;

    return 1;
}

int OutQueue(SequenceQueue *queue, int *item) {
    if (IsEmptyQueue(*queue)) {
        return 0;
    }

    (*queue)->front++;
    *item = (*queue)->data[(*queue)->front];

    return 1;
}

int InitQueue(SequenceQueue *queue) {
    // 此处 sizeof 的参数要注意
    *queue = (SequenceQueue) malloc(sizeof(struct SequenceQueueType));

    (*queue)->front = -1;
    (*queue)->rear = -1;
}

void ShowQueue(SequenceQueue queue) {
    printf("items: ");

    for (int i = queue->front + 1; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    SequenceQueue *queue = (SequenceQueue *) malloc(sizeof(SequenceQueue));
    int *item = (int *) malloc(sizeof(int));

    InitQueue(queue);

    InQueue(queue, 1);
    printf("in: 1\n");
    ShowQueue(*queue);
    printf("length of queue: %d\n", LengthOfQueue(*queue));

    InQueue(queue, 2);
    printf("in: 2\n");
    ShowQueue(*queue);
    printf("length of queue: %d\n", LengthOfQueue(*queue));

    OutQueue(queue, item);
    printf("out: %d\n\n", *item);
    ShowQueue(*queue);
    printf("length of queue: %d\n", LengthOfQueue(*queue));

    OutQueue(queue, item);
    printf("out: %d\n\n", *item);
    ShowQueue(*queue);
    printf("length of queue: %d\n", LengthOfQueue(*queue));

    InQueue(queue, 3);
    printf("in: 3\n");
    ShowQueue(*queue);
    printf("length of queue: %d\n", LengthOfQueue(*queue));

    InQueue(queue, 4);
    printf("in: 4\n");
    ShowQueue(*queue);
    printf("length of queue: %d\n", LengthOfQueue(*queue));

    OutQueue(queue, item);
    printf("out: %d\n", *item);
    ShowQueue(*queue);
    printf("length of queue: %d\n", LengthOfQueue(*queue));

    OutQueue(queue, item);
    printf("out: %d\n", *item);
    ShowQueue(*queue);
    printf("length of queue: %d\n", LengthOfQueue(*queue));

    getchar();

}