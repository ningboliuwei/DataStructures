//
// Created by Liu Wei on 2018/10/30.
// 1641 问题 A: 【数据结构7-12】哈夫编码
// OJ PASSED
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

// OJ 第一组测试数据
// 7（输入）
// 4（输入）
// 5（输入）
// 7（输入）
// 8（输入）
// 6（输入）
// 12（输入）
// 18（输入）
// A 4 1010（输出）
// B 5 1011（输出）
// C 7 011（输出）
// D 8 100（输出）
// E 6 010（输出）
// F 12 00（输出）
// G 18 11（输出）
// 101010110111000100011（输入）
// FFGCDAEE（输入）

// OJ 第二组测试数据
// 4
// 6
// 4
// 3
// 1
// A 6 0
// B 4 10
// C 3 111
// D 1 110
// ABCD
// 010111110
// AAAACB

// OJ 第三组测试数据
// 3
// 1
// 2
// 4
// A 1 00
// B 2 01
// C 4 1
// 00011
// AABCCCC

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_NODE_COUNT 100 // 定义最大节点数
#define MAX_LENGTH 1000    // 定义最大字符串长度
// 线性表，用于保存所有的权值
typedef struct {
    int weight;     // 节点权重
    int parent;     // 父节点索引
    char text;      // 节点对应的字符
    int leftChild;  // 左子节点索引
    int rightChild; // 右子节点索引
    char code[10];  // 存储节点的哈夫曼编码

} HTNode, *HuffmanTree;

HTNode treeNodes[MAX_NODE_COUNT]; // 全局数组存储哈夫曼树节点

