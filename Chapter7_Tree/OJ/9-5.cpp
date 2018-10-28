//
// Created by Liu Wei on 2018/10/23.
// 问题 E: 【数据结构7-9】求二叉树的深度
// 测试数据：ABE**FH***C*G**  答案：5
// 测试数据：AB**C**  答案：2

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

int Depth(BiTree T) {
    if (T == NULL) {
        return 0;
    }

    int leftDepth = Depth(T->lchild);
    int rightDepth = Depth(T->rchild);

    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int main() {
    char elements[20];
    int index = 0;
    BiTree T;


    gets(elements);
    CreateBiTree(T, elements, index);

    int depth = Depth(T);
    printf("%d", depth);
}

