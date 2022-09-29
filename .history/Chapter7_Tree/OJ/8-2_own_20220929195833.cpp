//
// Created by Liu Wei on 2018/10/11.
// 问题 B: 【数据结构7-5】由中序和后序恢复二叉树
// 测试数据1：
// 9
// DBHEAIFCG
// DHEBIFGCA
//结果：ABDEHCFIG

// 测试数据 2：
// 10
// DGBAECJHFI
// GDBEJHIFCA
// ABDGCEFHJI

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

int create(BiTree &T, char pa[], int low_a, int high_a, char pb[], int low_b,
           int high_b) { //创建根结点，递归创建T->lchild,T->rchild
                         //@@1
    T = (BiNode *)malloc(sizeof(BiNode));
    // 在后续序列中找到根
    T->data = pb[high_b];
    int rootIndex = 0;
    for (int i = low_a; i <= high_a; i++) {
        if (pa[i] == T->data) {
            rootIndex = i;
            break;
        }
    }

    int leftChildTreeNodeCount = rootIndex - low_a;
    if (leftChildTreeNodeCount > 0) {
        T->lchild = (BiNode *)malloc(sizeof(BiNode));
        create(T->lchild, pa, low_a, rootIndex - 1, pb, low_b, low_b + leftChildTreeNodeCount - 1);
    } else {
        T->lchild = NULL;
    }

    int rightChildTreeNodeCount = high_a - rootIndex;
    if (rightChildTreeNodeCount > 0) {
        T->rchild = (BiNode *)malloc(sizeof(BiNode));
        create(T->rchild, pa, rootIndex + 1, high_a, pb, high_b - rightChildTreeNodeCount, high_b - 1);
    } else {
        T->rchild = NULL;
    }

    //@@1
}

int CreateBiTree(BiTree &T, int n) {
    //@@2                           //读入先序，中序序列，分别存入数组pa，pb
    char pa[20];
    char pb[20];

    for (int i = 0; i < n; i++) {
        scanf("%c", &pa[i]);
    }

    // 用于避免上一行结束的 \n 字符导致的问题
    scanf("\n");

    for (int i = 0; i < n; i++) {
        scanf("%c", &pb[i]);
    }
    //@@2

    if (create(T, pa, 0, n - 1, pb, 0, n - 1)) //调用create函数创建二叉树T
        return 1;
}

void Preorder(BiTree T) //后序遍历
{
    //@@3
    if (T != NULL) {
        printf("%c", T->data);
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
    //@@3
}

int main() {
    BiTree T;
    int n;

    scanf("%d\n", &n); //二叉树结点个数

    CreateBiTree(T, n); //创建二叉链表

    Preorder(T); //后序遍历

    return 1;
}