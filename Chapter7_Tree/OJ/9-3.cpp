//
// Created by Liu Wei on 2018/10/30.
// 问题 C: 【数据结构7-7】交换二叉树的左右子树
// 测试数据：
// 输入：先序：ABE**FH***C*G**
// 输出：GCAFHBE

#include <stdlib.h>
#include <stdio.h>

typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

int CreateBiTree(BiTree &T, char *elements, int &index) {
    if (elements[index] == '\0') {
        return 1;
    }

    if (elements[index] == '*') {
        T = NULL;
    } else {
        T = (BiNode *) malloc(sizeof(BiNode));
        T->data = elements[index];
        CreateBiTree(T->lchild, elements, ++index);
        CreateBiTree(T->rchild, elements, ++index);
    }
}

void Swap(BiTree T) {
    BiNode *temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;

    if (T->lchild != NULL) {
        Swap(T->lchild);
    }

    if (T->rchild != NULL) {
        Swap(T->rchild);
    }
}

void MiddleOrderTraverse(BiTree T) {
    if (T != NULL) {
        MiddleOrderTraverse(T->lchild);
        printf("%c", T->data);
        MiddleOrderTraverse(T->rchild);
    }
}

int main() {
    char elements[20];
    int index = 0;
    BiTree T;
    int count = 0;

    gets(elements);
    CreateBiTree(T, elements, index);

    Swap(T);

    MiddleOrderTraverse(T);
}


