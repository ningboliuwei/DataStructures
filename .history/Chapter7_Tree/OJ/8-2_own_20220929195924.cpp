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
    // @@1

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
    // @ @1
}

int CreateBiTree(BiTree &T, int n) {
    //@@2 //读入先序，中序序列，分别存入数组pa，pb
    char pa[100];
    char pb[100];

    // 吞掉多余的\n
    getchar();

    for (int i = 0; i < n; i++) {
        scanf("%c", &pa[i]);
    }

    getchar();

    for (int i = 0; i < n; i++) {
        scanf("%c", &pb[i]);
    }
    //@@2
    //调用create函数创建二叉树T
    if (create(T, pa, 0, n - 1, pb, 0, n - 1)) {
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

    Postorder(T); //后序遍历

    getchar();
    getchar();
    return 1;
}