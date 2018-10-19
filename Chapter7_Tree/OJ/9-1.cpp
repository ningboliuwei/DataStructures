//
// Created by Liu Wei on 2018/10/19.
// 问题 A: 【数据结构7-1】根据先序创建二叉树
// 测试数据：ab**c**
// 结果：
//abc
//bac
//bca
#include <stdlib.h>
#include <stdio.h>

typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

int CreateBiTree(BiTree &T, char *elements, int &index) {
    if (elements[index] != '\0') {
        if (elements[index] == '*') {
            T = NULL;
        } else {
            T = (BiNode *) malloc(sizeof(BiNode));
            T->data = elements[index];
            CreateBiTree(T->lchild, elements, ++index);
            CreateBiTree(T->rchild, elements, ++index);
        }
    }
}

void PreOrderTraverse(BiTree T) {

    if (T != NULL) {
        printf("%c", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }

}

void MiddleOrderTraverse(BiTree T) {
    if (T != NULL) {
        MiddleOrderTraverse(T->lchild);
        printf("%c", T->data);
        MiddleOrderTraverse(T->rchild);
    }

}

void PostOrderTraverse(BiTree T) {
    if (T != NULL) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c", T->data);
    }

}


int main() {
    char elements[20];
    int index = 0;
    BiTree T;

    gets(elements);
    CreateBiTree(T, elements, index);

    PreOrderTraverse(T);
    printf("\n");
    MiddleOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");
}

