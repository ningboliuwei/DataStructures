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

typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

int create(BiTree &T, char pa[], int low_a, int high_a, char pb[], int low_b,
           int high_b) { //创建根结点，递归创建T->lchild,T->rchild
    // @@1
    // @@1
}

int CreateBiTree(BiTree &T, int n) {
    // @@2 //读入先序，中序序列，分别存入数组pa，pb
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