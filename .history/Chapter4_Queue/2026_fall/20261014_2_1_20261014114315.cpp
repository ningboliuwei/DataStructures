#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
#define MAXLEN 10

typedef struct {
    datatype data[MAXLEN];
    int front;
    int rear;
} SeqQueue;

void InitQueue(SeqQueue *&Q) {
    Q = (SeqQueue *)malloc(sizeof(SeqQueue));

    Q->front = -1;
    Q->rear = -1;
}

int InQueue(SeqQueue *Q, datatype x) {
    // Q->rear++;
    // Q->data[Q->rear] = x;
    Q->data[++Q->rear] = x;
}

int OutQueue(SeqQueue *Q, datatype &x) {
    // Q->front++;
    // x = Q->data[Q->front];
    x = Q->data[Q->front++];
}

int main() {
    SeqQueue *queue;
    InitQueue(queue);

    InQueue(queue, 3);
    InQueue(queue, 4);
    InQueue(queue, 5);

    int x;
    OutQueue(queue, x);
    OutQueue(queue, x);
    OutQueue(queue, x);
}