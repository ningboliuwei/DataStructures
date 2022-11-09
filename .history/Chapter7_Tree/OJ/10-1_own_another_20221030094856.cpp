//
// Created by Liu Wei on 2018/10/30.
// 1641 问题 A: 【数据结构7-11】哈夫曼树
// OJ PASSED
// 测试数据
// 输入：7 4 5 7 8 6 12 18
// 输出：0 -1 4 -1 7
// 1 -1 5 -1 7
// 2 -1 7 -1 8
// 3 -1 8 -1 9
// 4 -1 6 -1 8
// 5 -1 12 -1 10
// 6 -1 18 -1 11
// 7 0 9 1 9
// 8 4 13 2 10
// 9 3 17 7 11
// 10 5 25 8 12
// 11 9 35 6 12
// 12 10 60 11 -1

// 输入：5 2 4 2 3 3
// 输出：0 -1 2 -1 5
// 1 -1 4 -1 7
// 2 -1 2 -1 5
// 3 -1 3 -1 6
// 4 -1 3 -1 6
// 5 0 4 2 7
// 6 3 6 4 8
// 7 1 8 5 8
// 8 6 14 7 -1
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE_COUNT 100
// 线性表，用于保存所有的权值
typedef struct {
    int data[MAX_NODE_COUNT];
    int last;
} SeqList;

typedef struct {
    int weight;
    int parent;
    int leftChild;
    int rightChild;

} HTNode, *HuffmanTree;
HTNode treeNodes[MAX_NODE_COUNT];

void CreateHuffmanTree(HTNode treeNodes[], int &treeNodeCount) {
    for (int i = 0; i < MAX_NODE_COUNT; i++) {
        treeNodes[i].leftChild = -1;
        treeNodes[i].rightChild = -1;
        treeNodes[i].parent = -1;
    }
    // 输入的结点数
    int leafNodeCount = 0;

    scanf("%d", &leafNodeCount);

    for (int i = 0; i < leafNodeCount; i++) {
        int weight;
        scanf("%d", &weight);
        // 将所有的结点权值放入结点列表
        treeNodes[i].weight = weight;
        // 结点列表中的结点数
        treeNodeCount++;
    }

    while (treeNodeCount <= leafNodeCount * 2 - 1) {
        // 左结点的下标
        int leftIndex = -1;
        // 右结点的下标
        int rightIndex = -1;
        // 找到最小的那个结点作为左孩子
        for (int i = 0; i < treeNodeCount; i++) {
            if (treeNodes[i].parent != -1) {
                // 记录第一个没有父节点的结点的下标
                if (leftIndex == -1) {
                    leftIndex = i;
                }

                if (treeNodes[i].weight < treeNodes[leftIndex].weight) {
                    leftIndex = i;
                }
            }
        }
        // 跳过找到的最小的那个，然后找到次小的那个，作为右孩子
        for (int j = 0; j < treeNodeCount; j++) {
            if (treeNodes[j].parent != -1 && j != leftIndex) {
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
        printf("%d %d %d %d %d\n", i, treeNodes[i].leftChild, treeNodes[i].weight, treeNodes[i].rightChild,
               treeNodes[i].parent);
    }
}

int main() {
    int treeNodeCount = 0;
    CreateHuffmanTree(treeNodes, treeNodeCount);
    ShowHuffmanTree(treeNodes, treeNodeCount);
    getchar();
    getchar();
}
