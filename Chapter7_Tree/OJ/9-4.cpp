// Created by Liu Wei on 2018/10/19.
// 问题 D: 【数据结构7-8】求二叉树的度为1的结点个数
// 测试数据：abd*g***ce*h**f**
// 结果：3

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

void Count(BiTree T, int &count) {

    if (T != NULL) {
        if (T->lchild == NULL xor T->rchild == NULL) {
            count++;
        }

        Count(T->lchild, count);
        Count(T->rchild, count);
    }
}

int main() {
    char elements[20];
    int index = 0;
    BiTree T;
    int count = 0;

    gets(elements);
    CreateBiTree(T, elements, index);

    Count(T, count);
    printf("%d", count);

}

