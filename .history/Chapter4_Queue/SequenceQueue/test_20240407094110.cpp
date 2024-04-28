////
//// Created by Liu Wei on 2018/9/19.
//// 此版本，front 不再指向队列中第一个元素，而是第一个元素的前一个
////
//
//
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10

typedef struct SequenceQueueType {
    int data[MAX_LENGTH];
    int front;
    int rear;
} * SequenceQueue;

// int IsEmptyQueue(SequenceQueue queue) {
//     if (queue->front == queue->rear) {
//         return 1;
//     }
//     return 0;
// }

// int LengthOfQueue(SequenceQueue queue) {
//     return queue->rear - queue->front;
// }

int InQueue(SequenceQueue *queue, int item) {
    (*queue)->data[++(*queue)->rear] = item;

    return 1;
}

int OutQueue(SequenceQueue *queue, int *item) {
    *item = (*queue)->data[++(*queue)->front];

    return 1;
}

int InitQueue(SequenceQueue *queue) {
    // 此处 sizeof 的参数要注意
    *queue = (SequenceQueue)malloc(sizeof(struct SequenceQueueType));

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
    SequenceQueue *queue = (SequenceQueue *)malloc(sizeof(SequenceQueue));
    int *item = (int *)malloc(sizeof(int));

    InitQueue(queue);
    InQueue(queue, 2);
    InQueue(queue, 5);
    InQueue(queue, 3);
    OutQueue(queue, item);

    getchar();
    getchar();
    getchar();
    getchar();
}