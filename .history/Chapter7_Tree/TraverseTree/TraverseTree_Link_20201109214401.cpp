//
// Created by Liu Wei on 2018/10/16.
//

//
// Created by Liu Wei on 2018/10/16.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct BT {
    char data;
    BT *lchild;
    BT *rchild;
};

struct BT *GetTree() {
    struct BT *nodeA = (struct BT *)malloc(sizeof(struct BT));
    nodeA->data = 'A';

    struct BT *nodeB = (struct BT *)malloc(sizeof(struct BT));
    nodeB->data = 'B';

    struct BT *nodeC = (struct BT *)malloc(sizeof(struct BT));
    nodeC->data = 'C';

    struct BT *nodeD = (struct BT *)malloc(sizeof(struct BT));
    nodeD->data = 'D';

    struct BT *nodeE = (struct BT *)malloc(sizeof(struct BT));
    nodeE->data = 'E';

    struct BT *nodeF = (struct BT *)malloc(sizeof(struct BT));
    nodeF->data = 'F';

    // struct BT *nodeG = (struct BT *)malloc(sizeof(struct BT));
    // nodeG->data = 'G';

    // Tree1 ABCDEGF /CBEGDFA/CGEFDBA
    nodeA->lchild = nodeB;
    nodeA->rchild = NULL;

    nodeB->lchild = nodeC;
    nodeB->rchild = nodeD;

    nodeC->lchild = NULL;
    nodeC->rchild = NULL;

    nodeD->lchild = nodeE;
    nodeD->rchild = nodeF;

    nodeE->lchild = NULL;
    nodeE->rchild = nodeG;

    nodeF->lchild = NULL;
    nodeF->rchild = NULL;

    nodeG->lchild = NULL;
    nodeG->rchild = NULL;

    // Tree2 ABDEFGC/DBFEGAC/DFGEBCA
    // nodeA->lchild = nodeB;
    // nodeA->rchild = nodeC;

    // nodeB->lchild = nodeD;
    // nodeB->rchild = nodeE;

    // nodeC->lchild = NULL;
    // nodeC->rchild = NULL;

    // nodeD->lchild = NULL;
    // nodeD->rchild = NULL;

    // nodeE->lchild = nodeF;
    // nodeE->rchild = nodeG;

    // nodeF->lchild = NULL;
    // nodeF->rchild = NULL;

    // nodeG->lchild = NULL;
    // nodeG->rchild = NULL;

    // return nodeA;
}

void PreOrderTraverse(struct BT *tree) {
    if (tree != NULL) {
        printf("%c ", tree->data);
        PreOrderTraverse(tree->lchild);
        PreOrderTraverse(tree->rchild);
    }
}

void MiddleOrderTraverse(struct BT *tree) {
    if (tree != NULL) {
        MiddleOrderTraverse(tree->lchild);
        printf("%c ", tree->data);
        MiddleOrderTraverse(tree->rchild);
    }
}

void PostOrderTraverse(struct BT *tree) {
    if (tree != NULL) {
        PostOrderTraverse(tree->lchild);
        PostOrderTraverse(tree->rchild);
        printf("%c ", tree->data);
    }
}

int main() {
    struct BT *tree = GetTree();

    printf("PreOrder: ");
    PreOrderTraverse(tree);
    printf("\n");

    printf("MiddleOrder: ");
    MiddleOrderTraverse(tree);
    printf("\n");

    printf("PostOrder: ");
    PostOrderTraverse(tree);
    printf("\n");

    getchar();
}