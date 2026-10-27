#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
typedef int datatype;
typedef struct QNode {
    datatype data;
    struct QNode *next;
} QNode;

typedef struct qptr {
    QNode *front; //队头指针
    QNode *rear;  //队尾指针
} LinkQueue;

void InitQueue(LinkQueue *&Q) {
    //@@1
    //@@1
}
int QueueEmpty(LinkQueue *Q) {
    //@@2
    //@@2
}

int InQueue(LinkQueue *Q, datatype x) {
    //@@3
    //@@3
}

int OutQueue(LinkQueue *Q, datatype &x) {
    //@@4
    //@@4
}

int main() {
    LinkQueue *Q;
    //@@5
    //@@5
}