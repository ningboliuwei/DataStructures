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
    char *code;

} HTNode, *HuffmanTree;

typedef struct {
    char text;
    int code[];
} textCode;

HTNode treeNodes[MAX_NODE_COUNT];

void CreateHuffmanTree(HTNode treeNodes[], int &treeNodeCount, int &leafNodeCount) {
    for (int i = 0; i < MAX_NODE_COUNT; i++) {
        treeNodes[i].leftChild = -1;
        treeNodes[i].rightChild = -1;
        treeNodes[i].parent = -1;
    }
    // 输入的结点数

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

void Encode(HTNode treeNodes[], int index, char text, int treeNodeCount) {
    for (int i = 0; i < treeNodeCount; i++) {
        if (treeNodes[i].text == text) {
            index = i;
            break;
        }
    }

    int depth = floor(log(treeNodeCount) / log(2));

    while (treeNodes[index].parent != -1) {
        treeNodes[index].code = (char *)malloc(sizeof(char) * depth);

        int originalIndex = index;
        index = treeNodes[index].parent;
        if (treeNodes[index].leftChild == originalIndex) {
            printf("0");
        } else if (treeNodes[index].rightChild == originalIndex) {
            printf("1");
        }
    }
    // 上面要把他们都倒过来
    printf("\n");
}

void ShowCoding(HTNode treeNodes[], int treeNodeCount, textCode textCodeList[]) {
    for (int i = 0; i < 7; i++) {
        Encode(treeNodes, 0, treeNodes[i].text, treeNodeCount);
    }
}

int main() {
    int treeNodeCount = 0;
    int leafNodeCount = 0;
    HTNode treeNodes[MAX_NODE_COUNT];
    textCode textCodeList[MAX_NODE_COUNT];

    CreateHuffmanTree(treeNodes, treeNodeCount, leafNodeCount);
    ShowHuffmanTree(treeNodes, treeNodeCount);
    ShowCoding(treeNodes, treeNodeCount, textCodeList);
    getchar();
    getchar();
}
