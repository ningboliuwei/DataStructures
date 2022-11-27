#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 问题 B: 【数据结构9-2】二分查找
// ID：1654
// 输入：
// 45 23 56 12 78 6 20 58 60 90 -1
// 60
// 输出：输出查找过程中经过的结点以及最后找到的结点，结点之间用空格分隔，
// 45 56 78 58 60

#define MAX_COUNT 100

typedef struct BiTreeNodeType {
    int element;
    struct BiTreeNodeType *lchild;
    struct BiTreeNodeType *rchild;
} * BiTree, BiTreeNode;

BiTreeNode *BiTreeSearch(BiTree tree, int key) {
    BiTreeNode *node = tree;

    while (node != NULL) {
        if (node->element == key) {
            return node;
        } else if (key < node->element) {
            node = node->lchild;
        } else {
            node = node->rchild;
        }
    }
}

void BiTreeInsert(BiTree tree, int value) {
    BiTreeNode *pos = BiTreeSearch(tree, value);

    pos = (BiTreeNode *)malloc((sizeof(BiTreeNode)));
    pos->lchild = NULL;
    pos->rchild = NULL;
    pos->element = value;

    if (tree == NULL) {
        tree = pos;
    } else if (value < pos->element) {
        pos->lchild = pos;
    } else {
        pos->rchild = pos;
    }
}

BiTree CreateBiTree(BiTree tree) {
    int number = 0;

    while (number != -1) {
        scanf("%d", &number);
        BiTreeInsert(tree, number);
    }
}

int main() {
    BiTree tree = (BiTree)malloc(sizeof(BiTree));
    tree->lchild = NULL;
    tree->rchild = NULL;

    CreateBiTree(tree);

    getchar();
    getchar();
}
