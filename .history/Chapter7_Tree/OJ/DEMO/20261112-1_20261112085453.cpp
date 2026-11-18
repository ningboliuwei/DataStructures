#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE_COUNT 100

typedef struct {
    int weight;
    int parent;
    int leftChild;
    int rightChild;
} HTNode, *HuffmanTree;

HTNode treeNodes[MAX_NODE_COUNT];

void CreateHuffmanTree(HTNode treeNodes[], int &treeNodesCount) {
    for (int i = 0; i < MAX_NODE_COUNT; i++) {
        treeNodes[i].leftChild = -1;
        treeNodes[i].rightChild = -1;
        treeNodes[i].parent = -1;
    }

    int leafNodeCount = 0;
    scanf("%d", &leafNodeCount);

    for (int i = 0; i < leafNodeCount; i++) {
        int weight;
        scanf("%d", &weight);

        treeNodes[i].weight = weight;
        treeNodesCount++;
    }
}