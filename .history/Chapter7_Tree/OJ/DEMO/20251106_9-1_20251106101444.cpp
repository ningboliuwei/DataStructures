#include <stdio.h>
#include <stdlib.h>

typedef struct BiNode {
    char data;
    struct BiNode *lchild;
    struct BiNode *rchild;
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
    =
}

int main() {
    char elements[20];
    int index = 0;
    BiTree T;

    gets(elements);
    CreateBiTree(T, elements, index);

    return 1;
}