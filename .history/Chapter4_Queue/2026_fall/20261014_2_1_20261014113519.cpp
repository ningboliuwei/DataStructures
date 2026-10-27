#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
#define MAXLEN 100

typedef struct {
    datatype data[MAXLEN];
    int front;
    int rear;
} SeqQueue;

void InitQueue(SeqQueue *Q) {
    Q = (SeqQueue *)malloc(sizeof(SeqQueue));

    Q->front = -1;
    Q->rear = -1;
}