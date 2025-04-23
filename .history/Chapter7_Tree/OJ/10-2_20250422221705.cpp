//
// Created by Liu Wei on 2018/11/1.
// 问题 B: 【数据结构7-12】哈夫曼编码

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HuffmanCode char **

typedef struct {
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

void HuffmanCoding(HuffmanTree H, HuffmanCode &HC, int n) {
    HC = (HuffmanCode)malloc((n) * sizeof(char *));
    char *cd = (char *)malloc(n * sizeof(char));

    cd[n - 1] = '\0';

    for (int i = 0; i < n; i++) {
        int start = n - 1;
        int c = i;
        int j = H[i].parent;

        while (j != -1) {
            if (H[j].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';

            c = j;
            j = H[c].parent;
        }

        HC[i] = (char *)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);
    }

    free(cd);
}

void select(HuffmanTree H, int end, int &s1, int &s2) {
    int i = 0;
    int min1, min2;

    while (i <= end && H[i].parent != -1)
        i++;

    min1 = H[i].weight;
    s1 = i;

    i++;

    while (i <= end && H[i].parent != -1)
        i++;

    if (H[i].weight < min1) {
        min2 = min1;
        s2 = s1;
        min1 = H[i].weight;
        s1 = i;
    } else {
        min2 = H[i].weight;
        s2 = i;
    }

    for (int j = i + 1; j <= end; j++) {
        if (H[j].parent != -1)
            continue;
        if (H[j].weight < min1) {
            min2 = min1;
            s2 = s1;
            min1 = H[j].weight;
            s1 = j;
        }

        else if (H[j].weight >= min1 && H[j].weight < min2) {
            min2 = H[j].weight;
            s2 = j;
        }
    }
}

void creat(HuffmanTree &H, int n) {
    int m = 2 * n - 1;

    H = (HuffmanTree)malloc(m * sizeof(HTNode));

    for (int i = 0; i < m; i++) {
        H[i].parent = H[i].lchild = H[i].rchild = -1;
    }

    for (int i = 0; i < n; i++)
        scanf("%d", &(H[i].weight));

    for (int i = n; i < m; i++) {
        int s1, s2;

        select(H, i - 1, s1, s2);

        H[s1].parent = H[s2].parent = i;
        H[i].lchild = s1;
        H[i].rchild = s2;
        H[i].weight = H[s1].weight + H[s2].weight;
    }
}

void code(HuffmanCode HC) {
    char num[20];

    gets(num);

    for (int i = 0; num[i] != 0; i++) {
        printf("%s", HC[num[i] - 'A']);
    }
    printf("\n");
}

void Decode(HuffmanCode HC, char num[], int n) {
    char cmp[10];
    int j = 0;

    for (int i = 0; num[i] != 0; i++) {
        cmp[j++] = num[i];
        cmp[j] = '\0';

        for (int k = 0; k < n; k++) {
            if (strcmp(cmp, HC[k]) == 0) {
                printf("%c", 'A' + k);
                j = 0;
                break;
            }
        }
    }
}

int main() {
    int n;
    HuffmanTree H;
    HuffmanCode HC;
    char num[30];

    scanf("%d", &n);

    creat(H, n);
    HuffmanCoding(H, HC, n);

    for (int i = 0; i < n; i++)
        printf("%c %d %s\n", 'A' + i, H[i].weight, HC[i]);

    getchar();

    code(HC);

    gets(num);

    Decode(HC, num, n);
}