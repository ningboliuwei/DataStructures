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

    while (treeNodesCount < leafNodeCount * 2 - 1) {
        int leftIndex = -1;
        int rightIndex = -1;

        for (int i = 0; i < treeNodesCount; i++) {
            if (treeNodes[i].parent == -1) {
                if (leftIndex == -1) {
                    leftIndex = i;
                }

                if (treeNodes[i].weight < treeNodes[leftIndex].weight) {
                    leftIndex = i;
                }
            }
        }

        for (int j = 0; j < treeNodesCount; j++) {
            if (treeNodes[j].parent == -1 && j != leftIndex) {
                if (rightIndex == -1) {
                    rightIndex = j;
                }

                if (treeNodes[j].weight < treeNodes[rightIndex].weight) {
                    rightIndex = j;
                }
            }
        }

        treeNodes[treeNodesCount].weight = treeNodes[leftIndex].weight + treeNodes[rightIndex].weight;
        treeNodes[treeNodesCount].leftChild = leftIndex;
        treeNodes[treeNodesCount].rightChild = rightIndex;
        treeNodes[treeNodesCount].parent = -1;
        treeNodes[leftIndex].parent = treeNodesCount;
        treeNodes[rightIndex].parent = treeNodesCount;
        treeNodesCount++;
    }
}

void ShowHuffmanTree(HTNode treeNodes[], int treeNodeCount) {
    for (int i = 0; i < treeNodeCount; i++) {
        printf("%d %d %d %d %d\n", i, treeNodes[i].leftChild, treeNodes[i].weight, treeNodes[i].rightChild, treeNodes[i].parent);
    }
}

int main() {
    int treeNodeCount = 0;
    CreateHuffmanTree(treeNodes, treeNodeCount);
    ShowHuffmanTree(treeNodes, treeNodeCount);

    getchar();
    getchar();
}