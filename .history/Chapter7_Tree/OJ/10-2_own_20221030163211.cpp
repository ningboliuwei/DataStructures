//
// Created by Liu Wei on 2018/10/30.
// 1641 问题 A: 【数据结构7-12】哈夫编码
// OJ ？
// 测试数据
// 输入：
// 7
// 4
// 5
// 7
// 8
// 6
// 12
// 18
// ABCDEFG
// 00001101110010100100101
// 输出：
// A 4 1010
// B 5 1011
// C 7 011
// D 8 100
// E 6 010
// F 12 00
// G 18 11
// 101010110111000100011
// FFGCDAEE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODE_COUNT 100
// 线性表，用于保存所有的权值
typedef struct {
    int data[MAX_NODE_COUNT];
    int last;
} SeqList;

typedef struct {
    int weight;
    int parent;
    char text;
    int leftChild;
    int rightChild;

} HTNode, *HuffmanTree;

typedef struct {
    char text;
    int code[];
} textCode;

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

    char *s = (char *)malloc(sizeof(char) * leafNodeCount);
    scanf("%s", s);

    for (int i = 0; i < leafNodeCount; i++) {
        treeNodes[i].text = s[i];
    }

    while (treeNodeCount < leafNodeCount * 2 - 1) {
        // 左结点的下标
        int leftIndex = -1;
        // 右结点的下标
        int rightIndex = -1;
        // 找到最小的那个结点作为左孩子
        for (int i = 0; i < treeNodeCount; i++) {
            if (treeNodes[i].parent == -1) {
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
            if (treeNodes[j].parent == -1 && j != leftIndex) {
                if (rightIndex == -1) {
                    rightIndex = j;
                }

                if (treeNodes[j].weight < treeNodes[rightIndex].weight) {
                    rightIndex = j;
                }
            }
        }
        // 建立新的结点，以及建立与现有左右孩子结点直接的关系
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

void Encoding(HTNode treeNodes[], int treeNodeCount, textCode textCodeList[]) {
    int depth = floor(log(treeNodeCount) / log(2));

    for (int i = 0; i < treeNodeCount; i++) {
        int currentNodeIndex = i;
        int pos = 0;

        while (treeNodes[currentNodeIndex].parent != -1) {
            if (treeNodes[currentNodeIndex].leftChild == currentNodeIndex) {
                textCodeList[i].code[pos] = 0;
            }

            if (treeNodes[currentNodeIndex].rightChild == currentNodeIndex) {
                textCodeList[i].code[pos] = 1;
            }
        }

        pos++;
        currentNodeIndex = treeNodes[currentNodeIndex].parent;
    }

    for (int i = 0; i < treeNodeCount; i++) {
        for (int j = depth; j >= 0; j--) {
            printf("%d", textCodeList[i].code[j]);
        }
        printf("\n");
    }
}

int main() {
    int treeNodeCount = 0;
    HTNode treeNodes[MAX_NODE_COUNT];
    textCode textCodeList[MAX_NODE_COUNT];

    CreateHuffmanTree(treeNodes, treeNodeCount);
    ShowHuffmanTree(treeNodes, treeNodeCount);
    Encoding(treeNodes, treeNodeCount, textCodeList);
    getchar();
    getchar();
}
