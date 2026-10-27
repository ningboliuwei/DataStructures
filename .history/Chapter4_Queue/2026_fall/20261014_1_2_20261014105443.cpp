
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
#define MAXLEN 100

typedef struct {
    datatype data[MAXLEN];
    int front;
    int rear;
} SeqQueue;
