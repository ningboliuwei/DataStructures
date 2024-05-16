#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE_COUNT 100
#define MAX_CODE_LENGTH 100

typedef struct {
    char data;
    int weight;
    int parent, lchild, rchild;
    char code[MAX_CODE_LENGTH];
} HTNode, *HuffmanTree;

void CreateHuffmanTree(HTNode HT[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &HT[i].weight);
        HT[i].lchild = -1;
        HT[i].rchild = -1;
        HT[i].parent = -1;
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
}

void GenerateAndPrintHuffmanCodes(HuffmanTree HT, int n) {
    for (int i = 0; i < n; i++) {
        int j = i;
        int k = 0;
        while (HT[j].parent != -1) {
            if (HT[HT[j].parent].lchild == j) {
                HT[i].code[k] = '0';
            } else {
                HT[i].code[k] = '1';
            }
            j = HT[j].parent;
            k++;
        }

        HT[i].code[k] = '\0';
    }

    for (int i = 0; i < n; i++) {
        printf("%c %d ", HT[i].data, HT[i].weight);

        for (int j = 0; j < strlen(HT[i].code); j++) {
            printf("%c", HT[i].code[j]);
        }

        printf("\n");
    }
}

void HuffmanEncode(HuffmanTree HT, int n, char *str) {
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < n; j++) {
            if (HT[j].data == str[i]) {
                printf("%s", HT[j].code);
            }
        }
    }
}

void HuffmanDecode(HuffmanTree HT, int n, char *code) {
    int i = 2 * n - 2;
    while (*code != '\0') {
        if (*code == '0') {
            i = HT[i].lchild;
        } else {
            i = HT[i].rchild;
        }

        if (HT[i].lchild == -1 && HT[i].rchild == -1) {
            printf("%c", HT[i].data);
            i = 2 * n - 2;
        }

        code++;
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    HTNode HT[n * 2 - 1];

    CreateHuffmanTree(HT, n);
    GenerateAndPrintHuffmanCodes(HT, n);
    char str[1000];
    scanf("%s", str);
    HuffmanEncode(HT, n, str);
    scanf("%s", str);
    HuffmanDecode(HT, n, str);

    getchar();
    getchar();
    getchar();
}
