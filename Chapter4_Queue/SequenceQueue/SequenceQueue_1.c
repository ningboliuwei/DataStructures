//
// Created by Liu Wei on 2018/9/15.
// 此版本有缺陷，如：若进一个元素，又出一个元素，然后判断是否是空队列？
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
    }

    return queue->rear - queue->front + 1;
}

int InQueue(SequenceQueue *queue, int item) {
    if ((*queue)->rear == MAX_LENGTH - 1) {
        return 0;
    }

    if (IsEmptyQueue(*queue)) {
        (*queue)->front = 0;
    }

    (*queue)->rear++;
    (*queue)->data[(*queue)->rear] = item;

    return 1;
}

int OutQueue(SequenceQueue *queue, int *item) {
    if (IsEmptyQueue(*queue)) {
        return 0;
    }

    *item = (*queue)->data[(*queue)->front];
    (*queue)->front++;

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