//
// Created by Liu Wei on 2018/10/19.
// 问题 B: 【数据结构7-6】统计二叉树叶子结点数

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <string.h>

using namespace std;

typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

int create(BiTree &T, char pa[], int low_a, int high_a, char pb[], int low_b,
           int high_b) {     //创建根结点，递归创建T->lchild,T->rchild
//@@1
    T = (BiNode *) malloc(sizeof(BiNode));
    T->data = pa[low_a];
    int rootIndex = 0;
    for (int i = low_b; i <= high_b; i++) {
        if (pb[i] == T->data) {
            rootIndex = i;
            break;
        }
    }

    int leftChildTreeNodeCount = rootIndex - low_b;
    if (leftChildTreeNodeCount > 0) {
        T->lchild = (BiNode *) malloc(sizeof(BiNode));
        create(T->lchild, pa, low_a + 1, low_a + leftChildTreeNodeCount, pb, low_b, rootIndex - 1);
    } else {
        T->lchild = NULL;
    }

    int rightChildTreeNodeCount = high_b - rootIndex;
    if (rightChildTreeNodeCount > 0) {
        T->rchild = (BiNode *) malloc(sizeof(BiNode));
        create(T->rchild, pa, high_a - rightChildTreeNodeCount + 1, high_a, pb, rootIndex + 1, high_b);
    } else {
        T->rchild = NULL;
    }

//@@1
}

int CreateBiTree(BiTree &T) {
    char pa[20];
    char pb[20];

    gets(pa);
    gets(pb);

    int n = strlen(pa);

    if (create(T, pa, 0, n - 1, pb, 0, n - 1))      //调用create函数创建二叉树T
        return 1;
}

int CountLeaf(BiTree T, int &count)                 //后序遍历
{
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

    CreateBiTree(T);            //创建二叉链表
    CountLeaf(T, leafCount);                 //后序遍历

    printf("%d", leafCount);

    return 1;
}


