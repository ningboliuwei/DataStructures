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

#define MAX_NODE_COUNT 20

typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

int create(BiTree &T, char pa[], int low_a, int high_a, char pb[], int low_b,
           int high_b) { //创建根结点，递归创建T->lchild,T->rchild
    // @@1

    T = (BiNode *)malloc(sizeof(BiNode));
    char root = pa[low_a];
    T->data = root;
    int root_pos = -1;

    for (int i = low_b; i <= high_b; i++) {
        if (pb[i] == root) {
            root_pos = i;
            break;
        }
    }

    int leftChildTreeNodeCount = root_pos - low_b;
    int rightChildTreeNodeCount = high_b - root_pos;

    // 开始左子树处的递归
    // 在左子树处递归时，针对于 pa 的动作
    if (leftChildTreeNodeCount == 0) {
        T->lchild = NULL;
    } else {
        low_a++;
        high_a = low_a + leftChildTreeNodeCount - 1;
        // 针对于 pb 的动作
        high_b = root_pos - 1;
        create(T->lchild, pa, low_a, high_a, pb, low_b, high_b);
    }
    // 开始右子树处的递归
    // 在右子树处递归时，针对于 pa 的动作
    if (rightChildTreeNodeCount == 0) {
        T->rchild = NULL;
    } else {
        high_a = low_a + rightChildTreeNodeCount + 1;
        // 针对于 pb 的动作
        low_b = root_pos + 1;
        create(T->rchild, pa, low_a, high_a, pb, low_b, high_b);
    }
    // @@1
}

int CreateBiTree(BiTree &T, int n) {
    //@@2 //读入先序，中序序列，分别存入数组pa，pb
    char pa[MAX_NODE_COUNT];
    char pb[MAX_NODE_COUNT];

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

int Postorder(BiTree T) //后序遍历
{
    //@@3
    Postorder(T->lchild);
    Postorder(T->rchild);
    if (T != NULL) {
        printf("%c", T->data);
    }
    //@@3
}

int main() {
    BiTree tree;
    int n;

    cin >> n; //二叉树结点个数

    CreateBiTree(tree, n); //创建二叉链表

    Postorder(tree); //后序遍历

    return 1;
}