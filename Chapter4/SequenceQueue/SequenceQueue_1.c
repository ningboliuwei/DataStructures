//
// Created by Liu Wei on 2018/9/15.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10

typedef struct {
    int data[MAX_LENGTH];
    int front;
    int rear;
} *SequenceQueue;

int IsEmptyQueue(SequenceQueue *queue) {
    if (queue->front == -1 && queue->rear == -1) {
        return 1;
    }
    return 0;
}

int LengthOfQueue(SequenceQueue *queue) {
    if (IsEmptyQueue(queue)) {
        return 0;
    } else {
        return queue->rear - queue->front + 1;
    }
}

int InQueue(SequenceQueue *queue, int item) {
    if ()

    if (IsEmptyQueue(queue)) {
        queue->front = 0;
    }

    queue->rear++;
    queue->data[queue->rear] = item;

    return 1;
}

int OutQueue(SequenceQueue *queue,

*
int item
){

}

int InitQueue(SequenceQueue *queue) {
    queue->front = -1;
    queue->tail = -1;
}

int main() {
    SequenceQueue *queue = (SequenceQueue *) malloc(sizeof(SequenceQueue));
    InitQueue(queue);


}