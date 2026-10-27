#include <stdio.h>
#include <stdlib.h>

// 定义二叉树结点结构
typedef struct TreeNode {
    char data;
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
} TreeNode;

// 创建新结点
TreeNode *createNode(char data) {
    if (data == '*') {
        return NULL;
    }
    
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

    if (!node) {
        printf("内存分配失败\n");
        exit(1);
    }

    node->data = data;
    node->leftChild = node->rightChild = NULL;

    return node;
}

// 构建二叉树的递归函数
TreeNode *buildTree(const char *str, int *index) {
    if (str[*index] == '\0') {
        return NULL;
    }

    char current = str[*index];
    (*index)++;

    if (current == '*') {
        return NULL;
    }

    TreeNode *node = createNode(current);
    node->leftChild = buildTree(str, index);
    node->rightChild = buildTree(str, index);
    return node;
}

// 前序遍历：根-左-右
void preorder(TreeNode *root, char *output, int *pos) {
    if (root == NULL) {
        return;
    }
    output[*pos] = root->data;
    (*pos)++;
    preorder(root->leftChild, output, pos);
    preorder(root->rightChild, output, pos);
}

// 中序遍历：左-根-右
void inorder(TreeNode *root, char *output, int *pos) {
    if (root == NULL) {
        return;
    }
    inorder(root->leftChild, output, pos);
    output[*pos] = root->data;
    (*pos)++;
    inorder(root->rightChild, output, pos);
}

// 后序遍历：左-右-根
void postorder(TreeNode *root, char *output, int *pos) {
    if (root == NULL) {
        return;
    }
    postorder(root->leftChild, output, pos);
    postorder(root->rightChild, output, pos);
    output[*pos] = root->data;
    (*pos)++;
}

// 释放二叉树内存的递归函数
void freeTree(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->leftChild);
    freeTree(root->rightChild);
    free(root);
}

int main() {
    // 读取输入字符串
    char str[1000];
    scanf("%s", str); // 假设输入不包含空格

    int index = 0;
    TreeNode *root = buildTree(str, &index);

    // 准备输出字符串
    char preOrderOutput[1000];
    char inOrderOutput[1000];
    char postOrderOutput[1000];

    int pos = 0;
    preorder(root, preOrderOutput, &pos);
    preOrderOutput[pos] = '\0'; // 添加字符串结束符

    pos = 0;
    inorder(root, inOrderOutput, &pos);
    inOrderOutput[pos] = '\0'; // 添加字符串结束符

    pos = 0;
    postorder(root, postOrderOutput, &pos);
    postOrderOutput[pos] = '\0'; // 添加字符串结束符

    // 输出遍历结果
    printf("%s\n%s\n%s\n", preOrderOutput, inOrderOutput, postOrderOutput);

    // 释放内存
    freeTree(root);

    return 0;
}
