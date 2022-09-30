//
// Created by Liu Wei on 2018/10/19.
// 问题 B: 【数据结构7-6】统计二叉树叶子结点数

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

//创建根结点，递归创建T->lchild,T->rchild
int create(BiTree &T, char pa[], int low_a, int high_a, char pb[], int low_b, int high_b) {
    T = (BiNode *)malloc(sizeof(BiNode));
    int root_pos_a = low_a;
    char root = pa[root_pos_a];
    T->data = root;
    int root_pos_b = -1;

    for (int i = low_b; i <= high_b; i++) {
        if (pb[i] == root) {
            root_pos_b = i;
            break;
        }
    }

    int leftChildTreeNodeCount = root_pos_b - low_b;
    int rightChildTreeNodeCount = high_b - root_pos_b;

    // 开始左子树处的递归
    if (leftChildTreeNodeCount == 0) {
        T->lchild = NULL;
    } else {
        create(T->lchild, pa, low_a + 1, low_a + leftChildTreeNodeCount, pb, low_b, root_pos_b - 1);
    }
    // 开始右子树处的递归
    if (rightChildTreeNodeCount == 0) {
        T->rchild = NULL;
    } else {
        create(T->rchild, pa, low_a + leftChildTreeNodeCount + 1, high_a, pb, root_pos_b + 1, high_b);
    }

    return 1;
}

int CreateBiTree(BiTree &T) {
    //读入先序，中序序列，分别存入数组pa，pb
    char pa[100];
    char pb[100];

    gets(pa);
    gets(pb);

    int n = strlen(pa);

    //调用create函数创建二叉树T
    if (create(T, pa, 0, n - 1, pb, 0, n - 1)) {
        return 1;
    }
}

//统计叶子结点个数遍历
int CountLeaf(BiTree T, int &count) {
    if (T != NULL) {
        if (T->lchild == NULL && T->rchild == NULL) {
            count++;
        }

        CountLeaf(T->lchild, count);
        CountLeaf(T->rchild, count);
    }
}

int main() {
    BiTree T;
    int leafCount = 0;

    CreateBiTree(T);
    CountLeaf(T, leafCount);
    printf("%d", leafCount);

    getchar();
    getchar();
    return 1;
}