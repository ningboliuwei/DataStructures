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

int create(BiTree &T, char pb[], int low_b, int high_b, char pc[], int low_c,
           int high_c) { //创建根结点，递归创建T->lchild,T->rchild
    // @@1

    T = (BiNode *)malloc(sizeof(BiNode));
    int root_pos_c = high_b;
    char root = pc[root_pos_c];
    T->data = root;
    int root_pos_a = -1;

    for (int i = low_b; i <= high_b; i++) {
        if (pb[i] == root) {
            root_pos_a = i;
            break;
        }
    }

    int leftChildTreeNodeCount = root_pos_a - low_b;
    int rightChildTreeNodeCount = high_b - root_pos_a;

    // 开始左子树处的递归
    if (leftChildTreeNodeCount == 0) {
        T->lchild = NULL;
    } else {
        create(T->lchild, pb, low_b, root_pos_a - 1, pc, low_b, high_b - rightChildTreeNodeCount - 1);
    }
    // 开始右子树处的递归
    if (rightChildTreeNodeCount == 0) {
        T->rchild = NULL;
    } else {
        create(T->rchild, pb, root_pos_a + 1, high_b, pc, high_b - rightChildTreeNodeCount, high_b - 1);
    }

    return 1;
    // @ @1
}

int CreateBiTree(BiTree &T, int n) {
    //@@2 //读入先序，中序序列，分别存入数组pa，pb
    char pb[100];
    char pc[100];

    // 吞掉多余的\n
    getchar();

    for (int i = 0; i < n; i++) {
        scanf("%c", &pb[i]);
    }

    getchar();

    for (int i = 0; i < n; i++) {
        scanf("%c", &pb[i]);
    }
    //@@2
    //调用create函数创建二叉树T
    if (create(T, pb, 0, n - 1, pb, 0, n - 1)) {
        return 1;
    }
}

int Preorder(BiTree T) //后序遍历
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
    int n;
    BiTree T;

    cin >> n; //二叉树结点个数

    CreateBiTree(T, n); //创建二叉链表

    Preorder(T); //后序遍历

    getchar();
    getchar();
    return 1;
}