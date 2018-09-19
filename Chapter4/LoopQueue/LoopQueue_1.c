//
// Created by Liu Wei on 2018/9/19.
//

//
// Created by Liu Wei on 2018/9/15.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10

typedef struct LoopQueueType {
    int data[MAX_LENGTH];
    int front;
    int rear;
} *LoopQueue;

int IsEmptyQueue(LoopQueue queue) {
    if (queue->front == queue->rear) {
        return 1;
    }

    return 0;
}

int LengthOfQueue(LoopQueue queue) {
    int length = (queue->rear - queue->front + MAX_LENGTH) % MAX_LENGTH;

    return length;
}

int InQueue(LoopQueue *queue, int item) {
    // 队列已满
    if ((*queue)->front == (*queue)->rear + 1) {
        return 0;
    }

    (*queue)->rear++;
    (*queue)->data[(*queue)->rear] = item;

    return 1;
}

int OutQueue(LoopQueue *queue, int *item) {
    if (IsEmptyQueue(*queue)) {
        return 0;
    }

    *item = (*queue)->data[(*queue)->front];
    (*queue)->front++;

    return 1;
}

int InitQueue(LoopQueue *queue) {
    // 此处 sizeof 的参数要注意
    *queue = (LoopQueue) malloc(sizeof(struct LoopQueueType));

    (*queue)->front = -1;
    (*queue)->rear = -1;
}

void ShowQueue(LoopQueue queue) {
    printf("items: ");

    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    LoopQueue *queue = (LoopQueue *) malloc(sizeof(LoopQueue));
    InitQueue(queue);

    InQueue(queue, 1);
    InQueue(queue, 2);
    InQueue(queue, 3);
    InQueue(queue, 4);

    ShowQueue(*queue);
    int *item = (int *) malloc(sizeof(int));

    OutQueue(queue, item);
    printf("out: %d\n", *item);
    ShowQueue(*queue);

    OutQueue(queue, item);
    printf("out: %d\n", *item);
    ShowQueue(*queue);

    printf("length of queue: %d", LengthOfQueue(*queue));

    getchar();

}