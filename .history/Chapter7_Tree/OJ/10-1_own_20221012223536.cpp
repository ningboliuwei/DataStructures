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
HTNode treeNodes[100];

// 创建线性表
SeqList *CreateList() {
    SeqList *list = new SeqList;
    list->last = -1;

    return list;
}
// 线性表插入
int InsList_Seq(SeqList *&list, int i, int x) {
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

void CreateHuffmanTree(HTNode treeNodes[]) {
    int nodeCount = 0;
    // 创建一个用于放置所有权值的线性表
    SeqList *weightList = CreateList();

    scanf("%d", &nodeCount);

    for (int i = 0; i < nodeCount; i++) {
        int weight;
        scanf("%d", &weight);
        InsList_Seq(weightList, weightList->last + 1, weight);
    }

    int treeNodeCount = 0;
    while (weightList->last != -1) {
        int mostMinWeight = weightList->data[0];
        int mostMinWeightIndex = 0;
        // 得到当前权值中最小的那个
        for (int i = 1; i < LengthSeqList(weightList); i++) {
            if (weightList->data[i] < mostMinWeight) {
                mostMinWeight = weightList->data[i];
                mostMinWeightIndex = i;
            }
        }
        // 将当前权重最小的结点放入结点列表
        treeNodes[treeNodeCount].weight = mostMinWeight;
        printf("%d ", mostMinWeight);
        // 记录下权重最小结点的位置
        int pos1 = treeNodeCount;
        treeNodeCount++;

        // 从权值列表中删除这个最小的权值
        DelSeqList(weightList, mostMinWeightIndex + 1);
        // 得到当前权值中次小的那个
        int secondMinWeight = weightList->data[0];
        int secondMinWeightIndex = 0;

        for (int i = 1; i < LengthSeqList(weightList); i++) {
            if (weightList->data[i] < secondMinWeight) {
                secondMinWeight = weightList->data[i];
                secondMinWeightIndex = i;
            }
        }
        printf("%d ", secondMinWeight);
        // 从权值列表中删除这个最小的权值
        DelSeqList(weightList, secondMinWeightIndex + 1);
        // 将当前权重次小的结点放入结点列表
        treeNodes[treeNodeCount].weight = secondMinWeight;
        // 记录下权重次小结点的位置
        int pos2 = treeNodeCount;
        treeNodeCount++;
        // 得到两个结点权重之和
        treeNodes[treeNodeCount].weight = mostMinWeight + secondMinWeight;
        // 左孩子为权重最小结点
        treeNodes[treeNodeCount].leftChild = pos1;
        // 右孩子为权重次小结点
        treeNodes[treeNodeCount].rightChild = pos2;
        // 权重最小结点和次小结点的父节点为当前结点
        treeNodes[pos1].parent = treeNodeCount;
        treeNodes[pos2].parent = treeNodeCount;
        // 将两个结点的权重之和加到权重列表中
        InsList_Seq(weightList, weightList->last + 1, mostMinWeight + secondMinWeight);
    }
    printf("%d", treeNodeCount);
}

int main() {
    CreateHuffmanTree(treeNodes);
}
