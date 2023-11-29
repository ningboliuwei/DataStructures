#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 问题 B: 【数据结构9-2】二分查找
// ID：1654
// OJ PASSED
// 输入：
// 45 23 56 12 78 6 20 58 60 90 -1
// 60
// 输出：输出查找过程中经过的结点以及最后找到的结点，结点之间用空格分隔，
// 45 56 78 58 60

#define MAX_COUNT 100
// 定义二叉排序树的结点结构
typedef struct BiTreeNodeType {
    int element;
    struct BiTreeNodeType *lchild;
    struct BiTreeNodeType *rchild;
} * BiTree, BiTreeNode;
// 在二叉排序树中插入一个元素
void BiTreeInsert(BiTree &tree, int value) {
    // 定义一个名为 node 的结点指针，初始值指向当前子树的根结点
    BiTreeNode *node = tree;
    // 定义一个名为 parentNode 的结点指针，初始值为 NULL
    BiTreeNode *parentNode = NULL;
    // 当 node 指针指向的结点不为空时，循环执行以下操作
    while (node != NULL) {
        // 如果当前结点的值等于要插入的值，那么直接返回（因为二叉排序树中不允许出现相同的值）
        if (node->element == value) {
            return;
        }
        // 将 parentNode 指针指向当前结点
        parentNode = node;
        // 如果要插入的值小于当前结点的值，那么将 node 指针指向当前结点的左孩子（可以理解为进入左子树寻找要插入的值应该在的位置）
        if (value < node->element) {
            node = node->lchild;
        } // 如果要插入的值大于当前结点的值，那么将 node 指针指向当前结点的右孩子（可以理解为进入右子树寻找要插入的值应该在的位置）
        else {
            node = node->rchild;
        }
    }
    // 创建一个新的结点，将要插入的值赋值给新结点的 element 字段
    node = (BiTreeNode *)malloc((sizeof(BiTreeNode)));
    node->lchild = NULL;
    node->rchild = NULL;
    node->element = value;
    // 如果 tree 结点为空，那么说明当前二叉排序树为空，将新结点作为根结点
    if (tree == NULL) {
        tree = node;
    } // 如果要插入的值小于 parentNode 指针指向的结点的值，那么将新结点作为 parentNode 指针指向的结点的左孩子
    else if (value < parentNode->element) {
        parentNode->lchild = node;
    } // 如果要插入的值大于 parentNode 指针指向的结点的值，那么将新结点作为 parentNode 指针指向的结点的右孩子
    else {
        parentNode->rchild = node;
    }
}

void BiTreeSearch(BiTree &tree, int key) {
    BiTreeNode *node = tree;

    while (node != NULL) {
        printf("%d ", node->element);

        if (node->element == key) {
            return;
        }

        if (key < node->element) {
            node = node->lchild;
        } else {
            node = node->rchild;
        }
    }

    if (node == NULL) {
        printf("-1");
    }
}

void CreateBiTree(BiTree &tree) {
    int number = 0;

    while (number != -1) {
        scanf("%d", &number);
        BiTreeInsert(tree, number);
    }
}

int main() {
    BiTree tree = NULL;
    CreateBiTree(tree);

    int key;
    scanf("%d", &key);
    BiTreeSearch(tree, key);

    getchar();
}
