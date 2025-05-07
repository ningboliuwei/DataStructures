//
// Created by Liu Wei on 2018/10/30.
// 1641 问题 A: 【数据结构7-11】哈夫曼树
// OJ PASSED
// 测试数据
// 输入：7 4 5 7 8 6 12 18
// 输出
// 0 - 1 4 - 1 7
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
// 输出
// 0 -1 2 - 1 5
// 1 -1 4 -1 7
// 2 -1 2 -1 5
// 3 -1 3 -1 6
// 4 -1 3 -1 6
// 5 0 4 2 7
// 6 3 6 4 8
// 7 1 8 5 8
// 8 6 14 7 -1
#include <stdio.h>  // 标准输入输出库
#include <stdlib.h> // 标准库函数

#define MAX_NODE_COUNT 100 // 定义最大节点数

typedef struct {
    int weight;     // 节点权重
    int parent;     // 父节点索引
    int leftChild;  // 左子节点索引
    int rightChild; // 右子节点索引

} HTNode, *HuffmanTree;
HTNode treeNodes[MAX_NODE_COUNT]; // 全局数组存储哈夫曼树节点

void CreateHuffmanTree(HTNode treeNodes[], int &treeNodeCount) {
    for (int i = 0; i < MAX_NODE_COUNT; i++) {
        treeNodes[i].leftChild = -1;  // 初始化左子节点
        treeNodes[i].rightChild = -1; // 初始化右子节点
        treeNodes[i].parent = -1;     // 初始化父节点
    }
    int nodeCount = 0; // 初始节点数量

    scanf("%d", &nodeCount); // 读取节点数量

    for (int i = 0; i < nodeCount; i++) {
        int weight;
        scanf("%d", &weight);
        // 将所有的结点权值放入结点列表
        treeNodes[i].weight = weight; // 设置节点权重
        treeNodeCount++;              // 增加节点计数
    }

    // 循环直到只剩一个未使用的节点
    while (true) {
        // 计算未使用节点的数量（parent == -1）
        int unusedCount = 0;
        for (int i = 0; i < treeNodeCount; i++) {
            if (treeNodes[i].parent == -1) {
                unusedCount++;
            }
        }

        if (unusedCount < 2) {
            break; // 如果剩余未使用节点少于2个，退出循环
        }

        // 寻找最小权重的未使用节点
        int mostMinWeight = -1;
        int mostMinWeightNodeIndex = -1;

        for (int i = 0; i < treeNodeCount; i++) {
            // 检查节点是否未被使用（parent == -1）
            if (treeNodes[i].parent == -1) {
                if (mostMinWeight == -1 || treeNodes[i].weight < mostMinWeight) {
                    mostMinWeight = treeNodes[i].weight;
                    mostMinWeightNodeIndex = i;
                }
            }
        }

        // 寻找次小权重的未使用节点
        int secondMinWeight = -1;
        int secondMinWeightIndex = -1;

        for (int i = 0; i < treeNodeCount; i++) {
            if (treeNodes[i].parent == -1 && i != mostMinWeightNodeIndex) {
                if (secondMinWeight == -1 || treeNodes[i].weight < secondMinWeight) {
                    secondMinWeight = treeNodes[i].weight;
                    secondMinWeightIndex = i;
                }
            }
        }

        // 创建新节点
        treeNodes[treeNodeCount].weight = mostMinWeight + secondMinWeight;
        treeNodes[treeNodeCount].leftChild = mostMinWeightNodeIndex;
        treeNodes[treeNodeCount].rightChild = secondMinWeightIndex;

        // 将子节点的父指针指向新节点
        treeNodes[mostMinWeightNodeIndex].parent = treeNodeCount;
        treeNodes[secondMinWeightIndex].parent = treeNodeCount;

        treeNodeCount++; // 总节点数增加
    }
}

void ShowHuffmanTree(HTNode treeNodes[], int treeNodeCount) {
    for (int i = 0; i < treeNodeCount; i++) {
        printf("%d %d %d %d %d\n", i, treeNodes[i].leftChild, treeNodes[i].weight, treeNodes[i].rightChild, treeNodes[i].parent); // 打印节点信息
    }
}

int main() {
    int treeNodeCount = 0;                       // 初始化节点计数
    CreateHuffmanTree(treeNodes, treeNodeCount); // 创建哈夫曼树
    ShowHuffmanTree(treeNodes, treeNodeCount);   // 显示哈夫曼树
    getchar();                                   // 等待用户输入
    getchar();                                   // 再次等待输入，防止程序立即退出
}
