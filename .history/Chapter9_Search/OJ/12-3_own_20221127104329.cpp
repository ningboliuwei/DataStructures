#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 问题 B: 【数据结构9-2】二分查找
// ID：1654
// 输入：
// 45 23 56 12 78 6 20 58 60 90 -1
// 60
// 输出：输出查找过程中经过的结点以及最后找到的结点，结点之间用空格分隔，
// 45 56 78 58 60

#define MAX_COUNT 100

typedef struct BiTreeNodeType {
    int element;
    struct BiTreeNodeType *lchild;
    struct BiTreeNodeType *rchild;
} * BiTree, BiTreeNode;

void BiTreeInsert(BiTree *tree, int value) {
}

void CreateBiTree(BiTree tree, int element) {
    if (tree == NULL) {
        BiTreeNode *node = (BiTreeNode *)malloc((sizeof(BiTreeNode)));
        node->element = element;
    }
}

int main() {
    // 存放数据的数组
    int array[MAX_COUNT];
    // 比较次数
    int count = 0;
    // 找到的位置
    int pos = 0;
    // 输入的数据长度
    // 要查找的关键字
    int key = 0;
    scanf("%d", &key);

    if (pos == -1) {
        printf("失败 %d", count);
    } else {
        printf("%d %d", pos + 1, count);
    }

    getchar();
    getchar();
}
