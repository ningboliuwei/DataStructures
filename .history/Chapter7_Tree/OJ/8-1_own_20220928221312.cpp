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
    char root = pa[low_a];
    T->data = root;
    int pos = -1;

    for (int i = low_b; i < high_b; i++) {
        if (pb[i] == root) {
            pos = i;
            break;
        }
    }

    int leftChildTreeNodeCount = pos - low_b;
    int rightChildTreeNodeCount = high_b - pos;

    // 开始转换为左子树
    // 针对于 pa 的动作
    low_a++;
    high_a += leftChildTreeNodeCount;

    // @@1
}

int CreateBiTree(BiTree &T, int n) {
    //@@2 //读入先序，中序序列，分别存入数组pa，pb
    char pa[MAX_NODE_COUNT];
    char pb[MAX_NODE_COUNT];

    for (int i = 0; i < n; i++) {
        scanf("%c", &pa[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        scanf("%c", &pb[i]);
    }
    //@@2

    if (create(T, pa, 0, n - 1, pb, 0, n - 1)) //调用create函数创建二叉树T
        return 1;
}

int Postorder(BiTree T) //后序遍历
{
    //@@3
    //@@3
}

int main() {
    BiTree T;
    int n;

    cin >> n; //二叉树结点个数

    CreateBiTree(T, n); //创建二叉链表

    Postorder(T); //后序遍历

    return 1;
}