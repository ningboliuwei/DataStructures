#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct BiTreetype {
    char data;
    struct BiTreetype *leftChild;
    struct BiTreetype *rightChild;
} BiNode, *BiTree;

void preorder(BiTree t) {
    if (t) {
        printf("%c", t->data);
        preorder(t->leftChild);
        preorder(t->rightChild);
    }
}
void inorder(BiTree t) {
    if (t) {
        inorder(t->leftChild);
        printf("%c", t->data);
        inorder(t->rightChild);
    }
}
void postorder(BiTree t) {
    if (t) {
        postorder(t->leftChild);
        postorder(t->rightChild);
        printf("%c", t->data);
    }
}

// elements: AB**C**
void create(BiTree &t, char *elements, int &index) {
    if (elements[index] == '\0') {
        return;
    } else if (elements[index] == '*') {
        t = NULL;
    } else {
        t = new BiNode;
        t->data = elements[index];
        create(t->leftChild, elements, ++index);
        create(t->rightChild, elements, ++index);
    }
}
int main() {
    BiTree t;
    char elements[100];
    int index = 0;

    scanf("%s", &elements);
    create(t, elements, index);
    preorder(t);
    inorder(t);
}