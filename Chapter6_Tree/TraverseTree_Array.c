//
// Created by 慰 on 2018/10/16.
//
#include <stdio.h>
#include <stdlib.h>

#define TREE_NODE_COUNT 7

typedef int DataType;

typedef struct BT {
    DataType data;
    int lchild;
    int rchild;
};

struct BT *GetTree(struct BT *tree) {
    tree[0].data = 'a';
    tree[0].lchild = 1;
    tree[0].rchild = 2;

    tree[1].data = 'b';
    tree[1].lchild = 3;
    tree[1].rchild = 4;

    tree[2].data = 'c';
    tree[2].lchild = -1;
    tree[2].rchild = -1;

    tree[3].data = 'd';
    tree[3].lchild = -1;
    tree[3].rchild = -1;

    tree[4].data = 'e';
    tree[4].lchild = 5;
    tree[4].rchild = 6;

    tree[5].data = 'f';
    tree[5].lchild = -1;
    tree[5].rchild = -1;

    tree[6].data = 'g';
    tree[6].lchild = -1;
    tree[6].rchild = -1;

    return tree;
}

void PreOrderTraverse(struct BT *tree, int index) {
    printf("%c ", tree[index].data);

    if (tree[index].lchild != -1) {
        PreOrderTraverse(tree, tree[index].lchild);
    }

    if (tree[index].rchild != -1) {
        PreOrderTraverse(tree, tree[index].rchild);
    }
}

void MiddleOrderTraverse(struct BT *tree, int index) {
    if (tree[index].lchild != -1) {
        PreOrderTraverse(tree, tree[index].lchild);
    }

    printf("%c ", tree[index].data);

    if (tree[index].rchild != -1) {
        PreOrderTraverse(tree, tree[index].rchild);
    }
}

void PostOrderTraverse(struct BT *tree, int index) {
    if (tree[index].lchild != -1) {
        PreOrderTraverse(tree, tree[index].lchild);
    }

    if (tree[index].rchild != -1) {
        PreOrderTraverse(tree, tree[index].rchild);
    }

    printf("%c ", tree[index].data);
}

int main() {
    struct BT root;
    root.lchild = 0;
    struct BT *tree = (struct BT *) malloc(sizeof(struct BT) * TREE_NODE_COUNT);
    tree = GetTree(tree);

    printf("PreOrder: ");
    PreOrderTraverse(tree, 0);
    printf("\n");

    printf("MiddleOrder: ");
    MiddleOrderTraverse(tree, 0);
    printf("\n");

    printf("PostOrder: ");
    PostOrderTraverse(tree, 0);
    printf("\n");

    getchar();
}

