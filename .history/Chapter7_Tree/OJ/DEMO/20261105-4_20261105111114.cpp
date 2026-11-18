#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

void create(BiTree &T, char pa[], int low_a, int high_a, char pb[], int low_b, int high_b) { //创建根结点，递归创建T->lchild,T->rchild
    int root_pos_a = low_a;
}

int CreateBiTree(BiTree &T, int n) {
    //读入先序，中序序列，分别存入数组pa，pb
    char pa[100], pb[100];
    scanf("%s", pa);
    scanf("%s", pb);
    create(T, pa, 0, n - 1, pb, 0, n - 1); //调用create函数创建二叉树T
    return 1;
}

void Postorder(BiTree T) //后序遍历
{
}

int main() {
    BiTree T;
    int n;

    cin >> n; //二叉树结点个数

    CreateBiTree(T, n); //创建二叉链表

    Postorder(T); //后序遍历

    return 1;
}