#define MAX_ITEM_COUNT 10
typedef char DataType;
// 定义栈结点结构
typedef struct StackNodeStruct {
    DataType data;                // 栈节点存储的数据
    struct StackNodeStruct *next; // 指向下一个栈节点的指针
} StackNode;
// 定义链栈结构
typedef struct {
    StackNode *top; // 栈顶指针
} LinkStack;
// 初始化链栈
void InitStack(LinkStack *stack) {
    stack->top = NULL; // 将栈顶指针置为NULL，表示空栈
}
// 链栈的 ReadTop 函数
int ReadTop(LinkStack *stack, DataType &topElement) {
    if (stack->top == NULL) {
        return 0; // 栈为空，返回0表示失败
    }

    topElement = stack->top->data; // 获取栈顶元素值

    return 1; // 返回1表示成功
}
// 链栈的 Push 函数
void Push(LinkStack *stack, DataType x) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode)); // 为新节点分配内存
    node->data = x;                                           // 设置新节点的数据域
    node->next = stack->top;                                  // 将新节点的next指向当前栈顶
    stack->top = node;                                        // 更新栈顶为新节点
}
// 链栈的 Pop 函数
int Pop(LinkStack *stack, DataType &x) {
    // 栈为空
    if (stack->top == NULL) {
        return 0; // 栈为空，返回0表示失败
    }

    StackNode *node = stack->top; // 保存当前栈顶节点
    x = node->data;               // 获取栈顶元素值
    stack->top = node->next;      // 更新栈顶为下一个节点
    free(node);                   // 释放原栈顶节点内存

    return 1; // 返回1表示成功
}
// 判断是否是空栈
int IsEmptyStack(LinkStack *stack) {
    if (stack->top == NULL) {
        return 1; // 栈为空，返回1
    }
    return 0; // 栈不为空，返回0
}
// 创建哈夫曼树（参考 OJ-1641 代码）
void CreateHuffmanTree(HTNode treeNodes[], int &treeNodeCount, int &leafNodeCount) {
    char charset[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; // 定义字符集，用于给叶子节点赋值

    for (int i = 0; i < leafNodeCount; i++) {
        treeNodes[i].text = charset[i]; // 为每个叶子节点分配一个字符
    }

    while (treeNodeCount < leafNodeCount * 2 - 1) { // 循环直到构建完整的哈夫曼树
        // 左结点的下标
        int leftIndex = -1;
        // 右结点的下标
        int rightIndex = -1;
        // 找到最小的那个结点作为左孩子
        for (int i = 0; i < treeNodeCount; i++) {
            if (treeNodes[i].parent == -1) { // 只考虑没有父节点的节点
                // 记录第一个没有父节点的结点的下标
                if (leftIndex == -1) {
                    leftIndex = i;
                }

                if (treeNodes[i].weight < treeNodes[leftIndex].weight) {
                    leftIndex = i; // 更新为权重更小的节点
                }
            }
        }
        // 跳过找到的最小的那个，然后找到次小的那个，作为右孩子
        for (int j = 0; j < treeNodeCount; j++) {
            if (treeNodes[j].parent == -1 && j != leftIndex) { // 排除已选的最小节点
                if (rightIndex == -1) {
                    rightIndex = j;
                }

                if (treeNodes[j].weight < treeNodes[rightIndex].weight) {
                    rightIndex = j; // 更新为权重更小的节点
                }
            }
        }
        // 建立新的结点，以及建立与现有左右孩子结点直接的关系
        treeNodes[treeNodeCount].weight = treeNodes[leftIndex].weight + treeNodes[rightIndex].weight; // 新节点权重为两子节点权重之和
        treeNodes[treeNodeCount].leftChild = leftIndex;                                               // 设置左子节点索引
        treeNodes[treeNodeCount].rightChild = rightIndex;                                             // 设置右子节点索引
        treeNodes[leftIndex].parent = treeNodeCount;                                                  // 设置左子节点的父节点
        treeNodes[rightIndex].parent = treeNodeCount;                                                 // 设置右子节点的父节点
        treeNodeCount++;                                                                              // 节点总数加1
    }
}
// 输出哈夫曼树
void ShowHuffmanTree(HTNode treeNodes[], int treeNodeCount) {
    for (int i = 0; i < treeNodeCount; i++) {
        printf("%d %d %d %d %d\n", i, treeNodes[i].leftChild, treeNodes[i].weight, treeNodes[i].rightChild, treeNodes[i].parent); // 打印每个节点的信息
    }
}
// 获取每个叶子结点的哈夫曼编码
void Encode(HTNode treeNodes[], int index, char text, int treeNodeCount) {
    // 找到当前字符对应的叶子结点在结点列表中的下标，并放入 leafIndex 变量中
    for (int i = 0; i < treeNodeCount; i++) {
        if (treeNodes[i].text == text) {
            index = i; // 找到匹配字符的节点索引
            break;
        }
    }

    int leafIndex = index; // 保存叶子节点索引
    // 因为从叶子结点往根节点获取编码，所以需要一个栈来保存编码，以实现倒序
    LinkStack *codeStack = (LinkStack *)malloc(sizeof(LinkStack)); // 分配栈内存
    InitStack(codeStack);                                          // 初始化栈
    // 从叶子往根获取编码（0/1）
    // 从叶子结点的位置不断向上找父节点，直到找到根节点
    while (treeNodes[index].parent != -1) {
        int originalIndex = index;       // 保存当前节点索引
        index = treeNodes[index].parent; // 移动到父节点
        // 如果当前结点是父节点的左孩子，那么编码为 0
        if (treeNodes[index].leftChild == originalIndex) {
            Push(codeStack, '0'); // 左子节点编码为0
        }
        // 如果当前结点是父节点的右孩子，那么编码为 1
        else if (treeNodes[index].rightChild == originalIndex) {
            Push(codeStack, '1'); // 右子节点编码为1
        }
    }
    // 反向获取编码，放入对应的叶子结点的 code 域（一个字符数组）中
    int pos = 0; // 编码字符串的位置索引
    while (!IsEmptyStack(codeStack)) {
        // 先给 code 字符串数组开辟空间
        char codeSegment;                             // 存储弹出的编码位
        Pop(codeStack, codeSegment);                  // 从栈中弹出编码位
        treeNodes[leafIndex].code[pos] = codeSegment; // 存储到节点的编码数组
        pos++;                                        // 移动到下一个位置
    }
    // 最后加上字符串结束符 \0
    treeNodes[leafIndex].code[pos] = '\0'; // 设置字符串结束标志
}
// 生成码表
void GenerateCodeTable(HTNode treeNodes[], int treeNodeCount, int leafNodeCount) {
    // 为每个叶子结点生成码表
    for (int i = 0; i < leafNodeCount; i++) {
        Encode(treeNodes, 0, treeNodes[i].text, treeNodeCount); // 为每个叶子节点生成哈夫曼编码
    }
}
// 根据单个字符输出编码
void ShowCodeByText(HTNode treeNodes[], int treeNodeCount, char text) {
    // 遍历树中所有的结点
    for (int i = 0; i < treeNodeCount; i++) {
        // 如果结点是叶子结点，且结点的字符和参数 text 的字符相同
        if (treeNodes[i].leftChild == -1 && treeNodes[i].rightChild == -1 && treeNodes[i].text == text) {
            int pos = 0; // 编码字符串的位置索引
            // 输出这个字符对应的编码
            while (treeNodes[i].code[pos] != '\0') {
                printf("%c", treeNodes[i].code[pos]); // 输出编码的每一位
                pos++;                                // 移动到下一个位置
            }
        }
    }
}
// 输出码表
void ShowCodeTable(HTNode treeNodes[], int treeNodeCount, int leafNodeCount) {
    // 遍历所有的叶子结点，输出对应的哈夫曼编码
    for (int i = 0; i < leafNodeCount; i++) {
        printf("%c %d ", treeNodes[i].text, treeNodes[i].weight);    // 输出字符和权重
        ShowCodeByText(treeNodes, treeNodeCount, treeNodes[i].text); // 输出编码
        printf("\n");                                                // 换行
    }
}
// 编码（根据字符串输出编码）
void EncodeText(HTNode treeNodes[], int treeNodeCount, int leafNodeCount, char text[]) {
    // 对文本进行编码
    for (int i = 0; i < (int)strlen(text); i++) {
        ShowCodeByText(treeNodes, treeNodeCount, text[i]); // 输出每个字符的编码
    }

    printf("\n"); // 输出完成后换行
}
// 解码（根据编码输出字符串）
void DecodeText(HTNode treeNodes[], int treeNodeCount, char encodedText[]) {
    int currentSegmentStartPos = 0;                             // 当前编码段的起始位置
    while (currentSegmentStartPos < (int)strlen(encodedText)) { // 处理整个编码字符串
        for (int leafIndex = 0; leafIndex < treeNodeCount; leafIndex++) {
            bool match = true; // 匹配标志
            // 重置编码长度计数器
            int codeLength = 0;

            if (treeNodes[leafIndex].leftChild == -1 && treeNodes[leafIndex].rightChild == -1
                && strlen(treeNodes[leafIndex].code) > 0) { // 检查是否为有效叶子节点
                for (int j = 0; j < (int)strlen(treeNodes[leafIndex].code); j++) {
                    codeLength++;                                                                  // 编码长度加1
                    if (treeNodes[leafIndex].code[j] != encodedText[currentSegmentStartPos + j]) { // 检查编码是否匹配
                        match = false;                                                             // 不匹配
                        break;
                    }
                }

                if (match) {                                 // 找到匹配的编码
                    printf("%c", treeNodes[leafIndex].text); // 输出对应的字符
                    // 编码后的文本跳过编码的长度
                    currentSegmentStartPos += codeLength; // 移动到下一段编码的起始位置
                }
            }
        }
    }
}

int main() {
    int treeNodeCount = 0;            // 节点总数计数器
    int leafNodeCount = 0;            // 叶子节点数量
    HTNode treeNodes[MAX_NODE_COUNT]; // 定义存储哈夫曼树节点的数组
    // 对结点数组初始化
    for (int i = 0; i < MAX_NODE_COUNT; i++) {
        treeNodes[i].leftChild = -1;  // 初始化左子节点为-1，表示无左子节点
        treeNodes[i].rightChild = -1; // 初始化右子节点为-1，表示无右子节点
        treeNodes[i].parent = -1;     // 初始化父节点为-1，表示无父节点
    }
    // 输入结点数
    scanf("%d", &leafNodeCount); // 读取叶子节点数量
    // 输入各个结点权值
    for (int i = 0; i < leafNodeCount; i++) {
        int weight;           // 临时存储权重的变量
        scanf("%d", &weight); // 读取每个节点的权重
        // 将所有的结点权值放入结点列表
        treeNodes[i].weight = weight; // 设置节点权重
        // 结点列表中的结点数
        treeNodeCount++; // 节点总数加1
    }
    CreateHuffmanTree(treeNodes, treeNodeCount, leafNodeCount); // 创建哈夫曼树
    // 生成码表
    GenerateCodeTable(treeNodes, treeNodeCount, leafNodeCount); // 为每个叶子节点生成哈夫曼编码
    // 输出码表
    ShowCodeTable(treeNodes, treeNodeCount, leafNodeCount); // 显示哈夫曼编码表
    // 输入要转为编码的文本
    char text[MAX_LENGTH]; // 定义存储原始文本的数组
    scanf("%s", text);     // 读取原始文本
    // 输出编码
    EncodeText(treeNodes, treeNodeCount, leafNodeCount, text); // 将文本转换为哈夫曼编码并输出
    // 输入编码
    char encodedText[MAX_LENGTH]; // 定义存储编码后文本的数组
    scanf("%s", encodedText);     // 读取哈夫曼编码
    // 输出译码
    DecodeText(treeNodes, treeNodeCount, encodedText); // 将哈夫曼编码解码为原始文本并输出
}
