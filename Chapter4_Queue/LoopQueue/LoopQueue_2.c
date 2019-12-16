//
// Created by Liu Wei on 2018/9/19.
// front 同样也放元素的版本（会导致无法判断是队空还是队满）

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 7

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
    int length = (queue->rear + MAX_LENGTH - queue->front) % MAX_LENGTH;

    return length;
}

int InQueue(LoopQueue *queue, int item) {
    // 队列已满
    if ((*queue)->front == ((*queue)->rear + 1) % MAX_LENGTH) {
        return 0;
    }

    (*queue)->rear = ((*queue)->rear + 1) % MAX_LENGTH;
    (*queue)->data[(*queue)->rear] = item;

    return 1;
}

int OutQueue(LoopQueue *queue, int *item) {
    if (IsEmptyQueue(*queue)) {
        return 0;
    }

    (*queue)->front = ((*queue)->front + 1) % MAX_LENGTH;
    *item = (*queue)->data[(*queue)->front];

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

    int start = queue->front + 1;
    int length = LengthOfQueue(queue);

    for (int i = start; i < start + length; i++) {
        printf("%d ", queue->data[i % MAX_LENGTH]);
    }
    printf("\n");
}

void ShowLength(LoopQueue queue) {
    printf("length of queue: %d\n", LengthOfQueue(queue));
    printf("-----------------\n");
}

int main() {
    LoopQueue *queue = (LoopQueue *) malloc(sizeof(LoopQueue));
    int *item = (int *) malloc(sizeof(int));

    InitQueue(queue);

    ShowQueue(*queue);
    ShowLength(*queue);

    InQueue(queue, 1);
    printf("in: 1\n");
    ShowQueue(*queue);
    ShowLength(*queue);

    InQueue(queue, 2);
    printf("in: 2\n");
    ShowQueue(*queue);
    ShowLength(*queue);

    OutQueue(queue, item);
    printf("out: %d\n", *item);
    ShowQueue(*queue);
    ShowLength(*queue);

    OutQueue(queue, item);
    printf("out: %d\n", *item);
    ShowQueue(*queue);
    ShowLength(*queue);

    InQueue(queue, 3);
    printf("in: 3\n");
    ShowQueue(*queue);
    ShowLength(*queue);

    InQueue(queue, 4);
    printf("in: 4\n");
    ShowQueue(*queue);
    ShowLength(*queue);

    OutQueue(queue, item);
    printf("out: %d\n", *item);
    ShowQueue(*queue);
    ShowLength(*queue);


    OutQueue(queue, item);
    printf("out: %d\n", *item);
    ShowQueue(*queue);
    ShowLength(*queue);

    for (int i = 0; i < 5; i++) {
        int newItem = i + 5;
        InQueue(queue, newItem);
        printf("in: %d\n", newItem);
        ShowQueue(*queue);
        ShowLength(*queue);
    }

    InQueue(queue, 10);
    printf("in: 10\n");
    ShowQueue(*queue);
    ShowLength(*queue);

    for (int i = 0; i < 4; i++) {
        OutQueue(queue, item);
        printf("out: %d\n", *item);
        ShowQueue(*queue);
        ShowLength(*queue);
    }

    for (int i = 0; i < 4; i++) {
        int newItem = i + 11;
        InQueue(queue, newItem);
        printf("in: %d\n", newItem);
        ShowQueue(*queue);
        ShowLength(*queue);
    }

    int count = LengthOfQueue(*queue);

    for (int i = 0; i < count; i++) {
        OutQueue(queue, item);
        printf("out: %d\n", *item);
        ShowQueue(*queue);
        ShowLength(*queue);
    }

    getchar();

}