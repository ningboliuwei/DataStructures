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
#include <string.h>

#define MAX_NODE_COUNT 100
// 线性表，用于保存所有的权值
typedef struct {
    int weight;
    int parent;
    char text;
    int leftChild;
    int rightChild;
    char code[10];

} HTNode, *HuffmanTree;

HTNode treeNodes[MAX_NODE_COUNT];

#define MAX_ITEM_COUNT 10
typedef char DataType;

typedef struct StackNodeStruct {
    DataType data;
    struct StackNodeStruct *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;

void InitStack(LinkStack *stack) {
    stack->top = NULL;
}

int ReadTop(LinkStack *stack, DataType &topElement) {
    if (stack->top == NULL) {
        return 0;
    }

    topElement = stack->top->data;

    return 1;
}

int Push(LinkStack *stack, DataType x) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = x;
    node->next = stack->top;
    stack->top = node;
}

int Pop(LinkStack *stack, DataType &x) {
    // 栈为空
    if (stack->top == NULL) {
        return 0;
    }

    StackNode *node = stack->top;
    x = node->data;
    stack->top = node->next;
    free(node);

    return 1;
}

int IsEmptyStack(LinkStack *stack) {
    if (stack->top == NULL) {
        return 1;
    }
    return 0;
}

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
    // 记录下叶子结点的最初位置
    int leafIndex = index;

    LinkStack *codeStack = (LinkStack *)malloc(sizeof(LinkStack));
    InitStack(codeStack);
    // 从叶子往根获取编码（0/1）
    while (treeNodes[index].parent != -1) {
        int originalIndex = index;
        index = treeNodes[index].parent;

        if (treeNodes[index].leftChild == originalIndex) {
            Push(codeStack, '0');
        } else if (treeNodes[index].rightChild == originalIndex) {
            Push(codeStack, '1');
        }
    }
    // 反向获取编码，放入对应的叶子结点
    int pos = 0;
    while (!IsEmptyStack(codeStack)) {
        // 先给 code 字符串数组开辟空间
        char codeSegment;
        Pop(codeStack, codeSegment);
        treeNodes[leafIndex].code[pos] = codeSegment;
        pos++;
    }
    treeNodes[leafIndex].code[pos] = '\0';
}

void GenerateCodeTable(HTNode treeNodes[], int treeNodeCount, int leafNodeCount) {
    for (int i = 0; i < leafNodeCount; i++) {
        Encode(treeNodes, 0, treeNodes[i].text, treeNodeCount);
    }
}
// 根据单个字符输出编码
void ShowCodeByText(HTNode treeNodes[], int treeNodeCount, char text) {
    for (int i = 0; i < treeNodeCount; i++) {
        if (treeNodes[i].leftChild == -1 && treeNodes[i].rightChild == -1 && treeNodes[i].text == text) {
            int pos = 0;
            while (treeNodes[i].code[pos] != '\0') {
                printf("%c", treeNodes[i].code[pos]);
                pos++;
            }
        }
    }
}
// 输出码表
void ShowCodeTable(HTNode treeNodes[], int treeNodeCount, int leafNodeCount) {
    for (int i = 0; i < leafNodeCount; i++) {
        printf("%c ", treeNodes[i].text);
        ShowCodeByText(treeNodes, treeNodeCount, treeNodes[i].text);
        printf("\n");
    }
}
// 编码（根据字符串输出编码）
void EncodeText(HTNode treeNodes[], int treeNodeCount, int leafNodeCount) {
    char text[20];
    scanf("%s", text);

    for (int i = 0; i < strlen(text); i++) {
        ShowCodeByText(treeNodes, treeNodeCount, text[i]);
    }

    printf("\n");
}
// 译码（根据编码输出字符串）
void DecodeText(HTNode treeNodes[], int treeNodeCount) {
    char encodedText[100];
    scanf("%s", encodedText);

    for (int pos = 0; pos < strlen(encodedText); pos++) {
        for (int i = 0; i < treeNodeCount; i++) {
            bool match = true;
            int codeLength = 0;

            if (treeNodes[i].leftChild == -1 && treeNodes[i].rightChild == -1 && strlen(treeNodes[i].code) > 0) {
                for (int j = 0; j < strlen(treeNodes[i].code); j++) {
                    if (treeNodes[i].code[j] == encodedText[pos + j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    printf("%c", treeNodes[i].text);
                    // 编码后的文本跳过编码的长度
                    // pos += codeLength;
                }
            }
        }
    }
}

int main() {
    int treeNodeCount = 0;
    int leafNodeCount = 0;
    HTNode treeNodes[MAX_NODE_COUNT];

    CreateHuffmanTree(treeNodes, treeNodeCount, leafNodeCount);
    ShowHuffmanTree(treeNodes, treeNodeCount);
    GenerateCodeTable(treeNodes, treeNodeCount, leafNodeCount);
    ShowCodeTable(treeNodes, treeNodeCount, leafNodeCount);
    EncodeText(treeNodes, treeNodeCount, leafNodeCount);
    DecodeText(treeNodes, treeNodeCount);
    getchar();
    getchar();
}
