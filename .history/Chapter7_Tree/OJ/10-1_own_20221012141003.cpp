//
// Created by Liu Wei on 2018/10/30.
// 1641 问题 A: 【数据结构7-11】哈夫曼树
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

#define MAX_NODE_COUNT 10

typedef struct {
    int weight;                 //权值
    int parent, lchild, rchild; //双亲及左右孩子的下标

} HTNode, *HuffmanTree;

void CreateHuffmanTree() {
    int nodeCount = 0;
    int weights[MAX_NODE_COUNT];
    scanf("%d", &nodeCount);

    for (int i = 0; i < nodeCount; i++) {
        scanf("%d", &weights[i]);
    }

    int mostMinWeight = -1;
    int secondMinWeight = -1;

    for (int i = 0; i < nodeCount; i++) {}
}

int main() {
    CreateHuffmanTree();
}
