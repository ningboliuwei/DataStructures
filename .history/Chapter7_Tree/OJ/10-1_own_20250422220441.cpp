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

// 哈夫曼树节点结构
typedef struct {
    int weight; // 节点权值
    int parent; // 父节点下标（-1表示无父节点）
    int lchild; // 左子节点下标（-1表示无左子）
    int rchild; // 右子节点下标（-1表示无右子）
} HTNode, *HuffmanTree;

void CreateHuffmanTree() {
    int n;
    scanf("%d", &n);            // 读取叶子节点数量
    int totalNodes = 2 * n - 1; // 哈夫曼树总节点数

    // 动态分配哈夫曼树数组空间
    HuffmanTree HT = (HuffmanTree)malloc(totalNodes * sizeof(HTNode));

    // 初始化所有叶子节点
    for (int i = 0; i < n; i++) {
        scanf("%d", &HT[i].weight); // 读取权值
        HT[i].parent = -1;          // 初始时无父节点
        HT[i].lchild = -1;          // 叶子节点无左子
        HT[i].rchild = -1;          // 叶子节点无右子
    }

    // 构建哈夫曼树：生成非叶子节点
    for (int i = n; i < totalNodes; i++) {
        int min1 = -1, min2 = -1; // 最小和次小权值的节点下标

        // 寻找当前权值最小且未被合并的节点（min1）
        for (int j = 0; j < i; j++) {
            if (HT[j].parent == -1) { // 只处理未合并的节点
                if (min1 == -1 || HT[j].weight < HT[min1].weight
                    || (HT[j].weight == HT[min1].weight && j < min1)) { // 权值相同取下标小者
                    min1 = j;
                }
            }
        }

        // 寻找次小权值且未被合并的节点（min2）
        for (int j = 0; j < i; j++) {
            if (HT[j].parent == -1 && j != min1) { // 排除min1节点
                if (min2 == -1 || HT[j].weight < HT[min2].weight
                    || (HT[j].weight == HT[min2].weight && j < min2)) { // 权值相同取下标小者
                    min2 = j;
                }
            }
        }

        // 创建新父节点，并更新关联关系
        HT[i].weight = HT[min1].weight + HT[min2].weight; // 新节点权值为子节点和
        HT[i].lchild = min1;                              // 较小权值放左（因min1是遍历后最小的）
        HT[i].rchild = min2;                              // 较大权值放右
        HT[i].parent = -1;                                // 新节点暂时无父节点
        HT[min1].parent = i;                              // 更新min1的父节点
        HT[min2].parent = i;                              // 更新min2的父节点
    }

    // 输出哈夫曼树的顺序存储结构
    for (int i = 0; i < totalNodes; i++) {
        printf("%d %d %d %d %d\n",
               i,            // 节点序号
               HT[i].lchild, // 左子下标
               HT[i].weight, // 节点权值
               HT[i].rchild, // 右子下标
               HT[i].parent  // 父节点下标
        );
    }

    free(HT); // 释放动态分配的内存
}

int main() {
    CreateHuffmanTree(); // 程序入口
    return 0;
}
