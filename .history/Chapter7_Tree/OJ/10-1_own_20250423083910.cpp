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
// 线性表，用于保存所有的权值
typedef struct {
    int data[MAX_NODE_COUNT]; // 存储数据的数组
    int last;                 // 最后一个元素的下标
} SeqList;

typedef struct {
    int weight;     // 节点权重
    int parent;     // 父节点索引
    int leftChild;  // 左子节点索引
    int rightChild; // 右子节点索引

} HTNode, *HuffmanTree;
HTNode treeNodes[MAX_NODE_COUNT]; // 全局数组存储哈夫曼树节点

// 创建线性表
SeqList *CreateList() {
    SeqList *list = new SeqList; // 分配内存
    list->last = -1;             // 初始化为空表

    return list;
}
// 线性表插入
int InsListSeq(SeqList *&list, int i, int x) {
    int index = 0;

    if (list->last == MAX_NODE_COUNT - 1) {
        return 0; // 表已满，插入失败
    }

    if (i < 0 || i > list->last + 1) {
        return 0; // 位置无效，插入失败
    }

    for (index = list->last + 1; index >= i; index--) {
        list->data[index] = list->data[index - 1]; // 元素后移
    }

    list->data[i] = x; // 插入元素
    list->last++;      // 更新表长度

    return 1; // 插入成功
}
// 线性表长度
int LengthSeqList(SeqList *list) {
    return list->last + 1; // 返回线性表长度
}
// 线性表查找
int SearchListSeq(SeqList *list, int value) {
    for (int i = 0; i <= list->last; i++) {
        if (list->data[i] == value) {
            return i; // 返回找到元素的位置
        }
    }
    return -1; // 未找到元素
}

void CreateHuffmanTree(HTNode treeNodes[], int &treeNodeCount) {
    for (int i = 0; i < MAX_NODE_COUNT; i++) {
        treeNodes[i].leftChild = -1;  // 初始化左子节点
        treeNodes[i].rightChild = -1; // 初始化右子节点
        treeNodes[i].parent = -1;     // 初始化父节点
    }
    int nodeCount = 0; // 初始节点数量
    // "用过的"结点下标列表
    SeqList *usedNodeIndexList = CreateList(); // 创建已使用节点列表

    scanf("%d", &nodeCount); // 读取节点数量

    for (int i = 0; i < nodeCount; i++) {
        int weight;
        scanf("%d", &weight);
        // 将所有的结点权值放入结点列表
        treeNodes[i].weight = weight; // 设置节点权重
        treeNodeCount++;              // 增加节点计数
    }

    // 在权值列表仍有至少 2 个结点的时候，不断找最小和次小权重的结点
    while (treeNodeCount - LengthSeqList(usedNodeIndexList) >= 2) {
        int startPos = 0;

        for (startPos = 0; startPos < treeNodeCount; startPos++) {
            // 注意：找不到才 break，说明没用过
            if (SearchListSeq(usedNodeIndexList, startPos) == -1) {
                break;
            }
        }

        int mostMinWeight = treeNodes[startPos].weight; // 最小权重值
        int mostMinWeightNodeIndex = startPos;          // 最小权重节点索引
        // 得到当前权值中次小的那个
        for (int i = startPos; i < treeNodeCount; i++) {
            // 当前的结点下标不在"用过"的下标列表中
            if (SearchListSeq(usedNodeIndexList, i) == -1) {
                if (treeNodes[i].weight < mostMinWeight) {
                    mostMinWeight = treeNodes[i].weight; // 更新最小权重
                    mostMinWeightNodeIndex = i;          // 更新最小权重节点索引
                }
            }
        }
        // 将节点下标加入"用过的结点下标列表
        InsListSeq(usedNodeIndexList, LengthSeqList(usedNodeIndexList), mostMinWeightNodeIndex); // 标记为已使用

        // 得到当前权值中次小的那个
        for (startPos = 0; startPos < treeNodeCount; startPos++) {
            if (SearchListSeq(usedNodeIndexList, startPos) == -1) {
                break;
            }
        }

        int secondMinWeight = treeNodes[startPos].weight; // 次小权重值
        int secondMinWeightIndex = startPos;              // 次小权重节点索引

        for (int i = startPos; i < treeNodeCount; i++) {
            // 找不到是 ==-1！
            if (SearchListSeq(usedNodeIndexList, i) == -1) {
                if (treeNodes[i].weight < secondMinWeight) {
                    secondMinWeight = treeNodes[i].weight; // 更新次小权重
                    secondMinWeightIndex = i;              // 更新次小权重节点索引
                }
            }
        }

        InsListSeq(usedNodeIndexList, LengthSeqList(usedNodeIndexList), secondMinWeightIndex); // 标记为已使用
        // 得到两个结点权重之和
        treeNodes[treeNodeCount].weight = mostMinWeight + secondMinWeight; // 新节点权重为两子节点权重和
        // 左孩子为权重最小结点
        treeNodes[treeNodeCount].leftChild = mostMinWeightNodeIndex; // 设置左子节点
        // 右孩子为权重次小结点
        treeNodes[treeNodeCount].rightChild = secondMinWeightIndex; // 设置右子节点
        // 权重最小结点和次小结点的父节点为当前结点
        treeNodes[mostMinWeightNodeIndex].parent = treeNodeCount; // 设置父节点引用
        treeNodes[secondMinWeightIndex].parent = treeNodeCount;   // 设置父节点引用
        // 总结点数 +1
        treeNodeCount++; // 节点数增加
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
