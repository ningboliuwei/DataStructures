#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;              // 节点数据
    struct TreeNode *left;  // 左子树
    struct TreeNode *right; // 右子树
} TreeNode;

// 创建新的树节点
TreeNode *createNode(char data) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;                  // 初始化节点数据
    newNode->left = newNode->right = NULL; // 初始化左右子树为空
    return newNode;
}

// 在先序和中序序列中找到根节点的位置
int findRootIndex(char *inorder, int start, int end, char root) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == root) {
            return i; // 返回根节点在中序序列中的索引
        }
    }
    return -1; // 未找到根节点
}

// 递归构建二叉树
TreeNode *buildTree(char *preorder, char *inorder, int *preIndex, int inorderStart, int inorderEnd) {
    // 递归终止条件
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // 根节点为先序序列的当前索引
    char rootData = preorder[*preIndex];
    TreeNode *root = createNode(rootData); // 创建根节点

    (*preIndex)++; // 移动到下一个根节点

    // 在中序序列中找到根节点的位置
    int rootIndex = findRootIndex(inorder, inorderStart, inorderEnd, rootData);

    // 递归构建左子树和右子树
    root->left = buildTree(preorder, inorder, preIndex, inorderStart, rootIndex - 1);
    root->right = buildTree(preorder, inorder, preIndex, rootIndex + 1, inorderEnd);

    return root; // 返回构建好的树
}

// 计算叶子节点的数量
int countLeafNodes(TreeNode *root) {
    if (root == NULL) {
        return 0; // 空树返回0
    }
    // 如果是叶子节点，返回1
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    // 否则递归计算左子树和右子树的叶子节点数量
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    int n;           // 节点个数
    scanf("%d", &n); // 输入节点个数

    char preorder[n + 1]; // 先序遍历序列
    char inorder[n + 1];  // 中序遍历序列

    scanf("%s", preorder); // 输入先序遍历序列
    scanf("%s", inorder);  // 输入中序遍历序列

    int preIndex = 0;                                                   // 记录先序序列的当前索引
    TreeNode *root = buildTree(preorder, inorder, &preIndex, 0, n - 1); // 构建树

    // 计算并输出叶子节点的数量
    int leafCount = countLeafNodes(root);
    printf("%d\n", leafCount); // 输出叶子节点的个数

    return 0;
}
