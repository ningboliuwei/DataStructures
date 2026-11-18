#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int parent;
    int leftChild;
    int rightChild;
} HTNode, *HuffmanTree;
