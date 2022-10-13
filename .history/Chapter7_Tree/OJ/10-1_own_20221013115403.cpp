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
#define MAX_LENGTH 100
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
HTNode treeNodes[MAX_LENGTH];

// 创建线性表
SeqList *CreateList() {
    SeqList *list = new SeqList;
    list->last = -1;

    return list;
}
// 线性表插入
int InsListSeq(SeqList *&list, int i, int x) {
    int index = 0;

    if (list->last == MAX_NODE_COUNT - 1) {
        return 0;
    }

    if (i < 0 || i > list->last + 1) {
        return 0;
    }

    for (index = list->last + 1; index >= i; index--) {
        list->data[index] = list->data[index - 1];
    }

    list->data[i] = x;
    list->last++;

    return 1;
}
// 线性表删除
int DelSeqList(SeqList *&list, int i) {
    int index = 0;

    if (list->last == -1) {
        return 0;
    }
    if (i < 1 || i > list->last + 2) {
        return 0;
    }

    for (index = i - 1; index < list->last; index++) {
        list->data[index] = list->data[index + 1];
    }

    list->last--;

    return 1;
}
// 线性表长度
int LengthSeqList(SeqList *list) {
    return list->last + 1;
}
// 线性表查找
int SearchListSeq(SeqList *list, int x) {
    for (int i = 0; i <= list->last; i++) {
        if (list->data[i] == x) {
            return i;
        }
    }
    return -1;
}

void CreateHuffmanTree(HTNode treeNodes[], int &treeNodeCount) {
    for (int i = 0; i < MAX_LENGTH; i++) {
        treeNodes[i].leftChild = -1;
        treeNodes[i].rightChild = -1;
        treeNodes[i].parent = -1;
    }
    int nodeCount = 0;
    // “用过的”结点下标列表
    SeqList *usedNodeIndexList = CreateList();

    scanf("%d", &nodeCount);

    for (int i = 0; i < nodeCount; i++) {
        int weight;
        scanf("%d", &weight);
        // 将所有的结点权值放入结点列表
        treeNodes[i].weight = weight;
        treeNodeCount++;
    }

    // 在权值列表仍有至少 2 个结点的时候，不断找最小和次小权重的结点
    while (LengthSeqList(usedNodeIndexList) < treeNodeCount - 1) {
        int startPos = 0;

        for (startPos = 0; startPos < treeNodeCount; startPos++) {
            if (SearchListSeq(usedNodeIndexList, startPos) != -1) {
                break;
            }
        }

        int mostMinWeight = treeNodes[startPos].weight;
        int mostMinWeightNodeIndex = startPos;
        // 得到当前权值中最小的那个
        for (int i = 0; i < treeNodeCount; i++) {
            // 当前的结点下标不在“用过”的下标列表中
            if (SearchListSeq(usedNodeIndexList, i) != -1) {
                if (treeNodes[i].weight < mostMinWeight) {
                    mostMinWeight = treeNodes[i].weight;
                    mostMinWeightNodeIndex = i;
                }
            }
        }
        // 将节点下标加入“用过的结点下标列表
        InsListSeq(usedNodeIndexList, LengthSeqList(usedNodeIndexList), mostMinWeightNodeIndex);

        // 得到当前权值中次小的那个
        for (startPos = 0; startPos < treeNodeCount; startPos++) {
            if (SearchListSeq(usedNodeIndexList, startPos) != -1) {
                break;
            }
        }

        int secondMinWeight = treeNodes[0].weight;
        int secondMinWeightIndex = 0;

        for (int i = 0; i < treeNodeCount; i++) {
            if (SearchListSeq(usedNodeIndexList, i) != -1) {
                if (treeNodes[i].weight < secondMinWeight) {
                    secondMinWeight = treeNodes[i].weight;
                    secondMinWeightIndex = i;
                }
            }
        }

        InsListSeq(usedNodeIndexList, LengthSeqList(usedNodeIndexList), secondMinWeightIndex);
        // 得到两个结点权重之和
        treeNodes[treeNodeCount].weight = mostMinWeight + secondMinWeight;
        // 左孩子为权重最小结点
        treeNodes[treeNodeCount].leftChild = mostMinWeightNodeIndex;
        // 右孩子为权重次小结点
        treeNodes[treeNodeCount].rightChild = secondMinWeightIndex;
        // 权重最小结点和次小结点的父节点为当前结点
        treeNodes[mostMinWeightNodeIndex].parent = treeNodeCount;
        treeNodes[secondMinWeightIndex].parent = treeNodeCount;
        // 总结点数 +1
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
