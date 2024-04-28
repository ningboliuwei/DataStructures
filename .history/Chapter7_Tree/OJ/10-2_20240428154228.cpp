#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int weight;                 //权值
    int parent, lchild, rchild; //双亲及左右孩子的下标
    char data;                  //字符
} HTNode, *HuffmanTree;

#define MAX_CODE_LEN 100

void CreateHuffmanTree(HuffmanTree &ht, int n) {
    HTNode HT[n * 2 - 1];

    for (int i = 0; i < n * 2 - 1; i++) {
        HT[i].lchild = -1;
        HT[i].rchild = -1;
        HT[i].parent = -1;
        HT[i].data = '\0';
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &HT[i].weight);
        HT[i].data = 'A' + i;
    }

    for (int i = n; i < 2 * n - 1; i++) {
        int min1 = -1;

        for (int j = 0; j < i; j++) {
            if (HT[j].parent == -1) {
                if (min1 == -1) {
                    min1 = j;
                } else {
                    if (HT[j].weight < HT[min1].weight) {
                        min1 = j;
                    }
                }
            }
        }

        int min2 = -1;
        for (int j = 0; j < i; j++) {
            if (HT[j].parent == -1 && j != min1) {
                if (min2 == -1 && HT[j].weight >= HT[min1].weight) {
                    min2 = j;
                } else {
                    if (HT[j].weight >= HT[min1].weight && HT[j].weight < HT[min2].weight) {
                        min2 = j;
                    }
                }
            }
        }

        HT[i].weight = HT[min1].weight + HT[min2].weight;
        HT[i].parent = -1;
        HT[i].lchild = min1;
        HT[i].rchild = min2;
        HT[min1].parent = i;
        HT[min2].parent = i;
    }

    ht = HT;
}

void GenerateAndPrintHuffmanCodes(HuffmanTree HT, int n) {
    char code[MAX_CODE_LEN];       // 用于临时存储编码
    code[MAX_CODE_LEN - 1] = '\0'; // 字符串终结符

    for (int i = 0; i < n; i++) { // 遍历所有叶子节点
        int current = i;
        int parent = HT[i].parent;
        int codeIndex = MAX_CODE_LEN - 2;

        while (parent != -1) {
            if (HT[parent].lchild == current)
                code[codeIndex--] = '0'; // 左孩子为 "0"
            else
                code[codeIndex--] = '1'; // 右孩子为 "1"

            current = parent;
            parent = HT[current].parent;
        }

        // 打印节点信息
        printf("Character: %c, Code: %s\n", HT[i].data, &code[codeIndex + 1]);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    HuffmanTree ht = CreateHuffmanTree(n);
    GenerateAndPrintHuffmanCodes(ht, n);
}
