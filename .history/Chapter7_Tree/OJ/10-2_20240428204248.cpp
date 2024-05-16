//
// Created by Liu Wei on 2024/4/28
// 问题 A: 【数据结构7-12】哈夫曼编码
// OJ PASSED

#include <stdio.h>  // 引入标准输入输出库
#include <stdlib.h> // 引入标准库，用于动态分配内存等操作
#include <string.h> // 引入字符串库，用于处理字符串相关操作

#define MAX_NODE_COUNT 100  // 定义最大节点数
#define MAX_CODE_LENGTH 100 // 定义最大编码长度

// 哈夫曼树节点的结构体
typedef struct {
    char data;                  // 节点存储的字符
    int weight;                 // 权重（频率）
    int parent, lchild, rchild; // 父亲、左孩子、右孩子在数组中的位置
    char code[MAX_CODE_LENGTH]; // 该字符对应的哈夫曼编码
} HTNode, *HuffmanTree;

// 函数：创建哈夫曼树
void CreateHuffmanTree(HTNode HT[], int n) {
    // 初始化所有叶子节点
    for (int i = 0; i < n; i++) {
        scanf("%d", &HT[i].weight); // 读取权重
        HT[i].lchild = -1;          // 初始左孩子为-1，表示没有左孩子
        HT[i].rchild = -1;          // 初始右孩子为-1，表示没有右孩子
        HT[i].parent = -1;          // 初始父节点为-1，表示没有父节点
        HT[i].data = 'A' + i;       // 初始化字符数据，从'A'开始
    }

    // 构造n-1个非叶节点
    for (int i = n; i < 2 * n - 1; i++) {
        // 初始化两个最小权重节点的索引
        int min1 = -1, min2;

        // 寻找最小权重的节点
        for (int j = 0; j < i; j++) {
            if (HT[j].parent == -1) {
                if (min1 == -1 || HT[j].weight < HT[min1].weight) {
                    min1 = j;
                }
            }
        }

        // 寻找次小权重的节点，且不与最小的相同
        min2 = -1;
        for (int j = 0; j < i; j++) {
            if (HT[j].parent == -1 && j != min1) {
                if (min2 == -1 || HT[j].weight < HT[min2].weight) {
                    min2 = j;
                }
            }
        }

        // 设置新节点的权重和左右孩子
        HT[i].weight = HT[min1].weight + HT[min2].weight;
        HT[i].parent = -1; // 新节点目前还没有父节点
        HT[i].lchild = min1;
        HT[i].rchild = min2;
        // 更新最小和次小节点的父节点为当前新节点
        HT[min1].parent = HT[min2].parent = i;
    }
}

// 函数：生成并打印哈夫曼编码
void GenerateAndPrintHuffmanCodes(HuffmanTree HT, int n) {
    // 对每个叶子节点生成哈夫曼编码
    for (int i = 0; i < n; i++) {
        int j = i;                  // 当前节点
        int k = 0;                  // 编码的位置
        char temp[MAX_CODE_LENGTH]; // 临时存储哈夫曼编码

        // 向上遍历直到根节点，生成哈夫曼编码
        while (HT[j].parent != -1) {
            if (HT[HT[j].parent].lchild == j)
                temp[k++] = '0'; // 左孩子标为0
            else
                temp[k++] = '1'; // 右孩子标为1
            j = HT[j].parent;    // 向上移动到父节点
        }

        // 将生成的编码*倒序*存储到节点的编码中
        for (int q = k - 1, r = 0; q >= 0; q--, r++) {
            HT[i].code[r] = temp[q];
        }
        HT[i].code[k] = '\0'; // 添加字符串结束符

        // 打印字符和对应的哈夫曼编码
        printf("%c %d ", HT[i].data, HT[i].weight);
        printf("%s\n", HT[i].code); // 输出编码
    }
}

// 函数：哈夫曼编码，对字符串进行编码
void HuffmanEncode(HuffmanTree HT, int n, char *str) {
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < n; j++) {
            if (HT[j].data == str[i]) {
                printf("%s", HT[j].code); // 输出匹配字符的哈夫曼编码
                break;
            }
        }
    }
    printf("\n"); // 编码结束换行
}

// 函数：哈夫曼译码，对编码后的字符串进行解码
void HuffmanDecode(HuffmanTree HT, int n, char *code) {
    int i = 2 * n - 2; // 根节点索引
    // 遍历编码字符串
    while (*code != '\0') {
        if (*code == '0')
            i = HT[i].lchild; // 向左移动
        else
            i = HT[i].rchild; // 向右移动

        if (HT[i].lchild == -1 && HT[i].rchild == -1) {
            printf("%c", HT[i].data); // 到达叶子节点，输出字符
            i = 2 * n - 2;            // 重置为根节点，继续译码
        }

        code++; // 移动到编码的下一个字符
    }
}

// 主函数
int main() {
    // 输入叶子节点个数
    int n = 0;
    scanf("%d", &n);
    // 创建并填充哈夫曼树数组
    HTNode HT[n * 2 - 1];

    CreateHuffmanTree(HT, n);            // 构建哈夫曼树
    GenerateAndPrintHuffmanCodes(HT, n); // 生成并打印哈夫曼编码

    // 读入需要编码的字符串
    char str[1000];
    scanf("%s", str);
    HuffmanEncode(HT, n, str); // 进行哈夫曼编码

    // 读入需要译码的编码字符串
    scanf("%s", str);
    HuffmanDecode(HT, n, str); // 进行哈夫曼译码

    // 阻塞程序结束，等待用户输入，确保看到程序输出结果
    getchar();
    getchar();
    getchar();
}