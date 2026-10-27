#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct BiTreetype {
    char data;
    struct BiTreetype *in;
    struct BiTreetype *rightChild;
} BiNode, *BiTree;

void preorder(BiTree t) {
    if (t) {
        printf("%c", t->data);
        preorder(t->in);
        preorder(t->rightChild);
    }
}
void inorder(BiTree t) {
    if (t) {
        inorder(t->in);
        printf("%c", t->data);
        inorder(t->rightChild);
    }
}
void postorder(BiTree t) {
    if (t) {
        postorder(t->in);
        postorder(t->rightChild);
        printf("%c", t->data);
    }
}
void create(BiTree t, char n) {
    if (n == '\0' || n == '*')
        t = NULL;
    else {
        char n;

        scanf("%c", &n);
        t = new BiNode;
        t->data = n;
        create(t->in, n);
        create(t->rightChild, n);
    }
}
int main() {
    BiTree t;
    char n;
    scanf("%c", &n);
    create(t, n);
    preorder(t);
    inorder(t);
}