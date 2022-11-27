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

void BiTreeInsert(BiTree &tree, int value) {
    BiTreeNode *p = tree;
    BiTreeNode *f = NULL;

    while (p != NULL) {
        if (p->element == value) {
            return;
        }
        f = p;

        if (value < p->element) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }

    p = (BiTreeNode *)malloc((sizeof(BiTreeNode)));
    p->lchild = NULL;
    p->rchild = NULL;
    p->element = value;

    if (tree == NULL) {
        tree = p;
    } else if (value < p->element) {
        f->lchild = p;
    } else {
        f->rchild = p;
    }
}

BiTree CreateBiTree(BiTree &tree) {
    int number = 0;

    while (number != -1) {
        scanf("%d", &number);
        BiTreeInsert(tree, number);
    }
}

int main() {
    BiTree tree = NULL;
    CreateBiTree(tree);

    getchar();
    getchar();
}
