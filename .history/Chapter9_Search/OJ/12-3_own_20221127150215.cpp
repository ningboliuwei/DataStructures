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
    BiTreeNode *node = tree;
    BiTreeNode *parentNode = NULL;

    while (node != NULL) {
        if (node->element == value) {
            return;
        }
        parentNode = node;

        if (value < node->element) {
            node = node->lchild;
        } else {
            node = node->rchild;
        }
    }

    node = (BiTreeNode *)malloc((sizeof(BiTreeNode)));
    node->lchild = NULL;
    node->rchild = NULL;
    node->element = value;

    if (tree == NULL) {
        tree = node;
    } else if (value < parentNode->element) {
        parentNode->lchild = node;
    } else {
        parentNode->rchild = node;
    }
}

void BiTreeSearch(BiTree &tree, int key) {
    BiTreeNode *node = tree;
    int count = 0;

    while (node != NULL) {
        if (node->element == key) {
            return;
        }

        if (key < node->element) {
            node = node->lchild;
        } else {
            node = node->rchild;
        }
        count++;
    }

    printf("%d", count);
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

    int key;
    scanf("%d", &key);
    BiTreeSearch(tree, key);

    getchar();
    getchar();
    getchar();
}
