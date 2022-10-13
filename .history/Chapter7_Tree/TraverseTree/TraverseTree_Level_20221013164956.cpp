//
// Created by 慰 on 2018/10/18.
//

//
// Created by Liu Wei on 2018/10/19.
// 1631 问题 A: 【数据结构7-1】根据先序创建二叉树
// 测试数据：ab**c**
// 结果：
// abc
// bac
// bca
// OJ PASSED
#include <stdio.h>
#include <stdlib.h>

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
        T = (BiNode *)malloc(sizeof(BiNode));
        T->data = elements[index];
        CreateBiTree(T->lchild, elements, ++index);
        CreateBiTree(T->rchild, elements, ++index);
    }
}

void LevelOrder(BiTree &tree) {
}

int main() {
    char elements[20];
    int index = 0;
    BiTree tree;

    gets(elements);
    CreateBiTree(tree, elements, index);
    LevelOrder(tree);
}
