//
// Created by Liu Wei on 2018/10/30.
// 问题 A: 【数据结构7-11】哈夫曼树
// 测试数据
// 输入：7 4 5 7 8 6 12 18
// 输出：
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
// 输出：0 -1 2 -1 5
// 1 -1 4 -1 7
// 2 -1 2 -1 5
// 3 -1 3 -1 6
// 4 -1 3 -1 6
// 5 0 4 2 7
// 6 3 6 4 8
// 7 1 8 5 8
// 8 6 14 7 -1
#include <stdio.h>  // 引入标准输入输出头文件
#include <stdlib.h> // 引入标准库头文件，用于动态内存管理

// 定义哈夫曼树节点的结构体
typedef struct {
    int weight;                 // 结点权值
    int parent, lchild, rchild; // 父节点、左子节点和右子节点在数组中的索引
} HTNode, *HuffmanTree;

#define MAX_NODE_COUNT 100 // 定义最大结点数量，用于可能的结点计数限制

// 函数：创建哈夫曼树
void CreateHuffmanTree(HTNode HT[], int n) {
    // 输入叶子结点权值，并初始化叶子结点信息
    for (int i = 0; i < n; i++) {
        scanf("%d", &HT[i].weight); // 读取叶子结点的权值
        // 初始化叶子结点的父节点、左右孩子信息为-1
        HT[i].lchild = -1;
        HT[i].rchild = -1;
        HT[i].parent = -1;
    }

    // 开始构造非叶子结点，建立哈夫曼树
    for (int i = n; i < 2 * n - 1; i++) {
        // 初始化找最小两个节点的索引min1和min2
        int min1 = -1;
        int min2 = -1;

        // 遍历已有结点，找到最小权值结点的索引min1
        for (int j = 0; j < i; j++) {
            if (HT[j].parent == -1) {
                if (min1 == -1 || HT[j].weight < HT[min1].weight) {
                    min1 = j;
                }
            }
        }

        // 遍历已有结点，找到次小权值结点的索引min2，且确保不同于min1
        for (int j = 0; j < i; j++) {
            if (HT[j].parent == -1 && j != min1) {
                if (min2 == -1 || HT[j].weight < HT[min2].weight) {
                    min2 = j;
                }
            }
        }

        // 设置新建立的父结点的权值等于两个最小权结点权值之和
        HT[i].weight = HT[min1].weight + HT[min2].weight;
        HT[i].parent = -1;   // 新建立的父结点的父结点为-1
        HT[i].lchild = min1; // 设置新结点的左孩子为min1
        HT[i].rchild = min2; // 设置新结点的右孩子为min2
        HT[min1].parent = i; // 设置min1的父结点为新结点
        HT[min2].parent = i; // 设置min2的父结点为新结点
    }
}

// 函数：输出哈夫曼树的结点信息
void OutputHuffmanTree(HTNode HT[], int n) {
    // 遍历所有结点并输出它们的索引、左孩子、权值、右孩子和父节点
    for (int i = 0; i < 2 * n - 1; i++) {
        printf("%d %d %d %d %d\n", i, HT[i].lchild, HT[i].weight, HT[i].rchild, HT[i].parent);
    }
}

// 主函数
int main() {
    int n = 0;            // 存储结点个数
    scanf("%d", &n);      // 从用户处读取结点个数
    
    HTNode HT[n * 2 - 1]; // 创建足够大的数组存储所有哈夫曼树的结点

    CreateHuffmanTree(HT, n); // 调用函数创建哈夫曼树
    OutputHuffmanTree(HT, n); // 调用函数输出哈夫曼树的结点信息

    getchar(); // 等待用户输入字符以继续
    getchar(); // 需要两次getchar以处理输入流中额外的换行字符
}