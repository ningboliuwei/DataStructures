//
// Created by Liu Wei on 2018/10/11.
// 问题 A: 【数据结构7-4】由先序和中序恢复二叉树
// 测试数据：
// 9
// ABDEHCFIG
// DBHEAIFCG
//结果：DHEBIFGCA
// OJ PASSED

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
    // 先序序列中的下界处（第一个元素）是当前子树的根元素的位置
    int root_pos_a = low_a;
    // 在先序序列中得到根元素
    char root = pa[root_pos_a];
    // 当前子树的根元素为在先序序列中找到的根元素
    T->data = root;
    // 声明一个变量，用于保存中序序列中当前子树的根元素（即在先序序列中找到的根元素）的位置
    int root_pos_b = -1;

    for (int i = low_b; i <= high_b; i++) {
        if (pb[i] == root) {
            root_pos_b = i;
            break;
        }
    }

    // 当前根的左子树的元素个数为 根元素在中序序列中的下标 减去 当前子树元素在中序序列中的元素范围下界的下标
    int leftChildTreeNodeCount = root_pos_b - low_b;
    // 当前根的右子树的元素个数为 当前子树元素在中序序列中的元素范围上界的下标 减去 根元素在中序序列中的下标
    int rightChildTreeNodeCount = high_b - root_pos_b;

    // 开始左子树处的递归
    if (leftChildTreeNodeCount == 0) {
        // 若当前左子树元素个数为 0，则将当前元素的左孩子设为 NULL
        T->lchild = NULL;
    } else {
        // 否则（当前左子树元素个数不为 0），递归调用本函数，其中要创建的左子树的根节点为当前结点的左孩子（T->lchild）,
        // 实参 pa 为先序序列
        // 左子树在先序序列中的元素范围下界为当前子树在先序序列中的元素范围下界的后一个元素的下标（low_a+1）
        // 左子树在先序序列中的元素范围上界为左子树在先序序列中的元素范围下界 加 左子树的元素个数 - 1 →（low_a +
        // leftChildTreeNodeCount）
        // 实参 pb 为中序序列
        // 左子树在中序序列中的元素范围下界为当前子树在中序序列中的元素范围下界的下标（low_b）
        // 左子树在中序序列中的元素范围上界为当前子树在中序序列中的根节点位置的前一个元素的下标（root_pos_b - 1）
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

int Postorder(BiTree T) //后序遍历
{
    //@@3
    if (T != NULL) {
        Postorder(T->lchild);
        Postorder(T->rchild);
        printf("%c", T->data);
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