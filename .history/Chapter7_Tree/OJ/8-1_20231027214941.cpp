//
// Created by Liu Wei on 2018/10/11.
// 问题 A: 【数据结构7-4】由先序和中序恢复二叉树
// 测试数据：
// 9
// ABDEHCFIG
// DBHEAIFCG
//结果：DHEBIFGCA
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// 声明一个结构体类型 BiNode，表示二叉树的结点
typedef struct BiNode {
    char data;                      // 结点的数据域，用 char 类型表示
    struct BiNode *lchild, *rchild; // 左右子树的指针
} BiNode, *BiTree;                  // 定义一个二叉树类型 BiTree，是指向 BiNode 的指针

// 创建二叉树的函数，参数包括先序遍历序列 pa，中序遍历序列 pb，以及它们的下标范围
int create(BiTree &T, char pa[], int low_a, int high_a, char pb[], int low_b, int high_b) {
    T = (BiNode *)malloc(sizeof(BiNode)); // 分配一个结点的内存空间
    T->data = pa[low_a];                  // 将先序遍历序列的第一个元素作为根结点
    int rootIndex = 0;                    // 记录根结点在中序遍历序列中的下标

    for (int i = low_b; i <= high_b; i++) { // 在中序遍历序列中查找根结点
        if (pb[i] == T->data) {
            rootIndex = i;
            break;
        }
    }

    int leftChildTreeNodeCount = rootIndex - low_b; // 左子树的结点个数

    if (leftChildTreeNodeCount > 0) {                 // 如果左子树非空
        T->lchild = (BiNode *)malloc(sizeof(BiNode)); // 分配一个结点的内存空间
        // 递归创建左子树
        create(T->lchild, pa, low_a + 1, low_a + leftChildTreeNodeCount, pb, low_b, rootIndex - 1);
    } else {
        T->lchild = NULL; // 左子树为空
    }

    int rightChildTreeNodeCount = high_b - rootIndex; // 右子树的结点个数

    if (rightChildTreeNodeCount > 0) {                // 如果右子树非空
        T->rchild = (BiNode *)malloc(sizeof(BiNode)); // 分配一个结点的内存空间
        // 递归创建右子树
        create(T->rchild, pa, high_a - rightChildTreeNodeCount + 1, high_a, pb, rootIndex + 1, high_b);
    } else {
        T->rchild = NULL; // 右子树为空
    }
}

// 创建二叉树的函数，参数包括二叉树的指针 T 和结点个数 n
int CreateBiTree(BiTree &T, int n) {
    // 创建二叉树的函数，参数包括二叉树的指针 T 和结点个数 n
    //@@2                           //读入先序，中序序列，分别存入数组pa，pb
    char pa[20];
    char pb[20];

    for (int i = 0; i < n; i++) {
        scanf("%c", &pa[i]); // 读入先序遍历序列
    }

    // 用于避免上一行结束的 \n 字符导致的问题
    scanf("\n");

    for (int i = 0; i < n; i++) {
        scanf("%c", &pb[i]); // 读入中序遍历序列
    }
    //@@2

    if (create(T, pa, 0, n - 1, pb, 0, n - 1)) //调用create函数创建二叉树T
        return 1;
}

// 后序遍历
int Postorder(BiTree T) {
    //@@3
    if (T != NULL) {
        Postorder(T->lchild);  // 递归遍历左子树
        Postorder(T->rchild);  // 递归遍历右子树
        printf("%c", T->data); // 输出结点的数据域
    }
    //@@3
}

int main() {
    BiTree T;
    int n;

    scanf("%d\n", &n); // 读入二叉树结点个数

    if (CreateBiTree(T, n)) { // 创建二叉树
        printf("Error!\n");
        return 0;
    }

    Postorder(T); // 后序遍历二叉树

    return 0;
}