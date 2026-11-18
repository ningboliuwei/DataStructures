#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE_COUNT 15

typedef struct {
    int weight;
    int parent;
    int leftChild;
    int rightChild;
} HTNode, *HuffmanTree;

HTNode treeNodes[MAX_NODE_COUNT];

void CreateHuffmanTree(HTNode treeNodes[], int &treeNodeCount) {
    for (int i = 0; i < MAX_NODE_COUNT; i++) {
        treeNodes[i].weight = -1;
        treeNodes[i].leftChild = -1;
        treeNodes[i].rightChild = -1;
        treeNodes[i].weight = -1;
    }

    int leafNodeCount = 0;
    scanf("%d", &leafNodeCount);

    for (int i = 0; i < leafNodeCount; i++) {
        int weight;
        scanf("%d", &weight);
        treeNodes[i].weight = weight;
        treeNodeCount++;
    }

    while (treeNodeCount < leafNodeCount * 2 - 1) {
        int leftIndex = -1;
        int rightIndex = -1;

        for (int i = 0; i < treeNodeCount; i++) {
            if (treeNodes[i].parent != -1) {
                if (leftIndex == -1) {
                    leftIndex = i;
                }

                if (treeNodes[i].weight < treeNodes[leftIndex].weight) {
                    leftIndex = i;
                }
            }
        }

        for (int j = 0; j < treeNodeCount; j++) {
            if (treeNodes[j].parent != -1 && j != leftIndex) {
                if (rightIndex == -1) {
                    rightIndex = j;
                }

                if (treeNodes[j].weight < treeNodes[rightIndex].weight) {
                    rightIndex = j;
                }
            }
        }

        treeNodes[treeNodeCount].weight = treeNodes[leftIndex].weight + treeNodes[rightIndex].weight;
        treeNodes[treeNodeCount].leftChild = leftIndex;
        treeNodes[treeNodeCount].rightChild = rightIndex;
        treeNodes[leftIndex].parent = treeNodeCount;
        treeNodes[rightIndex].parent = treeNodeCount;
        treeNodeCount++;
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