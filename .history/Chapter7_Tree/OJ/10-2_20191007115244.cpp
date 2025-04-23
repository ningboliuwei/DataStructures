//
// Created by Liu Wei on 2018/11/1.
// 问题 B: 【数据结构7-12】哈夫曼编码

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;                            //权值
    int parent, lchild, rchild;      //双亲及左右孩子的下标

} HTNode, *HuffmanTree;

void CreateHuffmanTree() {
    // 输入叶子结点个数
    int n = 0;
    scanf("%d", &n);
    //    HT[ ] 数组初始化
    // 哈夫曼树结点个数为叶子结点个数 n * 2 - 1
    HTNode HT[n * 2 - 1];
    //    读入HT[i].weight  //叶子的权值
    for (int i = 0; i < n; i++) {
        scanf("%d", &HT[i].weight);
        HT[i].lchild = -1;
        HT[i].rchild = -1;
        HT[i].parent = -1;
    }

    for (int i = n; i < 2 * n - 1; i++) {
        // 权值最小结点的下标


        // 0~i-1 行 双亲为-1 的结点里权值最小的两个min1，min2
        // 进行合并（有5个值需要修改）

        int min1 = -1;

        for (int j = 0; j < i; j++) {
            if (HT[j].parent == -1) {
                // 初始化最小的位置为第 1 个（无父结点的）的结点的位置
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
            // j != min1 的作用就是解决权值相等情况下出现的问题
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

        printf("(%d)%d, (%d)%d\n", min1, HT[min1].weight, min2, HT[min2].weight);

        HT[i].weight = HT[min1].weight + HT[min2].weight;
        HT[i].parent = -1;
        HT[i].lchild = min1;
        HT[i].rchild = min2;
        HT[min1].parent = i;
        HT[min2].parent = i;
    }

    for (int i = 0; i < 2 * n - 1; i++) {
        printf("%d %d %d %d %d\n", i, HT[i].lchild, HT[i].weight, HT[i].rchild, HT[i].parent);
    }
}

int main() {
    CreateHuffmanTree();
}

